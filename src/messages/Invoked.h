/*
 * Invoked.h
 *
 *  Created on: Sep 22, 2020
 *      Author: anotherme
 */

#include "Message.h"

struct Invoked : public Message{
	Invoked(const unsigned long client_id_, const long output_);
	Message_id getMsgID() const;

	const unsigned long client_id;
	const long output;
};

