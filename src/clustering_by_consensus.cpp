//============================================================================
// Name        : clustering.cpp
// Author      : Margarita Belova
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

// del some later;
#include "cluster/Node.h"
#include "cluster/Role.h"
#include "network/Network.h"

using namespace std;


int main() {
	Network network;
	Node node(&network, "test");
	Role* role = new Role(&node);
	role->stop();
	delete role;
	return 0;
}
