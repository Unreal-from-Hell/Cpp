#include <iostream>

using namespace std;

// 다차원 배열

int main()
{
	int a[10] = { 1, 2, 3 };

	int first[5] = { 4, 2, 3, 4, 1 };
	int second[5] = { 1, 1, 5, 2, 2 };

	int apartment2D[2][5] = { { 4, 2, 3, 4, 1}, { 1, 1, 5, 2, 2} };

	for (int floor = 0; floor < 2; floor++)
	{
		for (int room = 0; room < 5; room++)
		{
			int num = apartment2D[floor][room];
			cout << num << " ";
		}
		cout << endl;
	}

	// 2차원 배열이 자주 사용되는 곳
	// 맵
	int map[5][5] =
	{
		{1, 1, 1, 1, 1},
		{1, 0, 0, 1, 1},
		{0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1,}
	};

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			int info = map[y][x];
			cout << info;
		}
		cout << endl;
	}
}