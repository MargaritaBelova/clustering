/*
 * Accepting.cpp
 *
 *  Created on: Oct 3, 2020
 *      Author: anotherme
 */

#include "Accepting.h"

Accepting::Accepting(const std::string leader_) : leader(leader_) {};

Message_id Accepting::getMsgID() const{
	return accepting;
}
