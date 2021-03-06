﻿// SWEA_2105. 디저트 카페

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct pos { 
	int y, x; 
};
int T, N, MAP[21][21];
int V[101];
// 왼쪽 위부터 오른쪽으로 차례로
int dy[4] = {-1, -1, 1, 1};
int dx[4] = {-1, 1, 1, -1};
int chdir[4] = { 1, 2, 3, 0 };

int dfs(pos cur, int dir, int cnt, pos& start)
{
	V[MAP[cur.y][cur.x]] = 1;
	int result = -1;

	// 기본타입은 참조자를 쓰지 말것
	int cy = cur.y, cx = cur.x;

	// 출발점으로 돌아왔을 때만 거쳐온 디저트 가게 수 반환
	if (cnt != 0 && cy == start.y && cx == start.x) return cnt;

	// 두갈래로 분기
	int ny = cy + dy[dir], nx = cx + dx[dir];
	// 해당 방향 그대로 직진
	if (!(ny < 1 || ny > N || nx < 1 || nx > N || (V[MAP[ny][nx]] == 1 && (ny != start.y || nx != start.x))))
		// 반환 값을 가지고 최대값 판벌
		result = max(result, dfs({ ny, nx }, dir, cnt + 1, start));
	// 90도 꺾기
	if (dir != 1 && cnt != 0)
	{
		ny = cy + dy[chdir[dir]], nx = cx + dx[chdir[dir]];
		if (!(ny < 1 || ny > N || nx < 1 || nx > N || (V[MAP[ny][nx]] == 1 && (ny != start.y || nx != start.x))))
			// 이전 기록과 반환 값 가지고 최대값 판별
			result = max(result, dfs({ ny, nx }, chdir[dir], cnt + 1, start));
	}

	

	
	V[MAP[cur.y][cur.x]] = 0;

	return result;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		

		cin >> N;
		
		for (int y = 1; y <= N; y++)
			for (int x = 1; x <= N; x++)
				cin >> MAP[y][x];
		

		int ANS = -1;
		// 필요한 정점만 탐색
		for (int y = 1; y <= N - 2; y++)
		{
			for (int x = 2; x <= N - 1; x++)
			{
				memset(V, 0, sizeof(V));
				pos cpos = { y,x };
				ANS = max(ANS, dfs({ y,x }, 2, 0, cpos));
			}
		}


		cout << "#" << t << " " << ANS << endl;
	}
	
	return 0;
}