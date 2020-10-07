/*
 * Accept.h
 *
 *  Created on: Sep 22, 2020
 *      Author: anotherme
 */

#ifndef MESSAGES_ACCEPT_H_
#define MESSAGES_ACCEPT_H_

#include "Message.h"

#include <memory>

class Proposal;
class Ballot;

struct Accept : public Message{
	Accept(const unsigned long slot_, std::shared_ptr<Ballot> ballot_num_, const std::shared_ptr<Proposal> proposal_);
	Message_id getMsgID() const;

	const std::shared_ptr<Proposal> proposal;
	const std::shared_ptr<Ballot> ballot_num;
	const unsigned long slot;
};

#endif /* MESSAGES_ACCEPT_H_ */
