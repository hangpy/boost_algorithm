// BAEK_16234. 인구이동

#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int N, L, R, MAP[50][50], V[50][50];
struct pos { int y, x; };
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool bfs(pos curNation)
{
	bool doMove = false;
	int people = MAP[curNation.y][curNation.x];
	queue<pos> q;
	vector<pos> cluster;
	q.push(curNation), cluster.push_back(curNation);
	V[curNation.y][curNation.x] = 1;
	while (!q.empty())
	{
		int cy = q.front().y, cx = q.front().x; q.pop();
		int cp = MAP[cy][cx];
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i], nx = cx + dx[i], np = MAP[ny][nx];
			if (ny < 0 || ny > N - 1 || nx < 0 || nx > N - 1 || V[ny][nx]) continue;

			int diff = abs(cp - np);
			if (!(L <= diff && diff <= R)) continue;
			
			V[ny][nx] = 1;
			q.push({ ny, nx });
			cluster.push_back({ ny, nx });
			people += MAP[ny][nx];
		}
	}
	
	if (cluster.size() > 1)
	{
		doMove = true;
		// update MAP
		int size = cluster.size();
		int avg = people / size;
		for (int i = 0; i < size; i++)
			MAP[cluster[i].y][cluster[i].x] = avg;
	}
	return doMove;
}


int main()
{
 
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> L >> R;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> MAP[y][x];
		
	int cnt = 0;
	while (1)
	{
		bool doMove = false;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (V[y][x]) continue;
				if (bfs({ y, x })) doMove = true;
			}
		}
		if (doMove) cnt++, memset(V, 0, sizeof V);
		else break;
	}
	cout << cnt << endl;
	return 0;
}