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

// del it later;
class Network;

class Node {
public:
	//del this constructor later; uncomment below;
	Node(){};

	// make  network pointer ?
	Node(Network network, std::string address);
	void registerRole(Role* const roles) const;
	void unregisterRole(Role* const roles) const;

	//void send(...);

	// instead of itertools.count()
	static unsigned int unique_ids;
	std::string address;

private:
	//Network network;
	//Logger logger;
	std::vector<Role*> roles;
};


#endif /* CLUSTER_NODE_H_ */
