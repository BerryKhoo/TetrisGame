#include <iostream>
#include <raylib.h>
#include <vector>
#include <random>
#include "game.h"
#include "grid.h"
#include "tetrisblock.h"

using namespace std;

Game::Game() {
	gameGrid = tetrisGrid();
	curBlock = BlockRandom();
	nextBlock = BlockRandom();
	blocks = AllBlocks();
}

//Next block
TetrisBlock Game::BlockRandom() {
	if (blocks.empty()) {
		blocks = AllBlocks();
	}
	int blockIndex = rand() % blocks.size();
	TetrisBlock nextBlock = blocks[blockIndex];
	blocks.erase(blocks.begin() + blockIndex); // Need to put iterator (pointer of a array, access provider of a container) to let erase know which element in the container.
	return nextBlock;
}

vector<TetrisBlock> Game::AllBlocks(){
	return {IBlock(), JBlock(), LBlock(), TBlock(), OBlock(), ZBlock(), SBlock()};
}

void Game::Draw() {
	gameGrid.Draw();
	curBlock.Draw();
}

void Game::ControlHandling() {

	int input = GetKeyPressed();

	switch (input) {
		case KEY_LEFT:
			curBlock.Movement(0, -1);
			if (DetectBlock() || CheckTiles() == false) {
				curBlock.Movement(0, 1);
			}
			break;
		case KEY_RIGHT:
			curBlock.Movement(0, 1);
			if (DetectBlock() || CheckTiles() == false) {
				curBlock.Movement(0, -1);
			}
			break;
		case KEY_DOWN:
			curBlock.Movement(1, 0);
			if (DetectBlock() || CheckTiles() == false) {
				curBlock.Movement(-1, 0);
			}
			break;
		case KEY_UP:
			curBlock.RotateClockwise();
			if (DetectBlock() || CheckTiles() == false) {
				curBlock.RotateAnticlockwise();
			}
	}
}

bool Game::OutskirtBlock(int row, int col) {
	if (row >= 0 && row < tetrisGrid().rowNum && col >= 0 && col < tetrisGrid().colNum) {
		return false;
	}
	return true;
}

bool Game::DetectBlock() { //Detect whether it is outside the grid
	vector<BlockPosition> tiles = curBlock.GetBlockPosition();
	for (BlockPosition item : tiles) {
		if (OutskirtBlock(item.row, item.col)) {
			return true;
		}
	}
	return false;
}
void Game::AutoDrop(){
	curBlock.Movement(1, 0);
	if (DetectBlock() || CheckTiles() == false) {
		curBlock.Movement(-1, 0);
		LockBlock();
	}
}

void Game::LockBlock() {
	vector<BlockPosition> tiles = curBlock.GetBlockPosition();
	for (BlockPosition item : tiles){
		gameGrid.grid[item.row][item.col] = curBlock.blockID; //Mark the block on the place.
	}
	ClearLines();
	curBlock = nextBlock;
	nextBlock = BlockRandom();
	
}

bool Game::CheckTiles() {
	vector<BlockPosition> tiles = curBlock.GetBlockPosition();
	for (BlockPosition item : tiles) {
		if (gameGrid.emptyCell(item.row, item.col) == false) { //False = cell occupied
			return false;
		}
	}
	return true;
}

void Game::ClearLines() {

	//Check the rows
	//If rows is full, trigger clear lines, make the row for all grid cell becomes 0
	//Moves down the row (-1)
	int clearRow = 0;

	for (int row = (gameGrid.rowNum - 1); row >= 0; row--) {
		if (CheckRow(row)) { //Will firstly check if got any rows need to be clear, if got, clear the current row and add the counter +1
			ClearRow(row);
			clearRow++;
		}
		else if (clearRow > 0) { //Every row clear, will move the row down once, hence it will run through all the rows and move down the row once (check every row)
			MoveRowDown(row, clearRow);
		}
	}

}

bool Game::CheckRow(int row) {
	int tilesCheck = 0;
	for (int col = 0; col < gameGrid.colNum; col++) {
		if (gameGrid.grid[row][col] == 0) {
			return false; // row is not filled
		}
		else {
			tilesCheck += 1;
		}	
	}
	if (tilesCheck == gameGrid.colNum) {
		return true; //all column for the row is filled.
	}
	return false;
}

void Game::ClearRow(int row) {
	for (int col = 0; col < gameGrid.colNum; col++) {
		gameGrid.grid[row][col] = 0;
	}
}

void Game::MoveRowDown(int row, int clearRow) {
	for (int col = 0; col < gameGrid.colNum; col++) {
		
		gameGrid.grid[row + clearRow][col] = gameGrid.grid[row][col]; //Move the row down, if row 18 is cleared (1 row is cleared), then the 19th row (18+1) will be replaced by the 18th row.
		gameGrid.grid[row][col] = 0;// Row 18 will fill with all 0.
	}
}