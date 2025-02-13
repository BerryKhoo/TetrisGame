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
	TetrisBlock();
	void Movement(int rows, int column);
	vector<BlockPosition> GetBlockPosition();
	void Draw();
	int blockID;
	map<int, vector<BlockPosition>> cells; // BlockID and its position with coordinates
private:
	int cellSize;
	Colors blockcolors{};
	int rowOff = 0;
	int colOff = 0;
};

TetrisBlock LBlock();