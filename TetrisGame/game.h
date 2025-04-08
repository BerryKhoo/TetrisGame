#pragma once
#include "grid.h"
#include "tetrisblock.h"

class Game
{
public:
	Game();
	TetrisBlock BlockRandom();
	void Draw();
	void UI();
	void ControlHandling();
	bool OutskirtBlock(int row, int col);
	bool DetectBlock();
	void AutoDrop();
	void LockBlock();
	bool CheckTiles();
	int ClearLines();
	bool CheckRow(int row);
	void ClearRow(int row);
	void MoveRowDown(int row, int clearRow);
	int Points(int clearRow);
	void MoveRight();
	void MoveLeft();
	void MoveDown();
	void HardDrop();
	void ClockwiseRotate();
	vector<TetrisBlock> AllBlocks();
	tetrisGrid gameGrid;
	bool LockblockFlag;
	bool gameOver;
private:
	vector<TetrisBlock> blocks;
	TetrisBlock curBlock;
	TetrisBlock nextBlock;
	Font score;
	int currentScore;
};
