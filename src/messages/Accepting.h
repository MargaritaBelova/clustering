/*
 * Accepting.h
 *
 *  Created on: Oct 3, 2020
 *      Author: anotherme
 */

#ifndef MESSAGES_ACCEPTING_H_
#define MESSAGES_ACCEPTING_H_

#include "Message.h"

#include <string>

struct Accepting : public Message{
	Accepting(const std::string leader_);
	Message_id getMsgID() const;

	const std::string leader;
};


#endif /* MESSAGES_ACCEPTING_H_ */
