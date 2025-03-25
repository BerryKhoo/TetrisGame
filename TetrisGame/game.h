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
	bool OutskirtBlock(int row, int col);
	bool DetectBlock();
	void AutoDrop();
	void LockBlock();
	bool CheckTiles();
	void ClearLines();
	bool CheckRow(int row);
	void ClearRow(int row);
	void MoveRowDown(int row, int clearRow);
	vector<TetrisBlock> AllBlocks();
	tetrisGrid gameGrid;
	bool LockblockFlag;
private:
	vector<TetrisBlock> blocks;
	TetrisBlock curBlock;
	TetrisBlock nextBlock;
};
