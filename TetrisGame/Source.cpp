#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <raylib.h>
#include "color.h"
#include "game.h"

using namespace std;

double lastTime = 0;

bool DropdownTirgger() {
	double timeNow = GetTime();
	//Interval
	if (timeNow - lastTime > 0.5) {  
		lastTime = timeNow;
		return true;
	} 
	return false;
}

int main() {

	InitWindow(800, 700, "Berry Tetris");
	SetTargetFPS(30);
	
	Font score = LoadFontEx("Font/victor-pixel.ttf", 64, 0, 0);
	Font gameover = LoadFontEx("Font/victor-pixel.ttf", 64, 0, 0);
	vector<Color> bgColor = getBgColor();
	vector<Color> blockColor = getBlockColor();
	Game game = Game();
	
	while (!WindowShouldClose()) {

		game.ControlHandling();
		if (DropdownTirgger()) {
			game.AutoDrop();
		}
		
		BeginDrawing();       
		ClearBackground(bgColor[1]);
		game.Draw();
		if (game.gameOver) {
			const char* message = "Game Over!";
			DrawText(message, 180, 300, 80, red);
		}
		EndDrawing();                             
	}

	CloseWindow();
	return 0;

}