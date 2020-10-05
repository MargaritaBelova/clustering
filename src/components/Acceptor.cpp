/*
 * Acceptor.cpp
 *
 *  Created on: Sep 17, 2020
 *      Author: anotherme
 */

#include "Acceptor.h"

#include <cassert> // del later

#include "../messages/Accepted.h"
#include "../messages/Accepting.h"
#include "../protocol/Ballot.h"
#include "../destinations/DestinationsType.h"
#include "Node.h"
//#include "../messages/Message.h" // include here or in role.h?



Acceptor::Acceptor(std::weak_ptr<Node> node_) : Role(node_) {
	//initialization with null_balot -is it ok or -1 is better?
	std::unique_ptr<Acceptor> uptr_for_this(this);	//is it safe?
	node.lock()->registerRole(std::move(uptr_for_this));

	ballot_num = std::make_shared<Ballot>(0, "empty"); // change empty later;
	std::cout << "Acceptor created\n";
}

Acceptor::~Acceptor(){
	std::cout << "Acceptor destructed\n";
}

Role_id Acceptor::getRoleName() const{
	return acceptor;	// rewrite to static?
}

//check for bad keys and initial values; check for nullptr which created after construction
void Acceptor::doAccept(const std::string sender, std::shared_ptr<Ballot> ballot_num_,\
		const unsigned long slot, std::shared_ptr<Proposal> proposal){

	assert(ballot_num); // del later;
	std::cout << "Acceptror::doAccept: ballot_num != nullptr\n";
	// check it for variable names
	if (ballot_num_->n >= ballot_num->n){
			ballot_num = ballot_num_;
			auto it = accepted_proposals.find(slot);
			if (it == accepted_proposals.end()){  // rewrite to "||" but shorter?
				accepted_proposals[slot] = std::make_tuple(ballot_num, proposal);
			} else {
				auto previous_ballot = std::get<0>(accepted_proposals[slot]);
				if (previous_ballot->n < ballot_num->n){
					accepted_proposals[slot] = std::make_tuple(ballot_num, proposal);
				}
			}
	}
	//del later
	assert(ballot_num->leader != "empty");

	// del later;
	std::cout << "doAccept: " << sender << " " << ballot_num->n << std::endl;

	auto accepted_msg = std::make_unique<Accepted>(slot, ballot_num);
	//rewrite to inline function as it is used throughout project?
	auto destinations_ptr = std::make_unique<destination_list>();
	destinations_ptr->push_back(sender);
	node.lock()->send(std::move(destinations_ptr), std::move(accepted_msg));
	//del later
	std::cout << "Acceptor.doAccept finished\n";
}

void Acceptor::doPrepare(const std::string sender, std::shared_ptr<Ballot> ballot_num_){
	// add check for nullptr in cmp everywhere!
	if (ballot_num_->n > ballot_num->n){
		ballot_num = ballot_num_;
	}
	auto destinations_ptr = std::make_unique<destination_list>();
	destinations_ptr->push_back(sender);
	auto accepting_msg = std::make_unique<Accepting>(sender);
	node.lock()->send(std::move(destinations_ptr), std::move(accepting_msg));
	//del later
	std::cout << "Acceptor.doPrepare finished\n";
}
