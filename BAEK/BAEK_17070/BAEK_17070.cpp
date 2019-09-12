// BAEK_17070. 파이트 옮기기

#include <iostream>

using namespace std;

struct pos { int  y, x; };
int N, MAP[17][17], hordp[17][17], crodp[17][17], verdp[17][17];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;

	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			cin >> MAP[y][x];

	hordp[1][2] = 1;
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			if (y == 1 && !MAP[y][x]) hordp[y][x] += hordp[y][x - 1];
			if (y == 2)
			{
				if (!(MAP[y][x] || MAP[y - 1][x] || MAP[y][x - 1]))
					crodp[y][x] += hordp[y - 1][x - 1];
				if(!MAP[y][x])
					hordp[y][x] += (hordp[y][x - 1] + crodp[y][x-1]);
			}
			if(!(y==1 || y==2) && !MAP[y][x])
			{
				if(!(MAP[y][x] || MAP[y-1][x] || MAP[y][x-1])) 
					crodp[y][x] += (hordp[y - 1][x - 1] + crodp[y - 1][x - 1] + verdp[y - 1][x - 1]);
				if (!MAP[y][x])
				{
					hordp[y][x] += (crodp[y][x - 1] + hordp[y][x - 1]);
					verdp[y][x] += (crodp[y - 1][x] + verdp[y - 1][x]);
				}
			}
		}
	}

	cout << crodp[N][N] + verdp[N][N] + hordp[N][N] << endl;
	return 0;
}
