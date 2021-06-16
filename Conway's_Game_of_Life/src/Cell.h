#pragma once

class Cell
{
public:
	Cell();
	void Set_Die();
	void Set_Alive();
	void set_change_on();
	void set_change_off();
	void change_state();
	bool get_cell_alive();
	bool get_cell_change();
private:
	bool is_alive; //survival state of cell
	bool change; //if the survival state of cell need to change, then use change to check it.
};