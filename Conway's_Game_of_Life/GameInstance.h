#pragma once
#include "Cell.h"
#include <cstdio>
#include <cstdlib>
#include <Windows.h>

class GameInstance
{
public:
	GameInstance();
	int Game_Start_UI();
	int Get_Surround_Cells_Number(int i, int j);
	void Game_Initialization_Data();
	void Game_Ready_Work();
	void Game_Ready_Work_2();
	void Gaming_Mode();
	void map_update();
	void map_show();
	void Set_Cell_Alive_Mode();
	void Set_Cell_Dead_Mode();
private:
	Cell** map; //map data
	int size; //map size
	int sleep_time;
};