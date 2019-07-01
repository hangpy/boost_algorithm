// SDS_LV1_1_papers.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string.h>

using namespace std;

int T, N, K, papers[10001], ans[10001]{ 0 }, TEST[56]{0};

int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N >> K;
		// cin papers
		for (int n = 1; n <= N; n++)
		{
			int num;
			cin >> num;
			papers[n] = num;
		}

		// logic
		int now_k(1), cnt(0), tmp(1);
		for (int i = 1; i <= N; i++)
		{
			if (now_k == papers[i]) tmp = i;
			if (now_k < papers[i])
			{
				cnt = cnt - (papers[i] - now_k - 1);
				ans[now_k] = cnt;
				cnt = 1;
				i = ++tmp;
				now_k++;
				continue;
			}
			if (i == N)
			{
				i = ++tmp;
				ans[now_k] = cnt - (K - now_k - 1);
				cnt = 1;
				now_k++;
				if (now_k == K) break;
				else continue;
			}
			cnt++;
		}

		// get MAX;
		int MAX(0);
		for (int i = 1; i <= K; i++)
			if (MAX < ans[i]) MAX = ans[i];

		TEST[t] = MAX;

		// initialize again
		memset(papers, 0, sizeof(papers));
		memset(ans, 0, sizeof(ans));
		MAX = 0;
	}
	for (int i = 1; i <= T; i++)
	{
		// cout answer
		cout << "#" << i << " " << TEST[i] << endl;
	}
}
