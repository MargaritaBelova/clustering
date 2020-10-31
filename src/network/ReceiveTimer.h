/*
 * ReceiveTimer.h
 *
 *  Created on: Oct 26, 2020
 *      Author: anotherme
 */

#ifndef NETWORK_RECEIVETIMER_H_
#define NETWORK_RECEIVETIMER_H_

#include "Timer.h"

#include <memory>

class Message;
class Node;

class ReceiveTimer : public Timer {
public:
	// сделать dest_address_ без ссылки? хотя потом все равно копируется в конструкторе
	ReceiveTimer(float expires_, std::string& dest_address_, Node* receiver_, std::unique_ptr<Message> message_);
	void callback();
private:
	Node* const receiver;
	std::unique_ptr<Message> message;

};



#endif /* NETWORK_RECEIVETIMER_H_ */
