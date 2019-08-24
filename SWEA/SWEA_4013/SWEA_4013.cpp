// SWEA_4013. 특이한 자석

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int T, K, visit[5];
struct chain { int num, dir; };

void rotate(vector<int>& v, int dir)
{
	// 시계 방향
	if (dir == 1)
	{
		int tmp = v[7];
		v.erase(v.end() - 1);
		v.insert(v.begin(), tmp);
	}
	// 반시계 방향
	else
	{
		int tmp = v[0];
		v.erase(v.begin());
		v.push_back(tmp);
	}
}

void dfs(vector<chain> &v, vector<int> *chains, int num, int dir)
{
	if (num < 1 || num > 4) return;

	visit[num] = 1;
	v.push_back({ num, dir });

	if (num > 1)
		if(visit[num - 1] == 0 && chains[num][6] != chains[num-1][2])
			dfs(v, chains, num - 1, (dir == 1 ? -1 : 1));
	
	
	if (num < 4)
		if (visit[num + 1] == 0 && chains[num][2] != chains[num + 1][6])
			dfs(v, chains, num + 1, (dir == 1 ? -1 : 1));
	
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	freopen("sample_input.txt", "r", stdin);

	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		vector<int> chains[5];

		cin >> K;
		for (int i = 1; i <= 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				int a; cin >> a;
				chains[i].push_back(a);
			}
		}

		for (int k = 0; k < K; k++)
		{
			int n, d;
			cin >> n >> d;

			vector<chain> tmp;
			dfs(tmp, chains, n, d);
			memset(visit, 0, sizeof(visit));

			for (auto chain : tmp)
				rotate(chains[chain.num], chain.dir);
		}

		int sum = 0;
		for (int i = 1; i <= 4; i++)
			if (chains[i][0] == 1) sum += pow(2, i - 1);

		cout << "#" << t << " " << sum << endl;
	}
	return 0;
}
