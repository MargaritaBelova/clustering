/*
 * Role.h
 *
 *  Created on: Sep 11, 2020
 *      Author: anotherme
 */

#ifndef COMPONENTS_ROLE_H_
#define COMPONENTS_ROLE_H_

#include <memory>
#include <iostream> //del later

class RoleTimer;
class Node;

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
	Role(std::weak_ptr<Node> node_);
	virtual ~Role() = 0;
	virtual Role_id getRoleName() const = 0;

	virtual void callback() = 0;

	// поменять тип на Role Timer?
	RoleTimer* setTimer(float seconds); //is it ok for time to be float?
	std::weak_ptr<Node> node;
private:
	void stop();
	bool running = false;
	//Logger& logger;
};

inline Role::~Role(){}
// put later where it needed
/*
#include "../destinations/DestinationsType.h"
inline auto makeDestinationsPtr(const std::string sender){
	auto destinations_ptr = std::make_unique<destination_list>();
	destinations_ptr->push_back(sender);
	return destinations_ptr;
}
*/

#endif /* COMPONENTS_ROLE_H_ */
