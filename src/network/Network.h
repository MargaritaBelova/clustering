/*
 * Network.h
 *
 *  Created on: Sep 12, 2020
 *      Author: anotherme
 */

#ifndef NETWORK_NETWORK_H_
#define NETWORK_NETWORK_H_

#include <memory>
#include <string>

#include "../destinations/DestinationsType.h"

class Message;

class Network{
public:
	Network();
	void send(const std::string sender, std::unique_ptr<destination_list> destinations,\
			const std::unique_ptr<Message> message); // add const for std::unique_ptr<Message> message for node?

};


#endif /* NETWORK_NETWORK_H_ */
