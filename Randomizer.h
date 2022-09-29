#ifndef _RANDOMIZER_H_
#define _RANDOMIZER_H_

#include <random>
#include <chrono>

/**
\brief Simple Randomizer
*/


class Randomizer
{
private:
	std::default_random_engine generator; ///< generator
	int from, to; ///< range of generated values
	/**
	\brief Checks range of generated values
	if 'to' less than 'from', then swaps the values
	*/
	void checkRange();
public:
	/**
	\brief Default constructor
	*/
	Randomizer();
	/**
	\brief Constructor
	\param from_ start of value range
	\param to_ end of value range
	*/
	Randomizer(int from_, int to_);
	/**
	\brief method generates a random value
	\return random value
	*/
	int getRandomValue();
	/**
	\brief the method updates the range
	\param from_ new start of value range
	\param to_ new end of value range
	*/
	void setRange(int from_,int to_);
	
	/**
	\brief Default destructor
	*/
	virtual ~Randomizer() = default;

};

#endif