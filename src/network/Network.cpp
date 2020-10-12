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

// ! don't forget to complete overloaded method

/*
void Network::send(const std::string sender, std::unique_ptr<std::string> destination,\
			std::unique_ptr<Message> message){
	std::cout << "in Network::send: msgID = " << message->getMsgID() << " to " << *destination <<"\n";
}
*/
void Network::send(const std::string& sender, std::string&& destination, std::unique_ptr<Message> message){
	std::cout << "in Network::send: msgID = " << message->getMsgID() << " to " << destination <<"\n";
}

void Network::send(const std::string& sender, const std::string& destination, std::unique_ptr<Message> message){
	std::cout << "in Network::send: msgID = " << message->getMsgID() << " to " << destination <<"\n";
}

void Network::send(const std::string& sender, std::unique_ptr<destination_list> destinations, std::unique_ptr<Message> message){
	std::cout << "in Network::send: msgID = " << message->getMsgID() << " to:\n";

	for (auto& destination : *destinations){
		std::cout << destination << "\n\n";
	}
}

