#pragma once
#include "grid.h"
#include "tetrisblock.cpp"

class Game
{
public:
	Game();
	tetrisGrid gameGrid;
private:
	vector<TetrisBlock> Blocks;

};
