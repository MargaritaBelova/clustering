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
	// will it be ok or should we use copy for sender instead const reference?;
	void send(const std::string& sender, std::string&& destination, std::unique_ptr<Message> message);
	void send(const std::string& sender, const std::string& destination, std::unique_ptr<Message> message);
	/*
	void send(const std::string sender, std::unique_ptr<std::string> destination,\
				std::unique_ptr<Message> message); // add const for std::unique_ptr<Message> message for node?
*/
	// will it be ok or should we use copy for sender instead const reference?; is it ok to use only move semantics here?
	void send(const std::string& sender, std::unique_ptr<destination_list> destinations, std::unique_ptr<Message> message);


};


#endif /* NETWORK_NETWORK_H_ */
