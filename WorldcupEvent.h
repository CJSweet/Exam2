//I affirm that all code given below was written solely by me, 
//Casey Sweet, and that any help I received adhered to the rules stated for this exam.
#ifndef _WORLDCUP_EVENT_H_
#define _WORLDCUP_EVENT_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Event.h"
#include "WorldcupTicket.h"

/**
* WorldcupEvent is derived from Event
*/
class WorldcupEvent : public Event
{
private:
	std::list<std::string> stadium; // Data structure for containing the event goers in this worldcup event
	std::string hometeam;
	std::string visitingteam;

	/**
	* Constructor for creating a WorldcupEvent
	*/
	WorldcupEvent(std::string home, std::string visiting) {
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
		/// FIXME 1b:
		///   Pseudo-code

		///  1. add name to the front of stadium
		stadium.push_front(name);

		///  2. get iterator to the front of the stadium (this points to the recently added event goer)
		std::list<std::string>::iterator person = stadium.begin();

		///  3. create a new worldcup ticket (WorldcupTicket) with its constructor
		///            Pass to the constructor "this" event, and the iterator from step 2

		EventTicket * ticket = new WorldcupTicket(this, person);
		///    4. return this new event ticket 

		return ticket;
	}

	/**
	* Show the event's home team and visiting team, then list all the persons currently in the event
	*/
	void list() {
		// FIXME 1c: Show the event's home team and visiting team, then iterate through all the persons here.
		std::cout << "The home team is " << hometeam << "." << std::endl;
		std::cout << "The visiting team is " << visitingteam << "." << std::endl;
		std::cout << "Here are all the fans currently at the stadium to watch " << visitingteam << " face off with "
			<< hometeam << ": " << std::endl;
		for (std::list<std::string>::iterator people = stadium.begin(); people != stadium.end(); ++people)
		{
			std::cout << *people << std::endl;
		}
	}

	/**
	* Remove the person identified by the iterator from the event
	*/
	void remove(std::list<std::string>::iterator it) {
		//FIXME 1d: someone's getting out of hand. Ushers have asked them to leave.
		std::cout << *it 
			<< " has started to display behavior that is not tolerated at the World Cup, so the ushers will escort them out now." 
			<< std::endl;
		stadium.erase(it);
	}

	/**
	 * Have world cup attendees chant
	 */
	void chant() {
		std::cout << "The fans are starting to chant!!" << std::endl;
		for (std::list<std::string>::iterator i = stadium.begin(); i != stadium.end(); i++) {
			std::cout << '\t' << *i << " says 'boom boom clap!'" << std::endl;
		}
	}
};
#endif