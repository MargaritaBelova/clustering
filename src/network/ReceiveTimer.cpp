/*
 * ReceiveTimer.cpp
 *
 *  Created on: Oct 26, 2020
 *      Author: anotherme
 */

#include "ReceiveTimer.h"

#include "../components/Node.h"
#include "../messages/Message.h"

ReceiveTimer::ReceiveTimer(float expires_, std::string& dest_address_, Node* receiver_, std::unique_ptr<Message> message_ ):
			Timer(expires_, dest_address_), receiver(receiver_), message(std::move(message_)) {
}

void ReceiveTimer::callback(){
	receiver->receive(address, std::move(message));
}
