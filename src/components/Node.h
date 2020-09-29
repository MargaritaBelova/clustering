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

class Role;
class Network;

// del later;
class Message;

class Node {
public:
	Node(const std::shared_ptr<Network> network, const std::string address);
	~Node(); 	// del later?
	void registerRole(const Role* role_to_add);
	void unregisterRole(const Role* role_to_remove);
	//void send([this - const string sender], [string] destinations, message);
	void receive(const std::string sender, const std::shared_ptr<Message> message);

	static unsigned long unique_ids;
	std::string address; // make const? initialization?

private:
	std::shared_ptr<Network> network;
	//Logger logger;
	std::vector<std::unique_ptr<const Role>> roles;
};


#endif /* COMPONENTS_NODE_H_ */
