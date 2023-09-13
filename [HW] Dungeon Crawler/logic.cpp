#include <iostream>
#include <fstream>
#include <string>
#include "logic.h"

using std::cout, std::endl, std::ifstream, std::string;

/**
 * TODO: Student implement this function
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * @param   fileName    File name of dungeon level.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference to set starting position.
 * @return  pointer to 2D dynamic array representation of dungeon map with player's location., or nullptr if loading fails for any reason
 * @updates  maxRow, maxCol, player
 */
char** loadLevel(const string& fileName, int& maxRow, int& maxCol, Player& player) {
	ifstream inFS;
	inFS.open(fileName);
	
	if(!inFS.is_open()) {
		return nullptr;
	}
	inFS >> maxRow;
	inFS >> maxCol;
	if (inFS.fail()) {
		return nullptr;
	}
	inFS >> player.row;
	inFS >> player.col;
	if (inFS.fail()) {
		return nullptr;
	}
	
	char** map = createMap(maxRow, maxCol);
	for (int i = 0; i < maxRow; ++i) {
		for (int j = 0; j < maxCol; ++j) {
			 inFS >> map[i][j];
			 
		}
	}
	 map[player.row][player.col] = TILE_PLAYER;
    return map;
	
}

/**
 * TODO: Student implement this function
 * Translate the character direction input by the user into row or column change.
 * That is, updates the nextRow or nextCol according to the player's movement direction.
 * @param   input       Character input by the user which translates to a direction.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @updates  nextRow, nextCol
 */
void getDirection(char input, int& nextRow, int& nextCol) {
	if (input == MOVE_UP) {
		 nextRow -= 1;
	} else if (input == MOVE_DOWN) {
		nextRow += 1;
	}else if (input == MOVE_LEFT) {
		nextCol -= 1;
	}else if (input == MOVE_RIGHT) {
		nextCol += 1;
	} else {
		nextRow = nextRow;
		nextCol = nextCol;
	}
	
    
}

/**
 * TODO: [suggested] Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @return  2D map array for the dungeon level, holds char type.
 */
 
 //Do FIRST
char** createMap(int maxRow, int maxCol) {
	char** map = new char*[maxRow];
	bool fail = false;
	
	for (int i = 0; i < maxRow; ++i) {
		map[i] = new char[maxCol];
		
		if (map[i] == nullptr) {
			fail = true;
	} 
	}
	
	
	if (fail) {
		deleteMap(map, maxRow);
		return map;
		
	}
	
	
	
	for (int i = 0; i < maxRow; ++i) {
		for (int j = 0; j < maxCol; ++j) {
			 map[i][j] = TILE_OPEN;
		}
	}
			
	
	return map;
}

/**
 * TODO: Student implement this function
 * Deallocates the 2D map array.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @return None
 * @update map, maxRow
 */
void deleteMap(char**& map, int& maxRow) {
	if (map != nullptr) {
    for(int i = 0; i < maxRow; ++i) {
		delete [] map[i];
	}
	delete [] map;
	map = nullptr;
	maxRow = 0;
	}
}

/**
 * TODO: Student implement this function
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * @return  pointer to a dynamically-allocated 2D array (map) that has twice as many columns and rows in size.
 * @update maxRow, maxCol
 */
 
char** resizeMap(char** map, int& maxRow, int& maxCol) {
	if (isdigit(maxRow) && isdigit(maxCol) && maxRow > 0 && maxCol > 0) {
		
	bool fail = false;
	if (map == nullptr) {
	return map;
	}
		
	
	
	int newRow = maxRow * 2;
	int newCol = maxCol * 2;
	
	
	char** map2 = new char*[newRow];
	
	
	for (int i = 0; i < newRow; ++i) {
		map2[i] = new char[newCol];
		
		if (map2[i] == nullptr) {
			fail = true;
	 } 
	}
	if (fail) {
		deleteMap(map2, maxRow);
		return map2;
	}
	
	
	
	//A
	for (int i = 0; i < maxRow; ++i) {
		for (int j = 0; j < maxCol; ++j) {
			 map2[i][j] = map[i][j];
		}
	}
	//B
	for (int i = 0; i < maxRow; ++i) {
		for (int j = maxCol; j < newCol; ++j) {
			 map2[i][j] = map[i][j-maxCol];
			 if(map2[i][j] == TILE_PLAYER) {
				 map2[i][j] = TILE_OPEN;
			 }
		}
	}
	//C
	for (int i = maxRow; i < newRow; ++i) {
		for (int j = 0; j < maxCol; ++j) {
			 map2[i][j] = map[i-maxRow][j];
			 if(map2[i][j] == TILE_PLAYER) {
				 map2[i][j] = TILE_OPEN;
			 }
		}
	}
	
	//D
	for (int i = maxRow; i < newRow; ++i) {
		for (int j = maxCol; j < newCol; ++j) {
			 map2[i][j] = map[i-maxRow][j-maxCol];
			 if(map2[i][j] == TILE_PLAYER) {
				 map2[i][j] = TILE_OPEN;
			 }
		}
	}	
	
	
	
	
	deleteMap(map, maxRow);
	maxRow = newRow;
	maxCol = newCol;
    return map2;
	} else {
		return nullptr;
	}
}

/**
 * TODO: Student implement this function
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure. 
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 * @update map contents, player
 */
int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol) {
	int tempStatus;
	if(map == nullptr)
	{ return STATUS_STAY;
	}
	if (nextRow >= 0 && nextRow < maxRow && nextCol >= 0 && nextCol < maxCol) {
	if (map[nextRow][nextCol] == TILE_MONSTER || map[nextRow][nextCol] == TILE_PILLAR) {
		nextRow = player.row;
		nextCol = player.col;
		return STATUS_STAY;

	} else if (map[nextRow][nextCol] == TILE_TREASURE) {
		tempStatus = STATUS_TREASURE;
		player.treasure++;
	} else if (map[nextRow][nextCol] == TILE_AMULET) {
		tempStatus = STATUS_AMULET;
	} else if (map[nextRow][nextCol] == TILE_DOOR) {
		tempStatus = STATUS_LEAVE;
	} else if (map[nextRow][nextCol] == TILE_EXIT ) {
		if (player.treasure >= 1) {
		tempStatus = STATUS_ESCAPE;
		} else {
		nextRow = player.row;
		nextCol = player.col;
		return STATUS_STAY;
		}
	}
		map[player.row][player.col] = TILE_OPEN;
		player.row = nextRow;
		player.col = nextCol;
		map[player.row][player.col] = TILE_PLAYER;
		
	
    return tempStatus;
	} else { 
	return STATUS_STAY;
	}
	
}

/**
 * TODO: Student implement this function
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the monster does not move.
 * If we see a monster before an obstacle, the monster moves one tile toward the player.
 * We should update the map as the monster moves.
 * At the end, we check if a monster has moved onto the player's tile.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference for current location.
 * @return  Boolean value indicating player status: true if monster reaches the player, false if not.
 * @update map contents
 */
 //up not working properley test 6g(monsters can see through monsters)/6h
bool doMonsterAttack(char** map, int maxRow, int maxCol, const Player& player) {
	//check up DONT WORK
	bool yehaw = false;
	for(int i = player.row; i >= 0; i--) {
		char cur = map[i][player.col];
		if (cur == TILE_PILLAR) {
		break;
		}
		else if (cur == TILE_MONSTER) {
			map[i + 1][player.col] = TILE_MONSTER;
			map[i][player.col] = TILE_OPEN;
			
		}
	}
	if (map[player.row][player.col] == TILE_MONSTER) {
		yehaw = true;
	} 
	//down
	for(int i = player.row; i < maxRow; ++i) {
		char cur = map[i][player.col];
		if (cur == TILE_PILLAR) {
		break;
		}
		else if (cur == TILE_MONSTER) {
			map[i - 1][player.col] = TILE_MONSTER;
			map[i][player.col] = TILE_OPEN;
			
		}
	}
	if (map[player.row][player.col] == TILE_MONSTER) {
		yehaw = true;
	} 
	//left DONT WORK
	for(int i = player.col; i >= 0; i--) {
		char cur = map[player.row][i];
		if (cur == TILE_PILLAR) {
		break;
		}
		else if (cur == TILE_MONSTER) {
			map[player.row][i + 1] = TILE_MONSTER;
			map[player.row][i] = TILE_OPEN;
			
		}
	}
	if (map[player.row][player.col] == TILE_MONSTER) {
		yehaw = true;
	} 
	//right
	for(int i = player.col; i < maxCol; ++i) {
		char cur = map[player.row][i];
		if (cur == TILE_PILLAR) {
		break;
		}
		else if (cur == TILE_MONSTER) {
			map[player.row][i - 1] = TILE_MONSTER;
			map[player.row][i] = TILE_OPEN;
			
		}
	}
			
		
	if (map[player.row][player.col] == TILE_MONSTER) {
		yehaw = true;
	} 
	
	if (yehaw) {
	return true;}
	else {
		return false;
	}
}
