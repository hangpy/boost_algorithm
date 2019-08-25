// BAEK_14499. 주사위 굴리기

#include <iostream>
#include <vector>

using namespace std;

int N, M, dice_y, dice_x, K;
int MAP[20][20], opers[1000];

int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };

void rotate_dice(vector<int> &row, vector<int> &col, int dir)
{
	int tmp = 0;
	switch (dir)
	{
	case 1:
		tmp = row[3];
		row.erase(row.end() - 1);
		row.insert(row.begin(), tmp);
		col[1] = row[1], col[3] = row[3];
		break;
	case 2:
		tmp = row[0];
		row.erase(row.begin());
		row.push_back(tmp);
		col[1] = row[1], col[3] = row[3];
		break;
	case 3:
		tmp = col[0];
		col.erase(col.begin());
		col.push_back(tmp);
		row[1] = col[1], row[3] = col[3];
		break;
	case 4:
		tmp = col[3];
		col.erase(col.end() - 1);
		col.insert(col.begin(), tmp);
		row[1] = col[1], row[3] = col[3];
		break;
	default:
		break;
	}
}


int main()
{
	cin >> N >> M >> dice_y >> dice_x >> K;

	for(int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> MAP[y][x];

	for (int k = 0; k < K; k++)
		cin >> opers[k];

	vector<int> dice_row = { 0,0,0,0 };
	vector<int> dice_col = { 0,0,0,0 };

	int cy = dice_y, cx = dice_x;

	for (int k = 0; k < K; k++)
	{
		int ny = cy + dy[opers[k]], nx = cx + dx[opers[k]];
		if (ny < 0 || ny > N - 1 || nx < 0 || nx > M - 1) continue;
		cy = ny, cx = nx;
		
		rotate_dice(dice_row, dice_col, opers[k]);
		
		if (MAP[cy][cx] == 0) // 칸이 0인 경우
			MAP[cy][cx] = dice_row[3];
		else // 0이 아닌경우
		{
			dice_row[3] = MAP[cy][cx];
			dice_col[3] = MAP[cy][cx];
			MAP[cy][cx] = 0;
		}

		cout << dice_row[1] << "\n";
	}

	return 0;
}