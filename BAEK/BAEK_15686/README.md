

### &#128526;[문제 링크](https://www.acmicpc.net/problem/15686)

<br>

<br>

<br>

## 시간

1시간 컷

`4 ms`, `2000 kb`

<br>

<br>

<br>

## 접근법

순열조합 문제. 맨 처음에 각 집마다 BFS로 구현했다가 시간초과 나서 다시 고침. 그럼에도 1시간 안에는 풀었음.

<br>

<br>

<br>

## 코드

```cpp
// BAEK_15686. 치킨배달

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <limits>

using namespace std;

int N, M, MAP[51][51];
struct pos { int y, x; };
pos stores[13], homes[100];

int getChickenDistance(pos &home, vector<pos> &stores)
{
	int ans = 987654321; int len = stores.size();
	for (int i = 0; i < len; i++)
	{
		int d = abs(home.y - stores[i].y) + abs(home.x - stores[i].x);
		ans = ans > d ? d : ans;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int hcnt = 0, scnt = 0;
	cin >> N >> M;
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			cin >> MAP[y][x];
			if (MAP[y][x] == 1) homes[hcnt] = { y, x }, hcnt++;
			if (MAP[y][x] == 2) stores[scnt] = { y, x }, scnt++;
		}
	}

	int ans = numeric_limits<int>::max();
	vector<int> v(scnt, 1);
	for (int i = 0; i < M; i++) v[i] = 0;
	do
	{
		vector<pos> selected;
		for (int i = 0; i < scnt; i++)
			if (v[i] == 0) selected.push_back(stores[i]);

		// get city chicken distance
		int tmp = 0;
		for (int i = 0; i < hcnt; i++)
			tmp += getChickenDistance(homes[i], selected);

		ans = ans > tmp ? tmp : ans;

	} while (next_permutation(v.begin(), v.end()));
	
	cout << ans << endl;

	return 0;
}

```

<br>

<br>

<br>



## 실수한 부분

### 각 조합에서 모든 집을 BFS로 하면 시간초과

```cpp
int bfs(pos home)
{
	int result = 987654321;
	queue<element> q;
	q.push({ home.y, home.x, 0 });
	V[home.y][home.x] = 1;

	while (!q.empty())
	{
		int cy = q.front().y, cx = q.front().x, cd = q.front().d; q.pop();
		int find = false;
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i], nx = cx + dx[i];
			if (ny < 1 || ny > N || nx < 1 || nx > N || V[ny][nx]) continue;
			q.push({ ny, nx, cd + 1 });
			V[ny][nx] = 1;
			if (MAP[ny][nx] == 2)
			{
				find = true;
				result = cd + 1;
				break;
			}
		}
		if (find) break;
	}

	memset(V, 0, sizeof V);
	return result;
}
```

처음엔 위와같이 BFS로 각 집마다의 치킨 거리를 구했는데 이렇게 할 경우 시간초과가 난다. 조금만 더 생각해보면 당연한 것을...

<br>

### 최대 M만큼 치킨집을 남겨놓는다는 의미를 잘 캐치했어야 했다.

0부터 M-1 까지의 치킨집을 고려하는 것은 의미가 없다. 어떻게 해서든 최대로 남겨놓는 것이 이득이기 때문이다.