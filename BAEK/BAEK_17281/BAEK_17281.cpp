// BAEK_17281. 야구

#include <iostream>
#include <algorithm>
#include <cstring>
#define endl "\n"

using namespace std;

int N, gInningScore[51][10];


int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int num = 1; num <= 9; num++)
			cin >> gInningScore[i][num];

	int order[9] = { 1,2,3,4,5,6,7,8,9 };
	int ans = 0;
	
	do
	{
		int score = 0;

		if (order[3] != 1) continue;

		int out = 0, base[3] = { 0, }, now = 0, inning = 1;

		// do game
		while (inning <= N)
		{
			int playerNum = order[now % 9];
			int state = gInningScore[inning][playerNum];
			switch (state)
			{
			case 0: out++;
				break;
			case 1:
				if (base[2] == 1) score++;
				base[2] = base[1];
				base[1] = base[0];
				base[0] = 1;
				break;
			case 2:
				for (int i = 2; i >= 1; i--) score += base[i], base[i] = 0;
				base[2] = base[0], base[1] = 1;
				base[0] = 0;
				break;
			case 3:
				for (int i = 0; i < 3; i++) score += base[i];
				memset(base, 0, sizeof base);
				base[2] = 1;
				break;
			case 4:
				for (int i = 0; i < 3; i++) score += base[i];
				score++;
				memset(base, 0, sizeof base);
				break;
			}

			now++;
			if (out == 3) inning++, out = 0, memset(base, 0, sizeof base);
		}
		ans = ans < score ? score : ans;
	}
	while (next_permutation(order, order + 9));

	cout << ans << endl;

	return 0;
}