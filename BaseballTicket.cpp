//I affirm that all code given below was written solely by me, 
//Casey Sweet, and that any help I received adhered to the rules stated for this exam.
#include "stdafx.h"
#include "BaseballTicket.h"
#include "BaseballEvent.h"

/**
* Implements the leave method
*/
void BaseballTicket::leave() {
	// FIXME 4: Implement leave for baseball games
	BaseballEvent * actual_event = dynamic_cast<BaseballEvent * > (the_event); // down-cast base class to derived class
	actual_event->remove(me); // call BaseballEvent remove method to erase event goer identified by "me"
}