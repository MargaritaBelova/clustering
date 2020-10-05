/*
 * Proposal.h
 *
 *  Created on: Sep 29, 2020
 *      Author: anotherme
 */

#ifndef PROTOCOL_PROPOSAL_H_
#define PROTOCOL_PROPOSAL_H_

#include <string>

struct Proposal{
	Proposal(std::string caller_, unsigned long client_id_, unsigned long input_);

	const std::string caller;
	const unsigned long client_id;
	const unsigned long input;

};


#endif /* PROTOCOL_PROPOSAL_H_ */
