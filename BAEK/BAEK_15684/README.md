

### &#128526;[문제 링크](https://www.acmicpc.net/problem/15684)

<br>

<br>

<br>

## 시간

1시간 50분... 실수 한번에 시간이 너무 잡아먹혔다. 분발하자

<br>

<br>

<br>

## 접근법





<br>

<br>

<br>

## 코드

```cpp
// BAEK_15684. 사다리 조작

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, H, MAP[31][11], V[31][11];
struct line { int a, b; };

int doGame(int col_num)
{
	int num = col_num;
	int h = 1;
	while (h <= H)
	{
		if (MAP[h][num] != 0) num = MAP[h][num];
		h++;
	}
	return num;
}

bool isAllSame()
{
	bool isSame = true;
	for (int c = 1; c <= N; c++)
	{
		if (c != doGame(c))
		{
			isSame = false;
			break;
		}
	}
	return isSame;
}

void restore(int size, vector<line> &tmpv)
{
	for (int i = 0; i < size; i++)
	{
		int a = tmpv[i].a, b = tmpv[i].b;
		MAP[a][b] = 0, MAP[a][b + 1] = 0;
		if (b > 1) V[a][b - 1] = 0;
		if (b < N - 1) V[a][b + 1] = 0;
	}
}

bool setMap(int size, vector<line> &tmpv)
{
	bool isPossible = true;
	for (int i = 0; i < size; i++)
	{
		int a = tmpv[i].a, b = tmpv[i].b;
		if (V[a][b])
		{
			isPossible = false;
			break;
		}
		MAP[a][b] = b + 1, MAP[a][b + 1] = b;
		if (b > 1) V[a][b - 1] = 1;
		if (b < N - 1) V[a][b + 1] = 1;
	}
	return isPossible;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> H;

	// a, b => b번 세로줄이 b+1 줄에 a번째 가로줄 연걸
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		MAP[a][b] = b + 1, MAP[a][b + 1] = b;
		V[a][b] = 1;
		if (b > 1) V[a][b - 1] = 1;
		if (b < N - 1) V[a][b + 1] = 1;
	}

	vector<line> candis;
	for (int b = 1; b < N; b++)
	{
		for (int a = 1; a <= H; a++)
		{
			if (V[a][b] == 1) continue;
			candis.push_back({ a, b });
		}
	}
	int result = -1;
    
    // 처음에 이 부분을 if(candis.size() > 0)으로 감싸는 실수를 함.
	for (int cnt = 0; cnt <= 3; cnt++)
	{
		int vsize = candis.size();
		vector<int> v(vsize, 1);
		if (vsize >= cnt)
			for (int i = 0; i < cnt; i++)
				v[i] = 0;

		int isFinded = false;

		do
		{
			vector<line> tmpv;
			for (int i = 0; i < vsize; i++)
				if (v[i] == 0) tmpv.push_back(candis[i]);

			// set map
			if (setMap(tmpv.size(), tmpv))
			{
				if (isAllSame())
				{
					result = cnt;
					isFinded = true;
					break;
				}
			}
			// restore map
			restore(tmpv.size(), tmpv);
		} while (next_permutation(v.begin(), v.end()));

		if (isFinded) break;
	}
	cout << result << "\n";
	return 0;
}
```

<br>

<br>

<br>

### 두번째 시도

```cpp
// BAEK_15684. 사다리 조작

#include <iostream>
#include <algorithm>
using namespace std;

int N, M, H, V[31][11];
struct line { int a, b; };
line candis[30 * 9];

int doGame(int b)
{
	int a = 1;
	while (a <= H)
	{
		if (V[a][b]) a++, b++;
		else if (V[a][b - 1]) a++, b--;
		else a++;
	}
	return b;
}

bool isAllSame()
{
	bool isSame = true;
	for(int c = 1; c <= N; c++)
	{
		if (c != doGame(c))
		{
			isSame = false;
			break;
		}
	}
	return isSame;
}

int dfs(int cnt, int index, int size) 
{
	int ans = 4;
	if (cnt == 4) return ans;
	
	if (isAllSame()) return cnt;
	else
	{
		for (int i = index; i < size; i++)
		{
			int a = candis[i].a, b = candis[i].b;
			if (V[a][b]) continue;
			if (b > 1 && V[a][b - 1]) continue;
			if (b < N - 1 && V[a][b + 1]) continue;

			V[a][b] = 1;
			ans = min(ans, dfs(cnt + 1, i, size));
			V[a][b] = 0;
		}
		return ans;
	}
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> H;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		V[a][b] = 1;
	}

	int size = 0;
	for (int b = 1; b < N; b++)
	{
		for (int a = 1; a <= H; a++)
		{
			if (V[a][b]) continue;
			if (b > 1 && V[a][b - 1]) continue;
			if (b < N - 1 && V[a][b + 1]) continue;
			candis[size] = { a, b }; size++;
		}
	}

	int ans = dfs(0, 0, size);
	if (ans == 4) cout << -1 << endl;
	else cout << ans << endl;

 	return 0;
}

```

<br>

<br>

<br>

## 실수한 부분

### 다리를 놓을 수 없을 경우를 처리를 안해줌

놓을 수 있는 자리는 0개인데, 즉 candis.size()가 0임에도 불구하고 if구문 아래의 for문을 돌리는 바람에 참조에러가 발생했었음.  또한 처음에는 아래 주석과 같이 if로 감쌌는데, 저렇게 할 경우, size가 0임에도 불구하고 result답이 0으로 나올 수 있는 경우를 캐치하지 못하는 바람에 처음에 틀렸음. 항상 양극 상황을 잘 생각해봐야 한다.

```cpp
int result = -1;
// 처음에 이 부분을 if(candis.size() > 0)으로 감싸는 실수를 함.
for (int cnt = 0; cnt <= 3; cnt++)
{
    int vsize = candis.size();
    vector<int> v(vsize, 1);
    
    // if()구문을 추가해줌.
    if (vsize >= cnt)
        for (int i = 0; i < cnt; i++)
            v[i] = 0;
...
```

> 양극 상황을 반드시 체크하자