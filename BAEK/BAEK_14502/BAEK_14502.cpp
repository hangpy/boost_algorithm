﻿// BAEK_14502. 연구소

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, MAP[8][8], V[8][8];
struct pos { int y, x; };

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int bfs(vector<pos> &newWalls, vector<pos> &viruses, int spaceSize)
{
	// 벽세우기
	for (auto wall : newWalls)
		MAP[wall.y][wall.x] = 1;
		

	// bfs
	memset(V, 0, sizeof(V));
	int cnt = spaceSize;
	queue<pos> q;
	for (auto virus : viruses)
	{
		V[virus.y][virus.x] = 1;
		q.push(virus);
	}
	while (!q.empty())
	{
		int cy = q.front().y, cx = q.front().x; q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i], nx = cx + dx[i];
			if (ny < 0 || ny > N - 1 || nx < 0 || nx > M - 1) continue;
			if (MAP[ny][nx] == 1 || V[ny][nx] == 1) continue;
			q.push({ ny, nx });
			cnt--;
			V[ny][nx] = 1;
		}
	}
	// 원상복구
	for (auto wall : newWalls)
		MAP[wall.y][wall.x] = 0;
	
	// 새로 지어진 벽을 제외한 빈공간을 초기값으로 했으니까 마지막에 3을 빼줘야함
	return cnt - 3;
}

int main()
{

	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	
	vector<pos> viruses;
	vector<pos> vacums;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			int a; cin >> a;
			MAP[y][x] = a;
			if (a == 0) vacums.push_back({ y, x });
			if (a == 2) viruses.push_back({ y, x });
		}
	}

	int spaceSize = vacums.size();
	vector<int> v(spaceSize, 1);
	for (int i = 0; i < 3; i++) v[i] = 0;
	int ans = 0;

	do
	{
		vector<pos> newWalls;
		for (int i = 0; i < spaceSize; i++)
			if (v[i] == 0) newWalls.push_back({ vacums[i].y, vacums[i].x });

		int result = bfs(newWalls, viruses, spaceSize);
		ans = ans < result ? result : ans;

	} while (next_permutation(v.begin(), v.end()));

	cout << ans << endl;

	return 0;
}