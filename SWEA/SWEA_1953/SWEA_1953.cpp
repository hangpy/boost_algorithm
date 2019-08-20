// SWEA_1953. 탈주범 검거

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int T, N, M, R, C, L, MAP[50][50], V[50][50];
// 위부터 시계방향
int isOpen[8][4] =
{
	{0,0,0,0},
	{1,1,1,1},
	{1,0,1,0},
	{0,1,0,1},
	{1,1,0,0},
	{0,1,1,0},
	{0,0,1,1},
	{1,0,0,1},
};
// 0: 위 부터 시계방향
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
// 마주보는 방향 표시 상 우 하 좌 <-> 하 좌 상 우
int opposite[4] = { 2, 3, 0, 1 };
struct pos { int y, x, d; };


// 틀린 DFS 방식! 해당 문제에서는 DFS가 별로 좋지 않음
//int dfs(int y, int x, int depth)
//{
//	
//	int cnt = V[y][x] == 1 ? 0 : 1;
//	V[y][x] = 1;
//
//	if (depth == 0) return cnt;
//	int pipe = MAP[y][x];
//	
//	for (int i = 0; i < 4; i++)
//	{
//		// 현재의 파이프가 해당 방향으로 방향이 없으면 무시
//		if (isOpen[pipe][i] != 1) continue;
//		int ny = y + dy[i], nx = x + dx[i];
//
//		// 이미 방문한 곳이면 무시
//		if (ny < 0 || ny > N-1 || nx < 0 || nx > M-1) continue;
//
//		// 다음 진입점의 반대 방향으로 뚫려 있지 않으면 무시
//		if (isOpen[MAP[ny][nx]][opposite[i]] != 1) continue;
//
//		cnt += dfs(ny, nx, depth - 1);
//	}
//	return cnt;
//}



int bfs(int y, int x, int depth)
{
	queue<pos> q;
	q.push({ y,x });
	int cnt = 0;

	while (!q.empty())
	{
		int cy = q.front().y, cx = q.front().x, cd = q.front().d; q.pop();

		// 요기가 키포인트!
		if (V[cy][cx] == 0) cnt++;
		V[cy][cx] = 1;

		int pipe = MAP[cy][cx];

		for (int i = 0; i < 4; i++)
		{
			// 깊이로 모두 들어갔으면 무시
			if (cd == depth) continue;
			// 현재의 파이프가 해당 방향으로 방향이 없으면 무시
			if (isOpen[pipe][i] != 1) continue;
			int ny = cy + dy[i], nx = cx + dx[i];

			// 이미 방문한 곳이거나 경계를 넘으면 무시
			if (V[ny][nx] == 1 || ny < 0 || ny > N - 1 || nx < 0 || nx > M - 1) continue;

			// 다음 진입점의 반대 방향으로 뚫려 있지 않으면 무시
			if (isOpen[MAP[ny][nx]][opposite[i]] != 1) continue;

			q.push({ ny, nx, cd + 1 });
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> N >> M >> R >> C >> L;
		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				cin >> MAP[y][x];
				
		int ANS = 0;
		ANS = bfs(R, C, L-1);

		cout << "#" << t << " " << ANS << "\n";

		memset(V, 0, sizeof(V));
		memset(MAP, 0, sizeof(MAP));
	}

	return 0;
}

