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
			if (DetectBlock()) {
				curBlock.Movement(0, 1);
			}
			break;
		case KEY_RIGHT:
			curBlock.Movement(0, 1);
			if (DetectBlock()) {
				curBlock.Movement(0, -1);
			}
			break;
		case KEY_DOWN:
			curBlock.Movement(1, 0);
			if (DetectBlock()) {
				curBlock.Movement(-1, 0);
			}
			break;
		case KEY_UP:
			curBlock.RotateClockwise();
			if (DetectBlock()) {
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

bool Game::DetectBlock() {
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
	if (DetectBlock()) {
		curBlock.Movement(-1, 0);
	}
}