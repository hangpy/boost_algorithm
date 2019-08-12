// BAEK_1914. 하노이 탑
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;
ull dp[101];
vector<char> bigNumber;

// when N > 64
void calc_big(vector<char> &number)
{
	// *2 + 1
	int len = number.size(), idx = 0;

	int trans = 0;
	while (idx < len)
	{
		int mod = 0;
		int x = number[idx] - '0';
		if (idx == 0)
		{
			int tmp = 2 * x + 1;
			trans = tmp / 10;
			mod = tmp % 10;
		}
		else
		{
			int tmp = 2 * x + trans;
			trans = tmp / 10;
			mod = tmp % 10;
		}
		number[idx] = mod + '0';
		++idx;
	}
	if (trans > 0) number.push_back(trans + '0');
}

void hanoi(int n, int s, int e)
{
	if (n == 1)
	{
		cout << s << " " << e << "\n";
		return;
	}
	hanoi(n - 1, s, 6 - s - e);
	hanoi(1, s, e);
	hanoi(n - 1, 6 - s - e, e);
}
ull hanoi_n(int n)
{
	if (n == 0) return 0;
	if (dp[n]) return dp[n];
	return dp[n] = 2 * hanoi_n(n - 1) + 1;
}

//void big_hanoi_n(int n)
//{
//	if (n == 1)
//	{
//		bigNumber.push_back('1');
//		return;
//	}
//	else
//	{
//		big_hanoi_n(n - 1);
//		calc_big(bigNumber);
//		return;
//	}
//}

void big_hanoi_n(int n)
{
	if(n>=1) bigNumber.push_back('1');
	for (int i = 0; i < n - 1; i++)
		calc_big(bigNumber);
}

int main()
{
	int N;
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;

	if (N <= 64) cout << hanoi_n(N) << endl;
	else
	{
		big_hanoi_n(N);
		reverse(bigNumber.begin(), bigNumber.end());
		for (auto n : bigNumber)
			cout << n;
		cout << endl;
	}

	if (N <= 20) hanoi(N, 1, 3);

	return 0;
}