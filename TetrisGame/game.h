#pragma once
#include "grid.h"
#include "tetrisblock.h"

class Game
{
public:
	Game();
	TetrisBlock BlockRandom();
	void Draw();
	void ControlHandling();
	vector<TetrisBlock> AllBlocks();
	tetrisGrid gameGrid;
private:
	vector<TetrisBlock> blocks;
	TetrisBlock curBlock;

};
