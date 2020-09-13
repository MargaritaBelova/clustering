/*
 * Timer.h
 *
 *  Created on: Sep 11, 2020
 *      Author: anotherme
 */

#ifndef NETWORK_TIMER_H_
#define NETWORK_TIMER_H_

#include <string>

class Timer {
public:
	Timer(float expires, std::string address, bool callback);
	// written instead of
	//def __cmp__(self, other):
    //return cmp(self.expires, other.expires)
	// maybe replace with operator overload?
	char cmp (const Timer& timer2) const;
	void cancel();
};

/*
 * class Timer(object):

    def __init__(self, expires, address, callback):
        self.expires = expires
        self.address = address
        self.callback = callback
        self.cancelled = False

    def __cmp__(self, other):
        return cmp(self.expires, other.expires)

    def cancel(self):
        self.cancelled = True
 */

#endif /* NETWORK_TIMER_H_ */
