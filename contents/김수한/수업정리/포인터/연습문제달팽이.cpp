#include <iostream>

using namespace std;
#include <iomanip>

// 연습 문제

const int MAX = 100;
int board[MAX][MAX] = {};
int N;

void PrintBoard()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		}
		cout << endl;
	}
}

void SetBoard()
{
	int move_line = N, count = 1, x = 0, y = 0;

	while (count <= N*N)
	{	int loop = move_line;

		// Right
		while (loop != 0)
		{
			board[y][x] = count;
			count++;
			x++;
			loop--;
		}
		x--;
		y++;
		move_line--;
		if (move_line == 0) return;
		loop = move_line;

		// Down
		while (loop != 0)
		{
			board[y][x] = count;
			count++;
			y++;
			loop--;
		}
		y--;
		x--;
		loop = move_line;

		// Left
		while (loop != 0)
		{
			board[y][x] = count;
			count++;
			x--;
			loop--;
		}
		x++;
		y--;
		move_line--;
		if (move_line == 0) return;
		loop = move_line;

		// Up
		while (loop != 0)
		{
			board[y][x] = count;
			count++;
			y--;
			loop--;
		}
		y++;
		x++;
		loop = move_line;
	}
}

int main()
{
	cin >> N;

	SetBoard();

	PrintBoard();
}