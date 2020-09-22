//============================================================================
// Name        : clustering.cpp
// Author      : Margarita Belova
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

#include "components/Node.h"
#include "components/Role.h"
#include "components/Acceptor.h"
// del those later;
#include "network/Network.h"
#include "messages/Message.h"
#include "messages/Prepare.h"

using namespace std;


int main() {
	Network network;

	Node node1(&network, "test");
	//Node node2(&network, "test");

	//Role role(&node1);
	Acceptor acceptor(&node1);
	Message* prepare = new Prepare(10);
	return 0;
}
