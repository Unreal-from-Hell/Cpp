#include <iostream>
#include "Game.h"
using namespace std;

// TextRPG 4

int main()
{
	srand((unsigned int)time(nullptr));
	Game game;
	game.Init();

	while (true)
	{
		game.Update();
	}
	return 0;
}