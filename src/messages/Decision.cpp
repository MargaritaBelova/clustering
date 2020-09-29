/*
 * Decision.cpp
 *
 *  Created on: Sep 22, 2020
 *      Author: anotherme
 */

#include "Decision.h"

Decision::Decision(const unsigned long slot, const std::shared_ptr<Proposal> proposal):
proposal(proposal), slot(slot) {}

Message_id Decision::getMsgID() const {
	return decision;
}
