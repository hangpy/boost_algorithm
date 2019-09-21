// BAEK_1976. 여행

#include <iostream>
#include <utility>

using namespace std;

int N, M, parent[201];

int find(int p)
{
	if (p == parent[p]) return p;
	else return parent[p] = find(parent[p]);
}

void merge(int l, int r)
{
	int lp = find(l);
	int rp = find(r);

	if (lp > rp) swap(lp, rp);
	parent[rp] = lp;
}


int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int con; cin >> con;
			if (i < j) if(con) merge(i, j);
		}
	}
	
	int allConnected = true; int f; cin >> f;
	int tmp = find(f);
	for (int i = 1; i < M; i++)
	{
		int t; cin >> t;
		if (tmp != find(t)) 
		{
			allConnected = false;
			break;
		}
	}
	if (allConnected) cout << "YES" << "\n";
	else cout << "NO" << "\n";


	return 0;
}