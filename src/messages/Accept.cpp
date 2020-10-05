/*
 * Accept.cpp
 *
 *  Created on: Sep 22, 2020
 *      Author: anotherme
 */

#include "Accept.h"

// del it later
#include <iostream>

// check whether ballot_num(move(ballot_num_)) is correct!
Accept::Accept(const unsigned long slot_, std::shared_ptr<Ballot> ballot_num_, \
		const std::shared_ptr<Proposal> proposal_) :
		slot(slot_), ballot_num(std::move(ballot_num_)), proposal(std::move(proposal_)){
	// test - why proposal count is 3 while ballot_num count is 2?
	//std::cout << "ballot_num count: " << ballot_num.use_count() << std::endl;
	//std::cout << "proposal count: " << proposal.use_count() << std::endl << std::endl;
}

Message_id Accept::getMsgID() const{
	return accept;
}


