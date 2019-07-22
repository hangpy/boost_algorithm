#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int map[102][102]{ 0 };
int dp[4][102][102]{ 0 };
// down: 0, right: 1, up: 2, left: 3
int drow[4] = { 1, 0, -1, 0 };
int dcol[4] = { 0, 1, 0, -1 };

// ch_d[block][cur_d]
int ch_d[6][4] = {
	{0, 0, 0, 0},
	{1, 3, 0, 2},
	{2, 3, 1, 0},
	{2, 0, 3, 1},
	{3, 2, 0, 1},
	{2, 3, 0, 1}
};

struct pos
{
	int row, col;
};

int main(int argc, char** argv)
{
	int T;

	freopen("sample_input.txt", "r", stdin);

	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		int N;

		vector<pos> wh[11];

		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> map[i][j];
				if (map[i][j] >= 6 && map[i][j] <= 10)
					wh[map[i][j]].push_back({ i, j });
			}
		}
		for (int i = 0; i <= N + 1; i++)
		{
			map[i][0] = 5;
			map[0][i] = 5;
			map[i][N + 1] = 5;
			map[N + 1][i] = 5;
		}

		int ANS = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (map[i][j] != 0) continue;
				for (int d = 0; d < 4; d++)
				{
					int cur_d = d;
					if (dp[cur_d][i][j] != 0) continue;
					int score = 0;
					int r = i, c = j;
					int check = 0;

					while (true)
					{
						check++;
						int block = map[r][c];

						if ((check != 1 && r == i && c == j) || block == -1) break;
						else if (block == 0)
						{
							r += drow[cur_d];
							c += dcol[cur_d];
						}
						else if (block > 0 && block < 6)
						{
							cur_d = ch_d[block][cur_d];
							r += drow[cur_d];
							c += dcol[cur_d];
							dp[cur_d][r][c] = 1;
							score++;
						}
						else // 웜홀
						{
							if (r == wh[block][0].row && c == wh[block][0].col) 
							{
								r = wh[block][1].row + drow[cur_d];
								c = wh[block][1].col + dcol[cur_d];
							}
							else
							{
								r = wh[block][0].row + drow[cur_d];
								c = wh[block][0].col + dcol[cur_d];
							}
						}
					}
					if (ANS < score) ANS = score;
				}
			}
		}

		cout << "#" << t << " " << ANS << endl;
	}

	return 0;
}
