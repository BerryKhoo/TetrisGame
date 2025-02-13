#pragma once
#include <iostream>
#include <raylib.h>
#include <vector>
#include <map>
#include "color.h"
#include "grid.h"

class BlockPosition
{
public:
	BlockPosition(int row, int col);
	int row;
	int col;
};