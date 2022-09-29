#include "Cell.h"

Cell::Cell(const Cell::coordinate_type x_,const Cell::coordinate_type y_,const Configuration state_)
	:location({x_, y_}), state(state_), nextState{Cell::Configuration::DEAD}
{

}

void Cell::changeState()
{
	this->state = this->state == LIVE ? DEAD : LIVE;
}
/*add neighbors cells
neighbors - cell with a coordinate that differs from the current one by 1 in one or more coordinates
*/
void Cell::addNeighbors(const Cell& other)
{
	if (this->neighbors.size() == 8)
		return;
	if (abs(this->getX() - other.getX()) <= 1 && std::abs(this->getY() - other.getY()) <= 1)
		if (this->getX() != other.getX() || this->getY() != other.getY())
			neighbors.emplace_back(std::ref(other));
}

Cell::coordinate_type Cell::getX() const
{
	return location.first;
}

Cell::coordinate_type Cell::getY() const
{
	return location.second;
}

Cell::Configuration Cell::getState() const
{
	return state;
}

void Cell::nextConfig()
{
	/*check next state
	if cell LIVE => it will stay live, if it has 2-3 neighbors
	if cell DEAD => it switch into LIVE, if it has 3 neighbors*/
	int liveCell = std::count_if(neighbors.begin(), neighbors.end(), [&](decltype(neighbors)::value_type& el)
	{
		return el.get().getState() == Cell::LIVE;
	});
	if (this->state == LIVE)
		this->nextState = liveCell == 2 || liveCell == 3 ? LIVE : DEAD;
	else
		this->nextState = liveCell == 3 ? LIVE : DEAD;
}

void Cell::nextGeneration()
{
	state = nextState;
}
