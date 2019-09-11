//// BAEK_17070. 파이트 옮기기
//
//#include <iostream>
//
//using namespace std;
//
//struct pos { int  y, x; };
//int N, MAP[17][17];
//
//int dy[3] = { 0, 1, 1 };
//int dx[3] = { 1, 1, 0 };
//int changeState[3] = { 0, 1, 2 };
//
//int dfs(int state, pos endPoint)
//{
//	int cnt = 0;
//	int cy = endPoint.y, cx = endPoint.x;
//	if (cy == N && cx == N) return 1;
//
//	if (state == 0) // 가로
//	{
//		for (int i = 0; i <= 1; i++)
//		{
//			int ny = cy + dy[i], nx = cx + dx[i], ns = changeState[i];
//			if (ny > N || nx > N || MAP[ny][nx]) continue;
//			if (ns == 1 && (MAP[ny][nx] || MAP[ny - 1][nx] || MAP[ny][nx - 1])) continue;
//			cnt += dfs(ns, { ny, nx });
//		}
//	}
//	else if (state == 1) // 대각선
//	{
//		for (int i = 0; i <= 2; i++)
//		{
//			int ny = cy + dy[i], nx = cx + dx[i], ns = changeState[i];
//			if (ny > N || nx > N || MAP[ny][nx]) continue;
//			if (ns == 1 && (MAP[ny][nx] || MAP[ny - 1][nx] || MAP[ny][nx - 1])) continue;
//			cnt += dfs(ns, { ny, nx });
//		}
//	}
//	else // 세로
//	{
//		for (int i = 1; i <= 2; i++)
//		{
//			int ny = cy + dy[i], nx = cx + dx[i], ns = changeState[i];
//			if (ny > N || nx > N || MAP[ny][nx]) continue;
//			if (ns == 1 && (MAP[ny][nx] || MAP[ny - 1][nx] || MAP[ny][nx - 1])) continue;
//			cnt += dfs(ns, { ny, nx });
//		}
//	}
//	return cnt;
//}
//
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0);
//
//	cin >> N;
//	for (int y = 1; y <= N; y++)
//		for (int x = 1; x <= N; x++)
//			cin >> MAP[y][x];
//
//	int ans = dfs(0, { 1, 2 });
//
//	cout << ans << endl;
//	return 0;
//}
