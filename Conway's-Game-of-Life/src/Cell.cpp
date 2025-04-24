#include "Cell.h"

Cell::Cell() {
	// set the survival state of cell to dead state
	isAlive = false;
	change = false;
}

void Cell::setAlive() { isAlive = true; }

void Cell::setDie() { isAlive = false; }

bool Cell::getCellAlive() { return isAlive; }

void Cell::setChangeOn() { change = true; }

void Cell::setChangeOff() { change = false; }

void Cell::changeState() {
	if (isAlive) {
		setDie();
    } else {
    	setAlive();
	}
}

bool Cell::getCellChange() { return change; }