/*
 * Accepted.h
 *
 *  Created on: Sep 22, 2020
 *      Author: anotherme
 */

#ifndef MESSAGES_ACCEPTED_H_
#define MESSAGES_ACCEPTED_H_

#include "Message.h"

#include <memory>

class Ballot;

struct Accepted : public Message{
	Accepted(const unsigned long slot_, std::shared_ptr<Ballot> ballot_num_);
	Message_id getMsgID() const;

	const unsigned long slot;
	std::shared_ptr<Ballot> ballot_num;
};



#endif /* MESSAGES_ACCEPTED_H_ */
