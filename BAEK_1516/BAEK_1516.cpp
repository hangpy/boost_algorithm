// BAEK_1516.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int time[501]{ 0 }, indegree[501]{ 0 }, N, min_time[501];
vector<int> adj[501];
queue<int> q;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int build_time(0);
		cin >> build_time;
		time[i] = build_time;
		min_time[i] = build_time;

		while (true)
		{
			int from(0);
			cin >> from;
			if (from == -1) break;
			else 
			{
				adj[from].push_back(i);
				indegree[i]++;
			}
		}
	}


	for (int i = 1; i <= N; i++)
		if (!indegree[i]) q.push(i);

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		for (int next : adj[curr])
		{
			min_time[next] = max(min_time[curr] + time[next], min_time[next]);
			if (--indegree[next] == 0) q.push(next);
		}
	}

	for (int i = 1; i <= N; i++)
		cout << min_time[i] << endl;


    return 0;
}

/*
5
10 -1
10 1 -1
4 1 -1
4 3 2 1 -1
3 3 -1
*/