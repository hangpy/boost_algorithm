// SWEA_4014.cpp. 활주로 건설
#include <iostream>
#include <cmath>

using namespace std;

int T, N, X, MAP[20][20];

int main()
{
    
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("sample_input.txt", "r", stdin);
	
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N >> X;
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				cin >> MAP[y][x];

		// 가로줄 탐색
		int result = 0;
		for (int y = 0; y < N; y++)
		{
			int prevh = MAP[y][0];
			int count = 1;
			bool down = false;

			int x;
			for (x = 1; x < N; x++)
			{
				int curh = MAP[y][x];
				if (down == false)
				{
					if (abs(prevh - curh) > 1) break;

					// 1높아졌을 때
					if (curh - prevh == 1)
					{
						// 같은 높이가 X개 이상 있을 때
						if (count >= X)
						{
							prevh = curh;
							count = 1;
							continue;
						}
						else break;
					}
					// 1 낮아졌을 때 앞으로 X개가 나올지 봐야함
					else if (prevh - curh == 1)
					{
						prevh = curh;
						down = true;
						count = 1;

					}
					// 높이가 똑같을 때
					else count++;
				}
				// 내려온 상황일 때
				else
				{
					if (curh == prevh) count++;
					else break;
					if (count >= X)
					{
						down = false;
						count = 0;
					}
				}
			}
			if (down == false && x == N) result++;

		}

		// 세로줄 탐색
		for (int x = 0; x < N; x++)
		{
			int prevh = MAP[0][x];
			int count = 1;
			bool down = false;

			int y;
			for (y = 1; y < N; y++)
			{
				int curh = MAP[y][x];
				if (down == false)
				{
					if (abs(prevh - curh) > 1) break;

					// 1높아졌을 때
					if (curh - prevh == 1)
					{
						// 같은 높이가 X개 이상 있을 때
						if (count >= X)
						{
							prevh = curh;
							count = 1;
							continue;
						}
						else break;
					}
					// 1 낮아졌을 때 앞으로 X개가 나올지 봐야함
					else if (prevh - curh == 1)
					{
						prevh = curh;
						down = true;
						count = 1;

					}
					// 높이가 똑같을 때
					else count++;
				}
				// 내려온 상황일 때
				else
				{
					if (curh == prevh) count++;
					else break;
					if (count >= X)
					{
						down = false;
						count = 0;
					}
				}
			}
			if (down == false && y == N) result++;
		}

		cout << "#" << t << " " << result << "\n";

	}
	return 0;
}




/*for (int y = 0; y < N; y++)
{
	for (int x = 0; x < N; x++)
	{
		cout << MAP[y][x] << " ";
	}
	cout << endl;
}*/