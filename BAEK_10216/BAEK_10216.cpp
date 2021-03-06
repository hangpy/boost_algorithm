// BAEK_10216.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

typedef struct point
{
	int x;
	int y;
	int r;
} point;

int T, N;
int V[3001];
point ens[3001];
vector<int> adj[3001];
vector<int> ANS;

void dfs(int node)
{	
	// check as visited
	V[node] = 1;

	for (auto n : adj[node])
		if (!V[n]) dfs(n);
}

int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int cnt = 0;
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			int x, y, r;
			cin >> x >> y >> r;
			ens[i] ={ x, y, r };
		}

		// make adjcent list
		for (int i = 1; i <= N-1; i++)
		{
			for (int j = i + 1; j <= N; j++)
			{
				point e1 = ens[i];
				point e2 = ens[j];

				// validate whether direct conn is possible
				// sqrt를 쓰는 것 보다 양측에 pow를 함으로써 부동소수점의 버그 가능성을 제거!
				if (pow(e1.x - e2.x, 2) + pow(e1.y - e2.y, 2) <= pow(e1.r + e2.r, 2))
																// 실수구간. e2를 계속 e1로 하고 계산함.
				{
					// make adj
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}


		for (int i = 1; i <= N; i++)
		{
			if (!V[i])
			{
				cnt++;
				dfs(i);
			}
		}

		// answer
		ANS.push_back(cnt);

		// clear for next test case
		for (int i = 1; i <= N; i++)
			adj[i].clear();
		memset(V, 0, sizeof(V));
	}

	for (auto i : ANS)
		cout << i << endl;

    return 0;
}
