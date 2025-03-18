#pragma once
#include <iostream>
#include <raylib.h>
#include <vector>
#include <map>
#include "color.h"
#include "grid.h"
#include "blockposition.h"

// Class for creating tetris blocks
class TetrisBlock
{
public:
	enum class Rotation
	{
		UP,
		RIGHT,
		DOWN,
		LEFT
	};
public:
	TetrisBlock();
	void Movement(int rows, int column);
	vector<BlockPosition> GetBlockPosition();
	bool CheckTilesRotate();
	void RotateClockwise();
	void RotateAnticlockwise();
	void Draw();
	int blockID;
	vector<int> matrix; // BlockID and its position with coordinates
	int dimension;
	int rowOff = 0;
	int colOff = 0;
private:
	int cellSize;
	Rotation currentRotation;
	vector<Color> blockColor;
	
};

TetrisBlock LBlock();
TetrisBlock JBlock();
TetrisBlock IBlock();
TetrisBlock OBlock();
TetrisBlock TBlock();
TetrisBlock ZBlock();
TetrisBlock SBlock();