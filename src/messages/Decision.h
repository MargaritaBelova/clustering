/*
 * Decision.h
 *
 *  Created on: Sep 22, 2020
 *      Author: anotherme
 */

#ifndef MESSAGES_DECISION_H_
#define MESSAGES_DECISION_H_

#include "Message.h"

class Proposal;

struct Decision : public Message{
	Decision(const unsigned long slot, const std::shared_ptr<Proposal> proposal);
	Message_id getMsgID() const;

	const unsigned long slot = 0;

	const std::shared_ptr<Proposal> proposal;
};

#endif /* MESSAGES_DECISION_H_ */
