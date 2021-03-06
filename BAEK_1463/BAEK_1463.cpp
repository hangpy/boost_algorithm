// BAEK_1463.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//


#include <cstdio>
#include <algorithm>
using namespace std;

//struct candi
//{
//	int cal, times;
//};
//queue<candi> q;

int dp[1000001];

int main()
{
	/*int target;
	scanf("%d", &target);
	

	int ANS(0);
	q.push({ 1,0 });
	
	while(true)
	{
		candi curr = q.front();
		q.pop();
		int curr_cal = curr.cal;
		int curr_times = curr.times;
		if (curr_cal == target)
		{
			ANS = curr_times;
			break;
		}
		for (int i = 0; i < 3; i++)
		{
			if (i == 0) q.push({ curr_cal * 3, curr_times + 1 });
			else if (i == 1) q.push({ curr_cal * 2, curr_times + 1 });
			else q.push({ curr_cal + 1, curr_times + 1 });
		}
	}
	
	printf("%d\n", ANS);*/

	int target;
	scanf("%d", &target);

	dp[1] = 0;
	for (int n = 2; n <= target; n++)
	{
		if (n % 3 != 0 && n % 2 != 0) dp[n] = dp[n - 1] + 1;
		else if (n % 3 == 0 && n % 2 != 0) dp[n] = min(dp[n / 3] + 1, dp[n - 1] + 1);
		else if (n % 3 != 0 && n % 2 == 0) dp[n] = min(dp[n / 2] + 1, dp[n - 1] + 1);
		else dp[n] = min(min(dp[n / 2] + 1, dp[n / 3] + 1), dp[n - 1] + 1);
	}

	printf("%d\n", dp[target]);

    return 0;
}

