// BAEK_11657.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>


using namespace std;

struct VE
{
	int vertex;
	int time;
};

vector<VE> adj[501];
int dist[501], N, M, can_reach[501]{ 0 };


int main()
{
	cin >> N >> M;
	for (int m = 1; m <= M; m++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
	}

	// about all N, do RELAX
	can_reach[1] = 1;
	memset(dist, -1, sizeof(dist));
	dist[1] = 0;
	for (int n = 1; n <= N; n++)
	{
		if (!can_reach[n]) continue;
		int i = n, count = N;
		// 처음에는 1, 2, 3, ... , N 까지
		// 그 다음은 2, 3, 4, ... , N, 1 까지
		while (count > 0)
		{
			// 노드 1의 모든 간선에 대해 update할 때, 도달할 수 있는 노드는 can_reach에 1로 표시
			// update(i);
			if (can_reach[i])
			{
				for (auto next : adj[i])
				{
					if (can_reach[next.vertex] == 0)
					{
						dist[next.vertex] = dist[i] + next.time;
						can_reach[next.vertex] = 1;
					}
					else dist[next.vertex] = min(dist[i] + next.time, dist[next.vertex]);
				}
			}
			i++, count--;
			if (i > N) i = 1;
		}
	}

	int ANS = 0;
	for (int v = 1; v <= N; v++)
	{
		// update(v)
		// if( dist 값 바뀜? ) ANS = -1;
		if (can_reach[v] == 0) continue;
		for (auto next : adj[v])
			if (min(dist[v] + next.time, dist[next.vertex]) != dist[next.vertex])
				ANS = -1;
	}

	if (ANS == -1) cout << ANS << endl;
	else
	{
		for (int n = 2; n <= N; n++)
		{
			if(can_reach[n] == 1) cout << dist[n] << endl;
			else cout << -1 << endl;
		}
	}

    return 0;
}

/*
#include <cstdio>
using namespace std;

#define INF 2147483647

struct road
{
	int from, to, time;
};
int N, M, dist[501];
road edges[6001];

int main()
{
	scanf("%d %d", &N, &M);
	for (int m = 1; m <= M; m++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edges[m] = { a, b, c };
	}

	for (int n = 1; n <= N; n++) dist[n] = INF;

	int ANS(0);
	dist[1] = 0;
	for (int n = 1; n <= N; n++)
	{
		for (int m = 1; m <= M; m++)
		{
			road edge = edges[m];
			if (dist[edge.from] != INF && dist[edge.to] > dist[edge.from] + edge.time)
			{
				dist[edge.to] = dist[edge.from] + edge.time;
				if (n == N) ANS = -1;
			}
		}
	}

	if (ANS == 0)
		for (int n = 2; n <= N; n++)
			dist[n] == INF ? printf("%d\n", -1) : printf("%d\n", dist[n]);
	else printf("%d\n", -1);
}
*/
