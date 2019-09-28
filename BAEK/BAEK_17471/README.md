

### &#128526;[문제 링크](https://www.acmicpc.net/problem/17471)

<br>

<br>

<br>

## 시간

1시간 컷



<br>

<br>

<br>

## 접근법

다소 복잡했던 문제. 하지만 차근차근 단계별로 접근하면 어렵지 않게 풀 수 있음.

<br>

<br>

<br>

## 코드

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define endl "\n"

using namespace std;

int N, gCity[10], visit[10];
vector<int> adj[10];

// 여기가 제일 중요! dfs 한번이면 전체 노드를 다방문할 수 있다는 것을 왜 상각하지 못했니!!
void dfs(int now)
{
	visit[now] = 1;
	
	for (int i = 0; i < adj[now].size(); i++)
	{
		if (visit[adj[now][i]]) continue;
		dfs(adj[now][i]);
	}
}

void setOppositeToVisit(vector<int> &v)
{
	memset(visit, 0, sizeof visit);
	for (int i = 0; i < v.size(); i++) visit[v[i]] = 1;
}

bool validate(vector<int> &a, vector<int> &b)
{
	bool isAllConnected = true;

	// validate a
	setOppositeToVisit(b);
	dfs(a[0]);
	for (int i = 0; i < a.size(); i++)
		if (!visit[a[i]]) return false;

	// validate b
	setOppositeToVisit(a);
	dfs(b[0]);
	for (int i = 0; i < b.size(); i++)
		if (!visit[b[i]]) return false;

	return isAllConnected;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) cin >> gCity[i];

	for (int i = 0; i < N; i++)
	{
		int k; cin >> k;
		for (int j = 0; j < k; j++)
		{
			int a; cin >> a;
			adj[i].push_back(a - 1);
		}
	}

	vector<int> v(N, 0);
	for (int i = 0; i < N; i++) v[i] = i;

	int ans = 987654321;
	bool canDivide = false;
	for (int i = 1; i <= N / 2; i++)
	{
		vector<int> tmpv(N, 1);
		for (int j = 0; j < i; j++) tmpv[j] = 0;

		do
		{
			vector<int> a;
			vector<int> b;
			for (int k = 0; k < N; k++)
			{
				if (tmpv[k] == 0) a.push_back(k);
				else b.push_back(k);
			}

			if (!validate(a, b)) continue;
			else canDivide = true;
			
			int sumA = 0;
			for (int i = 0; i < a.size(); i++) sumA += gCity[a[i]];
			int sumB = 0;
			for (int i = 0; i < b.size(); i++) sumB += gCity[b[i]];

			int result = abs(sumA - sumB);
			ans = ans > result ? result : ans;

		} while (next_permutation(tmpv.begin(), tmpv.end()));
	}

	if (canDivide) cout << ans << endl;
	else cout << -1 << endl;

	return 0;
}

```

<br>

<br>

<br>

## 실수한 부분

### 한 그룹으로 묶여있는지 판별하기 위해서 dfs를 생각해보자!

처음엔 아래와 같이 멍청하게 했다. 왜 굳이 두 노드를 뽑아서 다 검사를 해주었나? 어차피 한 노드로부터 dfs로 해서 모두 도달했다면 한 묶음인 것을...

```cpp
int N, gCity[10], visit[10];
vector<int> adj[10];

bool search(int now, int target)
{
	visit[now] = 1;
	bool isFinded = false;
	if (now == target) return isFinded = true;
	for (int i = 0; i < adj[now].size(); i++)
	{
		if (visit[adj[now][i]]) continue;
		isFinded = isFinded | search(adj[now][i], target);
	}
	visit[now] = 0;
	return isFinded;
}


void setOppositeToVisit(vector<int> &v)
{
	memset(visit, 0, sizeof visit);
	for (int i = 0; i < v.size(); i++) visit[v[i]] = 1;
}

bool validate(vector<int> &a, vector<int> &b)
{
	bool isConnected = true;

	// validate a

	int len = a.size();
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			setOppositeToVisit(b);
			// check the connection between i and j
			if (!search(a[i], a[j])) return false;
		}
	}
	// validate b

	len = b.size();
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			setOppositeToVisit(a);
			// check the connection between i and j
			if (!search(b[i], b[j])) return false;
		}
	}
	return isConnected;
}
```

그리고 아래는 아주 간단하게 된 로직

```cpp
void dfs(int now)
{
	visit[now] = 1;
	
	for (int i = 0; i < adj[now].size(); i++)
	{
		if (visit[adj[now][i]]) continue;
		dfs(adj[now][i]);
	}
}

void setOppositeToVisit(vector<int> &v)
{
	memset(visit, 0, sizeof visit);
	for (int i = 0; i < v.size(); i++) visit[v[i]] = 1;
}

bool validate(vector<int> &a, vector<int> &b)
{
	bool isAllConnected = true;

	// validate a
	setOppositeToVisit(b);
	dfs(a[0]);
    
    // 모두 방문 했는지에 대한 여부만 확인해주면 된다!
	for (int i = 0; i < a.size(); i++)
		if (!visit[a[i]]) return false;

	// validate b
	setOppositeToVisit(a);
	dfs(b[0]);
	for (int i = 0; i < b.size(); i++)
		if (!visit[b[i]]) return false;

	return isAllConnected;
}
```

