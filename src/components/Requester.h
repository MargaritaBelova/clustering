/*
 * Requester.h
 *
 *  Created on: Oct 7, 2020
 *      Author: anotherme
 */

#ifndef COMPONENTS_REQUESTER_H_
#define COMPONENTS_REQUESTER_H_

// not finished yet!
#include "Role.h"

#include <iostream> // del later;
#include <memory>
#include <string>

#include "../Network/RoleTimer"


class Requester : public Role {
public:
	// дописать конструктор
	Requester(std::weak_ptr<Node> node_, const unsigned long int n_);
	~Requester();
	Role_id getRoleName() const;

	void callback();
	void start();
	void doInvoked(const std::string sender, const unsigned long client_id, const long output);

private:
	static unsigned long client_ids;
	unsigned long client_id;
	const unsigned long int n;
	RoleTimer invoke_timer;

	const float kInvokeRetransmit = 0.5;

};

/*
 *
 в первую очередь, дописать output и callback в конструктор

*/
#endif /* COMPONENTS_REQUESTER_H_ */
