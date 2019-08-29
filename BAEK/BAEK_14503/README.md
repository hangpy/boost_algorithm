

### &#128526;[문제 링크](https://www.acmicpc.net/problem/14503)

<br>

<br>

<br>

## 시간

40분 컷.

`0 ms`, `1996 kb`

<br>

<br>

<br>

## 접근법

처음에 문제 자체를 이해하는데 다소 무리가 있었던 문제다. 특히 현재 방향을 기준으로 왼쪽부터 탐색하는데, 네 방향이 모두 청소 불가할 경우를 이해하는데 좀 애매했다.

<br>

<br>

<br>

## 코드

```cpp
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
		
		// 네 방향 모두 막혔음을 확인한 생태에서 후진 여부를 판단
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
```

<br>

<br>

<br>

