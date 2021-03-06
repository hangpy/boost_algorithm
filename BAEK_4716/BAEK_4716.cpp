#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct team
{
	int size, a, b;
};
vector<team> v;
vector<int> ans;

bool cmp(team t, team u)
{
	return abs(t.a - t.b) > abs(u.a - u.b);
}

int main()
{
	while (true)
	{
		int N, A, B;
		scanf("%d %d %d", &N, &A, &B);
		if (N == 0 && A == 0 && B == 0) break;
		for (int n = 1; n <= N; n++)
		{
			int size, a, b;
			scanf("%d %d %d", &size, &a, &b);
			v.push_back({ size, a, b });
		}
		sort(v.begin(), v.end(), cmp);

		//for (auto i : v) printf("%d %d %d\n", i.size, i.a, i.b);
		
		int grossLen(0);
		// logic for greedy
		for (auto t : v)
		{
			if (t.a > t.b)
			{
				if (B - t.size >= 0)
				{
					grossLen += t.size * t.b;
					B -= t.size;
				}
				else
				{
					int rest = abs(B - t.size);
					grossLen += B * t.b;
					B = 0;
					grossLen += rest * t.a;
					A -= rest;
				}
			}
			else
			{
				if (A - t.size >= 0)
				{
					grossLen += t.size * t.a;
					A -= t.size;
				}
				else
				{
					int rest = abs(A - t.size);
					grossLen += A * t.a;
					A = 0;
					grossLen += rest * t.b;
					B -= rest;
				}
			}
		}
		ans.push_back(grossLen);
		// initialize global vector
		v.clear();
	}
	for (auto i : ans) printf("%d\n", i);
    return 0;
}

