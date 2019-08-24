

### &#128526;[문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeV9sKkcoDFAVH)

<br>

<br>

<br>

## 시간

딱 1시간 컷. 더 빨리 풀 수 있었을 거 같은데 연습이 더 필요하다.

`12 ms`, `12,644 kb`

<br>

<br>

<br>

## 접근법

먼저 시계방향, 반시계 방향으로 회전시키는 함수를 하나 작성한다. 이후, 회전시키는 톱니바퀴를 기준으로 양쪽으로 퍼지면서 같이 맞물려 돌아갈 톱니바퀴를 찾아 벡터에 넣는다. 이후 벡터에 들어있는 톱니바퀴의 번호와, 방향을 바탕으로 아까 만든 회전 함수를 이용해 회전시킨다. 이를 주어진 K번 만큼 반복한다.

마지막으로 인덱스 0에 있는 것이 빨간 화살표 자리이므로 조건에 맞춰 합을 구한다.

<br>

<br>

<br>

## 코드

```cpp
// SWEA_4013. 특이한 자석

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int T, K, visit[5];
struct chain { int num, dir; };

void rotate(vector<int>& v, int dir)
{
	// 시계 방향
	if (dir == 1)
	{
		int tmp = v[7];
		v.erase(v.end() - 1);
		v.insert(v.begin(), tmp);
	}
	// 반시계 방향
	else
	{
		int tmp = v[0];
		v.erase(v.begin());
		v.push_back(tmp);
	}
}

void dfs(vector<chain> &v, vector<int> *chains, int num, int dir)
{
	if (num < 1 || num > 4) return;

	visit[num] = 1;
	v.push_back({ num, dir });

	if (num > 1)
		if(visit[num - 1] == 0 && chains[num][6] != chains[num-1][2])
            // 처음에 실수한 부분. dir = (dir == 1 ? -1 : 1) 를 대입했었음.
			dfs(v, chains, num - 1, (dir == 1 ? -1 : 1));
	
	if (num < 4)
		if (visit[num + 1] == 0 && chains[num][2] != chains[num + 1][6])
            // 위에 실수를 유지할 경우, dir이 갱신되므로 여기서부터 로직에 오류가 생김. 
			dfs(v, chains, num + 1, (dir == 1 ? -1 : 1));
	
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	freopen("sample_input.txt", "r", stdin);

	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		vector<int> chains[5];

		cin >> K;
		for (int i = 1; i <= 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				int a; cin >> a;
				chains[i].push_back(a);
			}
		}

		for (int k = 0; k < K; k++)
		{
			int n, d;
			cin >> n >> d;

			vector<chain> tmp;
			dfs(tmp, chains, n, d);
			memset(visit, 0, sizeof(visit));

			for (auto chain : tmp)
				rotate(chains[chain.num], chain.dir);
		}

		int sum = 0;
		for (int i = 1; i <= 4; i++)
			if (chains[i][0] == 1) sum += pow(2, i - 1);

		cout << "#" << t << " " << sum << endl;
	}
	return 0;
}
```

<br>

<br>

<br>

## 실수한 부분

### DFS에서 재귀호출을 할 때 현 시점의 상태를 함부로 갱신하지 말것.

매개변수를 넘겨줄 때 상태를 갱신하는 실수를 자주 범하게 된다.

```cpp
void dfs(vector<chain> &v, vector<int> *chains, int num, int dir)
{
	if (num < 1 || num > 4) return;

	visit[num] = 1;
	v.push_back({ num, dir });

	if (num > 1)
		if(visit[num - 1] == 0 && chains[num][6] != chains[num-1][2])
            // 처음에 실수한 부분. dir = (dir == 1 ? -1 : 1) 를 대입했었음.
			dfs(v, chains, num - 1, (dir == 1 ? -1 : 1));
	
	if (num < 4)
		if (visit[num + 1] == 0 && chains[num][2] != chains[num + 1][6])
            // 위에 실수를 유지할 경우, dir이 갱신되므로 여기서부터 로직에 오류가 생김. 
			dfs(v, chains, num + 1, (dir == 1 ? -1 : 1));
	
}
```

위에 적혀있는 것과 같이 `dir = (dir == 1 ? -1 : 1)`과 같이 매개변수를 넘겨줄 경우, 아래에서 `dir`의 값이 갱신되면서 의도했던 값이 넘어가지 않는다. 문제에서 주어진 첫번째 예시가 잘못나오게 된다. 즉, -1의 상태를 유지했어야 되는데 위에서 1로 갱신하는 바람에 오른쪽 톱니바퀴가 1이 되지 않고 -1로 벡터에 추가되게 된다. 이는 로직 오류를 야기했다.

> 현재의 기준 상태를 함부로 갱신하지 말것. 특히 매개변수를 쓸 때 주의하도록 하자.