#include <iostream>
#include <vector>
#include "grid.h"
#include "color.h"

using namespace std;

//To initialize the grid of the tetris field

tetrisGrid::tetrisGrid() {
	rowNum = 20;
	colNum = 10;
	cellSize = 30;
	initializeGrid();
	blockColor = getBlockColor();
}

void tetrisGrid::initializeGrid() {
	// Initialize all grid elements to 0
	for (int row = 0; row < rowNum; row++) {
		for (int column = 0; column < colNum; column++) {
			grid[row][column] = 0;
		}
	}
}

void tetrisGrid::printGrid() {
	for (int row = 0; row < rowNum; row++) {
		for (int column = 0; column < colNum; column++) {
			cout << grid[row][column] << " ";
		}

		cout << endl;
	}
}

void tetrisGrid::Draw() {
	for (int row = 0; row < rowNum; row++) {
		for (int column = 0; column < colNum; column++) {
			int cellValue = grid[row][column]; 
			DrawRectangle(column * cellSize + 70, row * cellSize + 50, cellSize - 1, cellSize - 1, blockColor[cellValue]);
		}
	}
}

bool tetrisGrid::emptyCell(int row, int col) {
	
	if (grid[row][col] == 0) {
		return true;
	}
	return false;
}


