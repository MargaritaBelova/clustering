/*
 * Role.h
 *
 *  Created on: Sep 11, 2020
 *      Author: anotherme
 */

#ifndef COMPONENTS_ROLE_H_
#define COMPONENTS_ROLE_H_

#include "../network/Timer.h"	// rewrite later to pointer?
//#include "../messages/Message.h"	// include all the msgs or just one header?

class Node;

//here or in separate file?
enum Role_id{
	acceptor,
	replica,
	leader,
	scout,
	commander,
	bootstrap,
	seed,
	requester
};

class Role {
public:
	Role(Node* node);
	virtual ~Role();	// del later?
	virtual Role_id getRoleName() const = 0;
	Timer setTimer(float seconds, bool callback);
	Node* node;

protected:
	void stop();
	bool running;
	//Logger& logger;
};



#endif /* COMPONENTS_ROLE_H_ */
