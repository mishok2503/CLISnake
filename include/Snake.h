#ifndef SNAKE_H
#define SNAKE_H

#include <list>
#include <utility>

class Snake
{
private:

	std::list< std::pair<int, int> > body;

	const int width, heigth;

public:

	Snake(int width, int heigth);
};

#endif //SNAKE_H