// BAEK_14501. 퇴사

#include <iostream>
#include <algorithm>

using namespace std;

int N, T[16], P[16];

int dfs(int day)
{
	int sum = 0;
	int pay = P[day], len = T[day];
	if (day > N) return sum;
	else
	{
		if(day + len <= N+1) sum = max(sum, pay + dfs(day + len));
		sum = max(sum, dfs(day + 1));
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> T[i] >> P[i];
	
	cout << dfs(1) << endl;

	cout << endl;

	return 0;
}