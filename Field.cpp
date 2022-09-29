#include "Field.h"

void Field::findNeighbors(Cell& curr)
{
	/*find neighbors for all cells*/
	auto currX = curr.getX();
	auto currY = curr.getY();
	constexpr std::array<std::tuple<std::int8_t, std::int8_t>, 8> arr =
	{
		std::make_tuple(-1,0),
		std::make_tuple(-1,1),
		std::make_tuple(0,1),
		std::make_tuple(1,1),
		std::make_tuple(0,1),
		std::make_tuple(1,-1),
		std::make_tuple(0,-1),
		std::make_tuple(-1,-1)

	};
	for (auto& el : arr)
	{
		std::int64_t nextX = static_cast<int64_t>(currX + std::get<0>(el));
		std::int64_t nextY = static_cast<int64_t>(currY + std::get<0>(el));
		if (nextX >= 0 && nextY >= 0 && nextX < size && nextY < size)
			curr.addNeighbors(cellList.at(nextY + nextX * this->size));
	}
}

Field::Field(std::int32_t size_)
	:size(size_)
{
	Randomizer random;
	random.setRange(0, 3);
	for (size_t x = 0; x < size; ++x)
		for (size_t y = 0; y < size; ++y)
		{
			cellList.emplace_back(Cell(x, y, random.getRandomValue() == 0 ? Cell::LIVE : Cell::DEAD));
			if (cellList.back().getState() == Cell::LIVE)
				++countOfLiveCell;
		}
	for (size_t i = 0; i < size*size; i++)
		this->findNeighbors(cellList.at(i));

}

void Field::startGame(std::int32_t numberOfCycles)
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
			if (cell.getState() == Cell::LIVE)
				++countOfLiveCell;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		this->print(i);
	}
}

void Field::print(std::int32_t step)
{
	std::system("cls");
	std::cout << "generatin = " << step << " count of live cells = " << countOfLiveCell << std::endl;
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
std::int32_t Field::countOfLiveCell = 0;