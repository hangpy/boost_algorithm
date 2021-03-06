// SDS_LV2_3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

int T, N, map[301][301], visited[301][301]{ 0 }, ANS[31][3]{ 0 };
int drow[4] = {1, 0, -1, 0};
int dcol[4] = {0, 1, 0, -1};

void greedy(int row, int col, int num, int t)
{
	// check visited
	visited[row][col] = 1;

	// when num is odd
	if (num % 2 == 1) ANS[t][1]++;
	// when num is even
	else ANS[t][2]++;

	if (row == N && col == N) return;

	// for when meeting even number
	for (int i = 0; i < 4; i++)
	{
		int adj_row = row + drow[i];
		int adj_col = col + dcol[i];
		if (adj_row < 1 || adj_row > N || adj_col < 1 || adj_col > N || visited[adj_row][adj_col])
			continue;

		int adj_num = map[adj_row][adj_col];
		if (adj_num % 2 == 0)
		{
			greedy(adj_row, adj_col, adj_num, t);
			return;
		}
	}

	// when there is no even adjacent, look for optimal odd number
	for (int i = 0; i < 4; i++)
	{
		int adj_row = row + drow[i];
		int adj_col = col + dcol[i];
		if (adj_row < 1 || adj_row > N || adj_col < 1 || adj_col > N || visited[adj_row][adj_col])
			continue;

		int adj_num = map[adj_row][adj_col];
		if (adj_num % 2 == 1)
		{
			greedy(adj_row, adj_col, adj_num, t);
			return;
		}
	}
}



int main()
{
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
				map[row][col] = a;
			}
		}


		
		greedy(1, 1, map[1][1], t);

		for (int row = 1; row <= N; row++)
		{
			for (int col = 1; col <= N; col++)
				cout << visited[row][col] << " ";
			cout << endl;
		}

		// initialize again
		memset(visited, 0, sizeof(visited)); 




		/*for (int row = 1; row <= N; row++)
		{
			for (int col = 1; col <= N; col++)
				cout << map[row][col] << " ";
			cout << endl;
		}*/

	}
	// cout answers
	for (int t = 1; t <= T; t++)
		cout << "#" << t << " " << ANS[t][1] << " " << ANS[t][2] << endl;

    return 0;
}

