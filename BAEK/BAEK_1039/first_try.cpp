// BAEK_1039 교환

//#include <iostream>
//#include <cmath>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int N, K, LEN = 1;
//int pos[7] = { 1, 2, 3, 4, 5, 6, 7 };
//
//// first < second
//int change_pos(int num, int first, int second)
//{
//	int a = num / pow(10, first - 1); a %= 10;
//	int b = num / pow(10, second - 1); b %= 10;
//	if (a == 0 && second == LEN) return 0;
//
//	num -= a * pow(10, first - 1);
//	num -= b * pow(10, second - 1);
//
//	num += a * pow(10, second - 1);
//	num += b * pow(10, first - 1);
//
//	return num;
//}
//
//int find_max(int curr, int k)
//{
//	if (k == 0) return curr;
//
//	int judge = 0;
//	vector<int> v(LEN, 1);
//	for (int i = 0; i < 2; i++) v[i] = 0;
//	do
//	{
//		// 바꿀 자리수 결정
//		int first_pos = 0, second_pos = 0;
//		for (int i = 0; i < LEN; i++)
//		{
//			if (v[i] == 0)
//			{
//				// first_pos < second_pos
//				if (first_pos == 0) first_pos = pos[i];
//				else second_pos = pos[i];
//			}
//		}
//
//		int changedNum = change_pos(curr, first_pos, second_pos);
//		if (changedNum == 0) continue;
//
//		judge = max(judge, find_max(changedNum, k - 1));
//
//	} while (next_permutation(v.begin(), v.end()));
//
//	return judge;
//}
//
//int main()
//{
//	cin >> N >> K;
//
//	// define length of number
//	int tmp_N = N;
//	while ((tmp_N /= 10) > 0) LEN++;
//
//	int answer = find_max(N, K);
//
//	if (!answer) cout << -1 << endl;
//	else cout << answer << endl;
//
//
//	return 0;
//}
