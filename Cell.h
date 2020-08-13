#ifndef _CELL_H_
#define _CELL_H_
#include <utility>
#include <vector>
#include <math.h>
#include <algorithm>
class Cell
{
public:
	enum Configuration
	{
		LIVE,
		DEAD
	};
	Cell(int x_, int y_, Configuration state_);
	void addNeighbors(Cell& other);
	int getX();
	int getY();
	Configuration getState();
	void nextConfig(); //check state in next generation
	void nextGeneration(); // change state
private:
	void changeState();
	Configuration state;
	Configuration nextState;
	std::pair<int, int> location;
	std::vector<std::reference_wrapper<Cell>> neighbors;
};
#endif // !_CELL_H_