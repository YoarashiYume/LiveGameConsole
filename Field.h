#ifndef _FIELD_H_
#define _FIELD_H_
#include "Cell.h"
#include "Randomizer.h"
#include <vector>
#include <iostream>
#include <thread>
#include<chrono>
class Field
{
private:
	int size;
	std::vector<Cell> cellList;
	void findNeighbors(Cell & curr);
	static int countOfLiveCell;
public:
	Field(int size_);
	void startGame(int numberOfCycles);
	void print(int i_);
};
#endif // !_FIELD_H_