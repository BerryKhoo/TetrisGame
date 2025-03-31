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
	
	Font score = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
	vector<Color> bgColor = getBgColor();
	Game game = Game();
	
	while (!WindowShouldClose()) {

		game.ControlHandling();
		if (DropdownTirgger()) {
			game.AutoDrop();
		}
		BeginDrawing();       
		ClearBackground(bgColor[1]);
		DrawTextEx(score, "Score", {525, 60}, 40, 2, white);
		game.Draw();
		EndDrawing();                             
	}

	CloseWindow();
	return 0;

}