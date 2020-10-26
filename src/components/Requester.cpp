/*
 * Requester.cpp
 *
 *  Created on: Oct 8, 2020
 *      Author: anotherme
 */
// not finished yet!
#include "Requester.h"

#include "Node.h"
#include "../messages/Invoke.h"

#include <iostream> //del later

unsigned long Requester::client_ids = 100000;

// complete constructor
Requester::Requester(std::weak_ptr<Node> node_, unsigned long int n_) : Role(node_), n(n_) {}

Requester::~Requester(){
	std::cout << this << " Requester destructed\n";
}

Role_id Requester::getRoleName() const {
	return requester;
}

void Requester::callback(){
	start();
}

void Requester::start(){
	const std::string& this_node_address = node.lock()->getAddress();
	auto invoke_msg = std::make_unique<Invoke>(this_node_address, client_id, n);
	node.lock()->send(this_node_address, std::move(invoke_msg));
}
/*
def start(self):
        self.node.send([self.node.address],
                       Invoke(caller=self.node.address,
                              client_id=self.client_id, input_value=self.n))
        self.invoke_timer = self.set_timer(INVOKE_RETRANSMIT, self.start)
*/

//void Requester::doInvoked(const std::string sender, const unsigned long client_id, const long output);
