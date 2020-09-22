/*
 * Prepare.h
 *
 *  Created on: Sep 21, 2020
 *      Author: anotherme
 */

#ifndef MESSAGES_PREPARE_H_
#define MESSAGES_PREPARE_H_

#include "Message.h"

class Prepare : public Message{
public:
	Prepare(unsigned int slot);
	Message_id getMsgID() const;

	const unsigned int slot;
};


#endif /* MESSAGES_PREPARE_H_ */
