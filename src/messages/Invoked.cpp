/*
 * Invoked.cpp
 *
 *  Created on: Oct 7, 2020
 *      Author: anotherme
 */

#include "Invoked.h"

Invoked::Invoked(const unsigned long client_id_, const long output_) : client_id(client_id_),
	output(output_) {}

Message_id Invoked::getMsgID() const{
	return accepted;
}
