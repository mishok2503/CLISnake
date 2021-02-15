#include "Snake.h"
 
int main()
{
	Snake snake(20, 20);
    while(snake.is_alive())
    {
        snake.draw();
        snake.move();
        snake.get_key();
    }
}