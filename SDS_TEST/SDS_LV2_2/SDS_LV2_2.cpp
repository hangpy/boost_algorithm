// SDS_LV2_2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <time.h>

using namespace std;

int T, N, board[501][501]{ 0 }, max_board[501][501]{ 0 }, tmp_board[501][501]{ 0 }, visited[501][501], ANS[36]{ 0 };
int drow[4] = { 1, 0, -1, 0 };
int dcol[4] = { 0, 1, 0, -1 };
int tmp_max(0), now_cards(1);

// 최적화를 위해
bool opt_board[501][501]{0};

typedef struct pos
{
	int x, y;
} pos;

void dfs(int row, int col)
{

	for (int i = 0; i < 4; i++)
	{
		int next_row = row + drow[i];
		int next_col = col + dcol[i];
		if (board[next_row][next_col] <= board[row][col] || visited[next_row][next_col]) continue;
		if (next_row < 1 || next_row > N || next_col < 1 || next_col > N) continue;
		visited[next_row][next_col] = 1;
		now_cards++;
		if (tmp_max < now_cards) tmp_max = now_cards;
		dfs(next_row, next_col);
	}
	now_cards--;
	visited[row][col] = 0;
	return;
}

int main()
{
	double result;
	clock_t start, end;
	start = clock();

	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N;
		for (int row = 1; row <= N; row++)
		{
			for (int col = 1; col <= N; col++)
			{
				int a;
				cin >> a;
				board[row][col] = a;

				for (int i = 0; i < 4; i++)
				{
					int next_row = row + drow[i];
					int next_col = col + dcol[i];
					int cmp = board[next_row][next_col];
					if (cmp > a) {
						opt_board[row][col] = true;
						break;
					}
				}
			}
		}

		int max(0);
		
		for (int row = 1; row <= N; row++)
		{
			for (int col = 1; col <= N; col++)
			{
				/*dfs(row, col);
				max_board[row][col] = tmp_max;*/

				if (!opt_board[row][col]) continue;

				//bfs
				queue<pos> q;
				q.push({ row, col });
				tmp_board[row][col] = 1;

				while (!q.empty())
				{
					pos xy = q.front();
					int now_row = xy.x;
					int now_col = xy.y;
					q.pop();
					
					for (int i = 0; i < 4; i++)
					{
						int next_row = now_row + drow[i];
						int next_col = now_col + dcol[i];
						if (board[next_row][next_col] <= board[now_row][now_col]) continue;
						if (next_row < 1 || next_row > N || next_col < 1 || next_col > N) continue;
						now_cards = tmp_board[now_row][now_col] + 1;
						tmp_board[next_row][next_col] = now_cards;

						/*for (int i = 1; i <= N; i++)
						{
							for (int j = 1; j <= N; j++)
								cout << tmp_board[i][j] << " ";
							cout << endl;
						}
						cout << "위 now card: " << now_cards << endl;
						cout << "--------------" << endl;*/
						

						if (tmp_max < now_cards) tmp_max = now_cards;
						q.push({ next_row, next_col });
					}
				}

				if (max < tmp_max) max = tmp_max;
				tmp_max = 0;

				memset(tmp_board, 0, sizeof(tmp_board));
				
			}
			
		}

		ANS[t] = max;
	}


	// cout answers
	for (int t = 1; t <= T; t++)
		cout << "#" << t << " " << ANS[t] << endl;

	end = clock();
	result = (double)(end - start)/CLOCKS_PER_SEC;
	cout << result << "sec" << endl;

    return 0;
}

