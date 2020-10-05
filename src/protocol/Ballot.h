/*
 * Ballot.h
 *
 *  Created on: Sep 29, 2020
 *      Author: anotherme
 */

#ifndef PROTOCOL_BALLOT_H_
#define PROTOCOL_BALLOT_H_

#include <string>

struct Ballot{
	Ballot(unsigned long n_, std::string leader_);

	const unsigned long n = 0;
	const std::string leader;
};



#endif /* PROTOCOL_BALLOT_H_ */
