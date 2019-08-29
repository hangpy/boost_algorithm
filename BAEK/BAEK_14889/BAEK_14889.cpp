// BAEK_14889. 스타트와 링크

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

int N, MAP[20][20];

int get_power(vector<int> &v)
{
	int power = 0;
	vector<int> tmpv(v.size(), 1);
	for (int i = 0; i < 2; i++) tmpv[i] = 0;
	do
	{
		int pos[2] = { 0,0 };
		int index = 0;
		for (int i = 0; i < tmpv.size(); i++)
		{
			if (tmpv[i] == 0)
			{
				pos[index] = v[i];
				index++;
			}
		}
		power += MAP[pos[0]][pos[1]];
		power += MAP[pos[1]][pos[0]];

	} while (next_permutation(tmpv.begin(), tmpv.end()));

	return power;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> MAP[y][x];

	int ans = numeric_limits<int>::max();
	vector<int> v(N, 1);
	for (int i = 0; i < N / 2; i++) v[i] = 0;
	do
	{
	
		vector<int> vstart;
		vector<int> vlink;
		
		for (int i = 0; i < N; i++)
		{
			if (v[i] == 0) vstart.push_back(i);
			else vlink.push_back(i);
		}

		int startPower = get_power(vstart);
		int linkPower = get_power(vlink);

		int result = abs(startPower - linkPower);
		
		ans = ans > result ? result : ans;

	} while (next_permutation(v.begin(), v.end()));

	cout << ans << "\n";

	return 0;
}