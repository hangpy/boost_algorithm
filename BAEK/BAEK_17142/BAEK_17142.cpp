// BAEK_17142. 연구소3

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define endl "\n"

using namespace std;

struct pos { int y, x; };
struct post { int y, x, t; };
int gMap[50][50], gTmp[50][50], N, M;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int getTime(vector<pos> &activeViruses, int emptySpace)
{
	memcpy(gTmp, gMap, sizeof gMap);

	queue<post> q;
	for (int i = 0; i < activeViruses.size(); i++)
	{
		q.push({ activeViruses[i].y, activeViruses[i].x, 0 });
		gTmp[activeViruses[i].y][activeViruses[i].x] = 1;
	}
	
	int time = 0;
	while (!q.empty())
	{
		// viruse pos
		post p = q.front(); q.pop();
		int py = p.y, px = p.x, pt = p.t;
		for (int d = 0; d < 4; d++)
		{
			int ny = py + dy[d], nx = px + dx[d];
			// 0: empty, 1: wall, 2:virus
			if (ny < 0 || ny > N - 1 || nx < 0 || nx > N - 1 || gTmp[ny][nx] == 1) continue;
			
			if (gTmp[ny][nx] == 0)
			{
				emptySpace--;
				time = time < pt + 1 ? pt + 1 : time;
			}
			gTmp[ny][nx] = 1;
			q.push({ ny, nx, pt + 1 });
		}
	}
	if (emptySpace == 0) return time;
	else return -1;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;

	vector<pos> viruses;
	int emptySpace = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			// 0: empty, 1: wall, 2:virus
			cin >> gMap[y][x];
			if (gMap[y][x] == 2) viruses.push_back({ y, x });
			if (gMap[y][x] == 0) emptySpace++;
		}
	}

	int ans = 987654321;
	bool canFull = false;
	vector<int> v(viruses.size(), 1);
	for (int i = 0; i < M; i++) v[i] = 0;
	do
	{
		vector<pos> activeViruses;
		for (int i = 0; i < v.size(); i++)
			if (v[i] == 0) activeViruses.push_back(viruses[i]);

		int tmp = getTime(activeViruses, emptySpace);
		
		if (tmp != -1) ans = ans > tmp ? tmp : ans, canFull = true;

	} while (next_permutation(v.begin(), v.end()));

	cout << (canFull == true ? ans : -1) << endl;

	return 0;
}
