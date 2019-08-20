//#include <iostream>
//#include <cstring>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//int N, M, K;
////				활성여부, 남은생명력, 활성까지남은시간
//struct CELL { int isActive, restLife, restTime; };
//struct POS { int y, x; };
//vector<CELL> MAP[350][350];
//int  V[350][350];
//
//
//// 상하좌우
//int dy[4] = { -1, 1, 0, 0 };
//int dx[4] = { 0, 0, -1, 1 };
//
//bool cmp(const CELL &t, const CELL &u)
//{
//	return t.restLife > u.restLife;
//}
//
//int main(int argc, char** argv)
//{
//	int T, cnt = 0;
//	ios::sync_with_stdio(0); cin.tie(0);
//	freopen("sample_input.txt", "r", stdin);
//	cin >> T;
//
//
//	for (int t = 1; t <= T; ++t)
//	{
//		cin >> N >> M >> K;
//		vector<POS> alives;
//		// MAP[150][150]을 왼쪽 위 기점으로 직사각형 분포
//		for (int y = 150; y < 150 + N; y++)
//		{
//			for (int x = 150; x < 150 + M; x++)
//			{
//				int restLife = 0;
//				cin >> restLife;
//				MAP[y][x].push_back({ 0, restLife, restLife });
//				V[y][x] = 1;
//				alives.push_back({ y,x });
//				cnt++;
//			}
//		}
//
//
//		int time = 0;
//		while (time < K)
//		{
//			vector<POS> tmpv;
//			vector<POS>::iterator it;
//			for (auto cell : alives)
//			{
//				CELL &ret = MAP[cell.y][cell.x][0];
//
//				if (ret.restLife == 0) continue;
//
//				if (ret.isActive == 0)
//				{
//					ret.restTime -= 1;
//					if (ret.restTime == 0) ret.isActive = 1;
//				}
//				// 활성화 되어 있다면
//				else
//				{
//					for (int i = 0; i < 4; i++)
//					{
//						int cy = cell.y, cx = cell.x;
//						int ny = cy + dy[i], nx = cx + dx[i];
//
//						if (V[ny][nx] == 1) continue;
//
//						// tmpv에 일단 넣기
//						tmpv.push_back({ ny, nx });
//						MAP[ny][nx].push_back({ 0, ret.restLife, ret.restLife });
//					}
//
//					ret.restLife -= 1;
//					if (ret.restLife == 0)
//					{
//						cnt--;
//					}
//				}
//			}
//
//			for (auto loc : tmpv)
//			{
//				int cy = loc.y, cx = loc.x;
//
//				// 겹치면
//				if (MAP[cy][cx].size() > 1)
//				{
//					vector<CELL> &v = MAP[cy][cx];
//					sort(v.begin(), v.end(), cmp);
//					CELL tmp = v[0];
//					v.clear();
//					v.push_back(tmp);
//					alives.push_back({ cy, cx });
//					V[cy][cx] = 1;
//					cnt++;
//				}
//				// 안겹치면
//				else
//				{
//					alives.push_back({ cy, cx });
//					V[cy][cx] = 1;
//					cnt++;
//				}
//			}
//			time++;
//		}
//
//
//		cout << "#" << t << " " << cnt << "\n";
//
//		memset(MAP, 0, sizeof(MAP));
//		memset(V, 0, sizeof(V));
//
//	}
//
//
//	return 0;
//}