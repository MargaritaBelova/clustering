/*
 * Acceptor.cpp
 *
 *  Created on: Sep 17, 2020
 *      Author: anotherme
 */

#include "Acceptor.h"

// del those later
#include <cassert>
#include <iostream>

#include "../messages/Accepted.h"
#include "../messages/Accepting.h"
#include "../messages/Promise.h"

#include "../protocol/Ballot.h"
#include "Node.h"


Acceptor::Acceptor(std::weak_ptr<Node> node_) : Role(node_) {
	//initialization with null_balot -is it ok or -1 is better?
	ballot_num = std::make_shared<Ballot>(0, "empty"); // change empty later;
	std::cout << "Acceptor created\n";
}

Acceptor::~Acceptor(){
	std::cout << "Acceptor destructed\n";
}

Role_id Acceptor::getRoleName() const {
	return acceptor;
}

void Acceptor::callback(){
	std::cout << "Acceptor callback: it shouldn't be called\n";
}

//check for bad keys and initial values; check for nullptr which created after construction
void Acceptor::doAccept(std::string sender, std::shared_ptr<Ballot> ballot_num_,\
		const unsigned long slot, std::shared_ptr<Proposal> proposal){

	assert(ballot_num); // del later;
	std::cout << "Acceptror::doAccept: ballot_num != nullptr\n";
	if (ballot_num_->n >= ballot_num->n){
			ballot_num = ballot_num_;
			auto const& it = accepted_proposals.find(slot);
			if (it == accepted_proposals.end()){  // rewrite to "||" but shorter?
				accepted_proposals[slot] = std::make_tuple(ballot_num, proposal);
			} else {
				auto& previous_ballot = std::get<0>(accepted_proposals[slot]);
				if (previous_ballot->n < ballot_num->n){
					accepted_proposals[slot] = std::make_tuple(ballot_num, proposal);
				}
			}
	}
	//del later
	assert(ballot_num->leader != "empty");
	std::cout << "doAccept: " << sender << " " << ballot_num->n << std::endl;

	auto accepted_msg = std::make_unique<Accepted>(slot, ballot_num);
	node.lock()->send(std::move(sender), std::move(accepted_msg));
}

// not finished yet!
void Acceptor::doPrepare(std::string sender, std::shared_ptr<Ballot> ballot_num_){
	// check for nullptr
	if (ballot_num_->n > ballot_num->n){ // is it safe for 0 ballot_num or should be >=?
		ballot_num = ballot_num_;
		auto accepting_msg = std::make_unique<Accepting>(sender);
		node.lock()->send(node.lock()->getAddress(), std::move(accepting_msg));
	}
	// оно че серьезно весь accepted_proposal каждый раз будет пересылать?!
	// complete Promise() message later
	auto promise_msg = std::make_unique<Promise>(ballot_num);
	node.lock()->send(std::move(sender), std::move(promise_msg));

}
