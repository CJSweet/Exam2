//I affirm that all code given below was written solely by me, 
//Casey Sweet, and that any help I received adhered to the rules stated for this exam.
#ifndef _BASEBALL_TICKET_H_
#define _BASEBALL_TICKET_H_

#include <list>
#include <string>
#include "Event.h"
#include "EventTicket.h"

class BaseballTicket : public EventTicket
{
private:
	Event * the_event; // the event this ticket is associated with
	std::list<std::string>::iterator me; // an iterator containing the event goer this ticket is associated with

public:

	/**
	* Constructor for creating a WorldcupTicket.
	* @param the_event	event to which this ticket belongs
	* @param me			event goer to which this ticket is associated with
	*/
	BaseballTicket(Event * the_event, std::list<std::string>::iterator &me) :
		the_event(the_event), me(me) {}

	/**
	* Allows the event goer, "me", to leave the event, "the_event"
	*/
	void leave();
	
};

#endif