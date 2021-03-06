// p215_low_jumpgame.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include <cstdio>

using namespace std;

int map[101][101], N;
bool visited[101][101]{ 0 };

int ANS(0);

bool dp(int row, int col)
{
	int canReach = false;

	if (row == N && col == N)
	{
		ANS++;
		return true;
	}
	else if (row > N || col > N || visited[row][col] == 1) return false;
	else
	{
		visited[row][col] = true;
		int &ret = map[row][col];
		return dp(row + ret, col) || dp(row, col + ret);
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &map[i][j]);

	printf("%d\n", dp(1, 1));

    return 0;
}

