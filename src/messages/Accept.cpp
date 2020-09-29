/*
 * Accept.cpp
 *
 *  Created on: Sep 22, 2020
 *      Author: anotherme
 */

#include "Accept.h"

Accept::Accept(const unsigned long slot, const unsigned long ballot_num, \
		const std::shared_ptr<Proposal> proposal) :
slot(slot), ballot_num(ballot_num), proposal(proposal){}

Message_id Accept::getMsgID() const{
	return accept;
}


