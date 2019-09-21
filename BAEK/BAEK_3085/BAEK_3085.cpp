﻿// BAEK_3085. 사탕게임

#include <iostream>
#include <utility>
#include <algorithm>
#define endl "\n"
using namespace std;

int N;
char MAP[50][50];

int getMax()
{
	int result = 1;
	for (int i = 0; i < N; i++)
	{
		char prev = MAP[i][0]; int cnt = 1;
		for (int x = 1; x < N; x++)
		{
			if (prev == MAP[i][x]) cnt++, result = result < cnt ? cnt : result;
			else prev = MAP[i][x], cnt = 1;
		}

		prev = MAP[0][i]; cnt = 1;
		for (int y = 1; y < N; y++)
		{
			if (prev == MAP[y][i]) cnt++, result = result < cnt ? cnt : result;
			else prev = MAP[y][i], cnt = 1;
		}
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0); cin >> N;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> MAP[y][x];

	int ans = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (y == N - 1 && x == N - 1) continue;
			else if (x + 1 > N - 1)
			{
				swap(MAP[y][x], MAP[y + 1][x]);
				ans = max(ans, getMax());
				swap(MAP[y][x], MAP[y + 1][x]);
			}
			else if (y + 1 > N - 1)
			{
				swap(MAP[y][x], MAP[y][x + 1]);
				ans = max(ans, getMax());
				swap(MAP[y][x], MAP[y][x + 1]);
			}
			else
			{
				swap(MAP[y][x], MAP[y + 1][x]);
				ans = max(ans, getMax());
				swap(MAP[y][x], MAP[y + 1][x]);
				swap(MAP[y][x], MAP[y][x + 1]);
				ans = max(ans, getMax());
				swap(MAP[y][x], MAP[y][x + 1]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}