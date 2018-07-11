//I affirm that all code given below was written solely by me, 
//Casey Sweet, and that any help I received adhered to the rules stated for this exam.
#ifndef _NBA_EVENT_H_
#define _NBA_EVENT_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Event.h"
#include "NBATicket.h"

/**
* WorldcupEvent is derived from Event
*/
class NBAEvent : public Event
{
private:
	std::list<std::string> MODAcenter; // Data structure for containing the event goers in this NBA event
	std::string hometeam;
	std::string visitingteam;

	/**
	* Constructor for creating a NBAEvent
	*/
	NBAEvent(std::string home, std::string visiting) {
		/**
		*  FIXME 1a:
		*    store the home team and visiting team names
		*/
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
		/// add name to the front of stadium
		MODAcenter.push_front(name);

		///  get iterator to the front of the MODACenter (this points to the recently added event goer)
		std::list<std::string>::iterator person = MODAcenter.begin();

		/// create a new NBA ticket (NBATicket) with its constructor
		/// Pass to the constructor "this" event, and the iterator from step 2
		EventTicket * ticket = new NBATicket(this, person);

		/// return this new event ticket
		return ticket;
	}

	/**
	* Show the event's home team and visiting team, then list all the persons currently in the event
	*/
	void list() {
		// Show the event's home team and visiting team, then iterate through all the persons here.
		std::cout << "The home team is the " << hometeam << "." << std::endl;
		std::cout << "The visiting team is the " << visitingteam << "." << std::endl;
		std::cout << "Here are all the fans currently at the Moda Center to watch the " << visitingteam << " play your "
			<< hometeam << ": " << std::endl;
		for (std::list<std::string>::iterator people = MODAcenter.begin(); people != MODAcenter.end(); ++people)
		{
			std::cout << *people << std::endl;
		}
	}

	/**
	* Remove the person identified by the iterator from the event
	*/
	void remove(std::list<std::string>::iterator it) {
		//someone's getting out of hand. Ushers have asked them to leave.
		std::cout << *it
			<< " has started to shout vulgar comments to the referees and the " << visitingteam << " players" <<
			" so she has been asked to leave."
			<< std::endl;
		MODAcenter.erase(it);
	}

	/**
	* Have NBA attendees distract the free throw shooter
	*/
	void FreeThrow() {
		std::cout << "A Utah Jazz player is at the line to shoot two free throws, so the fans are trying to distract him." <<
			std::endl;
		for (std::list<std::string>::iterator i = MODAcenter.begin(); i != MODAcenter.end(); i++) {
			std::cout << '\t' << *i << " says 'AAAAAAHHHHHHHHHHH!!!!!' while smashing the balloon sticks together," <<
				 " which make a very fast and loud 'boom-boom-boom-boom' sound." <<std::endl;
		}
	}
};
#endif