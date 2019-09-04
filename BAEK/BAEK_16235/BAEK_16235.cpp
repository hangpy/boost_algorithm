﻿// BAEK_16235. 나무 재테크
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K, NUTR[11][11], A[11][11], CNT[11][11], MAP[11][11][1000], DV[11][11];
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			cin >> A[y][x], NUTR[y][x] = 5;
		

	for (int i = 1; i <= M; i++)
	{
		int y, x, age;
		cin >> y >> x >> age;
		int size = CNT[y][x];
		MAP[y][x][size] = age;
		CNT[y][x]++;
	}

	while (K > 0)
	{
		// spring 
		// 어린 나무부터 나이만큼 양분 먹고 나이 + 1, 못먹은 나무들의 죽음이 결정
		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++) 
			{
				int cnt;
				if ((cnt = CNT[y][x]) == 0) continue;
				sort(MAP[y][x], MAP[y][x] + cnt);
				for (int i = 0; i < cnt; i++)
				{
					if (NUTR[y][x] >= MAP[y][x][i]) NUTR[y][x] -= MAP[y][x][i], MAP[y][x][i]++;
					else DV[y][x]++;
				}
			}
		}
			
		
		// summer 
		// 봄에 죽은 나무들의 양분으로 변하는 시기. 
		// 죽은 나무의 위치에 (죽은 나무들의 나이 / 2) 만큼 NUTR에 양분 추가. 소수점 버림
		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++)
			{
				if (DV[y][x] == 0) continue;
				int i = CNT[y][x] - DV[y][x];
				for (i; i < CNT[y][x]; i++)
					NUTR[y][x] += MAP[y][x][i]/2; MAP[y][x][i] = 0;
				CNT[y][x] -= DV[y][x], DV[y][x] = 0;
			}
		}

		// fall
		// 나무 번식. 1 미만 N 초과의 경계는 나이가 1인 나무 번식 X, i = 0~8 의 방향
		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++)
			{
				if (CNT[y][x] == 0) continue;
				int ccnt = CNT[y][x];
				for (int idx = 0; idx < ccnt; idx++)
				{
					if (MAP[y][x][idx] % 5 != 0) continue;
					for (int i = 0; i < 8; i++)
					{
						int ny = y + dy[i], nx = x + dx[i];
						if (ny < 1 || ny > N || nx < 1 || nx > N) continue;
						int ncnt = CNT[ny][nx];
						for (int k = ncnt; k < ncnt + 1; k++)
						{
							MAP[ny][nx][k] = 1;
						}
						CNT[ny][nx] += 1;
					}
				}
			}
		}

		// winter
		// NUTR의 모든 칸에 A[y][x]만큼 양분 추가.
		for (int y = 1; y <= N; y++)
			for (int x = 1; x <= N; x++)
				NUTR[y][x] += A[y][x];
		K--;
	}

	int ans = 0;
	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			ans += CNT[y][x];

	cout << ans << endl;

	return 0;
}