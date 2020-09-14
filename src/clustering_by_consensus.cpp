//============================================================================
// Name        : clustering.cpp
// Author      : Margarita Belova
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

// del it later;
#include "cluster/Node.h"
#include "network/Network.h"

using namespace std;


int main() {
	Network network;
	string str = "test";
	Node node(&network, str);
	cout << "node created;" << endl;
	return 0;
}
