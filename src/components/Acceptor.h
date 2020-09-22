/*
 * Acceptor.h
 *
 *  Created on: Sep 17, 2020
 *      Author: anotherme
 */

#ifndef COMPONENTS_ACCEPTOR_H_
#define COMPONENTS_ACCEPTOR_H_

#include <iostream> // del later;
#include <map>
#include <string>
#include <tuple>
#include "Role.h"	// include it or not?


// del implementation later!!
class Proposal{};
//enum Message_id{};

class Acceptor : public Role {
public:
	Acceptor(Node* node);
	~Acceptor();	// del later?
	Role_id getRoleName() const; 	// rewrite to static?
	void doPrepare(const std::string sender, const unsigned int ballot_num);
	void doAccept(const std::string sender, const unsigned int ballot_num,\
			const unsigned int slot, Proposal proposal);

	const std::string name = "Acceptor"; //? virtual;
private:
	std::map<int, std::tuple<const unsigned int, Proposal>> accepted_proposals;	// slot: tuple(ballot_num, proposal)
	unsigned int ballot_num;
};


#endif /* COMPONENTS_ACCEPTOR_H_ */
