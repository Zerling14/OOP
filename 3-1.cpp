#include <iostream>
#include <cstdlib>
#include <cassert>
#include <windows.h>
#include <stdio.h>
#include <ctime>

using namespace std;

class tPoint {
private:
	short x, y, vx, vy;
	short color;
public:
	tPoint(short color)
	{
		this->color = color;
	}
	tPoint(short color, int x, int y)
	{
		this->color = color;
		this->x = x;
		this->y = y;
	}
	tPoint(short color, int x, int y, int vx, int vy)
	{
		this->color = color;
		this->x = x;
		this->y = y;
		this->vx = vx;
		this->vy = vy;
	}
	void Print()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		SetConsoleCursorPosition(hConsole, {x - vx, y - vy});
		cout << " ";
		SetConsoleCursorPosition(hConsole, {x, y});
		cout << "*";
	}
	void Calc()
	{
		if (x + vx < 0 || x + vx > 10) {
			vx = 0 - vx;
		}
		if (y + vy < 0 || y + vy > 10) {
			vy = 0 - vy;
		}
		x = x + vx;
		y = y + vy;
	}
};
int main()
{
	srand(time(0));
	int pointCount = 10;
	tPoint **arr = new tPoint*[pointCount];
	for (int i = 0; i < pointCount; ++i) {
		arr[i] = new tPoint(rand() % 16, rand() % 10, rand() % 10, rand() % 2 - 1, rand() % 2 - 1);
	}
	while (true) {
		for (int i = 0; i < pointCount; ++i) {
			arr[i]->Print();
			arr[i]->Calc();
		}
		Sleep(500);
	}
	system("pause");
	return 0;
}