/*
 * Accepted.cpp
 *
 *  Created on: Sep 22, 2020
 *      Author: anotherme
 */

#include "Accepted.h"

Accepted::Accepted(const unsigned long slot, const unsigned long ballot_num) : slot(slot), ballot_num(ballot_num) {}

Message_id Accepted::getMsgID() const{
	return accepted;
}
