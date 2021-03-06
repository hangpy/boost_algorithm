// BAEK_1325.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N, M, check[10001]{ 0 };
bool visted[10001]{ 0 };
vector<int> adj[10001];
vector<int> ans;


int dfs(int node)
{
	int ans(1);
	
	// logic
	for (auto next_node : adj[node])
	{
		if (!visted[next_node])
		{
			visted[next_node] = true;
			ans += dfs(next_node);
		}
	}
	return ans;
}


int main()
{
	cin >> N >> M;
	for (int m = 1; m <= M; m++)
	{
		int from, to;
		cin >> from >> to;
		// make adjacent
		adj[to].push_back(from);
		check[to] = 1;
	}

	// searching and save simultaneously get max vec arr;
	int MAX(0);
	for (int i = 1; i <= N; i++)
	{
		if (check[i])
		{
			visted[i] = true;
			check[i] = dfs(i);
			if (MAX < check[i])
			{
				MAX = check[i];
				ans.clear();
				ans.push_back(i);
			}
			else if (MAX == check[i]) ans.push_back(i);
			else;
			// again initialize
			memset(visted, 0, sizeof(visted));
		}
	}

	// 아래 코드는 위에 노드를 찾으면서 동시에 연산 가능
	/*int MAX(0);
	for (int i = 1; i <= N; i++)
	{
		if (check[i] == 0) continue;
		if (MAX < check[i])
		{
			MAX = check[i];
			ans.clear();
			ans.push_back(i);
		}
		else if (MAX == check[i])
		{
			ans.push_back(i);
		}
		else continue;
	}*/

	// cout answer
	sort(ans.begin(), ans.end());
	for (auto i : ans)
		cout << i << " ";
	cout << endl;


    return 0;
}

