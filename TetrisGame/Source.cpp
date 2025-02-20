#include <iostream>
#include <raylib.h>
#include "color.h"
#include "game.h"

using namespace std;

int main() {

	InitWindow(300, 600, "Berry Tetris");
	SetTargetFPS(30);

	Colors blockColor = getColors();

	Game game = Game();
	
	while (!WindowShouldClose()) {
		
		game.ControlHandling();
		BeginDrawing();       
		ClearBackground(blockColor.white);
		game.Draw();
		EndDrawing();                             
	}

	CloseWindow();
	return 0;

}