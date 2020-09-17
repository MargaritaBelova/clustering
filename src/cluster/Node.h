/*
 * Node.h
 *
 *  Created on: Sep 11, 2020
 *      Author: anotherme
 */

#ifndef CLUSTER_NODE_H_
#define CLUSTER_NODE_H_

#include <iostream>	// del later;
#include <string>
#include <vector>
//#include "network/Network.h"

class Role;
class Network;

class Node {
public:
	Node(Network* network, std::string address);
	~Node(); 	// del later?
	void registerRole(const Role* role_to_add);
	void unregisterRole(const Role* role_to_remove);
	//void send();
	void receive(const std::string sender, const std::type_info message);

	static unsigned int unique_ids;
	std::string address;

private:
	Network* network;
	//Logger logger;
	std::vector<const Role*> roles;	// replace with map?
};


#endif /* CLUSTER_NODE_H_ */
