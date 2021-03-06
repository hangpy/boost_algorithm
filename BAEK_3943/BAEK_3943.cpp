#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int T;
map<int, int> dp;
vector<int> ans;

int getMax(int num)
{
	if (dp[num]) return dp[num];

	if (num % 2 == 0) return dp[num] = max(num, getMax(num / 2));
	else return dp[num] = max(num, getMax(num * 3 + 1));
	
}

int main()
{
	dp[1] = 1;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		int num;
		scanf("%d", &num);
		ans.push_back(getMax(num));
	}
	for (auto i : ans) printf("%d\n", i);

    return 0;
}

