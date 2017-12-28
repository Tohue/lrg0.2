#include "stdafx.h"
#include "PathFinder.h"

void PathFinder::GetPath(std::list<Path*> PathList)
{
	memset(PathArray, -1, sizeof PathArray);
	int x, y;
	for (std::list<Path*>::iterator it = PathList.begin(); it != PathList.end(); ++it)
	{
		for (x = 0; x < 21; x++)
		{
			for (y = 0; y < 16; y++)
			{
				if (((*it)->getx() / 32 == x) && ((*it)->gety() / 32 == y))
					PathArray[x][y] = -2;

			}

		}

	}


	
}

int PathFinder::FindPath(int enemy_x, int enemy_y, int player_x, int player_y)
{
	//THE WAVING METHOD

	enemy_x = enemy_x / 32;
	enemy_y = enemy_y / 32;

	player_x = player_x /32;
	player_y = player_y / 32;

	int CurrPath[25][20];

	const int W = 20;
	const int H = 15;

	int dx[4] = { 1, 0, -1, 0 };   // ��������, ��������������� ������� ������
	int dy[4] = { 0, 1, 0, -1 };   // ������, �����, ����� � ������
	int d, x, y, k;

	for (x = 0; x < 21; x++)
	{
		for (y = 0; y < 16; y++)

		{
			CurrPath[x][y] = PathArray[x][y];
		}
	}


	bool stop;
	/*
		if (CurrPath[enemy_y][enemy_x] == -1 || CurrPath[player_y][player_x] == -1) return false;  // ������ (ax, ay) ��� (bx, by) - �����
	x = 0;
	y = 0;
																	 // ��������������� �����
	d = 0;
	CurrPath[enemy_y][enemy_x] = 0;            // ��������� ������ �������� 0
	do {
		stop = true;               // ������������, ��� ��� ��������� ������ ��� ��������
		for (y = 0; y < 16; ++y)
			for (x = 0; x < 21; ++x)
				if (CurrPath[y][x] == d)                         // ������ (x, y) �������� ������ d
				{
					for (k = 0; k < 4; ++k)                    // �������� �� ���� ������������ �������
					{
						int iy = y + dy[k], ix = x + dx[k];
						if (iy >= 0 && iy < H && ix >= 0 && ix < W &&
							CurrPath[iy][ix] == -2)
						{
							stop = false;              // ������� ������������ ������
							CurrPath[iy][ix] = d + 1;      // �������������� �����
						}
					}
				}
		d++;
	} while (!stop && CurrPath[player_y][player_x] == -2);

	if (CurrPath[player_y][player_x] == -2) return false;  // ���� �� ������

											  // �������������� ����
	len = CurrPath[player_y][player_x];            // ����� ����������� ���� �� (ax, ay) � (bx, by)
	x = player_x;
	y = player_y;
	d = len;
	while (d > 0)
	{
		px[d] = x;
		py[d] = y;                   // ���������� ������ (x, y) � ����
		d--;
		for (k = 0; k < 4; ++k)
		{
			int iy = y + dy[k], ix = x + dx[k];
			if (iy >= 0 && iy < H && ix >= 0 && ix < W &&
				CurrPath[iy][ix] == d)
			{
				x = x + dx[k];
				y = y + dy[k];           // ��������� � ������, ������� �� 1 ����� � ������
				break;
			}
		}
	}
	px[0] = enemy_x;
	py[0] = enemy_y;                    // ������ px[0..len] � py[0..len] - ���������� ����� ����
	return true;
	
	
	
	
	*/
	if (CurrPath[enemy_x][enemy_y] == -1 || CurrPath[player_x][player_y] == -1) return false;  // ������ (ax, ay) ��� (bx, by) - �����
	x = 0;
	y = 0;
																	 // ��������������� �����
	d = 0;
	CurrPath[enemy_x][enemy_y] = 0;            // ��������� ������ �������� 0
	do {
		stop = true;               // ������������, ��� ��� ��������� ������ ��� ��������
		for (y = 0; y < 16; ++y)
			for (x = 0; x < 21; ++x)
				if (CurrPath[x][y] == d)                         // ������ (x, y) �������� ������ d
				{
					for (k = 0; k < 4; ++k)                    // �������� �� ���� ������������ �������
					{
						int iy = y + dy[k], ix = x + dx[k];
						if (iy >= 0 && iy < H && ix >= 0 && ix < W &&
							CurrPath[ix][iy] == -2)
						{
							stop = false;              // ������� ������������ ������
							CurrPath[ix][iy] = d + 1;      // �������������� �����
						}
					}
				}
		d++;
	} while (!stop && CurrPath[player_x][player_y] == -2);

	if (CurrPath[player_x][player_y] == -2) return false;  // ���� �� ������

											  // �������������� ����
	len = CurrPath[player_x][player_y];            // ����� ����������� ���� �� (ax, ay) � (bx, by)
	x = player_x;
	y = player_y;
	d = len;
	while (d > 0)
	{
		px[d] = x;
		py[d] = y;                   // ���������� ������ (x, y) � ����
		d--;
		for (k = 0; k < 4; ++k)
		{
			int iy = y + dy[k], ix = x + dx[k];
			if (iy >= 0 && iy < H && ix >= 0 && ix < W &&
				CurrPath[ix][iy] == d)
			{
				x = x + dx[k];
				y = y + dy[k];           // ��������� � ������, ������� �� 1 ����� � ������
				break;
			}
		}
	}
	px[0] = enemy_x;
	py[0] = enemy_y;                    // ������ px[0..len] � py[0..len] - ���������� ����� ����
	return true;
}

int PathFinder::GetNextPathX()
{
	return px[1];
}

int PathFinder::GetNextPathY()
{
	return py[1];
}
