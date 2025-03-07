#include <iostream>
#include <raylib.h>
#include <vector>
#include "color.h"
#include "grid.h"

using namespace std;

const Color grey = { 150,150,150,200 };
const Color white = { 255,255,255,255 };
const Color black = { 0,0,0,255 };
const Color blue = { 35,35,120,128 };
const Color red = { 233,28,28,255 };
const Color green = { 47,230,23,255 };
const Color yellow = { 237,237,4,255 };
const Color orange = { 226,117,17,255 };
const Color purple = { 166,0,247,255 };
const Color cyan = { 21,204,209,255 };

vector<Color> getBlockColor() {
	return { grey, blue, red, green, yellow, orange, purple, cyan};
};

vector<Color> getBgColor() {
	return { white, black};
};