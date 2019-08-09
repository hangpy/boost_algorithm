

### &#128526;[문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PoOKKAPIDFAUq)

<br>

<br>

<br>

## 시간

1시간 20분... 처음부터 DFS로 접근했어야 했는데 BFS로 푸는 바람에 시간 많이 잡아먹힘. 또 딱 한번만 높이조정을 할 수 있다는 조건을 빼먹는 실수 때문에 30분 가까이 더 잡아먹힘... 분발하자.

`8ms`, `12,524 kb`

<br>

<br>

<br>

## 접근법

처음엔 다짜고자 BFS로 접근했지만 미처 생각하지 못할만한 오류가 많았다. 일단 맵이 작았고 봉우리가 동시다발적으로 주어졌다는 생각에 BFS를 생각해봤지만 다시 보니 이는 최단경로가 아니라 일종의 최장경로 문제였음. 이럴 땐, 벡트레킹을 적용한 DFS가 더 효율적이었음을 처음부터 알았어야 됐다.

<br>

<br>

<br>

## 코드

```cpp
// SWEA_1949. 등산로 조정
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct pos { int y, x, h; };
int T, N, K, MAP[9][9], V[9][9];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

// 트리를 그려서 재귀호출 형태를 맞춰줌
// 딱 한번만 높이를 팔 수 있다는 조건을 처음에 빼먹는 실수를 함. cnt를 인자로 넣어줬어야함. 
int dfs(pos curr, int val, int cnt)
{
	// 이후 max()를 통해 result 업데이트
	int result = val;
	int cy = curr.y, cx = curr.x, ch = curr.h;
	// 진입하면 바로 방문 체크
	V[cy][cx] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = cy + dy[i], nx = cx + dx[i];
		// 경계선 넘거나 현재 경로 탐색중 방문했던 곳이면 무시
		if (ny < 1 || ny > N || nx < 1 || nx > N || V[ny][nx]) continue;

		// 고정된 데이터를 다룰 경우 참조자를 쓰자
		int &nh = MAP[ny][nx];
		if (nh < ch) 
			result = max(result, dfs({ ny, nx, nh }, val + 1, cnt));
		else
		{
			// 기회가 남았을 때만 가능
			if (cnt > 0 && nh - K < ch)
				result = max(result, dfs({ ny, nx, ch - 1 }, val + 1, cnt - 1));
			else continue;
		}
	}
	// 빠져나가면서 다른 경우를 위해 벡트레킹
	V[cy][cx] = 0;
	// 반환된 경로들 중 가장 큰 값을 반환
	return result;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	
	for (int t = 1; t <= T; t++)
	{
		int tmp_max = 0;
		vector<pos> highs;
		cin >> N >> K;
		// 입력과 동시에 가장 높은 봉우리를 벡터에 저장
		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++)
			{
				int h;
				cin >> h;
				MAP[y][x] = h;
				if (h == tmp_max) highs.push_back({ y, x, h });
				
				// 만약 새로운 높은 봉우리가 나왔을 경우 벡터를 청소하고 새로 넣기 시작
				else if (h > tmp_max)
				{
					tmp_max = h;
					highs.clear();
					highs.push_back({ y, x, h });
				}
				else continue;
			}
		}
		
		int ANS = 0;
		// 각 높은 봉우리에 대해서 DFS 실시
		for (auto h : highs) ANS = max(ANS, dfs(h, 1, 1));
		cout << "#" << t << " " << ANS << "\n";
	}

	return 0;
}

```

<br>

<br>

<br>

## 실수한 부분

### 주어진 조건 (딱 한번만 봉우리 높이 조정 가능)을 빼먹음

해당 조건을 dfs의 파라미터로 넣어줬어야만 했다.

### 최장경로 문제를 다짜고짜 BFS로 접근

제발 조금만 더 생각하고 접근하자.