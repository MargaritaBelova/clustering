/*
 * Message.h
 *
 *  Created on: Sep 20, 2020
 *      Author: anotherme
 */

#ifndef MESSAGES_MESSAGE_H_
#define MESSAGES_MESSAGE_H_

enum Message_id{
	accepted,
	accept,
	decision,
	invoked,
	invoke,
	join,
	active,
	prepare,
	promise,
	propose,
	welcome,
	decided,
	preempted,
	adopted,
	accepting
};

struct Message{
	virtual ~Message() = 0;
	virtual Message_id getMsgID() const = 0;
};

inline Message::~Message(){}

#endif /* MESSAGES_MESSAGE_H_ */
