// tmo_practice.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
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
		for(int m = 1; m <= M; m++)
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

