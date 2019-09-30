// BAEK_17471. 게리 멘더링

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
