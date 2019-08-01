#include <cstdio>
#include <vector>
using namespace std;

struct bug {int y, x, num, dir, tmp;};
vector<bug> ks;
int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, -1, 1 };
int changeDir[5] = { 0, 2, 1, 4, 3 };



int main()
{
	freopen("sample_input.txt", "r", stdin);

	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		int N, M, K;
		scanf("%d%d%d", &N, &M, &K);
		ks.clear(); ks.resize(K);

		// 입력값 초기화
		for (int k = 0; k < K; k++)
		{
			int y, x, num, dir;
			scanf("%d %d %d %d", &ks[k].y, &ks[k].x, &ks[k].num, &ks[k].dir);
		}
		
		// m시간동안 이동
		for (int m = 1; m <= M; m++)
		{
			// 이동
			for (int k = 0; k < ks.size(); k++)
			{
				ks[k].y += dy[ks[k].dir];
				ks[k].x += dx[ks[k].dir];					
				if (ks[k].y == 0 || ks[k].x == 0 || ks[k].y == N - 1 || ks[k].x == N - 1)
				{
					ks[k].num /= 2;
					ks[k].dir = changeDir[ks[k].dir];
				}
				ks[k].tmp = ks[k].num;
			}

			for (int i = 0; i < ks.size() - 1; i++)
			{
				for (int j = i + 1; j < ks.size(); j++)
				{
					if (ks[i].y == ks[j].y && ks[i].x == ks[j].x)
					{
						ks[i].dir = ((ks[i].tmp < ks[j].tmp) ? ks[j].dir : ks[i].dir);

						// 이부분!!!! num, tmp 둘다 됨.
						ks[i].tmp = ((ks[i].num < ks[j].num) ? ks[j].num : ks[i].num);
						ks[i].num += ks[j].num;
						ks.erase(ks.begin() + j); j-=1;
					}
				}
			}						
		}

		int rest = 0;
		for (auto bug : ks) rest += bug.num;
		printf("#%d %d\n", t, rest);
	}
	
	return 0;
}


//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//struct me {
//
//	int ii, jj, num, d, ttmp;
//
//};
//
//int N, M, K;
//int dir[5][2] = { {0,0}, {-1,0},{1,0},{0,-1},{0,1} };
//vector<me> m;
//
//int cal(int time, int me_n) {
//
//	while (time--) {
//
//		for (int i = 0; i < m.size(); i++) { // move
//
//			m[i].ii += dir[m[i].d][0]; m[i].jj += dir[m[i].d][1];
//
//			m[i].ttmp = m[i].num;
//
//		}
//
//		for (int i = 0; i < m.size() - 1; i++) { // combine
//
//			for (int j = i + 1; j < m.size(); j++) {
//
//				if (m[i].ii == m[j].ii && m[i].jj == m[j].jj) {
//
//					m[i].d = ((m[i].ttmp > m[j].ttmp) ? m[i].d : m[j].d);
//
//					m[i].ttmp = ((m[i].num > m[j].num) ? m[i].num : m[j].num);
//
//					m[i].num += m[j].num;
//
//					m.erase(m.begin() + j); j -= 1;
//
//				}
//
//			}
//
//		}
//
//		for (int i = 0; i < m.size(); i++) { // red
//
//			if (m[i].ii == 0 || m[i].ii == N - 1 || m[i].jj == 0 || m[i].jj == N - 1) {
//
//				int tmp = m[i].num; tmp /= 2; me_n -= (m[i].num - tmp); m[i].num /= 2;
//
//				if (m[i].d % 2 == 0) m[i].d -= 1;
//
//				else m[i].d += 1;
//
//			}
//
//		}
//
//	}
//
//	return me_n;
//
//}
//
//
//
//int main() {
//
//
//
//	std::ios::sync_with_stdio(false);
//	freopen("sample_input.txt", "r", stdin);
//	int T; cin >> T;
//
//	for (int tc = 1; tc <= T; tc++) {
//
//		cin >> N >> M >> K; m.clear(); m.resize(K); int tmpSum = 0;
//
//		for (int i = 0; i < K; i++) {
//
//			cin >> m[i].ii >> m[i].jj >> m[i].num >> m[i].d;
//
//			tmpSum += m[i].num;
//
//		}
//
//		cout << "#" << tc << " " << cal(M, tmpSum) << endl;
//
//	}
//
//	return 0;
//
//}


// 3ms의 엄청난 풀이

//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
//#define NONE 0
//#define MAX 1000
//
//const int d[5][2] = {
//	{ NONE, NONE },
//	{ -1, 0 },
//	{ 1 , 0 },
//	{ 0 ,-1 },
//	{ 0 , 1 }
//};
//
//int N, M, K;
//
//struct GROUP
//{
//	int r, c;
//	int cnt;
//	int dIdx;
//};
//
//GROUP groups[MAX];
//int clusterList[100][100][MAX];
//int clusterCnt[100][100];
//
//bool isDrugArea(int r, int c)
//{
//	return r == 0 || r == N - 1 || c == 0 || c == N - 1;
//}
//
//void reverseDir(int &nowDir)
//{
//	if (nowDir == 1)
//		nowDir = 2;
//	else if (nowDir == 2)
//		nowDir = 1;
//	else if (nowDir == 3)
//		nowDir = 4;
//	else
//		nowDir = 3;
//}
//void input()
//{
//	scanf("%d %d %d", &N, &M, &K);
//
//	for (int i = 0; i < K; ++i)
//	{
//		GROUP &now = groups[i];
//		scanf("%d %d %d %d", &now.r, &now.c, &now.cnt, &now.dIdx);
//	}
//}
//
//void move()
//{
//	for (int i = 0; i < K; ++i)
//	{
//		GROUP &now = groups[i];
//		if (now.cnt == NONE)
//			continue;
//
//		now.r += d[now.dIdx][0];
//		now.c += d[now.dIdx][1];
//
//		if (isDrugArea(now.r, now.c))
//		{
//			now.cnt /= 2;
//			reverseDir(now.dIdx);
//		}
//		int &cnt = clusterCnt[now.r][now.c];
//		clusterList[now.r][now.c][cnt] = i;
//		++cnt;
//	}
//}
//
//void merge()
//{
//	for (int i = 0; i < K; ++i)
//	{
//		GROUP &now = groups[i];
//
//		if (now.cnt == NONE)
//			continue;
//
//		if (clusterCnt[now.r][now.c] == 1)
//		{
//			clusterCnt[now.r][now.c] = 0;
//			continue;
//		}
//
//		int maxGroup = 0, maxCnt = -1;
//		for (int j = 0; j < clusterCnt[now.r][now.c]; ++j)
//		{
//			int groupIdx = clusterList[now.r][now.c][j];
//			GROUP &cur = groups[groupIdx];
//
//			if (cur.cnt > maxCnt)
//			{
//				maxCnt = cur.cnt;
//				maxGroup = groupIdx;
//			}
//		}
//
//		GROUP &king = groups[maxGroup];
//		for (int j = 0; j < clusterCnt[now.r][now.c]; ++j)
//		{
//			int groupIdx = clusterList[now.r][now.c][j];
//
//			if (groupIdx == maxGroup)
//				continue;
//
//			GROUP &cur = groups[groupIdx];
//			king.cnt += cur.cnt;
//			cur.cnt = NONE;
//		}
//
//		clusterCnt[now.r][now.c] = 0;
//	}
//}
//
//int calcCnt()
//{
//	int total = 0;
//	for (int i = 0; i < K; ++i)
//		total += groups[i].cnt;
//	return total;
//}
//
//int sol()
//{
//	while (M--)
//	{
//		// 1. 이동
//		move();
//
//		// 2. 합치기
//		merge();
//	}
//
//	return calcCnt();
//}
//
//int main()
//{
//	//freopen("1.txt", "r", stdin);
//
//	int T;
//	scanf("%d", &T);
//
//	for (int tc = 1; tc <= T; ++tc)
//	{
//		input();
//		printf("#%d %d\n", tc, sol());
//	}
//
//	return 0;
//}