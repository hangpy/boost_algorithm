//// BAEK_2104. 부분배열 고르기
//
//#include <iostream>
//
//using namespace std;
//typedef long long ll;
//
//int N, A[100000];
//
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0);
//	cin >> N;
//	for (int i = 0; i < N; i++) cin >> A[i];
//
//	int MAX = 0;
//	for (int n = 0; n < N; n++)
//	{
//		int min = A[n], i = n, j = n;
//		ll sum = min;
//		while (A[i] >= min || A[j] >= min)
//		{
//			if (A[i] >= min && i > -1)
//				if (A[--i] >= min) sum += A[i];
//
//			if (A[j] >= min && j < N)
//				if (A[++j] >= min) sum += A[j];
//
//		}
//		sum *= min;
//		MAX = MAX < sum ? sum : MAX;
//	}
//
//	cout << MAX << endl;
//	return 0;
//}