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

//#include "network/Network.h"

class Role;
class Network;

// del later;
class Message;

class Node {
public:
	Node(Network* network, std::string address);
	~Node(); 	// del later?
	void registerRole(const Role* role_to_add);
	void unregisterRole(const Role* role_to_remove);
	//void send([const string]);
	void receive(const std::string sender, Message* message);

	static unsigned int unique_ids;
	std::string address;

private:
	Network* network;
	//Logger logger;
	std::vector<const Role*> roles;
};


#endif /* COMPONENTS_NODE_H_ */
