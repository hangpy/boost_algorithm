// BAEK_15685. 드래곤 커브

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, MAP[101][101];
struct line { int y, x, d, g;};
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };
int changeDir[4] = { 1, 2, 3, 0 };

void drawDragon(int y, int x, int d, int g)
{
	MAP[y][x] = 1;

	int ny = y + dy[d], nx = x + dx[d];
	MAP[ny][nx] = 1;
	vector<int> vd;
	vd.push_back(d);
	int cy = ny, cx = nx;
	while (g > 0)
	{
		for (int i = vd.size() - 1; i >= 0; i--)
		{
			int nd = changeDir[vd[i]];
			int next_y = cy + dy[nd], next_x = cx + dx[nd];
			if (next_y < 0 || next_y > 100 || next_x < 0 || next_x > 100) continue;
			MAP[next_y][next_x] = 1;
			cy = next_y, cx = next_x;
			vd.push_back(nd);
		}
		g--;
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	vector<line> initDragon;

	for (int i = 0; i < N; i++)
	{
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		initDragon.push_back({ y, x, d, g });
	}

	for (auto dg : initDragon)
		drawDragon(dg.y, dg.x, dg.d, dg.g);
	
	int result = 0;
	for (int y = 0; y <= 100; y++)
	{
		for (int x = 0; x <= 100; x++)
			if (MAP[y][x] == 1 && MAP[y + 1][x] == 1 && MAP[y][x + 1] == 1 && MAP[y + 1][x + 1] == 1)
				result++;
	}

	cout << result << endl;

	return 0;
}