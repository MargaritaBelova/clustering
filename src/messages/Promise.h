/*
 * Promise.h
 *
 *  Created on: Oct 8, 2020
 *      Author: anotherme
 */

#ifndef MESSAGES_PROMISE_H_
#define MESSAGES_PROMISE_H_

//not finished yet

#include "Message.h"

#include <memory>

class Ballot;

struct Promise : public Message{
	Promise(std::shared_ptr<Ballot> ballot_num_);
	Message_id getMsgID() const;

	std::shared_ptr<Ballot> ballot_num;
	//accepted_proposals
};


#endif /* MESSAGES_PROMISE_H_ */
