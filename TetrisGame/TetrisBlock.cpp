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
}

//Turning it by changing location, dont static hardcode the block type.

//All Blocks
TetrisBlock LBlock() {
	TetrisBlock Lblock;
	Lblock.blockID = 1;
	Lblock.cells[0] = {BlockPosition(0,2),BlockPosition(1,0),BlockPosition(1,1),BlockPosition(1,2)};
	return Lblock;
}

TetrisBlock JBlock() {
	TetrisBlock Jblock;
	Jblock.blockID = 2;
	Jblock.cells[0] = { BlockPosition(0,0),BlockPosition(1,0),BlockPosition(1,1),BlockPosition(1,2) };
	return Jblock;
}

TetrisBlock OBlock() {
	TetrisBlock Oblock;
	Oblock.blockID = 2;
	Oblock.cells[0] = { BlockPosition(0,1),BlockPosition(0,2),BlockPosition(1,1),BlockPosition(1,2) };
	return Oblock;
}

TetrisBlock SBlock() {
	TetrisBlock Sblock;
	Sblock.blockID = 1;
	Sblock.cells[0] = { BlockPosition(0,1),BlockPosition(0,2),BlockPosition(1,0),BlockPosition(1,1) };
	return Sblock;
}

TetrisBlock ZBlock() {
	TetrisBlock Zblock;
	Zblock.blockID = 1;
	Zblock.cells[0] = { BlockPosition(0,0),BlockPosition(0,1),BlockPosition(1,1),BlockPosition(1,2) };
	return Zblock;
}

TetrisBlock TBlock() {
	TetrisBlock Tblock;
	Tblock.blockID = 1;
	Tblock.cells[0] = { BlockPosition(0,1),BlockPosition(1,0),BlockPosition(1,1),BlockPosition(1,2) };
	return Tblock;
}

TetrisBlock IBlock() {
	TetrisBlock Iblock;
	Iblock.blockID = 1;
	Iblock.cells[0] = { BlockPosition(1,0),BlockPosition(1,1),BlockPosition(1,2),BlockPosition(1,3) };
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
	vector<BlockPosition> tiles = cells[0];
	vector<BlockPosition> movedTiles;
	for (BlockPosition pos : tiles) {
		BlockPosition newPos = BlockPosition(pos.row + rowOff, pos.col + colOff);
		movedTiles.push_back(newPos);
	}
	return movedTiles;
}
