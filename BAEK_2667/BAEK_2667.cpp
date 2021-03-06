// BAEK_2667.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <Windows.h>

using namespace std;


int map[25][25], N(0);
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
vector<int> ans;
typedef pair<int, int> pii;


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1)
			{
				int cnt(1);
				queue<pii> q;
				q.push({ i, j });
				map[i][j] = 0;
				// searching
				while (!q.empty())
				{
					int now_row = q.front().first;
					int now_col = q.front().second;
					q.pop();

					/*map[next_row][next_col] = 0;
					cnt++;*/
					// 위의 위치에 0을 대입하고 카운트를 할 경우 중복으로 세는 경우가 발생. 잘 해놔야 겠다.


					/*for (int i = 0; i < N; i++)
					{
						for (int j = 0; j < N; j++)
						{
							cout << map[i][j];
						}
						cout << endl;
					}
					cout << cnt;

					Sleep(1000);
					system("cls");*/

					// move drow, dcol
					for (int k = 0; k < 4; k++) 
					{
						int next_row = now_row + drow[k];
						int next_col = now_col + dx[k];
						if (map[next_row][next_col] == 0 || next_row < 0 || 
							next_row > N-1 || next_col < 0 || next_col > N-1) continue;
						q.push({ next_row, next_col });
						map[next_row][next_col] = 0;
						cnt++;
					}
				}
				ans.push_back(cnt);
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (auto i : ans)
		cout << i << endl;

	
    return 0;
}

