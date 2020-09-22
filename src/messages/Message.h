/*
 * Message.h
 *
 *  Created on: Sep 20, 2020
 *      Author: anotherme
 */

#ifndef MESSAGES_MESSAGE_H_
#define MESSAGES_MESSAGE_H_

#include <string>

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

class Message{
public:
	virtual Message_id getMsgID() const = 0;
	//Message_id getMsgID(); 	//test only, del after uncomment previous
};



#endif /* MESSAGES_MESSAGE_H_ */
