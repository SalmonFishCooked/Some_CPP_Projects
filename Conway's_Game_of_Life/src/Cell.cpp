#include "Cell.h"

Cell::Cell()
{
	is_alive = false; //set the survival state of cell as dead state
	change = false;
}

void Cell::Set_Alive()
{
	is_alive = true;
}

void Cell::Set_Die()
{
	is_alive = false;
}

bool Cell::get_cell_alive()
{
	return is_alive;
}

void Cell::set_change_on()
{
	change = true;
}

void Cell::set_change_off()
{
	change = false;
}

void Cell::change_state()
{
	if (is_alive) { Set_Die(); }
	else { Set_Alive(); }
}

bool Cell::get_cell_change()
{
	return change;
}