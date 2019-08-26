

### &#128526;[문제 링크](https://www.acmicpc.net/problem/15685)

<br>

<br>

<br>

## 시간

시간을 재진 못했지만 1시간 30분은 확실하게 넘김

아직도 연습이 많이 필요하다.

<br>

<br>

<br>

## 접근법

드래곤 커브를 이해하고 각 세대 변화를 어떻게 구현할 것인지가 핵심인 문제였다. 처음엔 끝점을 기준점으로 두고   저장한 나머지 점들을 시계방향으로 90도 회전하려 했지만 뜻처럼 잘 되진 않았다. 해결한 다른 방법이 한 변 자체를 벡터로 생각하고 각 세대에 따른 방향성 변화의 규칙성을 발견해 낸 것이다.

이런 문제는 핵심이 되는 변화에 어떤 규칙성이 있고 해당 규칙을 어떻게 구현할지가 가장 중요하다.

<br>

<br>

<br>

## 코드

```cpp
// BAEK_15685. 드래곤 커브

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, MAP[101][101];
struct line { int y, x, d, g;};
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };
int changeDir[4] = { 1, 2, 3, 0 };

void drawDragon(int y, int x, int d, int g)
{
	MAP[y][x] = 1;

	int ny = y + dy[d], nx = x + dx[d];
	MAP[ny][nx] = 1;
	vector<int> vd;
	vd.push_back(d);
	int cy = ny, cx = nx;
	while (g > 0)
	{
		for (int i = vd.size() - 1; i >= 0; i--)
		{
			int nd = changeDir[vd[i]];
			int next_y = cy + dy[nd], next_x = cx + dx[nd];
			if (next_y < 0 || next_y > 100 || next_x < 0 || next_x > 100) continue;
			MAP[next_y][next_x] = 1;
			cy = next_y, cx = next_x;
			vd.push_back(nd);
		}
		g--;
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	vector<line> initDragon;

	for (int i = 0; i < N; i++)
	{
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		initDragon.push_back({ y, x, d, g });
	}

	for (auto dg : initDragon)
		drawDragon(dg.y, dg.x, dg.d, dg.g);
	
	int result = 0;
	for (int y = 0; y <= 100; y++)
	{
		for (int x = 0; x <= 100; x++)
			if (MAP[y][x] == 1 && MAP[y + 1][x] == 1 && MAP[y][x + 1] == 1 && MAP[y + 1][x + 1] == 1)
				result++;
	}

	cout << result << endl;

	return 0;
}
```

<br>

<br>

<br>

## 실수한 부분

### 90도 회전을 처음에 바로 표현하지 못함

기준점을 두고 좌표를 변화시키는 것이 아니라 그냥 세대에 따른 규칙적인 벡터만 추가하면 됨.

```cpp
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };
int changeDir[4] = { 1, 2, 3, 0 };
```

<br>

### 경계 표현을 N으로 잘못함

원래 100으로 했어야함.

<br>

### 제약조건 0 <= x,y <= 100 을 잘못반영함.

배열을 101까지 만들었어야 100까지 모두 표현 가능하다.

<br>

