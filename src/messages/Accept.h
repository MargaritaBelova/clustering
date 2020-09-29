/*
 * Accept.h
 *
 *  Created on: Sep 22, 2020
 *      Author: anotherme
 */

#ifndef MESSAGES_ACCEPT_H_
#define MESSAGES_ACCEPT_H_

#include "Message.h"

class Proposal;

struct Accept : public Message{
	Accept(const unsigned long slot, const unsigned long ballot_num, const std::shared_ptr<Proposal> proposal);
	Message_id getMsgID() const;

	const std::shared_ptr<Proposal> proposal;

	const unsigned long ballot_num = 0;
	const unsigned long slot = 0;
};

#endif /* MESSAGES_ACCEPT_H_ */
