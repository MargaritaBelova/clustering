/*
 * Acceptor.h
 *
 *  Created on: Sep 17, 2020
 *      Author: anotherme
 */

#ifndef COMPONENTS_ACCEPTOR_H_
#define COMPONENTS_ACCEPTOR_H_

#include "Role.h"

#include <unordered_map>
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
	void callback();
	void doPrepare(std::string sender, std::shared_ptr<Ballot> ballot_num_);

	void doAccept(std::string sender, std::shared_ptr<Ballot> ballot_num_,
			const unsigned long slot, std::shared_ptr<Proposal> proposal);

private:
	std::unordered_map<unsigned long, std::tuple<std::shared_ptr<Ballot>, std::shared_ptr<Proposal>>> accepted_proposals; // slot: tuple(ballot_num, proposal)
	std::shared_ptr<Ballot> ballot_num;
};


#endif /* COMPONENTS_ACCEPTOR_H_ */
