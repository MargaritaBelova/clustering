/*
 * Message.h
 *
 *  Created on: Sep 20, 2020
 *      Author: anotherme
 */

#ifndef MESSAGES_MESSAGE_H_
#define MESSAGES_MESSAGE_H_

enum Message_id{
	accepted, //0
	accept, // 1
	decision, // 2
	invoked, // 3
	invoke, // 4
	join, // 5
	active, // 6
	prepare, // 7
	promise, // 8
	propose, // 9
	welcome, // 10
	decided, // 11
	preempted, // 12
	adopted, // 13
	accepting // 14
};

struct Message{
	virtual ~Message() = 0;
	virtual Message_id getMsgID() const = 0;
};

inline Message::~Message(){}

#endif /* MESSAGES_MESSAGE_H_ */
