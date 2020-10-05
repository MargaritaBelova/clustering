/*
 * Decision.cpp
 *
 *  Created on: Sep 22, 2020
 *      Author: anotherme
 */

#include "Decision.h"

Decision::Decision(const unsigned long slot_, const std::shared_ptr<Proposal> proposal_):
		slot(slot_), proposal(proposal_) {}

Message_id Decision::getMsgID() const {
	return decision;
}
