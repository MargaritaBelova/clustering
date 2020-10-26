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
#include "../components/Node.h"
#include "Timer.h"

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
	std::cout << "in Network::send: msgID = " << message->getMsgID() << " to " << destination <<"\n";
}

void Network::send(const Node& sender, const std::string& destination, std::unique_ptr<Message> message){
	std::cout << "in Network::send: msgID = " << message->getMsgID() << " to " << destination <<"\n";
}

void Network::send(const Node& sender, std::unique_ptr<destination_list> destinations, std::unique_ptr<Message> message){
	std::cout << "in Network::send: msgID = " << message->getMsgID() << " to:\n";

	for (auto& destination : *destinations){
		std::cout << destination << "\n\n";
	}
}

void Network::sendto(const std::string& dest, std::unique_ptr<Message> message){
	/*
	if (dest == sender->address){	// deliver local messages with delay=0
		set_timer(sender->address, 0, )
	}
	*/
}

std::shared_ptr<Node> Network::newNode(std::string address){
	auto node_sp = std::make_shared<Node>(*this, address);
	std::weak_ptr<Node> node_wp = node_sp;
	nodes[address] = node_wp;
	return node_sp;
}

void Network::stop(){
	timers = std::priority_queue<Timer, std::vector<Timer>, CompareTimers> ();
	if (timers.empty()){
		std::cout << "timers queue is cleared\n"; // del later;
	}
}

Timer* const Network::setTimer(std::string address, float seconds, Role* creator, void (Role::*fpcallback)()){
	Timer* timer_ptr = new Timer(now + seconds, address, creator, fpcallback); // optimize it? нельзя через временный объект?
	timers.push(*timer_ptr);
	return timer_ptr;
}

void Network::run(){
	while (!timers.empty()){
		Timer next_timer = timers.top();
		std::cout << "Network.run - timers: " << next_timer.address << " " << next_timer.expires << std::endl; // del later;
		if (next_timer.expires > now){
			now = next_timer.expires;
		}
		timers.pop();
		if (next_timer.cancelled){
			continue;
		}
		auto it = nodes.find(next_timer.address);
		if (next_timer.address.empty() || it != nodes.end()){	// how this address can be empty?
			assert(next_timer.creator != nullptr);	// del later;
			std::cout << "Network.run: next_timer.creator != nullptr\n";
			(next_timer.creator->*(next_timer.fpcallback))();
		}
	}
}
