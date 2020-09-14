/*
 * Node.cpp
 *
 *  Created on: Sep 11, 2020
 *      Author: anotherme
 */

#include "Node.h"

unsigned int Node::unique_ids = 0;

Node::Node(Network* network, std::string address){
	this->network = network;
	if (address.empty()){
		++unique_ids;
		this->address = "N" + std::to_string(unique_ids) + "d";
	} else {
		this->address = address;
	};
	// add logger here;
	// logger.info;
}

Node::~Node(){

}

void Node::registerRole(const Role* rolesToAdd){
	roles.push_back(rolesToAdd);
}

void Node::unregisterRole(const Role* rolesToRemove){
	// maybe iterate from the begining?
	auto it = roles.end();
	while (*it != rolesToRemove and it != roles.begin()){
		--it;
	}
	if (it == roles.begin() && *it != rolesToRemove){
		return;
	}
	roles.erase(it);
}

void Node::receive(std::string sender, std::type_info message){
	//std::string handler_name = "do_" + message.name() + "s";

	for (auto comp : roles){

	}
}




