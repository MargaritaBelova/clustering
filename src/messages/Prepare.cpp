/*
 * Prepare.cpp
 *
 *  Created on: Sep 21, 2020
 *      Author: anotherme
 */

#include "Prepare.h"

Prepare::Prepare (std::shared_ptr<Ballot> ballot_num_) : ballot_num(ballot_num_) {}

Message_id Prepare::getMsgID() const {
	return prepare;
}

