#include <cstdio>
#include <queue>

using namespace std;

struct pos
{
	int row, col;
};
struct change
{
	int time, direc;
};

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int map[101][101], N, K, L;
queue<pos> snake;
queue<change> changes;
int DIR, TIME;

int changeDirection(int leftOrRight)
{
	if (leftOrRight == 0) // left
	{
		if (DIR > 0) return --DIR;
		else return 3;
	}
	else
	{
		if (DIR < 3) return ++DIR;
		else return 0;
	}
}

int main()
{
	scanf("%d", &N); // 2 <= N <= 100
	scanf("%d", &K); // 0 <= K <= 100
	for (int k = 1; k <= K; k++)
	{
		int row, col;
		scanf("%d %d", &row, &col);
		map[row][col] = 2;
	}
	scanf("%d", &L); // 1 <= L <= 100
	for (int l = 1; l <= L; l++)
	{
		int time;
		char d;
		scanf("%d %c", &time, &d);
		// 0: left, 1: right
		if (d == 'L') changes.push({ time, 0 });
		else changes.push({ time, 1 });
	}

	// drow[0], dcol[0]
	DIR = 0;
	TIME = 0;
	map[1][1] = 1;
	snake.push({ 1,1 });
	pos head = { 1, 1 };
	while (true)
	{
		TIME++;
		
		int nrow = head.row + dy[DIR];
		int ncol = head.col + dx[DIR];

		// if crush to the wall or to snake itself
		if (nrow > N || nrow < 1 || ncol > N || ncol < 1 ||
			map[nrow][ncol] == 1) break;

		// if there is no apple, erase tail
		if (map[nrow][ncol] != 2)
		{
			pos tail = snake.front();
			map[tail.row][tail.col] = 0;
			snake.pop();
		}

		map[nrow][ncol] = 1;
		snake.push({ nrow, ncol });
		head = { nrow, ncol };

		// if it is time to change direction, pop node from changes and change direction
		// !!!WARNING!!!

		/*
		if we don't limit if(!changes.empty()) it will be faced with below error.
		Expression: deque iterator not dereferencable
		*/
		if (!changes.empty())
		{
			if (TIME == changes.front().time)
			{
				DIR = changeDirection(changes.front().direc);
				changes.pop();
			}
		}
	}

	printf("%d\n", TIME);

    return 0;
}

