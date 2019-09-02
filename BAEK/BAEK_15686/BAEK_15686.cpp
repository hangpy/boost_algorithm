// BAEK_15686. 치킨배달

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <limits>

using namespace std;

int N, M, MAP[51][51];
struct pos { int y, x; };
pos stores[13], homes[100];

int getChickenDistance(pos &home, vector<pos> &stores)
{
	int ans = 987654321; int len = stores.size();
	for (int i = 0; i < len; i++)
	{
		int d = abs(home.y - stores[i].y) + abs(home.x - stores[i].x);
		ans = ans > d ? d : ans;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int hcnt = 0, scnt = 0;
	cin >> N >> M;
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			cin >> MAP[y][x];
			if (MAP[y][x] == 1) homes[hcnt] = { y, x }, hcnt++;
			if (MAP[y][x] == 2) stores[scnt] = { y, x }, scnt++;
		}
	}

	int ans = numeric_limits<int>::max();
	vector<int> v(scnt, 1);
	for (int i = 0; i < M; i++) v[i] = 0;
	do
	{
		vector<pos> selected;
		for (int i = 0; i < scnt; i++)
			if (v[i] == 0) selected.push_back(stores[i]);

		// get city chicken distance
		int tmp = 0;
		for (int i = 0; i < hcnt; i++)
			tmp += getChickenDistance(homes[i], selected);

		ans = ans > tmp ? tmp : ans;

	} while (next_permutation(v.begin(), v.end()));
	
	cout << ans << endl;

	return 0;
}





//int dy[4] = { 1, -1, 0, 0 };
//int dx[4] = { 0, 0, 1, -1 };
//int V[51][51];
//struct element { int y, x, d; };

//int bfs(pos home)
//{
//	int result = 987654321;
//	queue<element> q;
//	q.push({ home.y, home.x, 0 });
//	V[home.y][home.x] = 1;
//
//	while (!q.empty())
//	{
//		int cy = q.front().y, cx = q.front().x, cd = q.front().d; q.pop();
//		int find = false;
//		for (int i = 0; i < 4; i++)
//		{
//			int ny = cy + dy[i], nx = cx + dx[i];
//			if (ny < 1 || ny > N || nx < 1 || nx > N || V[ny][nx]) continue;
//			q.push({ ny, nx, cd + 1 });
//			V[ny][nx] = 1;
//			if (MAP[ny][nx] == 2)
//			{
//				find = true;
//				result = cd + 1;
//				break;
//			}
//		}
//		if (find) break;
//	}
//
//	memset(V, 0, sizeof V);
//	return result;
//}
