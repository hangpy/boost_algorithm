// BAEK_14503. 로봇 청소기

#include <iostream>

using namespace std;

int N, M, MAP[50][50];
//	북, 동, 남, 서
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
struct pos { int y, x, d; };
pos robot;

int backDir[4] = { 2, 3, 0, 1 };
int leftDir[4] = { 3, 0, 1, 2 };

int main()
{
 
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	cin >> robot.y >> robot.x >> robot.d;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> MAP[y][x];
		}
	}

	int clean = 0;
	int blocked = 0;
	while (1)
	{
		int cy = robot.y, cx = robot.x, cd = robot.d;
		if (MAP[cy][cx] != 2)
		{
			MAP[cy][cx] = 2;
			clean++;
		}

		int ny = cy + dy[leftDir[cd]], nx = cx + dx[leftDir[cd]];
		
		if (MAP[ny][nx] == 0)
		{
			robot.y = ny, robot.x = nx, robot.d = leftDir[cd];
			blocked = 0;
			continue;
		}
		
		// 네 방향 모두 
		if (blocked == 4) 
		{
			// 후진 가능
			int ny = cy + dy[backDir[cd]], nx = cx + dx[backDir[cd]];
		
			if (MAP[ny][nx] != 1) // 후진 가능
			{
				robot.y = ny, robot.x = nx;
				blocked = 0;
				continue;
			}
			// 후진 불가
			else break;
		}

		if (MAP[ny][nx] == 2 || MAP[ny][nx] == 1 || ny > N - 1 || ny < 0 || nx > M-1 || nx < 0)
		{
			blocked++;
			robot.d = leftDir[cd];
			continue;
		}
	}


	cout << clean << endl;

	return 0;
}