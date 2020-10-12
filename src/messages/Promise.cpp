/*
 * Promise.cpp
 *
 *  Created on: Oct 8, 2020
 *      Author: anotherme
 */

#include "Promise.h"

//not finished yet
Promise::Promise(std::shared_ptr<Ballot> ballot_num_) : ballot_num(ballot_num_) {};

Message_id Promise::getMsgID() const{
	return promise;
}
