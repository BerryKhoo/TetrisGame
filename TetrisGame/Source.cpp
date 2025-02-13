#include <iostream>
#include <raylib.h>
#include "color.h"
#include "grid.h"
#include "tetrisblock.h"
#include "blockposition.h"

using namespace std;

int main() {

	InitWindow(300, 600, "Berry Tetris");
	SetTargetFPS(30);

	tetrisGrid grid = tetrisGrid();
	grid.printGrid();

	Colors blockColor = getColors();

	//Blocks
	TetrisBlock Lblock = LBlock();
	Lblock.Movement(4, 3);

	while (!WindowShouldClose()) {
		
		BeginDrawing();       
		ClearBackground(blockColor.white);
		grid.Draw();
		Lblock.Draw();
		EndDrawing();                             
	}

	CloseWindow();
	return 0;

}