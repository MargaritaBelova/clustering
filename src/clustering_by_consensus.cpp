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
#include "components/Acceptor.h"
// del those later;
#include "network/Network.h"
#include "messages/Prepare.h"


using namespace std;

class Role;
class Message;

int main() {
	auto network = make_shared<Network>();

	shared_ptr<Node> sp1 = make_shared<Node>(network, "test");
	//shared_ptr<Node> sp2 = make_shared<Node>(network, "test");

	weak_ptr<Node> wp1 = sp1;
	//weak_ptr<Node> wp2 = sp2;

	Role* acceptor1 = new Acceptor(wp1);
	auto accepted = make_shared<Prepare>(10);
	sp1->receive("sender", accepted);
	delete acceptor1;
	//sp1->registerRole()
	//Message* prepare = new Prepare(10);
	//node1.receive("sender", prepare);
	return 0;
}
