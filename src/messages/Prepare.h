/*
 * Prepare.h
 *
 *  Created on: Sep 21, 2020
 *      Author: anotherme
 */

#ifndef MESSAGES_PREPARE_H_
#define MESSAGES_PREPARE_H_

#include "Message.h"

struct Prepare : public Message{
	Prepare(const unsigned long ballot_num_);
	Message_id getMsgID() const;

	const unsigned long ballot_num = 0;
};

#endif /* MESSAGES_PREPARE_H_ */
