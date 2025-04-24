#pragma once
#include "Cell.h"
#include <cstdio>
#include <cstdlib>
#include <Windows.h>

class GameInstance {
public:
	GameInstance();
	int gameStartUi();
	int getSurroundingCellsNumber(int i, int j);
	void initData();
	void gameReadyToWork();
	void gameReadyToWork2();
	void gameMode();
	void mapUpdate();
	void mapShow();
	void setCellAliveMode();
	void setCellDeadMode();

private:
	Cell **map;			// map data
	int size;			// map size
	int sleepTime;
};