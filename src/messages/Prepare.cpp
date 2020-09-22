/*
 * Prepare.cpp
 *
 *  Created on: Sep 21, 2020
 *      Author: anotherme
 */

#include "Prepare.h"

Prepare::Prepare (unsigned int _slot) : slot(_slot) {
}

Message_id Prepare::getMsgID() const {
	return prepare;
}

