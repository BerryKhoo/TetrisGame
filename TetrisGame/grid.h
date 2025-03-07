#pragma once
#include <raylib.h>
#include <vector>
#include "color.h"

class tetrisGrid
{
public:
	tetrisGrid();
	void initializeGrid();
	void printGrid();
	void Draw();
	int grid[20][10];
	vector<Color> blockColor;
	bool emptyCell(int row, int col);
	int rowNum;
	int colNum;

private:
	int cellSize;
};