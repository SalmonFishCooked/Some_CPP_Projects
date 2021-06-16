#include "GameInstance.h"

using namespace std;

GameInstance::GameInstance()
{
	sleep_time = 100;
}

int GameInstance::Game_Start_UI()
{
	int id;
	while (true)
	{
		system("cls");
		printf("Conway's_Game_of_Life\n");
		printf("Created by SalmonFishCooked.\n");
		printf("------------------------------\n");
		printf("1.Start a new Game.\n");
		printf("2.exit.\n");
		scanf("%d", &id);
		if (id == 1) { Game_Initialization_Data(); }
		else { return 0; }
	}
	return -1;
}

void GameInstance::Game_Initialization_Data()
{
	int temp;
	while (true)
	{
		system("cls");
		printf("input map size(n x n, n <= 25):");
		scanf("%d", &temp);
		if (!(temp > 0 && temp <= 25)) { continue; }
		size = temp;
		map = new Cell * [size];
		for (int i = 0; i < size; ++i) { map[i] = new Cell[size]; }
		break;
	}
	Game_Ready_Work();
}

void GameInstance::Game_Ready_Work()
{
	int id;
	while (true)
	{
		system("cls");
		map_show();
		printf("-----------------\" -1 \" to continue--------------------\n");
		printf("1. Set Cell Alive.\n2. Set Cell Dead.\n");
		scanf("%d", &id);
		if (id == 1) { Set_Cell_Alive_Mode(); }
		else if (id == 2) { Set_Cell_Dead_Mode(); }
		else if (id == -1) { break; }
		else { continue; }
	}
	Game_Ready_Work_2();
}

void GameInstance::Game_Ready_Work_2()
{
	int temp;
	while (true)
	{
		system("cls");
		printf("input the time of updating map(ms,): ");
		scanf("%d", &temp);
		sleep_time = temp;
		break;
	}
	Gaming_Mode();
}

void GameInstance::Gaming_Mode()
{
	while (true)
	{
		system("cls");
		map_show();
		map_update();
		Sleep(DWORD(sleep_time));
	}
}

void GameInstance::map_update()
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			int cnt = Get_Surround_Cells_Number(i, j);
			if (cnt < 2 || cnt > 3)
			{
				if (map[i][j].get_cell_alive()) { map[i][j].set_change_on(); }
			}
			else if (cnt == 3)
			{
				if (!map[i][j].get_cell_alive()) { map[i][j].set_change_on(); }
			}
		}
	}

	//set change ok, need to update.

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (map[i][j].get_cell_change()) 
			{ 
				map[i][j].change_state(); 
				map[i][j].set_change_off();
			}
		}
	}
}

int GameInstance::Get_Surround_Cells_Number(int i, int j)
{
	int cnt = 0;
	if (map[(i + size - 1) % size][(j + size) % size].get_cell_alive()) { ++cnt; }
	if (map[(i + size - 1) % size][(j + size + 1) % size].get_cell_alive()) { ++cnt; }
	if (map[(i + size) % size][(j + size + 1) % size].get_cell_alive()) { ++cnt; }
	if (map[(i + size + 1) % size][(j + size + 1) % size].get_cell_alive()) { ++cnt; }
	if (map[(i + size + 1) % size][(j + size) % size].get_cell_alive()) { ++cnt; }
	if (map[(i + size + 1) % size][(j + size - 1) % size].get_cell_alive()) { ++cnt; }
	if (map[(i + size) % size][(j + size - 1) % size].get_cell_alive()) { ++cnt; }
	if (map[(i + size - 1) % size][(j + size - 1) % size].get_cell_alive()) { ++cnt; }
	return cnt;
}

void GameInstance::map_show()
{
	system("cls");
	printf("  ");
	for (int i = 0; i < size; ++i) { printf(" %2d ", i); }
	printf("\n");
	for (int i = 0; i < size; ++i)
	{
		printf("%2d ", i);
		for (int j = 0; j < size; ++j)
		{
			if (map[i][j].get_cell_alive()) { printf(" ¡ö"); }
			else { printf(" ¡¤"); }
			printf(" ");
		}
		printf("\n\n");
	}
}

void GameInstance::Set_Cell_Alive_Mode()
{
	int m, n;
	while (true)
	{
		system("cls");
		map_show();
		printf("----------------input such as \"2 3\" -1 -1 to exit-----------------\n");
		scanf("%d %d", &m, &n);
		if (m == -1) { break; }
		if (m < 0 || m >= size) { continue; } //forbid bug
		if (n < 0 || n >= size) { continue; }
		map[m][n].Set_Alive();
	}
}

void GameInstance::Set_Cell_Dead_Mode()
{
	int m, n;
	while (true)
	{
		system("cls");
		map_show();
		printf("----------------input such as \"2 3\" -1 -1 to exit-----------------\n");
		scanf("%d %d", &m, &n);
		if (m == -1) { break; }
		if (m < 0 || m >= size) { continue; }
		if (n < 0 || n >= size) { continue; }
		map[m][n].Set_Die();
	}
}