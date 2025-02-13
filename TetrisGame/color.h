#pragma once
#include <raylib.h>
#include <vector>
#include <iostream>

using namespace std;

//Specifying own colors
//vector<Color> getColors();
struct Colors;
Colors getColors();

struct Colors {
	Color blue = {35,35,120,128};
	Color red = {233,28,28,255};
	Color green = {47,230,23,255};
	Color grey = {150,150,150,200};
	Color white = {255,255,255,255};
	Color black = {0,0,0,255};
};