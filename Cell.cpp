#include "Cell.h"

Cell::Cell(int x_, int y_, Configuration state_)
{
	this->location.first = x_;
	this->location.second = y_;
	this->state = state_;
	this->nextState = DEAD;
}

void Cell::changeState()
{
	this->state = this->state == LIVE ? DEAD : LIVE;
}
/*add neighbors cells*/
void Cell::addNeighbors(Cell& other)
{
	if (this->neighbors.size() == 8)
		return;
	if (abs(this->getX() - other.getX()) <= 1 && abs(this->getY() - other.getY()) <= 1)
		if (this->getX() != other.getX() || this->getY() != other.getY())
			/*for some reason it doesn`t work*/
		/*if (find_if(neighbors.begin(), neighbors.end(), [&other](auto& curr) { 
		return curr.get().getX() == other.getX() && curr.get().getY() == other.getY();
			}) == neighbors.end())*/
			neighbors.push_back(std::ref(other));
}

int Cell::getX()
{
	return location.first;
}

int Cell::getY()
{
	return location.second;
}

Cell::Configuration Cell::getState()
{
	return state;
}

void Cell::nextConfig()
{
	/*check next state
	if cell LIVE => it will stay live, if it has 2-3 neighbors
	if cell DEAD => it switch into LIVE, if it has 3 neighbors*/
	int liveCell = 0;
	for (auto & el : neighbors)
		liveCell += el.get().getState() == Cell::LIVE ? 1 : 0;
	if (this->state == LIVE)
		this->nextState = liveCell == 2 || liveCell == 3 ? LIVE : DEAD;
	else
		this->nextState = liveCell == 3 ? LIVE : DEAD;
}

void Cell::nextGeneration()
{
	state = nextState;
}
