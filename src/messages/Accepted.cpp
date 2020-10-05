/*
 * Accepted.cpp
 *
 *  Created on: Sep 22, 2020
 *      Author: anotherme
 */

#include "Accepted.h"

Accepted::Accepted(const unsigned long slot_, std::shared_ptr<Ballot> ballot_num_) : \
		slot(slot_), ballot_num(ballot_num_) {}

Message_id Accepted::getMsgID() const{
	return accepted;
}
