#include <cstdio>
#include <vector>
using namespace std;
int dp[12] = {1, 1, 2};
int T, N;
vector<int> v;
int main()
{
	scanf("%d", &T);
	for (int n = 3; n <= 11; n++) dp[n] = dp[n - 1] + dp[n - 2] + dp[n - 3];
	for (int i = 1; i <= T; i++)
	{
		int n;
		scanf("%d", &n);
		v.push_back(n);
	}
	for(auto i : v) printf("%d\n", dp[i]);
	
    return 0;
}

