#include "Snake.h"

#include <iostream>
#include <utility>
#include <list>
#include <conio.h>
#include <windows.h>
#include <ctime>

Snake::Snake(int width, int heigth) : width(width + 2), heigth(heigth + 2)
{
	srand(time(0));
	body.push_back({width / 2, heigth / 2});
	set_food();
}

bool Snake::is_in_list(const std::list< std::pair<int, int> >& l, const std::pair<int, int>& p) const
{
	for (const auto& i : l)
		if (i == p)
			return true;
	return false;
}

void Snake::set_food()
{
	bool in_snake = true;
	while (in_snake)
	{
		food.first = rand() % (width - 2) + 1;
		food.second = rand() % (heigth - 2) + 1;
		in_snake = is_in_list(body, food);	
	}
}

void Snake::get_key()
{
	if (_kbhit())
	{
		switch(getch())
		{
		case 'w':
			if (speed != std::pair<int, int>{0, 1})
				speed = {0, -1};
			break;
		case 's':
			if (speed != std::pair<int, int>{0, -1})
				speed = {0, 1};
			break;
		case 'a':
			if (speed != std::pair<int, int>{1, 0})
				speed = {-1, 0};
			break;
		case 'd':
			if (speed != std::pair<int, int>{-1, 0})
				speed = {1, 0};
			break;
		case ' ':
			drop();
			break;
		}
	}
}

void Snake::drop()
{
	if (body.size() > 1)
	{
		lost_body.push_back(body.back());
		body.pop_back();
	}
}

void Snake::move()
{
	std::pair<int, int> np = {body.front().first + speed.first, body.front().second + speed.second};
	if (is_in_list(body, np) && speed != std::pair<int, int>{0, 0})
		alive = false;
	if (is_in_list(lost_body, np))
		alive = false;
	body.push_front(np);
	if (body.front() == food)
	{
		eaten.push_back(food);
		set_food();
	}
	if (body.front().first % (width - 1) == 0 || body.front().second % (heigth - 1) == 0)
		alive = false;
	if (body.back() == eaten.front())
		eaten.pop_front();
	else
		body.pop_back();
}

void Snake::draw() const
{
	system("cls");
	for (int i=0; i < heigth; ++i)
	{
		for (int j=0; j < width; ++j)
		{
			bool body_cell = is_in_list(body, {j, i});
			bool eaten_cell = false;
			if (body_cell)
			{
    			if (is_in_list(eaten, {j, i}))
    			{
    				body_cell = false;
    				eaten_cell = true;
    			}
    		}
			if (body_cell)
				std::cout << 'o';
			else if (eaten_cell)
				std::cout << 'O';
			else if (is_in_list(lost_body, {j, i}))
				std::cout << 'x';
			else if (j == food.first && i == food.second)
				std::cout << '%';
			else
				std::cout << (i % (heigth - 1) && j % (width - 1) ? ' ' : '#');//% big time, but small code
		}
		std::cout << "\n";
	}
	Sleep(alive ? 120 : 2000);
}

bool Snake::is_alive() const
{
	return alive;
}