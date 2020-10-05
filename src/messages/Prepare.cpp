/*
 * Prepare.cpp
 *
 *  Created on: Sep 21, 2020
 *      Author: anotherme
 */

#include "Prepare.h"

Prepare::Prepare (const unsigned long ballot_num_) : ballot_num(ballot_num_) {}

Message_id Prepare::getMsgID() const {
	return prepare;
}

