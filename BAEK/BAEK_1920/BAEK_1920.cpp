// BAEK_1920. 수찾기
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, A[100000];

//bool find(int num, int s, int e)
//{
//	int middle = (s + e) / 2;
//	if (A[middle] == num) return true;
//	else
//	{
//		if (middle == s) return (A[e] == num);
//
//		if (A[middle] > num)find(num, s, middle);
//		else find(num, middle, e);
//	}
//}


int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);

	cin >> M;
	/*for (int i = 0; i < M; i++)
	{
		int num; cin >> num;
		cout << find(num, 0, N-1) << "\n";
	}*/
	for (int i = 0; i < M; i++)
	{
		int n; cin >> n;
		cout << binary_search(A, A+N, n) << "\n";
	}

	return 0;
}