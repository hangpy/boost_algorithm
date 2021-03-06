//문제 출처: https://algospot.com/judge/problem/read/WILDCARD

#include <queue>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int T, N;
string W, S;
vector<string> v;

int dp[101][101];

bool isMatched(int w, int s)
{
	int &ret = dp[w][s];
	if (ret != -1) return ret;
	// until matched
	while (w < W.size() && s < S.size() &&
		(W[w] == S[s] || W[w] == '?'))
	{
		w++;
		s++;
	}
	// if not matched, why?
	if (w == W.size()) return ret = (s == S.size());
	if (W[w] == '*')
	{
		for (int skip = 0; s + skip <= S.size(); skip++)
			if (isMatched(w + 1, s + skip))
				return ret = 1;
	}
	return ret = 0;
}

int main()
{


	cin >> T;
	if (T < 1 || T > 10) exit(-1);
	for (int t = 1; t <= T; t++)
	{
		// he**p
		cin >> W;
		cin >> N;
		if (N < 1 || N > 50) exit(-1);

		for (int n = 1; n <= N; n++)
		{
			memset(dp, -1, sizeof(dp));

			cin >> S;

			if (isMatched(0, 0) == 1) v.push_back(S);

			memset(dp, -1, sizeof(dp));
		}
	}

	sort(v.begin(), v.end());
	for (auto s : v)
		cout << s << endl;

	/*while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}*/

    return 0;
}

