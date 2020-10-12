/*
 * Invoke.cpp
 *
 *  Created on: Oct 8, 2020
 *      Author: anotherme
 */
#include "Invoke.h"

Invoke::Invoke(const std::string caller_, const unsigned long client_id_, const long input_value_) : caller(caller_),
	client_id(client_id_), input_value(input_value_) {}

Message_id Invoke::getMsgID() const{
	return invoke;
}


