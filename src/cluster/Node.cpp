/*
 * Node.cpp
 *
 *  Created on: Sep 11, 2020
 *      Author: anotherme
 */

#include "Node.h"

#include <iostream> // del later;

unsigned int Node::unique_ids = 0;

Node::Node(Network* network, std::string address){
	this->network = network;
	if (address.empty()){
		++unique_ids;
		this->address = "N" + std::to_string(unique_ids);
	} else {
		this->address = address;
	};
	// add logger here;
	// logger.info;
}

Node::~Node(){
	std::cout << "Node is destructed" << std::endl;
}

void Node::registerRole(const Role* role_to_add){
	roles.push_back(role_to_add);
}

void Node::unregisterRole(const Role* role_to_remove){
	// test it
	for (auto it = roles.begin(); it != roles.end(); ++it){
		if (*it == role_to_remove){
			// release memory here?;
			roles.erase(it);
			// del later;
			std::cout << "Role is unregistered by its node" << std::endl;
			return;
		}
		// Raise Err here;
	}

}

void Node::receive(std::string sender, std::type_info message){
	//std::string handler_name = "do_" + message.name();

	for (auto comp : roles){
		// handle message here;
	}
}




