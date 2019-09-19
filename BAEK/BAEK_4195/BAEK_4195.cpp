// BAEK_4195. 친구 네트워크

#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#define endl "\n"

using namespace std;

int T, F, parent[200002], cnt[200002];

int find(int p)
{
	if (parent[p] == p) return p;
	else return parent[p] = find(parent[p]);
}

void merge(int l, int r)
{
	int leftParent = find(l);
	int rightParent = find(r);

	if (leftParent == rightParent) return;

	if (leftParent > rightParent) swap(leftParent, rightParent);

	parent[rightParent] = leftParent;
	cnt[leftParent] += cnt[rightParent];
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> F;
		int num = 0;
		map<string, int> nameMap;
		for (int i = 0; i < F; i++)
		{
			string f1, f2;
			cin >> f1 >> f2;
			if (nameMap.count(f1) == 0) nameMap[f1] = num, parent[num] = num, cnt[num++] = 1;
			if (nameMap.count(f2) == 0) nameMap[f2] = num, parent[num] = num, cnt[num++] = 1;

			merge(nameMap[f1], nameMap[f2]);

			cout << cnt[find(nameMap[f1])] << endl;
		}
	}
	return 0;
}