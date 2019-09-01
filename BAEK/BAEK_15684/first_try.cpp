//// BAEK_15684. 사다리 조작
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int N, M, H, MAP[31][11], V[31][11];
//struct line { int a, b; };
//
//int doGame(int col_num)
//{
//	int num = col_num;
//	int h = 1;
//	while (h <= H)
//	{
//		if (MAP[h][num] != 0) num = MAP[h][num];
//		h++;
//	}
//	return num;
//}
//
//bool isAllSame()
//{
//	bool isSame = true;
//	for (int c = 1; c <= N; c++)
//	{
//		if (c != doGame(c))
//		{
//			isSame = false;
//			break;
//		}
//	}
//	return isSame;
//}
//
//void restore(int size, vector<line> &tmpv)
//{
//	for (int i = 0; i < size; i++)
//	{
//		int a = tmpv[i].a, b = tmpv[i].b;
//		MAP[a][b] = 0, MAP[a][b + 1] = 0;
//		if (b > 1) V[a][b - 1] = 0;
//		if (b < N - 1) V[a][b + 1] = 0;
//	}
//}
//
//bool setMap(int size, vector<line> &tmpv)
//{
//	bool isPossible = true;
//	for (int i = 0; i < size; i++)
//	{
//		int a = tmpv[i].a, b = tmpv[i].b;
//		if (V[a][b])
//		{
//			isPossible = false;
//			break;
//		}
//		MAP[a][b] = b + 1, MAP[a][b + 1] = b;
//		if (b > 1) V[a][b - 1] = 1;
//		if (b < N - 1) V[a][b + 1] = 1;
//	}
//	return isPossible;
//}
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	cin >> N >> M >> H;
//
//	// a, b => b번 세로줄이 b+1 줄에 a번째 가로줄 연걸
//	for (int i = 0; i < M; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		MAP[a][b] = b + 1, MAP[a][b + 1] = b;
//		V[a][b] = 1;
//		if (b > 1) V[a][b - 1] = 1;
//		if (b < N - 1) V[a][b + 1] = 1;
//	}
//
//	vector<line> candis;
//	for (int b = 1; b < N; b++)
//	{
//		for (int a = 1; a <= H; a++)
//		{
//			if (V[a][b] == 1) continue;
//			candis.push_back({ a, b });
//		}
//	}
//	int result = -1;
//	for (int cnt = 0; cnt <= 3; cnt++)
//	{
//		int vsize = candis.size();
//		vector<int> v(vsize, 1);
//		if (vsize >= cnt)
//			for (int i = 0; i < cnt; i++)
//				v[i] = 0;
//
//		int isFinded = false;
//
//		do
//		{
//			vector<line> tmpv;
//			for (int i = 0; i < vsize; i++)
//				if (v[i] == 0) tmpv.push_back(candis[i]);
//
//			// set map
//			if (setMap(tmpv.size(), tmpv))
//			{
//				if (isAllSame())
//				{
//					result = cnt;
//					isFinded = true;
//					break;
//				}
//			}
//			// restore map
//			restore(tmpv.size(), tmpv);
//		} while (next_permutation(v.begin(), v.end()));
//
//		if (isFinded) break;
//	}
//	cout << result << "\n";
//	return 0;
//}
