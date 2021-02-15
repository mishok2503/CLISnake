#include <iostream>
#include <conio.h>
 
using namespace std;
 
int main()
{
 	while (true)
	{
		std::cout << "123" << std::
     struct termios oldt,
     newt;
     int ch;
     tcgetattr( STDIN_FILENO, &oldt );
     newt = oldt;
     newt.c_lflag &= ~( ICANON | ECHO );
     tcsetattr( STDIN_FILENO, TCSANOW, &newt );
     ch = getchar();
     tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
     cout<<ch;
 }
}
