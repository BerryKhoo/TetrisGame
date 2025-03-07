#pragma once
#include <raylib.h>
#include <vector>
#include <iostream>

using namespace std;

//Specifying own colors
extern const Color blue;
extern const Color red;
extern const Color green;
extern const Color yellow;
extern const Color cyan;
extern const Color orange;
extern const Color purple;
extern const Color grey;
extern const Color black;
extern const Color white;

vector<Color> getBlockColor();
vector<Color> getBgColor();