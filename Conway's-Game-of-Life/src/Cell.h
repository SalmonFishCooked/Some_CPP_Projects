#pragma once

class Cell {
public:
	Cell();
	void setDie();
	void setAlive();
	void setChangeOn();
	void setChangeOff();
	void changeState();
	bool getCellAlive();
	bool getCellChange();

private:
	// survival state of cell
	bool isAlive; 

	// if the survival state of cell need to be changed, use change to check it.
	bool change; 
};