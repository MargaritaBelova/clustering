/*
 * Prepare.h
 *
 *  Created on: Sep 21, 2020
 *      Author: anotherme
 */

#ifndef MESSAGES_PREPARE_H_
#define MESSAGES_PREPARE_H_

#include "Message.h"

#include <memory>

class Ballot;

struct Prepare : public Message{
	Prepare(std::shared_ptr<Ballot> ballot_num_);
	Message_id getMsgID() const;

	std::shared_ptr<Ballot> ballot_num;
};

#endif /* MESSAGES_PREPARE_H_ */
