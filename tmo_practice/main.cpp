#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a[8];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	// а╤гу!
	sort(a, a + n);
	vector<int> v(n, 1);
	for (int i = 0; i < m; i++) v[i] = 0;
	do
	{
		for (int i = 0; i < n; i++)
			if (!v[i]) printf("%d ", a[i]);
		printf("\n");
	} while (next_permutation(v.begin(), v.end()));
	return 0;
}