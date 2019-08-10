

### &#128526;[문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V61LqAf8DFAWu)

<br>

<br>

<br>

## 시간

풀이시간 자체는 오래걸리지 않았지만 발상을 인터넷 검색을 통해 알게됨... BFS는 좀 더 연습해야겠음.

풀이자체 시간은 약 1시간 30분



<br>

<br>

<br>

## 접근법

단순히 BFS로 돌리기에는 메모리나 시간이 뻑날거 같은 느낌이 강하게 들었던 문제여서 발상 자체가 쉽지 않았다. 1시간 가까이 생각해도 썩 괜찮은 풀이가 생각이 나지 않아 다른 사람이 푼 것들을 조금만 참고하기로 해봄. 그때 유클리디안 거리라는 글자를 보는 순간 이거다 싶었다.

좌표평면 위에서 거리 관련 문제는 bsf건 dfs건 일단 유클리디안 거리를 생각해보도록 하자! 특히나 bfs에서의 각 깊이에서 도달할 수 있는 집의 개수는 유클리디안 거리 계산으로 쉽게 알 수 있다. 이말인 즉슨, bfs를 통해 모든 정점을 검사하는 것이 아니라 , 기존에 저장해 놓은 집들의 위치만 가지고 연산을 획기적으로 줄일 수 있다는 뜻이다.

> **좌표평면 상 거리는 유클리디안 거리를 떠올리자!!!!**

<br>

<br>

<br>

## 코드

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int T, N, M, MAP[21][21];
struct pos { int y, x; };

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N >> M;
		// 집 위치 기억해두기
		vector<pos> homes;
		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++)
			{
				cin >> MAP[y][x];
				if (MAP[y][x]) homes.push_back({ y,x });
			}
		}

		int max_home = 0;

		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++)
			{
				// 연산낭비를 막기위해 방범서비스 범위 구하기
				int max_k = max(
					max(abs(1 - y) + abs(1 - x), abs(1 - y) + abs(N - x)),
					max(abs(N - y) + abs(1 - x), abs(N - y) + abs(N - x))
				);

				// k는 해당 정점으로부터의 거리 => 계산할 때는 +1 해야함.
				for (int k = 0; k <= max_k; k++)
				{
					int cost = pow(k + 1, 2) + pow(k, 2);
					int benefit = 0;
					for (auto home : homes)
					{
						if (abs(y - home.y) + abs(x - home.x) <= k)
							benefit += M;
					}
					if (benefit >= cost)
						max_home = max(max_home, benefit / M);
				}
			}
		}

		// Asnwer
		cout << "#" << t << " " << max_home << "\n";
	}

	return 0;
}
```

<br>

### 다른 사람이 푼 정말 본받을 만한 코드

```cpp
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("sample_input.txt", "r", stdin);
	int t, hx[400], hy[400], idx, n, m, ans;
	char a[20][20];
	cin >> t;
	for (int tc = 1; tc <= t; tc++) 
	{
		ans = idx = 0;
		cin >> n >> m;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) 
			{
				cin >> a[i][j];
                // 집의 위치를 차례로 저장
				if (a[i][j] == '1') hx[idx] = i, hy[idx++] = j;
			}
		}
			
		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < n; j++)
			{
				int c[41] = { 0, };

                // 이부분이 제일 대단했음
				for (int k = 0; k < idx; k++)
					c[abs(i - hx[k]) + abs(j - hy[k]) + 1]++;
                
				for (int k = 1; k < 41; k++)
				{
                    // 아름다운 코드였다
					c[k] += c[k - 1];
					if (c[k] * m - ((k - 1)*(k - 1) + k * k) >= 0)
						ans = c[k] > ans ? c[k] : ans;
				}
			}
		}
		cout << "#" << tc << " " << ans << '\n';
	}
	return 0;
}
```

난 언제쯤 이렇게 풀 수 있을라나

<br>

<br>

<br>

## 실수한 부분

### 좌표평면 상에서 거리관련은 일단 유클리디안 거리를 생각해보자!

특히나 BFS의 경우 연산을 비약적으루 줄일 수 있는 기회가 있을 수 있음.