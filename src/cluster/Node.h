/*
 * Node.h
 *
 *  Created on: Sep 11, 2020
 *      Author: anotherme
 */

#ifndef CLUSTER_NODE_H_
#define CLUSTER_NODE_H_

#include <string>
#include <vector>
//#include "network/Network.h"

class Role;
class Network;

class Node {
public:
	Node(Network* network, std::string address);
	~Node();	// add later
	void registerRole(const Role* rolesToAdd);
	void unregisterRole(const Role* rolesToRemove);
	//void send();
	void receive(std::string sender, std::type_info message);

	static unsigned int unique_ids;
	std::string address;

private:
	Network* network;
	//Logger logger;
	std::vector<const Role*> roles;	// replace with map?
};


#endif /* CLUSTER_NODE_H_ */
