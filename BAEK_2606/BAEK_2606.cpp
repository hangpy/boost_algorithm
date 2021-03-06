// BAEK_2606.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int N, P, V[101] = { 0 };
vector< vector<int> > adj(101);

int dfs(int node)
{
	int ans = 1;
	V[node] = 1;
	for (auto i : adj[node])
		if (!V[i]) ans += dfs(i);		
	return ans;
}

int main()
{
	cin >> N >> P;
	for (int i = 1; i <= P; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		// 만약 아래와 같은 무방향성 연결을 표현해주지 않는다면
		// 7 6 과 같은 쌍이 추가되도 방향성을 고려하기 때문에
		// 답이 6이 아니고 오답인 4가 나오게 된다.
		// 인접 리스트를 쓸 때는 반드시 엣지의 방향성 유무를 잘
		// 체크해야만 한다.
		adj[y].push_back(x);
	}

	// 노드 1의 카운트는 제외
	cout << dfs(1) - 1 << endl;
	
    return 0;
}

