#include <cstdio>

using namespace std;

int L, n, m;
int N[3000];
int M[3000];

int main()
{
	scanf("%d", &L);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &N[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) scanf("%d", &M[i]);

	int C=0, P=0;
	int l = N[0], i = 1, j = 1;
	int preN = N[0], preM = M[0];
	int min_cal = 0;
	while (l <= L)
	{
		if (preN == 1 && N[i] == 2 && preM == 2)
		{
			min_cal += 2;
			C += 2;


			i++, j++;
		}
		else if (preN == 2 && preM == 1 && M[j] == 2)
		{
			min_cal += 2;
			C += 2;


			i++, j++;
		}
		else if (preN == 1 && N[i] == 1 && preM == 2)
		{
			min_cal += 1;
			P += 1;


			j++;
		}
		else if (preN == 2 && preM == 1 && M[j] == 1)
		{
			min_cal += 1;
			P += 1;


			i++;
		}
		else
		{
			i++, j++;
		}
	}


	return 0;
}