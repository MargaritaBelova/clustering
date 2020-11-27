/*
 * Network.h
 *
 *  Created on: Sep 12, 2020
 *      Author: anotherme
 */

#ifndef NETWORK_NETWORK_H_
#define NETWORK_NETWORK_H_

#include <memory>
//#include <queue>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>

#include "../destinations/DestinationsType.h"
#include "TimersPriorityQueue.h"
//#include "Timer.h"

class Message;
class Node;
class Role;

class ReceiveTimer;
class RoleTimer;

class Network{
public:
	Network(float seed);
	// add logger to every send method
	void send(Node& sender, std::string&& destination, std::unique_ptr<Message> message);
	void send(Node& sender, const std::string& destination, std::unique_ptr<Message> message);
	void send(Node& sender, std::unique_ptr<destination_list> destinations, std::unique_ptr<Message> message);

	std::shared_ptr<Node> newNode(std::string address="");
	RoleTimer* setRoleTimer(const std::string& address, float seconds, Role* creator);
	ReceiveTimer* setReceiveTimer(const std::string& dest_address, float seconds, Node* receiver, std::unique_ptr<Message> message);

	void run();
	void stop();

private:
	const float kPropDelay = 0.03;
	const float kPropJitter = 0.02;
	const float kDropProb = 0.05;

	void sendto(Node& sender, const std::string& dest, std::unique_ptr<Message> message);
	std::unordered_map<std::string, std::weak_ptr<Node>> nodes;
	//std::priority_queue<Timer*, std::vector<Timer*>, CompareTimers> timers;
	TimersPriorityQueue timers;

	std::default_random_engine generator;

	float now;
};


#endif /* NETWORK_NETWORK_H_ */
