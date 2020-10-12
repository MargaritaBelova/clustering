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


class Requester : public Role {
public:
	// дописать конструктор
	Requester(std::weak_ptr<Node> node_, const unsigned long int n_);
	~Requester(); //del later
	Role_id getRoleName() const; 	// rewrite to static?

	void callback();
	void start();
	void doInvoked(const std::string sender, const unsigned long client_id, const long output);

private:
	static unsigned long client_ids; // 100_000?
	unsigned long client_id;
	const unsigned long int n;

};

/*
class Requester(Role):
    client_ids = itertools.count(start=100000)

    def __init__(self, node, n, callback):
        super(Requester, self).__init__(node)
        self.client_id = self.client_ids.next()
        self.n = n
        self.output = None
        self.callback = callback



    def do_Invoked(self, sender, client_id, output):
        if client_id != self.client_id:
            return
        self.logger.debug("received output %r" % (output,))
        self.invoke_timer.cancel()
        self.callback(output)
        self.stop()

*/
#endif /* COMPONENTS_REQUESTER_H_ */
