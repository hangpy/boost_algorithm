// SWEA_1238. Contact

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#define endl "\n"

using namespace std;

int visit[101];

int bfs(int now, vector<int> * adj)
{
	visit[now] = 1;
	queue<int> q; q.push(now);

	vector< vector<int> > vv;
	while (!q.empty())
	{
		int len = q.size();
		vector<int> v;
		for (int i = 0; i < len; i++)
		{
			int p = q.front(); q.pop();
			for (int i = 0; i < adj[p].size(); i++)
			{
				int next = adj[p][i];
				if (visit[next] == 1) continue;
				q.push(next);
				v.push_back(next);
				visit[next] = 1;
			}
		}
		if(v.size() > 0) vv.push_back(v);
	}
	vector<int> result = vv[vv.size() - 1];

	int ans = 0;
	for (int i = 0; i < result.size(); i++)
		ans = ans < result[i] ? result[i] : ans;

	return ans;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("input.txt", "r", stdin);

	//for(int t =1; t <= 10; t++)
	int t = 1;
	while(true)

	{
		int nInput, start;
		vector<int> adj[101];
		cin >> nInput;
		if (cin.fail()) break;
		cin >> start;

		for (int i = 0; i < nInput; i += 2)
		{
			int from, to;
			cin >> from >> to;
			bool check = true;
			for (int k = 0; k < adj[from].size(); k++)
				if (adj[from][k] == to) check = false;

			if(check) adj[from].push_back(to);
		}
		
		memset(visit, 0, sizeof visit);
		int result = bfs(start, adj);

		cout << "#" << t << " " << result << endl;
		t++;
	}
	return 0;
}