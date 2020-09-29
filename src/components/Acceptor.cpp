/*
 * Acceptor.cpp
 *
 *  Created on: Sep 17, 2020
 *      Author: anotherme
 */

#include "Acceptor.h"

#include "../messages/Message.h" // inclue here or in role.h?

Acceptor::Acceptor(std::weak_ptr<Node> node) : Role(node) {
	std::cout << "Acceptor created\n";
	//ballot_num = null_ballot;
}

Acceptor::~Acceptor(){
	std::cout << "Acceptor destructed\n";
}

Role_id Acceptor::getRoleName() const{
	return acceptor;	// rewrite to static?
}

void Acceptor::doAccept(const std::string sender, const unsigned long ballot_num,\
		const unsigned long slot, std::shared_ptr<Proposal> proposal){

	// test it for variable names
	if (ballot_num > this->ballot_num){
			this->ballot_num = ballot_num;
			//acc = accepted_proposals;
			//if slot in ...
	}
	std::cout << "doAccept: " << sender << " " << ballot_num << std::endl;
	//node.send()
}
