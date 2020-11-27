/*
 * Node.h
 *
 *  Created on: Sep 11, 2020
 *      Author: anotherme
 */

#ifndef COMPONENTS_NODE_H_
#define COMPONENTS_NODE_H_

#include <string>
#include <vector>
#include <memory>

#include "../destinations/DestinationsType.h" // here or put in every class?
#include "../network/Network.h"

class Message;
class Role;

class Node {
public:
	Node(Network* network_, const std::string address_);
	~Node(); 	// del later
	// REWRITE IT! received message cannot be a pointer! should accept copies
	void receive(const std::string sender, std::unique_ptr<Message> message);
	void send(std::string&& destination, std::unique_ptr<Message> message);
	void send(const std::string& destination, std::unique_ptr<Message> message);
	void send(std::unique_ptr<destination_list> destinations, std::unique_ptr<Message> message);
	const std::string& getAddress() const;

private:
	void registerRole(std::unique_ptr<Role> role_to_add);
	void unregisterRole(const Role* role_to_remove);

	static unsigned long unique_ids;

	std::string address;
	Network* network;	//std::shared_ptr<Network> network;
	//Logger logger;
	std::vector<std::unique_ptr<Role>> roles;

	friend Role; // is it ok?
};

// should it be here, in header file?
inline const std::string& Node::getAddress() const{
	return address;
}


#endif /* COMPONENTS_NODE_H_ */
