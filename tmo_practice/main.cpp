#include <cstdio>
#include <algorithm>

using namespace std;

int arr[8], result[8];

void r_perm(int n, int m, int index, int depth)
{
	if (depth == m)
	{
		for (int i = 0; i < m; i++)
			printf("%d ", result[i]);
		printf("\n");
	}
	else
	{
		int tmp = 0;
		for (int i = index; i < n; i++)
		{
			if (tmp == arr[i]) continue;
			tmp = arr[i];
			result[depth] = arr[i];
			r_perm(n, m, i, depth + 1);
		}
		
	}
}


int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + N);

	r_perm(N, M, 0, 0);

	return 0;
}