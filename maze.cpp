#include <cstdbool>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <random>

#include "Stack.h"

enum Direction
{
	Center,
	West,
	East,
	North,
	South,
	NorthWest,
	NorthEast,
	SouthWest,
	SouthEast
};

struct Position
{
	int X;
	int Y;

	Position(int x = 0, int y = 0)
	{
		X = x;
		Y = y;
	}

	Position(const Position & position)
	{
		X = position.X;
		Y = position.Y;
	}

	Position & operator=(const Position & position)
	{
		if(&position == this)
		{
			return *this;
		}

		X = position.X;
		Y = position.Y;
	}

	~Position()
	{

	}

	friend std::ostream & operator<<(std::ostream & os, const Position & position)
	{
		os << "(" << position.X << ", " << position.Y << ")";
		return os;
	}
};

class Point
{
private:
	Position _Position;

public:
	Point(int x = 0, int y = 0)
	{
		_Position = Position(x, y);
	}

	Point(const Point & point)
	{
		_Position = point._Position;
	}

	Point & operator=(const Point & point)
	{
		if(&point == this)
		{
			return *this;
		}

		_Position = point._Position;
		return *this;
	}

	~Point()
	{

	}

	void Move(enum Direction direction)
	{
		int newX = _Position.X;
		int newY = _Position.Y;

		switch (direction)
		{
		case West:
			newY--;
			break;
		case East:
			newY++;
			break;
		case North:
			newX--;
			break;
		case South:
			newX++;
			break;
		case NorthWest:
			newX--;
			newY--;
			break;
		case NorthEast:
			newX--;
			newY++;
			break;
		case SouthWest:
			newX++;
			newY--;
			break;
		case SouthEast:
			newX++;
			newY++;
			break;
		default:
			break;
		}

		_Position.X = newX;
		_Position.Y = newY;
	}

	Position GetPosition() const
	{
		return _Position;
	}
};

const int32_t MaxRowCount = 30;
const int32_t MaxColCount = 30;

bool GetRowAndColCount(int &rows, int &cols)
{
	try
	{
		std::string input;

		std::cout << "请输入迷宫行数("
			 << "1~" << MaxRowCount << "): ";
		std::cin >> input;
		rows = stoi(input);
		if (rows == 0 || rows > MaxRowCount)
		{
			return false;
		}

		std::cout << "请输入迷宫列数("
			 << "1~" << MaxColCount << "): ";
		std::cin >> input;
		cols = stoi(input);
		if (cols == 0 || cols > MaxColCount)
		{
			return false;
		}
	}
	catch (const std::exception &e)
	{
		return false;
	}

	return true;
}

int *GenerateMaze(int rows, int cols)
{
	int *maze = new int[rows * cols];
	int *tempMaze = new int[(rows + 2) * (cols + 2)];
	Point point;
	hy::Stack<Position> stack;
	std::default_random_engine random;

	memset(maze, 0, sizeof(int) * rows * cols);
	memset(maze, 0, sizeof(int) * (rows + 2) * (cols + 2));
	
	

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			*(maze + cols * i + j) = random() % 2;
		}
	}

	return maze;
}

void DisplayMaze(int *maze, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << *(maze + cols * i + j) << " ";
		}
		std::cout << std::endl;
	}
}

void ThroughMaze()
{
	std::cout << "ThroughMaze(): 已穿越随机迷宫" << std::endl;
}

int main()
{
	int rows = -1;
	int cols = -1;
	int *maze = nullptr;

	if (!GetRowAndColCount(rows, cols))
	{
		std::cout << "未输入有效的迷宫行数或列数，程序退出。" << std::endl;
		return EXIT_SUCCESS;
	}

	maze = GenerateMaze(rows, cols);
	DisplayMaze(maze, rows, cols);
	ThroughMaze();

	delete[] maze;

	return EXIT_SUCCESS;
}