#ifndef SNAKE_H
#define SNAKE_H

#include <list>
#include <utility>

class Snake
{
private:

	std::list< std::pair<int, int> > body, eaten, lost_body;
	std::pair<int, int> speed, food;
	
	const int width, heigth;
	
	bool alive = true;
	
	void set_food();
	void drop();
	bool is_in_list(const std::list< std::pair<int, int> >&, const std::pair<int, int>&) const;
	
public:

	Snake(int width, int heigth);
	
	void get_key();
	void draw() const;
	void move();
	
	bool is_alive() const;
};

#endif //SNAKE_H