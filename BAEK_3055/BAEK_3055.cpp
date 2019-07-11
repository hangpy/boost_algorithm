#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

struct pos
{
	int row, col;
	bool isWater;
};
int R, C, ANS;
pos D, S;
int drow[4] = { 1, 0, -1, 0 };
int dcol[4] = { 0, 1, 0, -1 };
int forest[51][51], mem[51][51];
queue<pos> q;
vector<pos> wv;


int main()
{
	cin >> R >> C;
	for (int row = 1; row <= R; row++)
	{
		for (int col = 1; col <= C; col++)
		{
			char c(0);

			cin >> c;

			switch (c)
			{
			case '.':
				break;
			case 'D':
				D = { row, col };
				forest[row][col] = -2;
				break;
			case 'X':
				forest[row][col] = -1;
				break;
			case '*':
				wv.push_back({ row, col, true });
				forest[row][col] = -1;
				break;
			case 'S':
				S = { row, col, false };
				break;
			default: break;
			}
		}
	}

	for (auto W : wv)
	{
		q.push(W);
	}
	q.push(S);

	bool isAnswer = false;
	memset(mem, -1, sizeof(mem));
	mem[S.row][S.col] = 0;


	while (!q.empty())
	{
		bool toBreak = false;

		pos curr = q.front();

		q.pop();

		int crow = curr.row;
		int ccol = curr.col;
		bool isWater = curr.isWater;

		if (isWater)
		{
			for (int i = 0; i < 4; i++)
			{
				int nrow = crow + drow[i];
				int ncol = ccol + dcol[i];

				if (nrow > R || nrow < 1 || ncol > C || ncol < 1 ||
					forest[nrow][ncol] <= -1) continue;
				forest[nrow][ncol] = -1;
				q.push({ nrow, ncol, true });
			}
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				int nrow = crow + drow[i];
				int ncol = ccol + dcol[i];

				if (nrow > R || nrow < 1 || ncol > C || ncol < 1 ||
					forest[nrow][ncol] == -1 || mem[nrow][ncol] >= 0) continue;
				mem[nrow][ncol] = mem[crow][ccol] + 1;
				q.push({ nrow, ncol, false });
				if (nrow == D.row && ncol == D.col)
				{
					ANS = mem[nrow][ncol];
					toBreak = true;
					isAnswer = true;
					break;
				}
			}
		}

		if (toBreak) break;
	}

	if (isAnswer) cout << ANS << endl;
	else cout << "KAKTUS" << endl;


	return 0;
}