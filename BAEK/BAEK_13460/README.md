

### &#128526;[문제 링크](https://www.acmicpc.net/problem/13460)

<br>

<br>

<br>

## 시간

첫번째 풀이: 1시간 50분 컷, `472 ms`, `1988 kb`

두번째 풀이: ?, `0 ms`, `1236 kb`



<br>

<br>

<br>

## 접근법

실제 시험장이었으면 멘붕이었을 확률이 높은 문제였다. 최적화를 어떻게 시켜야 할지 생각이 나지 않아 일단 무식하게 브루트포스로 전부 다 확인해서 최소값을 찾았다. 하지만 너무 오래걸리는 것이 문제였다. 특히 -1 결과가 나올때 오래걸렸다. 최소값을 찾는데 가장 먼저 고려해야할 것은 먼저 BFS다.

그동안 BFS에서 큐를 사용할 때 한 노드의 상황 (좌표, 뎁스 등)만 넣어주는 폭좁은 이해를 하고 있었다. 해당 문제 같은 경우는 좀 더 추상적이다. 빨강, 파랑 두 구슬의 각각의 위치에 대한 정보와 지금까지 몇번 기울였는지에 대한 정보를 큐에 넣어줌으로써 문제를 풀 수 있다.

중요한 것은 BFS를 쓸 수 있을 것이다라는 사실을 착안하기까지의 과정이다. 먼저 해당 로직은 트리로 나타낼 수 있다. 상하좌우, 상화좌우, 상하좌우 와 같이 각 단계에서 한개씩 방향을 택할 수 있으므로 최대 (4^10 + 4^9 + 4^8 + ... + 4^1)  의 상황을 고려할 수 있다. 이렇게 무식하게 풀 수는 있지만 현명한 방법은 아니다. 즉 트리 형태로 늘여뜨려놨을 때, 최소 깊이의 상황을 캐치하고 그 뒤로는 탐색을 멈출 수 있는 로직을 짜야만 한다. 그럴 때 쓰는게 BFS인 것이다. 즉, 트리에서 각 노드를, 빨강, 파랑 두 구슬의 각각 좌표로 볼 수 있다.

그 다음으로 중요한 포인트는 로직에서 중복 계산을 없앨 수 있는 해당 문제의 성질을 파악하는 것이다. 

1. 먼저 기울였던 부분으로 다시 기울이지 않아도 된다.

2. 이전의 반대방향으로 기울일 필요는 없다. 이전 상태로 돌아가기 때문에 의미가 없다.

3. 파란구슬이 홀에 들어가면 무조건 해당 분기의 뒷 부분은 탐색할 필욕가 없다 -> 가지치기

4. 이전에 존재했던 상태에 대해서는 탐색을 이어나갈 필요가 없다. -> 작은 부분으로 포함되기 때문이다.

   여기서 중요한 개념중 하나가 `차원`이다. 차원이란 어떤 상황을 인식하기 위해 고려할 수 있는 최소한의 변수의 개수로 생각할 수 있다. 그리고 프로그래밍해서 해당 차원은 `다중배열`로 구현할 수 있다. 다만 그 크기가 너무 크게 되면 공간낭비가 심하겠지만 해당 문제에서는 MAP이 10을 넘어가지 않으므로, `visit[10][10][10][10]`와 같이 각 구슬의 위치를 고려했었다라는 정보를 기록할 수 있다.

또 하나의 포인트는 구슬이 같은 선상에서 기울였을 때 겹치지 않는 것을 표현하는 것이다. 이 경우, 어느 방향으로 기울였을 때 무엇이 상하좌우 한칸 옆에 있을지 한정적으로 결정되므로 아래와 같이 구현할 수 있다.



상당히 난이도 있던 문제였다. 정답률이 낮은 이유가 있는 문제다. 특히 DFS보다 BFS를 활용하는 연습을 더 많이 하도록 해야겠다. 

<br>

<br>

<br>

## 코드

두번째 코드

```cpp
// BAEK_13460. 구슬탈출2

#include <iostream>
#include <queue>

using namespace std;

int N, M, ry, rx, by, bx, hy, hx;
// 실수한 부분 -> 문자열은 10문자를 받아오면 11만큼 선언해야한다.
char MAP[11][11], V[10][10][10][10];
struct state { int cnt, ry, rx, by, bx; };
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void move(int &y, int &x, int dir)
{
	while (1)
	{
		y += dy[dir], x += dx[dir];
		if (MAP[y][x] == '#')
		{
			y -= dy[dir], x -= dx[dir];
			break;
		}
		if (MAP[y][x] == 'O') break;
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;

	for (int y = 0; y < N; y++) 
	{
		cin >> MAP[y];
		for (int x = 0; x < M; x++)
		{
			if (MAP[y][x] == 'R') ry = y, rx = x;
			else if (MAP[y][x] == 'B') by = y, bx = x;
			else if (MAP[y][x] == 'O') hy = y, hx = x; 
			else;
		}
	}
	
	queue<state> q; q.push({ 0, ry, rx, by, bx });
	V[ry][rx][by][bx] = 1;

	int ans = -1;
	while (!q.empty())
	{
		state cur = q.front(); q.pop();

		if (cur.cnt > 10) break;
		if (cur.ry == hy && cur.rx == hx)
		{
			ans = cur.cnt;
			break;
		}
		
		for (int i = 0; i < 4; i++)
		{
			int cry = cur.ry, crx = cur.rx;
			int cby = cur.by, cbx = cur.bx;
			int ccnt = cur.cnt;

			move(cry, crx, i); move(cby, cbx, i);

			if (cby == hy && cbx == hx) continue;

			if (cry == cby && crx == cbx)
			{
				switch (i)
				{
				case 0:
					cur.ry < cur.by ? cby++ : cry++; break;
				case 1:
					cur.ry < cur.by ? cry-- : cby--; break;
				case 2:
					cur.rx < cur.bx ? cbx++ : crx++; break;
				case 3:
					cur.rx < cur.bx ? crx-- : cbx--; break;
				}
			}

			if (V[cry][crx][cby][cbx]) continue;

			q.push({ ccnt + 1, cry, crx, cby, cbx });
			V[cry][crx][cby][cbx] = 1;
		}
	}

	cout << ans << endl;

	return 0;
}

```

<br>

### 첫번째 시도

```cpp
// BAEK_13460. 구슬탈출2

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, MAP[10][10], CMAP[10][10];

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int DIR[10];
struct pos { int y, x; };
pos ball[2]; // ball[0]: RED, ball[1]: BLUE
pos cball[2];

bool incline(int color, int dir)
{
	bool fall = false;
	int cy = cball[color].y, cx = cball[color].x;

	int opositeColor = color == 0 ? 4 : 3;

	while (true)
	{
		int ny = cy + dy[dir], nx = cx + dx[dir];

		if (CMAP[ny][nx] == 1) break;
		if (CMAP[ny][nx] == opositeColor) break;
		if (CMAP[ny][nx] == 2)
		{
			fall = true;
			CMAP[cy][cx] = 0;
			break;
		}

		swap(CMAP[cy][cx], CMAP[ny][nx]);
		cy = ny, cx = nx;
	}

	cball[color] = { cy, cx };

	return fall;
}

bool dfs(int index, int times)
{
	bool pass = false;
	if (index == times)
	{
		memcpy(CMAP, MAP, sizeof(MAP));
		memcpy(cball, ball, sizeof(ball));

		// times만큼 DIR에 있는 방향으로 기울이기
		bool redIn = false, blueIn = false;
		for (int i = 0; i < times; i++)
		{
			int dir = DIR[i];

			// 두번 하면 됨.
			redIn = incline(0, dir);
			blueIn = incline(1, dir);

			if (redIn == false) redIn = incline(0, dir);
			if (blueIn == false) blueIn = incline(1, dir);

			if (redIn == true && blueIn == false)
			{
				pass = true;
				break;
			}
			if (redIn == true && blueIn == true) break;
			if (redIn == false && blueIn == true) break;
		}
		return pass;
	}

	for (int d = 0; d < 4; d++)
	{
		DIR[index] = d;
		pass = pass | dfs(index + 1, times);
		if (pass) break;
	}

	return pass;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			char a;
			cin >> a;
			switch (a)
			{
			case '.':
				MAP[y][x] = 0;
				break;
			case '#':
				MAP[y][x] = 1;
				break;
			case 'O':
				MAP[y][x] = 2;
				break;
			case 'R':
				ball[0] = { y, x };
				MAP[y][x] = 3;
				break;
			case 'B':
				ball[1] = { y, x };
				MAP[y][x] = 4;
				break;
			default:
				break;
			}
		}
	}

	// 해당 횟수에서 찾았으면 반환
	bool inHole = false;
	int result = -1;
	for (int i = 1; i <= 10; i++)
	{
		inHole = dfs(0, i);
		if (inHole)
		{
			result = i;
			break;
		}
	}

	cout << result << endl;


	return 0;
}

```

<br>

<br>

<br>

## 실수한 부분

### 문자열 받을 때 끝의 null 값을 고려하자

`3 <= N, M <= 10` 에서 문제에 있는 문자열을 받기 위해선 가장 뒤에 들어갈 null값을 집어넣어줄 공간이 필요하다. 컴파일러에 따라 이부분을 자동으로 처리해주는 것도 있기 때문에 반드시 null을 고려하도록 하자

```cpp
char MAP[11][11]
// char MAP[10][10] -> 잘못된 선언
```

<br>

### BFS를 할 때 한 좌표뿐만이 아니라 상황 자체를 노드로 나타낼 수 있다.

```cpp
queue<state> q; q.push({ 0, ry, rx, by, bx });
V[ry][rx][by][bx] = 1;
```



