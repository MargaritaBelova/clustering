/*
 * network.cpp
 *
 *  Created on: Sep 12, 2020
 *      Author: anotherme
 */

#include "Network.h"

#include <iostream> // del later

#include "../messages/Message.h"

Network::Network(){
	//add later
}

void Network::send(const std::string sender, std::unique_ptr<destination_list> destinations,\
			const std::unique_ptr<Message> message){
	std::cout << "in Network::send: msgID = " << message->getMsgID() << std::endl;
}

