#include <iostream>
#include <raylib.h>
#include <vector>
#include <random>
#include "game.h"

using namespace std;

Game::Game() {
	gameGrid = tetrisGrid();
}

//Next block
TetrisBlock Game::BlockRandom() {
	if (blocks.empty()) {
		AllBlocks();
	}
	int blockIndex = rand() % blocks.size();
	TetrisBlock nextBlock = blocks[blockIndex];
	blocks.erase(blocks.begin() + blockIndex); // Need to put iterator (pointer of a array, access provider of a container) to let erase know which element in the container.
	return nextBlock;
}

vector<TetrisBlock> AllBlocks(){
	return {IBlock(), JBlock(), LBlock(), TBlock(), OBlock(), ZBlock(), SBlock()};
}