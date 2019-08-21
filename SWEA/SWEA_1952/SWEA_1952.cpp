// SWEA_1952. 수영장
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int T, D1, M1, M3, Y1, plan[13];
const int INF = numeric_limits<int>::max();

int dfs(int mounth)
{
	int days = plan[mounth];
	int pay = INF;

	if (mounth > 12) return 0;
	else
	{
		// 일 결제
		pay = min(pay, D1 * days + dfs(mounth + 1));
		// 월 결제
		pay = min(pay, M1 + dfs(mounth + 1));
		// 3달 결제;
		pay = min(pay, M3 + dfs(mounth + 3));
		// 1년 결제;
		pay = min(pay, Y1 + dfs(mounth + 12));
	}
	return pay;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> D1 >> M1 >> M3 >> Y1;
		for (int y = 1; y <= 12; y++) cin >> plan[y];

		int result = dfs(1);
		cout << "#" << t << " " << result << "\n";
	}
	return 0;
}