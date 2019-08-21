

### &#128526;[문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRJ8EKe48DFAUo)

<br>

<br>

<br>

## 시간

결국 다른 사람 풀이 보고 풀었음... 분발합시다

<br>

<br>

<br>

## 접근법

정해진 맵이 있고 단순한 DFS, BFS문제가 아닌 시뮬레이션이라 구현에 초점이 맞춰졌다. 하지만 동시에 같은 곳에 번식을 하려는 경우를 어떻게 구현해야 할지를 몰라서 많이 해맸음.

내 기준에서 정말 어려웠던 문제였다. 내가 생각해낸 풀이는 너무 장황하고 구현하기도 너무 버거웠다. 반복자를 사용해서 동적 순회를 하기에는 에러가 너무 많이 발생했고 vector<>::erase() 연산이 특히 vector iterator incompatable 에러를 일으키는 바람에 내 풀이에는 답이 없어 결국 포기함. 결국 간단하면서도 완전한 로직을 통해 동시성 우선순위를 해결했어야 했다. 

동시성 우선순위같은 경우 말그대로 우선순위대로 연산을 시행하고 그 뒤에 중복되는 연산은 무시해 버리는 식으로 로직을 구현할 수 있다. 이런 류의 문제는 연습을 많이해야 할 듯 함.

<br>

<br>

<br>

## 코드

```cpp
#include <iostream>
#include <cstring>
#include <queue>
#define BASE 150

using namespace std;

int N, M, K;
struct CELL {
	int y, x;
	int restLife, toActive;
};
int MAP[50 + BASE*2][50 + BASE*2];
// 상하좌우
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main(int argc, char** argv)
{
	int T, cnt = 0;
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		cin >> N >> M >> K;

		queue<CELL> q[11];
		int cnt = 0;

		for (int y = BASE; y < BASE + N; y++)
		{
			for (int x = BASE; x < BASE + M; x++)
			{
				cin >> MAP[y][x];
				if (MAP[y][x]) 
				{
					q[MAP[y][x]].push({ y, x, MAP[y][x], MAP[y][x] });
					cnt++;
				}
			}
		}

		while (K > 0)
		{
			for (int vital = 10; vital >= 1; vital--)
			{
				queue<CELL> &tq = q[vital];
				int len = tq.size();
				for (int i = 0; i < len; i++)
				{
					// 초기상태 값
					CELL cell = tq.front(); tq.pop();
					int cy = cell.y, cx = cell.x
                        , restLife = cell.restLife, toActive = cell.toActive;
					cnt--;

					// 비활성
					if (toActive > 0)
					{
						tq.push({ cy, cx, restLife, toActive - 1 }), cnt++;
					}
					// 활성 후 첫 번식
					else if (toActive == 0 && restLife == MAP[cy][cx])
					{
						for (int i = 0; i < 4; i++)
						{
							int ny = cy + dy[i], nx = cx + dx[i];
							if (MAP[ny][nx]) continue;
							MAP[ny][nx] = MAP[cy][cx];
							tq.push({ ny, nx, restLife, restLife }); cnt++;
						}
						if (restLife - 1 > 0)
							tq.push({ cy, cx, restLife - 1, 0 }), cnt++;
					}
					// 첫 번식 이후 활성상태
					else
					{
						if (restLife - 1 > 0)
							tq.push({ cy, cx, restLife - 1, 0 }), cnt++;
					}
				}
			}
			K--;
		}
		cout << "#" << t << " " << cnt << "\n";
		memset(MAP, 0, sizeof(MAP));
	}
	return 0;
}
```

<br>

<br>

<br>

## 실수한 부분

### queue도 사이즈를 체크할 수 있다!

이말인 즉슨, queue에 있는 것들까지만 연산 가능하게 로직을 짤 수 있다는 의미이다.

```cpp
queue<CELL> &tq = q[vital];
int len = tq.size();
for (int i = 0; i < len; i++)
{
	// 큐에 들어있는 원소들에 한에서 실행시킬 로직
}
```

<br>

### 동시성 우선순위를 위해서는 queue 배열을 이용해 해결 가능하다.

```cpp
queue<CELL> q[11];
for (int vital = 10; vital >= 1; vital--)
{
	queue<CELL> &tq = q[vital];
    // 우선순위가 내림차순이라면 10부터 시작해서 그 뒤에 겹치는 연산은
    // 시행되지 못하게 로직을 짜면 된다
}

```

