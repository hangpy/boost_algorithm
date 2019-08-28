//// BAEK_13460. 구슬탈출2
//
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int N, M, MAP[10][10], CMAP[10][10];
//
//int dy[4] = { 1, -1, 0, 0 };
//int dx[4] = { 0, 0, -1, 1 };
//int DIR[10];
//struct pos { int y, x; };
//pos ball[2]; // ball[0]: RED, ball[1]: BLUE
//pos cball[2];
//
//bool incline(int color, int dir)
//{
//	bool fall = false;
//	int cy = cball[color].y, cx = cball[color].x;
//
//	int opositeColor = color == 0 ? 4 : 3;
//
//	while (true)
//	{
//		int ny = cy + dy[dir], nx = cx + dx[dir];
//
//		if (CMAP[ny][nx] == 1) break;
//		if (CMAP[ny][nx] == opositeColor) break;
//		if (CMAP[ny][nx] == 2)
//		{
//			fall = true;
//			CMAP[cy][cx] = 0;
//			break;
//		}
//
//		swap(CMAP[cy][cx], CMAP[ny][nx]);
//		cy = ny, cx = nx;
//	}
//
//	cball[color] = { cy, cx };
//
//	return fall;
//}
//
//bool dfs(int index, int times)
//{
//	bool pass = false;
//	if (index == times)
//	{
//		memcpy(CMAP, MAP, sizeof(MAP));
//		memcpy(cball, ball, sizeof(ball));
//
//		// times만큼 DIR에 있는 방향으로 기울이기
//		bool redIn = false, blueIn = false;
//		for (int i = 0; i < times; i++)
//		{
//			int dir = DIR[i];
//
//			// 두번 하면 됨.
//			redIn = incline(0, dir);
//			blueIn = incline(1, dir);
//
//			if (redIn == false) redIn = incline(0, dir);
//			if (blueIn == false) blueIn = incline(1, dir);
//
//			if (redIn == true && blueIn == false)
//			{
//				pass = true;
//				break;
//			}
//			if (redIn == true && blueIn == true) break;
//			if (redIn == false && blueIn == true) break;
//		}
//		return pass;
//	}
//
//	for (int d = 0; d < 4; d++)
//	{
//		DIR[index] = d;
//		pass = pass | dfs(index + 1, times);
//		if (pass) break;
//	}
//
//	return pass;
//}
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//
//	cin >> N >> M;
//
//	for (int y = 0; y < N; y++)
//	{
//		for (int x = 0; x < M; x++)
//		{
//			char a;
//			cin >> a;
//			switch (a)
//			{
//			case '.':
//				MAP[y][x] = 0;
//				break;
//			case '#':
//				MAP[y][x] = 1;
//				break;
//			case 'O':
//				MAP[y][x] = 2;
//				break;
//			case 'R':
//				ball[0] = { y, x };
//				MAP[y][x] = 3;
//				break;
//			case 'B':
//				ball[1] = { y, x };
//				MAP[y][x] = 4;
//				break;
//			default:
//				break;
//			}
//		}
//	}
//
//	// 해당 횟수에서 찾았으면 반환
//	bool inHole = false;
//	int result = -1;
//	for (int i = 1; i <= 10; i++)
//	{
//		inHole = dfs(0, i);
//		if (inHole)
//		{
//			result = i;
//			break;
//		}
//	}
//
//	cout << result << endl;
//
//
//	return 0;
//}
