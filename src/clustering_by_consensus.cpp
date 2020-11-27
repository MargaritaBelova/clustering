//============================================================================
// Name        : clustering.cpp
// Author      : Margarita Belova
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
//#include <tuple>
//#include <mutex>

#include "components/Node.h"
#include "components/Acceptor.h"
#include "components/Requester.h"
// del those later;
#include "network/Network.h"
#include "messages/Prepare.h"
#include "messages/Accept.h"
#include "protocol/Ballot.h"
#include "protocol/Proposal.h"
#include "network/ReceiveTimer.h"
#include "network/RoleTimer.h"

using namespace std;


//class Role;
class Message;


int main() {
	Network network(11.11);

	shared_ptr<Node> sp1 = network.newNode("node1");
	shared_ptr<Node> sp2 = network.newNode("node2");


	weak_ptr<Node> wp1 = sp1;
	//weak_ptr<Node> wp2 = sp2;
	Acceptor* acc1 = new Acceptor(wp1);
	cout << "in acc1: " << acc1->node.lock().get() << endl;
	auto proposal = make_shared<Proposal>("caller", 0, 10);
	auto bal1 = make_shared<Ballot>(1, "leader");
	const int slot = 0;
	acc1->doAccept("node1", bal1, slot, proposal);

	//Requester* requester = new Requester(wp1, 11);
	network.run();
	network.stop();
	return 0;
}
