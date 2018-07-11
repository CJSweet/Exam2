//I affirm that all code given below was written solely by me, 
//Casey Sweet, and that any help I received adhered to the rules stated for this exam.
#ifndef _EVENT_H_
#define _EVENT_H_
#include <string>
#include "EventTicket.h"

/**
* Abstract Base Class for an athletic event.
* This class just defines the methods that need to be implemented in its derived classes.
*/
class Event
{
public:

	/**
	* Adds a person to the party, and returns a party ticket
	*/
	virtual EventTicket * add(std::string name) = 0;

	/**
	* List the people currently in the party
	*/
	virtual void list() = 0;
};

#endif