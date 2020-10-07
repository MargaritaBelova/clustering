//============================================================================
// Name        : clustering.cpp
// Author      : Margarita Belova
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <tuple>

#include "components/Node.h"
#include "components/Acceptor.h"
// del those later;
#include "network/Network.h"
#include "messages/Prepare.h"
#include "messages/Accept.h"
#include "protocol/Ballot.h"
#include "protocol/Proposal.h"



using namespace std;

class Role;
class Message;

class Pointee{
public:
	Pointee(){
		cout << "Pointee created\n";
	}
};

class Container{
public:
	Container(){
		auto ballot_num = std::make_shared<Ballot>(0, "empty"); // change empty later;
		std::cout << "Acceptor created\n";
	}

};


int main() {
	auto network = make_shared<Network>();

	shared_ptr<Node> sp1 = make_shared<Node>(network, "address1");
	//shared_ptr<Node> sp2 = make_shared<Node>(network, "address12");

	weak_ptr<Node> wp1 = sp1;
	//weak_ptr<Node> wp2 = sp2;
	//auto prepare = make_shared<Prepare>(10);
	//sp1->receive("sender", prepare);

	Acceptor* acc1 = new Acceptor(wp1);
	Acceptor* acc2 = new Acceptor(wp1);

	auto bal0 = make_shared<Ballot>(0, "leader");
	auto proposal = make_shared<Proposal>("caller", 0, 10);

	acc1->doAccept("sender", bal0, 0, proposal);

	acc2->doPrepare("sender", bal0);
	return 0;
}
