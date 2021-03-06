// BAEK_1890.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <queue>

using namespace std;

int BOARD[101][101]{ 0 }, N;
// 주의!
long long dp[101][101]{ 0 };
// only two direction: right or below
int dy[2] = { 1, 0 };
int dx[2] = { 0, 1 };
typedef struct loc
{
	int row;
	int col;
} loc;

// for BFS
queue<loc> q;

/*
// DFS recursive

int dfs(int row, int col)
{
	int ans(0);

	int len = BOARD[row][col];
	
	for (int direction = 0; direction < 2; direction++)
	{
		int next_row = row + drow[direction]*len;
		int next_col = col + dcol[direction]*len;
		// 만약 경계 벗어나면 무시
		if (next_row > N || next_col > N) continue;
		
		if (BOARD[next_row][next_col] == 0)
		{
			ans++;
			return ans;
		}
		else ans += dfs(next_row, next_col);
	}

	return ans;
}
*/

/*
void find_paths(int row, int col)
{
	int len = BOARD[row][col];
	for (int direction = 0; direction < 2; direction++)
	{
		int next_row = row + drow[direction] * len;
		int next_col = col + dcol[direction] * len;
		if (next_row > N || next_col > N) continue;
		dp[next_row][next_col] += dp[row][col];
		if (BOARD[next_row][next_col] == 0) return;
		else find_paths(next_row, next_col);
		
	}
}
*/


int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int n;
			cin >> n;
			BOARD[i][j] = n;
		}
	}

	/* 함수 호출 필요 없음 */
	dp[1][1] = 1;
	for (int row = 1; row <= N; row++)
	{
		for (int col = 1; col <= N; col++)
		{
			int len = BOARD[row][col];
			
			//  이부분을 추가 안하게 되면 오답이 도출, 필요 없는 계산은 건너 뛰기!
			if (BOARD[row][col] == 0 || dp[row][col] == 0) continue;

			if (row + len <= N)
				dp[row + len][col] += dp[row][col];
			if (col + len <= N)
				dp[row][col + len] += dp[row][col];
		}
	
	}
	cout << dp[N][N] << endl;


	
	/*
	// dp as function
	COUNT[1][1] = 1;
	dp(1, 1);
	cout << COUNT[N][N] << endl;
	*/



	/*
	// BFS
	int ans(0);
	q.push({ 1, 1 });
	while (!q.empty())
	{
		loc now = q.front();
		int now_row = now.row;
		int now_col = now.col;
		q.pop();

		int len = BOARD[now_row][now_col];

		for (int direction = 0; direction < 2; direction++)
		{
			int next_row = now_row + drow[direction] * len;
			int next_col = now_col + dcol[direction] * len;
			// 만약 경계 벗어나면 무시
			if (next_row > N || next_col > N) continue;
			
			if (BOARD[next_row][next_col] == 0) ans++;
			else q.push({ next_row, next_col });
		}
	}
	cout << ans << endl;
	*/

	/*
	// DFS
	cout << dfs(1, 1) << endl;;
	*/
	

    return 0;
}

