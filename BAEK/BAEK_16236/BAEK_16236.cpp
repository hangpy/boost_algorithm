// BAEK_16236. 아기상어

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int N, MAP[20][20], V[20][20];
struct pos { int y, x; };
struct qpos { int y, x, t; };
struct info { int y, x, size, live; };


int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
pos shark_pos;

// 타겟까지 도달하기까지 걸리는 시간 반환: 만약 0이면 도달할 수 없다는 뜻.
int reach(const pos &cur, int sharkSize)
{
	memset(V, 0, sizeof(V));

	queue<qpos> q; q.push({cur.y, cur.x, 0});

	V[cur.y][cur.x] = 1;

	bool canReach = false;
	int result = numeric_limits<int>::max();
	pos toEat = {0, 0};

	while (!q.empty())
	{
		int cy = q.front().y, cx = q.front().x, ct = q.front().t; q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i], nx = cx + dx[i];
			if (ny < 0 || ny > N - 1 || nx < 0 || nx > N - 1) continue;
			if (MAP[ny][nx] > sharkSize || V[ny][nx] >= 1) continue;
			
			q.push({ ny, nx, ct+1 });
			V[ny][nx] = 1;

			if (0 < MAP[ny][nx] && MAP[ny][nx] < sharkSize)
			{
				if (ct + 1 > result) break;
				canReach = true;
				if (ct + 1 < result) result = ct + 1, toEat = { ny, nx };
				else if(ct + 1 == result) // 같을 때
				{
					if (ny < toEat.y) toEat = { ny, nx };
					else if(ny == toEat.y)
					{
						if (nx < toEat.x) toEat = { ny, nx };
					}
					else;
				}
				else;
			}
		}
	}

	if (canReach) 
	{
		MAP[toEat.y][toEat.x] = 0;
		shark_pos = { toEat.y, toEat.x };
		return result;
	}
	else return 0;
}

int main()
{
	cin >> N;	

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			int a;
			cin >> a;
			if (a == 9) shark_pos = { y, x }, MAP[y][x] = 0;
			else MAP[y][x] = a;
		}
	}

	int time = 0, eat = 0;
	int sharkSize = 2;

	while (true)
	{
		int result = reach(shark_pos, sharkSize);
		if (result != 0)
		{
			time += result;
			eat++;
			if (eat == sharkSize) sharkSize++, eat = 0;
		}
		else break;
	}

	cout << time << endl;

	return 0;
}