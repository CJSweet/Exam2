//I affirm that all code given below was written solely by me, 
//Casey Sweet, and that any help I received adhered to the rules stated for this exam.
#ifndef _BASEBALL_EVENT_H_
#define _BASEBALL_EVENT_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Event.h"
#include "BaseballTicket.h"

// FIXME 2: Create BaseballEvent and BaseballTicket to for good baseball games!
// FIXME 2a: Create a function stretch so that the attendees can stand up an stretch for the 7th inning
// FIXME 3: Update EventFactory::factory() to allow it to be the ONLY method for creating a BaseballEvent
/**
* BaseballEvent is derived from Event
*/
class BaseballEvent : public Event
{
private:
	std::list<std::string> stadium; // Baseball list.
	std::string hometeam;
	std::string visitingteam;

	/**
	* Constructor for creating a WorldcupEvent
	*/
	BaseballEvent(std::string home, std::string visiting) {
		
		hometeam = home;
		visitingteam = visiting;
	}

	friend class EventFactory;

public:

	/**
	* Add a person to the event
	* @param name the name of the event goer
	*/
	EventTicket * add(std::string name) {
		//	name added to list 
		stadium.push_front(name);
		//	iterator to person just added. 
		std::list<std::string>::iterator person = stadium.begin();
		//	create the ticket
		EventTicket * ticket = new BaseballTicket(this, person);
		//	return ticket 
		return ticket;
	}

	/**
	* Show the event's home team and visiting team, then list all the persons currently in the event
	*/
	void list() {
		std::cout << "The home team is " << hometeam << "." << std::endl;
		std::cout << "The visiting team is " << visitingteam << "." << std::endl;
		std::cout << "Here are all the people in attendance to watch " << visitingteam << " play " << hometeam << ":"
			<< std::endl;
		for (std::list<std::string>::iterator people = stadium.begin(); people != stadium.end(); ++people)
		{
			std::cout << *people << std::endl;
		}
	}

	/**
	* Remove the person identified by the iterator from the event
	*/
	void remove(std::list<std::string>::iterator it) {
		std::cout << *it << " is out of hand, and has been escorted by the ushers out of the stadium." << std::endl;
		stadium.erase(it);
	}

	void stretch() {
		std::cout << "It is the 7th inning stretch! Feel free to stand, stretch, walk around or even get something to eat!!" << std::endl;
		for (std::list<std::string>::iterator i = stadium.begin(); i != stadium.end(); i++) {
			std::cout << '\t' << *i << " stands up, stretches, and groans." << std::endl;
		}
	}

};

#endif