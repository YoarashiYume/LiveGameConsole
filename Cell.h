#ifndef _CELL_H_
#define _CELL_H_
#include <algorithm>
#include <utility>
#include <vector>
#include <math.h>

/**
\brief Сlass stores information about the cell of the field
*/

class Cell final
{
public:
	using coordinate_type = std::int32_t;
	/**
	\brief Sell states
	*/	
	enum Configuration
	{
		LIVE,///< cell is active 
		DEAD///< cell is inactive
	};
private:
	/**
	\brief Method switches cell state
	*/
	void changeState();
	
	Configuration state; ///< Current state of the cell
	Configuration nextState;///< Next state of the cell
	
	std::pair<coordinate_type, coordinate_type> location;///< Cell coordinates
	std::vector<std::reference_wrapper<const Cell>> neighbors; ///< Array of neighbors cells 
public:
	/**
	\brief Constructor
	\param x,y Cell coordinates
	\param state_ Cell cell state
	*/
	Cell(const coordinate_type x_,const coordinate_type y_,const Configuration state_);
	/**
	\brief Method adds a link to the neighboring cell
	Method checks if the "other" cell is adjacent. and, if so, adds a link
	\param other other Cell
	*/
	void addNeighbors(const Cell& other);
	/**
	\brief Method returns x coordinate
	\return x coordinate
	*/
	coordinate_type getX() const;
	/**
	\brief Method returns y coordinate
	\return y coordinate
	*/
	coordinate_type getY() const;
	/**
	\brief Method returns cell state
	\return cell state
	*/
	Configuration getState() const;
	/**
	\brief Method calculates the next cell state
	if cell LIVE => it will stay live, if it has 2-3 neighbors
	if cell DEAD => it switch into LIVE, if it has 3 neighbors
	*/
	void nextConfig(); //check state in next generation
	/**
	\brief Method changes the current state of the cell to the following
	*/
	void nextGeneration(); // change state

};
#endif // !_CELL_H_
