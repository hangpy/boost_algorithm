// SWEA_4008. 숫자 만들기

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int T, N, nums[12];

int calc(int lhs, int rhs, int i)
{
	switch (i)
	{
	case 0:
		return lhs + rhs;
		break;
	case 1:
		return lhs - rhs;
		break;
	case 2:
		return lhs * rhs;
		break;
	case 3:
		return lhs / rhs;
		break;
	default:
		break;
	}
}

int main()
{
	
	ios::sync_with_stdio(0); cin.tie(0);

	freopen("sample_input.txt", "r", stdin);

	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		vector<int> ops;
		cin >> N;
		for (int i = 0; i < 4; i++)
		{
			int n; cin >> n;
			for (int j = 0; j < n; j++) ops.push_back(i);
		}
		for (int i = 0; i < N; i++) cin >> nums[i];

		int _max = numeric_limits<int>::min();
		int _min = numeric_limits<int>::max();
		do
		{
			int tmp = nums[0];
			for (int i = 1; i < N; i++)
				tmp = calc(tmp, nums[i], ops[i - 1]);
			
			_max = max(_max, tmp);
			_min = min(_min, tmp);

		} while (next_permutation(ops.begin(), ops.end()));
		
		int result = abs(_max - _min);

		cout << "#" << t << " " << result << endl;
	}
	return 0;
}
