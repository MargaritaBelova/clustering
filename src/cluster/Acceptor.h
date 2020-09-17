/*
 * Acceptor.h
 *
 *  Created on: Sep 17, 2020
 *      Author: anotherme
 */

#ifndef CLUSTER_ACCEPTOR_H_
#define CLUSTER_ACCEPTOR_H_

#include "Role.h"	// include it or not?

#include <map>
#include <string>
#include <tuple>

// del implementation later!!
class Proposal{};

class Acceptor : public Role {
public:
	Acceptor(Node* node);
	void doPrepare(const std::string sender, const unsigned int ballot_num);
	void doAccept(const std::string sender, const unsigned int ballot_num,\
			const unsigned int slot, Proposal proposal);
private:
	std::map<int, std::tuple<const unsigned int, Proposal>> accepted_proposals;	// slot: tuple(ballot_num, proposal)
	unsigned int ballot_num;
};


#endif /* CLUSTER_ACCEPTOR_H_ */
