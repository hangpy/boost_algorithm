

### &#128526;[문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpLlKAQ4DFAUq)

<br>

<br>

<br>

## 시간

1시간 20분. 실수만 하지 않았으면 1시간 미만 컷이었는데 또 실수가 컸다...

`9ms`, `12,548 kb`

<br>

<br>

<br>

## 접근법

처음에는 DFS로 접근했다. 하지만 방문한 곳을 체크하고 중복 방문을 하지 않는 로직을 했을 때 가야할 곳에 방문점에 막혀 가지 못하는 상황이 생겼다. 이에 방문점은 체크하지만 체크된 방문점의 곳은 카운트 하지 않는 방식으로 바꿨지만 이는 또 시간초과를 야기했다.

그래서 바로 바꾼 것이 BFS. BFS로 할 경우, 방문했던 곳을 가지 않더라도 가야할 곳은 모두 갈 수 있다. 하지만 미처 방문한 곳을 체크하지 않은 시점에서 큐에 다음 방문점을 넣을 수 있는 중복 문제는 여전히 존재하기 때문에 일단 넣고 꺼냈을 때 방문하지 않은 곳이면 카운트를 올리는 방식으로 풀 수 있었다.

<br>

<br>

<br>

## 코드

```cpp
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int T, N, M, R, C, L, MAP[50][50], V[50][50];
// 위부터 시계방향
int isOpen[8][4] =
{
	{0,0,0,0},
	{1,1,1,1},
	{1,0,1,0},
	{0,1,0,1},
	{1,1,0,0},
	{0,1,1,0},
	{0,0,1,1},
	{1,0,0,1},
};
// 0: 위 부터 시계방향
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
// 마주보는 방향 표시 상 우 하 좌 <-> 하 좌 상 우
int opposite[4] = { 2, 3, 0, 1 };
struct pos { int y, x, d; };

int bfs(int y, int x, int depth)
{
	queue<pos> q;
	q.push({ y,x });
	int cnt = 0;

	while (!q.empty())
	{
		int cy = q.front().y, cx = q.front().x, cd = q.front().d; q.pop();

		// 요기가 키포인트!
		if (V[cy][cx] == 0) cnt++;
		V[cy][cx] = 1;

		int pipe = MAP[cy][cx];

		for (int i = 0; i < 4; i++)
		{
			// 깊이로 모두 들어갔으면 무시
			if (cd == depth) continue;
			// 현재의 파이프가 해당 방향으로 방향이 없으면 무시
			if (isOpen[pipe][i] != 1) continue;
			int ny = cy + dy[i], nx = cx + dx[i];

			// 이미 방문한 곳이거나 경계를 넘으면 무시
			if (V[ny][nx] == 1 || ny < 0 || ny > N - 1 || nx < 0 || nx > M - 1) continue;

			// 다음 진입점의 반대 방향으로 뚫려 있지 않으면 무시
			if (isOpen[MAP[ny][nx]][opposite[i]] != 1) continue;

			q.push({ ny, nx, cd + 1 });
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> N >> M >> R >> C >> L;
		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				cin >> MAP[y][x];
				
		int ANS = 0;
		ANS = bfs(R, C, L-1);

		cout << "#" << t << " " << ANS << "\n";

		memset(V, 0, sizeof(V));
		memset(MAP, 0, sizeof(MAP));
	}

	return 0;
}
```

<br>

<br>

<br>

## 실수한 부분

### 카운트에 눈이 멀어 다짜고짜 DFS로 접근

중복 계산에 대한 가능성을 항상 염두하면서 접근하도록 하자.