//I affirm that all code given below was written solely by me, 
//Casey Sweet, and that any help I received adhered to the rules stated for this exam.
#include "stdafx.h"
#include "NBATicket.h"
#include "NBAEvent.h"

/**
* Implements the leave method
*/
void NBATicket::leave() {
	NBAEvent * actual_event = dynamic_cast<NBAEvent *>(the_event); // down-cast base class to derived class
	actual_event->remove(me); // call WorldcupEvent remove method to erase event goer identified by "me"
}