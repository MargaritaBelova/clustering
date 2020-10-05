/*
 * Acceptor.h
 *
 *  Created on: Sep 17, 2020
 *      Author: anotherme
 */

#ifndef COMPONENTS_ACCEPTOR_H_
#define COMPONENTS_ACCEPTOR_H_

#include "Role.h"

#include <iostream> // del later;
#include <map>
#include <memory>
#include <string>
#include <tuple>


class Ballot;
class Proposal;

class Acceptor : public Role {
public:
	Acceptor(std::weak_ptr<Node> node_);
	~Acceptor(); //del later
	Role_id getRoleName() const; 	// rewrite to static?
	void doPrepare(const std::string sender, std::shared_ptr<Ballot> ballot_num_);
	// change to weak_ptr?


	void doAccept(const std::string sender, std::shared_ptr<Ballot> ballot_num_,\
			const unsigned long slot, std::shared_ptr<Proposal> proposal);

	const std::string name = "Acceptor";
private:
	std::map<unsigned long, std::tuple<std::shared_ptr<Ballot>, std::shared_ptr<Proposal>>> accepted_proposals; // slot: tuple(ballot_num, proposal)
	std::shared_ptr<Ballot> ballot_num; //add check for nullptr everywhere in comparasion!
};


#endif /* COMPONENTS_ACCEPTOR_H_ */
