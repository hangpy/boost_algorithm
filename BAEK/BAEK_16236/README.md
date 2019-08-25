

### &#128526;[문제 링크](https://www.acmicpc.net/problem/16236)

<br>

<br>

<br>

## 시간

1시간 50분. 이렇게 오래걸릴 문제가 전혀 아닌데, 발상 자체를 처음에 잘못했다. 쉬운걸 어렵게 생각하지 말도록 하자.

처음: `336 ms`, `1992 kb`

두번째: `4 ms`, `1992 kb`

<br>

<br>

<br>

## 접근법

전형적인 BFS 문제이다. 같은 거리의 시식 가능 물고기에 도달했을 때 동시성 우선순위만 잘 처리해 준다면 빠른 시간안에 쉽게 풀 수 있는 문제였다. 하지만 자기보다 큰 물고기를 지나갈 수 없다는 제약을 놓치면서 접근 자체를 잘못했다. 이바람에 애꿎은 풀이 시간만 많이 날렸다. 결국 1시간 50분 안에 풀기는 했지만 목표했던 1시간에는 한참 못미치는 시간이었다. 이렇게 제약조건을 놓치는 것은 치명적이다. 지금까지 푼 것에서 자꾸 덧붙이면서 로직을 수정하다보니 코드 자체도 길어지고 오류 확률도 늘어난다. 때문에 처음부터 접근 자체를 잘하는 것이 매우 중요하다. 바로 아래 코드는 1시간 50분만에 푼 뒤에, 다시 마음을 가다듬고 처음부터 제대로 접근해서 풀었을 때의 풀이이다. 당연히 구현 자체는 30분도 안걸리는 로직이었다.

반성합시다. 

<br>

<br>

<br>

## 코드

```cpp
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
    
    // 동시성 우선순위를 위한 임시 변수
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
```

<br>

<br>

<br>

### 첫번째로 풀었던 코드 (336 ms)

처음부터 BFS로 시작하면 좋은 것을 굳이 먹을 수 있는 후보군을 설정하고 각 후보군마다 BFS로 도달 가능성을 체크했다. 또한 체크하면서 뒤에 다시 동시성 우선순위를 판별하는 로직을 짰다... 뭐 결과적으로 풀긴했지만 실제 업무상 코드였다면 정말 안짜느니만 못한 코드였다. 이렇게 굳이 복잡하게 구현한 스스로에게도 감탄스럽다 참;;

제발 졸면서 풀지 말자.

```cpp
// BAEK_16236. 아기상어

#include <iostream>
#include <vector>
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


// 타겟까지 도달하기까지 걸리는 시간 반환: 만약 0이면 도달할 수 없다는 뜻.
int reach(const info &target, const pos &cur, int sharkSize)
{
	memset(V, 0, sizeof(V));

	queue<qpos> q; q.push({ cur.y, cur.x, 0 });

	V[cur.y][cur.x] = 1;

	bool canReach = false;
	int result = 0;

	while (!q.empty())
	{
		int cy = q.front().y, cx = q.front().x, ct = q.front().t; q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i], nx = cx + dx[i];
			if (ny < 0 || ny > N - 1 || nx < 0 || nx > N - 1) continue;
			if (MAP[ny][nx] > sharkSize || V[ny][nx] >= 1) continue;

			q.push({ ny, nx, ct + 1 });
			V[ny][nx] = 1;
			if (ny == target.y && nx == target.x)
			{
				canReach = true;
				result = ct + 1;
				break;
			}
		}
	}

	if (canReach) return result;
	else return 0;
}

int main()
{
	cin >> N;
	pos shark_pos;
	vector<info> fishes;


	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			int a;
			cin >> a; MAP[y][x] = a;
			if (0 < a && a < 7) fishes.push_back({ y, x, a, 1 });
			if (a == 9) shark_pos = { y, x }, MAP[y][x] = 0;
		}
	}


	int time = 0;
	int sharkSize = 2;
	int eat = 0;

	while (true)
	{
		vector<int> fishesToEat;

		for (int i = 0; i < fishes.size(); i++)
			if (fishes[i].live == 1 && fishes[i].size < sharkSize)
				fishesToEat.push_back(i);

		int min = numeric_limits<int>::max();
		info prev;
		int idx;
		bool canEat = false;
		for (auto index : fishesToEat)
		{
			info &fish = fishes[index];
			int result = reach(fish, shark_pos, sharkSize);
			if (result != 0)
			{
				canEat = true;
				if (result < min) min = result, prev = fish, idx = index;
				else if (result == min)
				{
					if (fish.y < prev.y) prev = fish, idx = index;
					else if (fish.y == prev.y)
					{
						if (fish.x < prev.x) prev = fish, idx = index;
					}
					else;
				}
				else;
			}
		}

		if (canEat == true)
		{
			time += min;
			fishes[idx].live = 0;
			shark_pos = { fishes[idx].y, fishes[idx].x };
			MAP[fishes[idx].y][fishes[idx].x] = 0;
			eat++;
			if (eat == sharkSize) sharkSize++, eat = 0;
		}
		else break;
	}

	cout << time << endl;

	return 0;
}
```

<br>

<br>

<br>

## 실수한 부분

### 맵에 아기상어를 그대로 9로 놓았다

```cpp
for (int y = 0; y < N; y++)
{
    for (int x = 0; x < N; x++)
    {
        int a;
        cin >> a; MAP[y][x] = a;
        if (0 < a && a < 7) fishes.push_back({ y, x, a, 1 });
        // 처음엔 이부분도 그대로 9를 삽입.
        // 이렇게 할 경우 후에 로직이 9를 물고기 크기로 인식하게 되어 지나칠 수 없게 된다.
        if (a == 9) shark_pos = { y, x }, MAP[y][x] = 0;
    }
}
```

아기상어의 초기 위치는 대상 물고기가 아니기 때문에 0으로 처리했어야 했는데 입력값 그대로 맵에 박아두는 바람에 로직 자체엔 오류가 없지만 틀린 맵을 순회하고 있었던 것.

<br>

### if, else if, else 원칙은 귀찮더라도 지키자

두 번째로 시간을 잡아먹었던 실수는 아래와 같다

```cpp
if (0 < MAP[ny][nx] && MAP[ny][nx] < sharkSize)
{
    if (ct + 1 > result) break;
    canReach = true;
    if (ct + 1 < result) result = ct + 1, toEat = { ny, nx };
    else if(ct + 1 == result) 
    {
        if (ny < toEat.y) toEat = { ny, nx };
        // 처음엔 이부분을 else로만 처리했음.
        else if(ny == toEat.y)
        {
            if (nx < toEat.x) toEat = { ny, nx };
        }
        else;
    }
    else;
}
```

주석과  같이 내가 생각했던 세부 조건을 else로 처리했을 경우, 의도치 않은 로직 오류가 생길 수 있다. else if를 쓰고 혹시 모를 컴파일러의 호환성 때문에 else를 쓰는 것이 다소 귀찮고 못생겨보이긴 하지만, 그래도  분기의 완전성 원칙은 반드시 지키도록 하자.