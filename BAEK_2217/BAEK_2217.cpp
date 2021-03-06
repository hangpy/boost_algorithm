#include <cstdio>
#include <algorithm>

using namespace std;

int N, greedy[100000];

int main()
{
	scanf("%d", &N);
	for (int n = 0; n < N; n++) scanf("%d", &greedy[n]);
	sort(greedy, greedy+N);
	
	int MAX(0);
	int curr(0);
	for (int i = 0; i < N; i++)
	{
		if (greedy[i] == curr) continue;
		int curr_max = (N - i) * greedy[i];
		if (MAX < curr_max) MAX = curr_max;
	}

	printf("%d\n", MAX);

    return 0;
}

