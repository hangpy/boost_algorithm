// BAEK_10775. 공항

#include <iostream>
#define endl "\n"

using namespace std;

int G, P, parent[100001], air[100000];

int find(int p)
{
	if (p == parent[p]) return p;
	else return parent[p] = find(parent[p]);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> G >> P;
	for (int i = 1; i <= G; i++) parent[i] = i;
	for (int i = 0; i < P; i++) cin >> air[i];

	int cnt = 0;
	for (int i = 0; i < P; i++)
	{
		int toDock = find(air[i]);
		// merge 부분
		if (toDock != 0) parent[toDock] = parent[toDock - 1], cnt++;
		else break;
	}
	cout << cnt << endl;

	return 0;
}