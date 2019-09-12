// BAEK_16637. 괄호 추가하기

#include <iostream>
#include <limits>

using namespace std;

char opers[19]; // opers는 0 <= ~ < N/2 까지
int nums[10]; // nums는 0 <= ~ < N/2 + 1 까지
char input[20];
int V[9], sel[9], N;
int ans = numeric_limits<int>::min();

int calc(int lhs, int rhs, char oper)
{
	int result = 0;
	switch (oper)
	{
	case '+':
		result = lhs + rhs;
		break;
	case '-':
		result = lhs - rhs;
		break;
	case '*':
		result = lhs * rhs;
		break;
	}
	return result;
}

void solve(int index, bool prevSelected)
{
	if (index == N/2)
	{
		int sum = nums[0];
		for (int i = 0; i < N / 2; i++)
		{
			// 묶인 경우
			if (sel[i+1] && i < N/2 - 1) sum = calc(sum, calc(nums[i+1], nums[i+2], opers[i+1]), opers[i]), i++;
			// 안묶인 경우
			else sum = calc(sum, nums[i + 1], opers[i]);
		}
		ans = ans < sum ? sum : ans;
	}
	else
	{
		if (prevSelected) solve(index + 1, false);
		if (!prevSelected) {
			sel[index] = 1;
			solve(index + 1, true);
			sel[index] = 0;
			solve(index + 1, false);
		}
	}
}

int main()
{
	cin >> N;
	cin >> input;
	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0) nums[i / 2] = input[i] - '0';
		else opers[i / 2] = input[i];
	}
	if (N > 1) 
	{
		solve(1, false);
		cout << ans << endl;
	}
	else cout << input << endl;
	
	return 0;
}
