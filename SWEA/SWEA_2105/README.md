

### &#128526;[문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5VwAr6APYDFAWu)

<br>

<br>

<br>

## 시간

3시간 걸림... 이런 문제는 중복 계산을 빠르게 찾아내고 파할 수 있는 방법을 찾는 것이 관건이다.

`62ms`, `12,628 kb`

<br>

<br>

<br>

## 접근법

DFS + 백트레킹으로 접근. 하지만 모든 방향을 고려할 필요는 없었다. 사각형의 형태를 유지하면서 탐색을 해야하는 것이 첫번째 포인트였고, 또한 같은 사각형을 그리게 되는 중복 계산 가능성을 타파하는 것이 두번째 포인트였다. DFS의 구현 경우, 자신의 방향을 계속 가는 상황, 다음 방향으로 꺾는 상황, 이렇게 두 개의 분기점을 만들어 재귀호출을 한다.

구현에서의 또 다른 포인트는 시작점으로 돌아옴에도 불구하고 시작점의 방문여부가 체크되어 있어 미처 돌아올 수 없을 수도 있다는 것이다. 이를 조건으로 잘 만족 시켜 주어야만 했다.

<br>

<br>

<br>

## 코드

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct pos { 
	int y, x; 
};
int T, N, MAP[21][21];
int V[101];
// 왼쪽 위부터 오른쪽으로 차례로
int dy[4] = {-1, -1, 1, 1};
int dx[4] = {-1, 1, 1, -1};
// 특정 방향에서의 방향 전환 구현
int chdir[4] = { 1, 2, 3, 0 };

int dfs(pos cur, int dir, int cnt, pos& start)
{
	V[MAP[cur.y][cur.x]] = 1;
	int result = -1;

	// 기본타입은 참조자를 쓰지 말것
	int cy = cur.y, cx = cur.x;

	// 출발점으로 돌아왔을 때만 거쳐온 디저트 가게 수 반환
	if (cnt != 0 && cy == start.y && cx == start.x) return cnt;

	// 두갈래로 분기
	int ny = cy + dy[dir], nx = cx + dx[dir];
	// 해당 방향 그대로 직진
	if (!(ny < 1 || ny > N || nx < 1 || nx > N || (V[MAP[ny][nx]] == 1 && (ny != start.y || nx != start.x))))
		// 반환 값을 가지고 최대값 판벌
		result = max(result, dfs({ ny, nx }, dir, cnt + 1, start));
	// 90도 꺾기
	if (dir != 1 && cnt != 0)
	{
		ny = cy + dy[chdir[dir]], nx = cx + dx[chdir[dir]];
		if (!(ny < 1 || ny > N || nx < 1 || nx > N || (V[MAP[ny][nx]] == 1 && (ny != start.y || nx != start.x))))
			// 이전 기록과 반환 값 가지고 최대값 판별
			result = max(result, dfs({ ny, nx }, chdir[dir], cnt + 1, start));
	}
	V[MAP[cur.y][cur.x]] = 0;

	return result;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> N;
		
		for (int y = 1; y <= N; y++)
			for (int x = 1; x <= N; x++)
				cin >> MAP[y][x];
		
		int ANS = -1;
		// 필요한 정점만 탐색
		for (int y = 1; y <= N - 2; y++)
		{
			for (int x = 2; x <= N - 1; x++)
			{
				memset(V, 0, sizeof(V));
				pos cpos = { y,x };
				ANS = max(ANS, dfs({ y,x }, 2, 0, cpos));
			}
		}
		cout << "#" << t << " " << ANS << endl;
	}
	
	return 0;
}
```

<br>

<br>

<br>

## 실수한 부분

### 시작점으로 돌아와도 방문 체크가 되어있어 하지 cnt를 반환하지 않은 실수

시작점을 판별하는 조건을 잘 만족시켜야함.