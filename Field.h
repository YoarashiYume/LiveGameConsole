#ifndef _FIELD_H_
#define _FIELD_H_
#include "Cell.h"
#include "Randomizer.h"

#include <vector>
#include <iostream>
#include <thread>
#include<chrono>

/**
\brief Сlass contains and updates information about cells
*/

class Field final
{
private:
	std::int32_t size; ///< field side
	std::vector<Cell> cellList; ///< cell storage
	static std::int32_t countOfLiveCell;///< current count of live cells
	/**
	\brief Method iterates cells to find neighbors
	\param curr Cell for which the search for neighbors is performed
	*/
	void findNeighbors(Cell & curr);
	
public:
	/**
	\brief Constructor
	\param size_ field side
	*/
	Field(std::int32_t size_);
	/**
	\brief Method starts "simulation"
	\param numberOfCycles number of simulation cycles
	*/
	void startGame(std::int32_t numberOfCycles);
	/**
	\brief Method prints the current state of the field to the console
	\param step current cycles
	*/
	void print(std::int32_t step);
};
#endif // !_FIELD_H_