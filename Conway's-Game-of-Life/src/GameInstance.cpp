#include "GameInstance.h"

using namespace std;

GameInstance::GameInstance() { sleepTime = 100; }

int GameInstance::gameStartUi() {
	int id;
	while (true) {
		system("cls");
		printf("Conway's_Game_of_Life\n");
		printf("Created by SalmonFishCooked.\n");
		printf("------------------------------\n");
		printf("1.Start a new Game.\n");
		printf("2.exit.\n");
		scanf("%d", &id);
		if (id == 1) { initData(); }
		else { return 0; }
	}

	return -1;
}

void GameInstance::initData() {
	int temp;
	while (true) {
		system("cls");
		printf("input map size(n x n, n <= 25):");
		scanf("%d", &temp);
		if (!(temp > 0 && temp <= 25)) { continue; }
		size = temp;
		map = new Cell * [size];
		for (int i = 0; i < size; ++i) { map[i] = new Cell[size]; }
		break;
	}

	gameReadyToWork();
}

void GameInstance::gameReadyToWork() {
	int id;
	while (true) {
		system("cls");
		mapShow();
		printf("-----------------\" -1 \" to continue--------------------\n");
		printf("1. Set Cell Alive.\n2. Set Cell Dead.\n");
		scanf("%d", &id);
		if (id == 1) { setCellAliveMode(); }
		else if (id == 2) { setCellDeadMode(); }
		else if (id == -1) { break; }
		else { continue; }
	}

	gameReadyToWork2();
}

void GameInstance::gameReadyToWork2() {
	int temp;
	while (true) {
		system("cls");
		printf("input the time of updating map(ms,): ");
		scanf("%d", &temp);
		sleepTime = temp;
		break;
	}

	gameMode();
}

void GameInstance::gameMode() {
	while (true) {
		system("cls");
		mapShow();
		mapUpdate();
		Sleep(DWORD(sleepTime));
	}
}

void GameInstance::mapUpdate() {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			int cnt = getSurroundingCellsNumber(i, j);
			if (cnt < 2 || cnt > 3){
				if (map[i][j].getCellAlive()) { map[i][j].setChangeOn(); }
			} else if (cnt == 3) {
				if (!map[i][j].getCellAlive()) { map[i][j].setChangeOn(); }
			}
		}
	}

	// set change to ok, representing it needs to be updated.
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (map[i][j].getCellChange())  { 
				map[i][j].changeState(); 
				map[i][j].setChangeOff();
			}
		}
	}
}

int GameInstance::getSurroundingCellsNumber(int i, int j) {
	int cnt = 0;
	if (map[(i + size - 1) % size][(j + size) % size].getCellAlive()) { ++cnt; }
	if (map[(i + size - 1) % size][(j + size + 1) % size].getCellAlive()) { ++cnt; }
	if (map[(i + size) % size][(j + size + 1) % size].getCellAlive()) { ++cnt; }
	if (map[(i + size + 1) % size][(j + size + 1) % size].getCellAlive()) { ++cnt; }
	if (map[(i + size + 1) % size][(j + size) % size].getCellAlive()) { ++cnt; }
	if (map[(i + size + 1) % size][(j + size - 1) % size].getCellAlive()) { ++cnt; }
	if (map[(i + size) % size][(j + size - 1) % size].getCellAlive()) { ++cnt; }
	if (map[(i + size - 1) % size][(j + size - 1) % size].getCellAlive()) { ++cnt; }

	return cnt;
}

void GameInstance::mapShow() {
	system("cls");
	printf("  ");
	for (int i = 0; i < size; ++i) { printf(" %2d ", i); }
	printf("\n");

	for (int i = 0; i < size; ++i) {
		printf("%2d ", i);
		for (int j = 0; j < size; ++j) {
			if (map[i][j].getCellAlive()) { printf("  ♪"); }
			else { printf("  •"); }
			printf(" ");
		}
		printf("\n\n");
	}
}

void GameInstance::setCellAliveMode() {
	int m, n;
	while (true) {
		system("cls");
		mapShow();
		printf("----------------input such as \"2 3\" -1 -1 to exit-----------------\n");
		scanf("%d %d", &m, &n);
		if (m == -1) { break; }
		if (m < 0 || m >= size) { continue; } //forbid bug
		if (n < 0 || n >= size) { continue; }
		map[m][n].setAlive();
	}
}

void GameInstance::setCellDeadMode() {
	int m, n;
	while (true) {
		system("cls");
		mapShow();
		printf("----------------input such as \"2 3\" -1 -1 to exit-----------------\n");
		scanf("%d %d", &m, &n);
		if (m == -1) { break; }
		if (m < 0 || m >= size) { continue; }
		if (n < 0 || n >= size) { continue; }
		map[m][n].setDie();
	}
}