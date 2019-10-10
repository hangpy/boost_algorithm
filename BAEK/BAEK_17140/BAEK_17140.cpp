// BAEK_17140. 이차원 배열과 연산

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define endl "\n"

using namespace std;

struct nc
{
	int num, cnt;
};

int gMap[100][100], num[101];

bool cmp(nc &t, nc &u)
{
	// 오름차순
	if (t.cnt < u.cnt) return true;
	else if (t.cnt == u.cnt)
	{
		if (t.num < u.num) return true;
		else return false;
	}
	else return false;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int r, c, k;

	cin >> r >> c >> k;

	int nrow = 3, ncol = 3;
	for (int y = 0; y < nrow; y++)
		for (int x = 0; x < ncol; x++)
			cin >> gMap[y][x];

	int t = 0;
	while (gMap[r-1][c-1] != k)
	{
		t++;
		if (t > 100) break;
		// 행 수 >= 열 수
		if (nrow >= ncol)
		{
			// 행 순회
			int tncol = ncol;
			for (int y = 0; y < nrow; y++)
			{
				memset(num, 0, sizeof num);
				vector<nc> v;
				for (int x = 0; x < ncol; x++) num[gMap[y][x]]++;
				for (int i = 1; i <= 100; i++)
					if (num[i] > 0) v.push_back({ i, num[i] });
				sort(v.begin(), v.end(), cmp);

				memset(gMap[y], 0, sizeof gMap[y]);
				
				int idx = 0;
				for (int i = 0; i < v.size(); i++)
				{
					gMap[y][idx++] = v[i].num;
					if (idx == 100) break;
					gMap[y][idx++] = v[i].cnt;
					if (idx == 100) break;
				}
				tncol = tncol < idx ? idx : tncol;
			}
			ncol = tncol;
		}
		// 행 수 < 열 수
		else
		{
			// 열 순회
			int tnrow = nrow;
			for (int x = 0; x < ncol; x++)
			{
				memset(num, 0, sizeof num);
				vector<nc> v;
				for (int y = 0; y < nrow; y++) num[gMap[y][x]]++;
				for (int i = 1; i <= 100; i++)
					if (num[i] > 0) v.push_back({ i, num[i] });
				sort(v.begin(), v.end(), cmp);

				// 0으로 초기화
				for (int y = 0; y < nrow; y++) gMap[y][x] = 0;

				int idx = 0;
				for (int i = 0; i < v.size(); i++)
				{
					gMap[idx++][x] = v[i].num;
					if (idx == 100) break;
					gMap[idx++][x] = v[i].cnt;
					if (idx == 100) break;
				}
				tnrow = tnrow < idx ? idx : tnrow;
			}
			nrow = tnrow;
		}		
	}

	if (t > 100) cout << -1 << endl;
	else cout << t << endl;

	return 0;
}