#include <iostream>
#include <raylib.h>
#include <vector>
#include "color.h"
#include "grid.h"
#include "tetrisblock.h"

Colors blockcolor = getColors();
//Creating tetris Blocks
TetrisBlock::TetrisBlock(){
	cellSize = 30;
	Rotation currentRotation(Rotation::UP);
}

//Turning it by changing location, dont static hardcode the block type.

//All Blocks
TetrisBlock LBlock() {
	TetrisBlock Lblock;
	Lblock.blockID = 1;
	Lblock.matrix = {0, 0, 1,
					 1, 1, 1,
					 0, 0, 0};
	Lblock.dimension = 3;
	return Lblock;
}

TetrisBlock JBlock() {
	TetrisBlock Jblock;
	Jblock.blockID = 2;
	Jblock.matrix = {1, 0, 0,
					 1, 1, 1,
					 0, 0, 0};
	Jblock.dimension = 3;
	return Jblock;
}

TetrisBlock OBlock() {
	TetrisBlock Oblock;
	Oblock.blockID = 3;
	Oblock.matrix = {1, 1,
					 1, 1};
	Oblock.dimension = 2;
	return Oblock;
}

TetrisBlock SBlock() {
	TetrisBlock Sblock;
	Sblock.blockID = 4;
	Sblock.matrix = {0, 1, 1,
					 1, 1, 0,
					 0, 0, 0};
	Sblock.dimension = 3;
	return Sblock;
}

TetrisBlock ZBlock() {
	TetrisBlock Zblock;
	Zblock.blockID = 5;
	Zblock.matrix = {1, 1, 0,
					 0, 1, 1,
					 0, 0, 0};
	Zblock.dimension = 3;
	return Zblock;
}

TetrisBlock TBlock() {
	TetrisBlock Tblock;
	Tblock.blockID = 6;
	Tblock.matrix = {0, 1, 0,
					 1, 1, 1,
					 0, 0, 0};
	Tblock.dimension = 3;
	return Tblock;
}

TetrisBlock IBlock() {
	TetrisBlock Iblock;
	Iblock.blockID = 7;
	Iblock.matrix = {0, 0, 1, 0,
					 0, 0, 1, 0,
					 0, 0, 1, 0,
					 0, 0, 1, 0};
	Iblock.dimension = 4;
	return Iblock;
}

// Draw the tetris block location in the grid
void TetrisBlock::Draw(){
	vector<BlockPosition> filled = GetBlockPosition();
	for (BlockPosition item : filled)
	{
		DrawRectangle(item.col * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize - 1, blockcolor.red);
	}
}

void TetrisBlock::Movement(int rows, int columns){
	colOff += columns;
	rowOff += rows;
}

vector<BlockPosition> TetrisBlock::GetBlockPosition() {
	vector<BlockPosition> movedTiles;
	for (int row = 0; row < dimension; ++row) {
		for (int col = 0; col < dimension; ++col) {
			
			bool cell = false;
			switch (currentRotation)
				{
				case TetrisBlock::Rotation::UP:
					cell = matrix[row * dimension + col];
					break;
				case TetrisBlock::Rotation::RIGHT:
					cell = matrix[dimension * (dimension - 1) - dimension * col + row];
					break;
				case TetrisBlock::Rotation::DOWN:
					cell = matrix[(dimension * dimension - 1) - dimension * row - col];
					break;
				case TetrisBlock::Rotation::LEFT:
					cell = matrix[dimension - 1 + dimension * col - row];
					break;
				default:
					break;
				}

			if (cell) {
				movedTiles.push_back(BlockPosition(row + rowOff, col + colOff));
			}
		}
	}
	return movedTiles;
}

void TetrisBlock::RotateClockwise() {

	currentRotation = Rotation((int(currentRotation) + 1) % 4);

}