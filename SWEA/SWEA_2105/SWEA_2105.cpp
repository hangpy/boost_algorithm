// SWEA_2105. 디저트 카페

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct pos { 
	int y, x; 
};
int T, N, MAP[21][21];
int V[101];
// 왼쪽 위부터 오른쪽으로 차례로
int dy[4] = {-1, -1, 1, 1};
int dx[4] = {-1, 1, 1, -1};
int chdir[4] = { 1, 2, 3, 0 };

int dfs(pos cur, int dir, int cnt, pos& start)
{
	V[MAP[cur.y][cur.x]] = 1;
	int result = -1;

	int cy = cur.y, cx = cur.x;

	if (cnt != 0 && cy == start.y && cx == start.x)
	{
		return cnt;
	}

	// 두갈래로 분기
	int ny = cy + dy[dir], nx = cx + dx[dir];
	if (!(ny < 1 || ny > N || nx < 1 || nx > N || (V[MAP[ny][nx]] == 1 && (ny != start.y || nx != start.x))))
		result = max(result, dfs({ ny, nx }, dir, cnt + 1, start));

	if (dir != 1 && cnt != 0)
	{
		ny = cy + dy[chdir[dir]], nx = cx + dx[chdir[dir]];
		if (!(ny < 1 || ny > N || nx < 1 || nx > N || (V[MAP[ny][nx]] == 1 && (ny != start.y || nx != start.x))))
			result = max(result, dfs({ ny, nx }, chdir[dir], cnt + 1, start));
	}
	// 각각 최대값 병합 판별

	
	V[MAP[cur.y][cur.x]] = 0;

	return result;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		

		cin >> N;
		
		for (int y = 1; y <= N; y++)
			for (int x = 1; x <= N; x++)
				cin >> MAP[y][x];
		
		int ANS = -1;
		for (int y = 1; y <= N - 2; y++)
		{
			for (int x = 2; x <= N - 1; x++)
			{
				memset(V, 0, sizeof(V));
				pos cpos = { y,x };
				ANS = max(ANS, dfs({ y,x }, 2, 0, cpos));
			}
		}


		cout << "#" << t << " " << ANS << endl;
	}
	
	return 0;
}