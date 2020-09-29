/*
 * Accepted.h
 *
 *  Created on: Sep 22, 2020
 *      Author: anotherme
 */

#ifndef MESSAGES_ACCEPTED_H_
#define MESSAGES_ACCEPTED_H_

#include "Message.h"

struct Accepted : public Message{
	Accepted(const unsigned long slot, const unsigned long ballot_num);
	Message_id getMsgID() const;

	const unsigned long slot = 0;
	const unsigned long ballot_num = 0;
};



#endif /* MESSAGES_ACCEPTED_H_ */
