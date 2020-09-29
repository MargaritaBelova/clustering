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
//#include <memory> - include or not?
#include <string>
#include <tuple>
#include "Role.h"


// del implementation later
class Proposal;

class Acceptor : public Role {
public:
	Acceptor(std::weak_ptr<Node> node);
	~Acceptor();
	Role_id getRoleName() const; 	// rewrite to static?
	void doPrepare(const std::string sender, const unsigned long ballot_num);
	// change to weak_ptr?
	void doAccept(const std::string sender, const unsigned long ballot_num,\
			const unsigned long slot, std::shared_ptr<Proposal> proposal);

	const std::string name = "Acceptor";
private:
	// change to shared_ptr?
	// slot: tuple(ballot_num, proposal)
	std::map<unsigned long, std::tuple<unsigned long, std::shared_ptr<Proposal>>> accepted_proposals;
	unsigned long ballot_num = 0;
};


#endif /* COMPONENTS_ACCEPTOR_H_ */
