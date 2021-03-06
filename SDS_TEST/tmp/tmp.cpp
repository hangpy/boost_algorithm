// tmp.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

				

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <time.h>

using namespace std;


int T, N, board[501][501]{ 0 }, max_board[501][501]{ 0 }, ANS[36]{ 0 };
int drow[4] = { -1, 0, 1, 0 };
int dcol[4] = { 0, -1, 0, 1 };
int tmp_max(0), now_cards(1);

// 최적화를 위해
bool opt_board[501][501]{ 0 };
bool visited[501][501]{ 0 };
int add_board[501][501]{ 0 };


void dfs(int row, int col)
{
	// 한번 1로 설정되면 안바뀜
	opt_board[row][col] = 1;
	/*cout << "--------------" << endl;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cout << opt_board[i][j] << " ";
			cout << endl;
	}
	cout << "--------------" << endl;*/
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
	clock_t start, end;
	double result;
	start = clock(); //시간 측정 시작

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
			}
		}



		int max(0);

		for (int row = 1; row <= N; row++)
		{
			for (int col = 1; col <= N; col++)
			{
				// opt_board[row][col]에 1이면 탐색을 시작할 필요가 없는 셀.
				if (opt_board[row][col]) continue;

				// 쓸데없는 dfs계산 피하기
				int tmp(0);
				for (int i = 0; i < 2; i++)
				{
					int adj_row = row + drow[i];
					int adj_col = col + dcol[i];
					if (adj_row < 1 || adj_col < 1) continue;
					if (add_board[adj_row][adj_col] > 0 && board[adj_row][adj_col] > board[row][col])
					{
						if (tmp < add_board[adj_row][adj_col])
						{
							tmp = add_board[adj_row][adj_col];
						}
						
					}
				}
				if (tmp)
				{
					max_board[row][col] = tmp+1;
					add_board[row][col] = tmp+1;
					if (max < tmp + 1) max = tmp + 1;
					continue;
				}

				// 위의 경우가 모두 아니면 그때서 dfs
				tmp_max = 1;
				now_cards = 1;

				dfs(row, col);
				// dfs가 실행되었을 때 다시 max비교
				max_board[row][col] = tmp_max;
				add_board[row][col] = tmp_max;

				if (max < tmp_max) max = tmp_max;

				// 왼쪽, 위 노드 업데이트 하기
				for (int i = 0; i < 2; i++)
				{
					int adj_row = row + drow[i];
					int adj_col = col + dcol[i];
					if (adj_row < 1 || adj_col < 1) continue;
					if (max_board[adj_row][adj_col] < max_board[row][col] + 1 
						&& board[adj_row][adj_col] < board[row][col])
					{
						add_board[adj_row][adj_col] = max_board[row][col] + 1;
						max_board[adj_row][adj_col] = add_board[adj_row][adj_col];
						if (max < max_board[adj_row][adj_col]) max = max_board[adj_row][adj_col];
					}
				}
				memset(visited, 0, sizeof(visited));

				/*cout << "--------------" << endl;
				for (int i = 1; i <= N; i++)
				{
					for (int j = 1; j <= N; j++)
						cout << add_board[i][j] << " ";
					cout << endl;
				}
				cout << "--------------" << endl;*/

			}
		}

		ANS[t] = max;
		// 젼역 변수 초기화.
		tmp_max = 0;
		memset(opt_board, 0, sizeof(opt_board));
	}


	// cout answers
	for (int t = 1; t <= T; t++)
		cout << "#" << t << " " << ANS[t] << endl;
	
	end = clock(); //시간 측정 끝
	result = (double)(end - start)/CLOCKS_PER_SEC;
	printf("%fsec\n", result);

	return 0;
}


