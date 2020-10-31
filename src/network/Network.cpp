/*
 * network.cpp
 *
 *  Created on: Sep 12, 2020
 *      Author: anotherme
 */

#include "Network.h"

#include <iostream> // del later
#include <cassert>	// del later

#include "../messages/Message.h"
#include "../components/Role.h"
#include "../components/Node.h"
//#include "Timer.h"
#include "RoleTimer.h"
#include "ReceiveTimer.h"

Network::Network(float seed){
	std::default_random_engine generator_(seed);
	generator = generator_;	// is it ok?
	now = 1000.0;
}

/*
void Network::send(const std::string sender, std::unique_ptr<std::string> destination,\
			std::unique_ptr<Message> message){
	std::cout << "in Network::send: msgID = " << message->getMsgID() << " to " << *destination <<"\n";
}
*/
void Network::send(const Node& sender, std::string&& destination, std::unique_ptr<Message> message){
	auto it = nodes.find(destination);
	if (it != nodes.end()){
		std::cout << "in Network::send: msgID = " << message->getMsgID() << " to " << destination <<"\n";
	}
}

void Network::send(const Node& sender, const std::string& destination, std::unique_ptr<Message> message){
	std::cout << "in Network::send: msgID = " << message->getMsgID() << " to " << destination <<"\n";
}

void Network::send(const Node& sender, std::unique_ptr<destination_list> destinations, std::unique_ptr<Message> message){
	std::cout << "in Network::send: msgID = " << message->getMsgID() << " to:\n";

	for (auto& destination : *destinations){
		std::cout << destination << "\n\n";
	}
	//for dest in (d for d in destinations if d in self.nodes):
    //sendto(dest, copy.deepcopy(message))

	//std::for_each(destinations.begin(), destinations.end(), Sum()) - а чего тут со ссылками в итераторе?
}

void Network::sendto(Node& sender, const std::string& dest, std::unique_ptr<Message> message){
	std::string sender_address = sender.getAddress();
	if (dest == sender.getAddress()){	// deliver local messages with delay=0
		setReceiveTimer(sender_address, 0, &sender, std::move(message));
	}
	else {	// deliver messages to dest with random delay
		std::uniform_real_distribution<float> distribution(0.0, 1.0);
		float drop_prob = distribution(generator);
		std::cout << drop_prob << std::endl; // del later;
		if (drop_prob > kDropProb){
			float jitter = distribution(generator) * 2 * kPropJitter - kPropJitter;
			float delay = kPropDelay + jitter;
			Node* dest_node = nodes[dest].lock().get();
			setReceiveTimer(sender_address, delay, dest_node, std::move(message));
		}
	}
}


std::shared_ptr<Node> Network::newNode(std::string address){
	auto node_sp = std::make_shared<Node>(*this, address);
	std::weak_ptr<Node> node_wp = node_sp;
	nodes[address] = node_wp;
	return node_sp;
}

void Network::stop(){
	while (!timers.empty()){
		Timer* next_timer = timers.top();
		timers.pop();
		delete next_timer;
	}
	timers = std::priority_queue<Timer*, std::vector<Timer*>, CompareTimers> ();
	if (timers.empty()){
		std::cout << "timers queue is cleared\n"; // del later;
	}
}

RoleTimer* Network::setRoleTimer(std::string& address, float seconds, Role* creator){
	RoleTimer* timer_ptr = new RoleTimer(now + seconds, address, creator);
	timers.push(timer_ptr);
	return timer_ptr;
}

ReceiveTimer* Network::setReceiveTimer(std::string& dest_address, float seconds, Node* receiver, std::unique_ptr<Message> message){
	ReceiveTimer* timer_ptr = new ReceiveTimer(now + seconds, dest_address, receiver, std::move(message));
	timers.push(timer_ptr);
	return timer_ptr;
}

void Network::run(){
	while (!timers.empty()){
		Timer* next_timer = timers.top();
		std::cout << "Network.run - timers: " << next_timer->address << " " << next_timer->expires << std::endl; // del later;
		if (next_timer->expires > now){
			now = next_timer->expires;
		}
		timers.pop();
		if (next_timer->cancelled){
			continue;
		}
		auto it = nodes.find(next_timer->address);
		if (next_timer->address.empty() || it != nodes.end()){	// how this address can be empty though?
			next_timer->callback();
		}
	}
}
