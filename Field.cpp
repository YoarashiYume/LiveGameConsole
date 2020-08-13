#include "Field.h"

void Field::findNeighbors(Cell& curr)
{
	/*find neighbors for all cells*/
	for (auto& cell : cellList)
		curr.addNeighbors(cell);
}

Field::Field(int size_)
{
	Randomizer random;
	random.setRange(0, 3);
	this->size = size_;
	for (size_t x = 0; x < size; ++x)
		for (size_t y = 0; y < size; ++y)
		{
			cellList.push_back(Cell(x, y, random.getRandomValue() == 0 ? Cell::LIVE : Cell::DEAD));
			countOfLiveCell += cellList.back().getState() == Cell::LIVE ? 1 : 0;
		}
			//cellList.push_back(Cell(x, y, Cell::LIVE ));
	for (size_t i = 0; i < size*size; i++)
		this->findNeighbors(cellList[i]);

}

void Field::startGame(int numberOfCycles)
{
	this->print(-1);
	for (size_t i = 0; i < numberOfCycles; i++)
	{
		countOfLiveCell = 0;
		/*check and switch state*/
		for (auto& cell : cellList)
			cell.nextConfig();
		for (auto& cell : cellList)
		{
			cell.nextGeneration();
			countOfLiveCell += cell.getState() == Cell::LIVE ? 1 : 0;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		this->print(i);
	}
}

void Field::print(int i_)
{
	std::system("cls");
	std::cout << "generatin = " << i_ << " count of live cells = " << countOfLiveCell << std::endl;
	for (size_t i = 0; i < size * size; i++)
	{
		if (i % size == 0)
			std::cout << '\n';
		if (cellList[i].getState() == Cell::LIVE)
			std::cout << '*';
		else
			std::cout << '0';
	}
}
int Field::countOfLiveCell = 0;