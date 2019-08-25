//// BAEK_16236. 아기상어
//
//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//#include <cstring>
//#include <queue>
//
//using namespace std;
//
//int N, MAP[20][20], V[20][20];
//struct pos { int y, x; };
//struct qpos { int y, x, t; };
//struct info { int y, x, size, live; };
//
//int dy[4] = { 1, -1, 0, 0 };
//int dx[4] = { 0, 0, 1, -1 };
//
//
//// 타겟까지 도달하기까지 걸리는 시간 반환: 만약 0이면 도달할 수 없다는 뜻.
//int reach(const info &target, const pos &cur, int sharkSize)
//{
//	memset(V, 0, sizeof(V));
//
//	queue<qpos> q; q.push({ cur.y, cur.x, 0 });
//
//	V[cur.y][cur.x] = 1;
//
//	bool canReach = false;
//	int result = 0;
//
//	while (!q.empty())
//	{
//		int cy = q.front().y, cx = q.front().x, ct = q.front().t; q.pop();
//		for (int i = 0; i < 4; i++)
//		{
//			int ny = cy + dy[i], nx = cx + dx[i];
//			if (ny < 0 || ny > N - 1 || nx < 0 || nx > N - 1) continue;
//			if (MAP[ny][nx] > sharkSize || V[ny][nx] >= 1) continue;
//
//			q.push({ ny, nx, ct + 1 });
//			V[ny][nx] = 1;
//			if (ny == target.y && nx == target.x)
//			{
//				canReach = true;
//				result = ct + 1;
//				break;
//			}
//		}
//	}
//
//	if (canReach) return result;
//	else return 0;
//}
//
//int main()
//{
//	cin >> N;
//	pos shark_pos;
//	vector<info> fishes;
//
//
//	for (int y = 0; y < N; y++)
//	{
//		for (int x = 0; x < N; x++)
//		{
//			int a;
//			cin >> a; MAP[y][x] = a;
//			if (0 < a && a < 7) fishes.push_back({ y, x, a, 1 });
//			if (a == 9) shark_pos = { y, x }, MAP[y][x] = 0;
//		}
//	}
//
//
//	int time = 0;
//	int sharkSize = 2;
//	int eat = 0;
//
//	while (true)
//	{
//		vector<int> fishesToEat;
//
//		for (int i = 0; i < fishes.size(); i++)
//			if (fishes[i].live == 1 && fishes[i].size < sharkSize)
//				fishesToEat.push_back(i);
//
//		int min = numeric_limits<int>::max();
//		info prev;
//		int idx;
//		bool canEat = false;
//		for (auto index : fishesToEat)
//		{
//			info &fish = fishes[index];
//			int result = reach(fish, shark_pos, sharkSize);
//			if (result != 0)
//			{
//				canEat = true;
//				if (result < min) min = result, prev = fish, idx = index;
//				else if (result == min)
//				{
//					if (fish.y < prev.y) prev = fish, idx = index;
//					else if (fish.y == prev.y)
//					{
//						if (fish.x < prev.x) prev = fish, idx = index;
//					}
//					else;
//				}
//				else;
//			}
//		}
//
//		if (canEat == true)
//		{
//			time += min;
//			fishes[idx].live = 0;
//			shark_pos = { fishes[idx].y, fishes[idx].x };
//			MAP[fishes[idx].y][fishes[idx].x] = 0;
//			eat++;
//			if (eat == sharkSize) sharkSize++, eat = 0;
//		}
//		else break;
//	}
//
//
//	cout << time << endl;
//
//
//	return 0;
//}