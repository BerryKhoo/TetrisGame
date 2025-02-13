#include <iostream>
#include <raylib.h>
#include <vector>
#include <map>
#include "color.h"
#include "grid.h"
#include "blockposition.h"

BlockPosition::BlockPosition(int row, int col) {
	//Assigning position of the blocks
	this->row = row; 
	this->col = col;
}
