// BAEK_17472. 다리 만들기2

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define endl "\n"
#define INF 987654321
using namespace std;

int N, M, gMap[10][10], gNumMap[10][10], gMinDist[7][7];
// 상 우 하 좌
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
struct pos { int y, x; };
struct qpos { int y, x, dist; };
struct edge { int a, b, w; };
vector<pos> islands[7];

struct cmp
{
	bool operator()(const edge &t, const edge &u)
	{
		// min_heap
		if (t.w > u.w) return true;
		else if (t.w == u.w) return t.a > t.b;
		else return false;
	}
};
priority_queue<edge, vector<edge>, cmp> pq;

int gParent[7] = { 0,1,2,3,4,5,6 };

int getIslandNum()
{
	int islandNum = 1;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (gMap[y][x] == 0) continue;
			gNumMap[y][x] = islandNum; gMap[y][x] = 0;
			islands[islandNum].push_back({ y, x });
			queue<pos> q;
			q.push({ y, x });
			while (!q.empty())
			{
				pos now = q.front(); q.pop();
				int py = now.y, px = now.x;
				for (int i = 0; i < 4; i++)
				{
					int ny = py + dy[i], nx = px + dx[i];
					if (ny < 0 || ny > N - 1 || nx < 0 || nx > M - 1 || gMap[ny][nx] == 0) continue;
					
					q.push({ ny, nx });
					gNumMap[ny][nx] = islandNum;
					islands[islandNum].push_back({ ny, nx });
					gMap[ny][nx] = 0;
				}
			}
			islandNum++;
		}
	}
	return islandNum;
}

void getMinDistBetweenIsland(int nIsland)
{
	for (int y = 1; y <= nIsland; y++)
		for (int x = 1; x <= nIsland; x++)
			if(y != x) gMinDist[y][x] = INF;

	for (int n = 1; n <= nIsland; n++)
	{
		vector<pos> &island = islands[n];
		for (int p = 0; p < island.size(); p++)
		{
			pos &now = island[p];
			
			// 방향
			for (int i = 0; i < 4; i++)
			{
				int py = now.y, px = now.x;
				int dist = 0;
				while (1)
				{
					py += dy[i], px += dx[i];
					if (py < 0 || py > N - 1 || px < 0 || px > M - 1) break;
					if (gNumMap[py][px] > 0)
					{
						if (gNumMap[py][px] == n) break;
						else
						{
							if (dist > 1)
							{
								int target = gNumMap[py][px];
								gMinDist[n][target] = gMinDist[n][target] > dist ? dist : gMinDist[n][target];
							}
							break;
						}
					}
					dist++;
				}
			}
		}
	}
}

void getEdges(int nIsland)
{
	for (int a = 1; a < nIsland; a++)
		for (int b = a + 1; b <= nIsland; b++)
			if (gMinDist[a][b] != INF)
				pq.push({ a, b, gMinDist[a][b] });
}

int findParent(int child)
{
	if (gParent[child] == child) return gParent[child] = child;
	else return findParent(gParent[child]);
}

void merge(int left, int right)
{
	int pLeft = findParent(left);
	int pRight = findParent(right);

	if (pLeft == pRight) return;
	else
	{
		if (pLeft > pRight) swap(pLeft, pRight);
		gParent[pRight] = pLeft;
	}
}

int mst(int nIsland)
{
	int ans = 0;
	while (!pq.empty())
	{
		edge now = pq.top(); pq.pop();
		int a = now.a, b = now.b, w = now.w;
		int pa = findParent(a), pb = findParent(b);

		if (pa != pb) merge(a, b);
		else continue;
		ans += w;
	}
	
	int tmp = findParent(1);
	for (int i = 2; i <= nIsland; i++)
	{
		if (tmp != findParent(i))
		{
			ans = -1;
			break;
		}
	}
	return ans;
}

int main()
{
	cin >> N >> M;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> gMap[y][x];

	int nIsland = getIslandNum() - 1;
	getMinDistBetweenIsland(nIsland);
	getEdges(nIsland);

	int ans = mst(nIsland);

	cout << ans << endl;

	return 0;
}
