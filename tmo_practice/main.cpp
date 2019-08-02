#include <cstdio>
#include <iostream>
#include "board.h"
#include "main.h"

using namespace std;

int main(int argc, char *argv[])
{
	cout << "Hello world!\n";

	struct pos {
		int x, y; 
		/*void operator=(const pos &t)
		{
			this->x = t.x;
			this->y = t.y;
		}*/
	};

	Board<pos> board(20, 20);
	//board.set_board(20, 20);
	//pos data = { 30, 40 };
	board.set_data({4,5});

	cout << board.getData().x << ", " << board.getData().y << endl;
	cout << board.getHeight() << ", " << board.getWidth() << endl;

	
	struct MyData
	{
		int a, b, c=10, d=20;
	};

	MyData myData  = { 1,2,3 };

	cout << myData.a << myData.b << myData.c << myData.d << endl;
	

	return 0;
}