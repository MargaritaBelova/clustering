/*
 * Node.cpp
 *
 *  Created on: Sep 11, 2020
 *      Author: anotherme
 */

#include "Node.h"

#include <iostream> // del later;

#include "../messages/Message.h"
#include "Role.h"
#include "../network/Network.h"

unsigned long Node::unique_ids = 0;

Node::Node(const std::shared_ptr<Network> network_, const std::string address_): network(network_){
	if (address_.empty()){
		++unique_ids;
		address = "N" + std::to_string(unique_ids);
	} else {
		address = address_;
	};
	// add logger here;
	// logger.info;
}

Node::~Node(){
	std::cout << "Node " << address << " is destructed" << std::endl;
}

//is the implementation good?
void Node::registerRole(std::unique_ptr<Role> role_to_add){
	roles.push_back(std::move(role_to_add));
	// del later
	std::cout << "Role " << roles.back().get() << " registered" << std::endl;
}

void Node::unregisterRole(const Role* role_to_remove){ // is that ok to pass this pointer to check unique one?
	for (auto it = roles.begin(); it != roles.end(); ++it){
		//del later
		std::cout << "in Node::unregisterRole\n";
		if (it->get() == role_to_remove){
			roles.erase(it);
			//del later;
			std::cout << "Role " << role_to_remove << " is unregistered by its node" << std::endl;
			return;
		}
		// Raise Err here;
	}
}

void Node::receive(const std::string sender, std::shared_ptr<Message> message){
	// how to rewrite it? received message cannot be a pointer!
	switch (message->getMsgID()){
		case accepted:
			for (auto& comp : roles){	// roles[:] ?
					if (comp->getRoleName() == commander){
						std::cout << "Commander->doAccepted\n";
						//comp->doAccept(...)
					}
				}
			break;
		case accept:
			for (auto& comp : roles){
					if (comp->getRoleName() == acceptor){
						std::cout << "Acceptor->doAccept\n";
						//comp->doAccept(...)
					}
						}
					break;
		case decision:
			for (auto& comp : roles){
					if (comp->getRoleName() == replica){
						std::cout << "Replica->doDecision\n";
						//comp->doDecision(...)
					}
				}
			break;
		case invoked:
			for (auto& comp : roles){
					if (comp->getRoleName() == requester){
						std::cout << "Requester->doInvoked\n";
						//comp->doInvoked(...)
					}
				}
			break;
		case invoke:
			for (auto& comp : roles){
					if (comp->getRoleName() == replica){
						std::cout << "Replica->doInvoke\n";
						//comp->doAccept(...)
					}
				}
			break;
		case join:
			for (auto& comp : roles){
					if (comp->getRoleName() == replica || comp->getRoleName() == seed){
						std::cout << "Replica->Join or Seed->Join\n";
						//comp->doJoin(...)
					}
				}
			break;
		case active:
			for (auto& comp : roles){
					if (comp->getRoleName() == replica){
						std::cout << "Replica->doActive\n";
						//comp->doActive(...)
					}
				}
			break;
		case prepare:
			for (auto& comp : roles){
					if (comp->getRoleName() == acceptor){
						std::cout << "Acceptor->doPrepare\n";
						//comp->doAccept(...)
					}
				}
			break;
		case promise:
			for (auto& comp : roles){
					if (comp->getRoleName() == scout){
						std::cout << "Scout->doPromise\n";
						//comp->doPromise(...)
					}
				}
			break;
		case propose:
			for (auto& comp : roles){
					if (comp->getRoleName() == leader){
						std::cout << "Leader->doPropose\n";
						//comp->doPropose(...)
					}
				}
			break;
		case welcome:
			for (auto& comp : roles){
					if (comp->getRoleName() == bootstrap){
						std::cout << "Bootstrap->doWelcome\n";
						//comp->doWelcome(...)
					}
				}
			break;
//		case decided:
//			for (auto comp : roles){
//					if (comp->getRoleName() == acceptor){
//						std::cout << "comp->doAccept\n";
//						//comp->doAccept(...)
//					}
//				}
			break;
		case preempted:
			for (auto& comp : roles){
					if (comp->getRoleName() == leader){
						std::cout << "Leader->doPreempted\n";
						//comp->doPreempted(...)
					}
				}
			break;
		case adopted:
			for (auto& comp : roles){
					if (comp->getRoleName() == replica || comp->getRoleName() == leader){
						std::cout << "Replica->doAdopted or Leader->doAdopted\n";
						//comp->doAdopted(...)
					}
				}
			break;
		case accepting:
			for (auto& comp : roles){
					if (comp->getRoleName() == replica ){
						std::cout << "replica->doAccept\n";
						//comp->doAccept(...)
					}
				}
			break;

	}
}

void Node::send(std::unique_ptr<destination_list> destinations, std::unique_ptr<Message> message){
	network->send(address, std::move(destinations), std::move(message));
}

