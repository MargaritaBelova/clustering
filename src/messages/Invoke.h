/*
 * Invoke.h
 *
 *  Created on: Oct 8, 2020
 *      Author: anotherme
 */

#ifndef MESSAGES_INVOKE_H_
#define MESSAGES_INVOKE_H_

#include "Message.h"

#include <string>

struct Invoke : public Message{
	Invoke(const std::string caller_, const unsigned long client_id_, const long input_value_);
	Message_id getMsgID() const;

	const std::string caller;
	const unsigned long client_id;
	const long input_value;
};

//('Invoke', ['caller', 'client_id', 'input_value'])

#endif /* MESSAGES_INVOKE_H_ */
