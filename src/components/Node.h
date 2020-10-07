/*
 * Node.h
 *
 *  Created on: Sep 11, 2020
 *      Author: anotherme
 */

#ifndef COMPONENTS_NODE_H_
#define COMPONENTS_NODE_H_

#include <iostream>	// del later;
#include <string>
#include <vector>
#include <memory>

#include "../destinations/DestinationsType.h" // here or put in every class?

//class Role;
class Network;

// del later;
class Message;
class Role;

class Node {
public:
	Node(const std::shared_ptr<Network> network_, const std::string address_);
	~Node(); 	// del later?
	// HOW TO REWRITE IT? received message cannot be a pointer!
	void receive(const std::string sender, const std::shared_ptr<Message> message);
	void send(std::unique_ptr<destination_list> destinations, std::unique_ptr<Message> message);

	static unsigned long unique_ids;

private:
	void registerRole(std::unique_ptr<Role> role_to_add);
	void unregisterRole(const Role* role_to_remove);

	std::string address; // make const? initialization?
	std::shared_ptr<Network> network;
	//Logger logger;
	std::vector<std::unique_ptr<Role>> roles;

	friend Role; // is it ok?
};


#endif /* COMPONENTS_NODE_H_ */
