#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;
ull dp[101];
vector<char> bigNumber;

// when N > 64
void cal_big(vector<char> &number)
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
			int tmp = 2 * x  + trans;
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
	hanoi(n-1, s,6-s-e);
	hanoi(1, s, e);
	hanoi(n-1, 6-s-e,e);
}
ull hanoi_n(int n)
{
	if (n == 0) return 0;
	if (dp[n]) return dp[n];
	return dp[n] = 2 * hanoi_n(n - 1) + 1;
}
void big_hanoi_n(int n)
{
	if (n == 1)
	{
		bigNumber.push_back('1');
		return;
	}
	else
	{
		big_hanoi_n(n - 1);
		cal_big(bigNumber);
		return;
	}
}

void f()
{
	int *a = new int(10);

	tr1::shared_ptr<int> spInt(a);
	cout << *spInt << endl;
}

int main()
{

	double a = -10.3;
	int b = static_cast<int>(a);
	cout <<  << endl;


	return 0;
}