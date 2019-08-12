// BAEK_1019. 책 페이지

#include <iostream>
#include <cmath>

using namespace std;
typedef unsigned long long ull;

ull cnt[10];

int N;

void count_each(int num, int power)
{
	while (num > 0)
	{
		cnt[num % 10] += pow(10, power);
		num /= 10;
	}
}

int main()
{
	ios::sync_with_stdio(false); cout.tie(0);
  	cin >> N;

	ull start = 1, end = N;
	int power = 0;
	while (start <= end)
	{
		while (start % 10 != 0 && start <= end)
		{
			count_each(start, power);
			start++;
		}

		if (start > end) break;

		while (end % 10 != 9 && start <= end)
		{
			count_each(end, power);
			end--;
		}

		if (start > end) break;

		// 10 ~ 119
		start /= 10;
		end /= 10;
		for(int i = 0; i <= 9; i++)
			cnt[i] += (end - start + 1) * pow(10, power);

		power++;
	}


	for (int i = 0; i < 10; i++)
		cout << cnt[i] << " ";

	return 0;
}