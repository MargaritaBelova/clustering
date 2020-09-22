/*
 * Acceptor.cpp
 *
 *  Created on: Sep 17, 2020
 *      Author: anotherme
 */

#include "Acceptor.h"
#include "../messages/Message.h" // inclue here or in role.h?

Acceptor::Acceptor(Node* node) : Role(node) {
	//ballot_num = null_ballot;
}

Acceptor::~Acceptor(){
}

Role_id Acceptor::getRoleName() const{
	return acceptor;	// rewrite to static?
}

void Acceptor::doAccept(const std::string sender, const unsigned int ballot_num,\
		const unsigned int slot, Proposal proposal){
	// test it for variable names
	if (ballot_num > this->ballot_num){
			this->ballot_num = ballot_num;
			//acc = accepted_proposals;
			//if slot in ...
	}
	std::cout << "doAccept: " << sender << " " << ballot_num << std::endl;
	//node.send()
}
