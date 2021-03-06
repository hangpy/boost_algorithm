// BAEK_1504.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

struct VE
{
	int vertex;
	int edge;
};

struct candi
{
	int node;
	long long minDist;
};

struct cmp
{
	bool operator()(candi t, candi u)
	{
		// 치명적이었던 실수 구간. u를 t로 씀.
		return t.minDist > u.minDist;
	}
};

int N, E, X, Y;
long long dist[801];

priority_queue<candi, vector<candi>, cmp> pq;
vector<VE> adj[801];

void dijkstra(int start_node)
{
	dist[start_node] = 0;
	long long currDist = dist[start_node];
	pq.push({start_node, 0});
	while (!pq.empty())
	{
		if (dist[X] != -1 && dist[Y] != -1) break;
		candi toUpdate = pq.top();
		pq.pop();
		currDist = toUpdate.minDist;
		if (dist[toUpdate.node] == -1)
			dist[toUpdate.node] = currDist;
		for (auto next : adj[toUpdate.node])
			if (dist[next.vertex] == -1)
				pq.push({ next.vertex, currDist + next.edge });
	}
	// initialize pq
	while (!pq.empty()) pq.pop();
}

int main()
{
	cin >> N >> E;
	for (int e = 1; e <= E; e++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	cin >> X >> Y;

	memset(dist, -1, sizeof(dist));
	dijkstra(1);
	long long one_to_X = dist[X];
	long long one_to_Y = dist[Y];

	memset(dist, -1, sizeof(dist));
	dijkstra(X);
	long long interXY = dist[Y];

	memset(dist, -1, sizeof(dist));
	dijkstra(N);
	long long Y_to_N = dist[Y];
	long long X_to_N = dist[X];

	long long ANS(0);

	if (interXY == -1) ANS = -1;
	else
	{
		if ((one_to_X == -1 || Y_to_N == -1) && (one_to_Y != -1 && X_to_N != -1)) ANS = one_to_Y + interXY + X_to_N;
		else if ((one_to_X != -1 && Y_to_N != -1) && (one_to_Y == -1 || X_to_N == -1)) ANS = one_to_X + interXY + Y_to_N;
		else ANS = min(one_to_Y + interXY + X_to_N, one_to_X + interXY + Y_to_N);
	}
	cout << ANS << endl;

    return 0;
}

