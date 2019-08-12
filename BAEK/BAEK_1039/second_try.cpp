
//#include <iostream>
//#include <cmath>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int N, K, LEN = 1;
//// 숫자 두개 이상인지를 판별하기 위한 배열 0 ~ 9
//int cnt[10];
//// 쉬운 스왑을 위한 벡터 이용
//vector<int> v;
//
//// 1 2 3 4 5
//// [][][][][]
//// 인덱스가 1부터 시작
//// 최대값이 구해지는 최소 자리바꿈 뒤에 남은 k를 반환하는 함수
//int change(int s, int k)
//{
//	// 더이상 자리바꿈을 진행할 수 없을 때
//	if (k == 0) return 0;
//
//
//	if (s == LEN) return k;
//
//	// 시작점 기준
//	int max_idx = s, tmp_max = v[s];
//	for (int i = s + 1; i <= LEN; i++)
//	{
//		// v[s]로부터 가장 멀리 있는 최대값
//		// 만약 10044이고 v[s]가 1이면 max_idx는 v[4]가 아니고 v[5]
//		if (tmp_max <= v[i])
//		{
//			tmp_max = v[i];
//			max_idx = i;
//		}
//	}
//
//	// 예를들어 20020인 경우, 현재 idx가 1인 상황에서 굳이 자리바꿈을 할 필요가 없음
//	// 때문에 k를 소모하지 않고 그대로 다음 시작점으로 재귀호출
//	if (s != max_idx && v[s] == v[max_idx]) return change(s + 1, k);
//	// 시작점보다 큰 숫자가 없어서 바꿀 필요가 없을 때, k는 줄어들지 않음
//	else if (s == max_idx) return change(s + 1, k);
//	else
//	{
//		swap(v[s], v[max_idx]);
//		// 자리바꿈이 된 경우 바꾸고 k를 하나 소모하고 다음 시작점을 재귀호출
//		return change(s + 1, k - 1);
//	}
//}
//
//
//
//int main()
//{
//	cin >> N >> K;
//
//	// 길이 구하기
//	int tmp_N = N;
//	while ((tmp_N /= 10) > 0) LEN++;
//	// 벡터 리사이징
//	v.resize(LEN + 1, 0);
//	// 인덱스 1부터 시작
//	tmp_N = N;
//	// 최대값이 구해지고 남은 k를 아는 시점에서 만약 같은 숫자가 두개 잇을 경우
//	// 더이상의 자리바꿈은 의미없으므로 같은 숫자가 두 개 있는지를 판별
//	bool isTwo = false;
//	for (int i = LEN; i > 0; i--)
//	{
//		v[i] = (tmp_N % 10);
//		tmp_N /= 10;
//		cnt[v[i]]++;
//		// 만약 같은 숫자가 두개 이상 있으면 isTwo를 true로 변환
//		if (cnt[v[i]] >= 2) isTwo = true;
//	}
//
//
//	// 한자리 숫자거나, 두자리 숫자이면서 10의 배수인 경우 -1를 반환
//	if ((LEN == 2 && N % 10 == 0) || N < 10) cout << -1 << endl;
//	else
//	{
//		// 최소 자리바꿈으로 최대값이 구해진 시점
//		int rest_k = change(1, K);
//
//		// 같은 수가 두 개 이상 없는 경우
//		if (!isTwo)
//		{
//			// 남은 k가 홀수인 경우 일의자리, 십의자리 숫자를 한번만 바꿔줌
//			if (rest_k % 2 == 1)
//				swap(v[LEN], v[LEN - 1]);
//			// 짝수번 남은 경우 더이상 바꾸는 것은 의미 없으므로 그대로 둠
//			else;
//		}
//
//		// INT반환하기 위해서 벡터의 각 숫자 계산
//		int ans = 0;
//		for (int i = 1; i <= LEN; i++) ans += v[i] * pow(10, LEN - i);
//
//		cout << ans << endl;
//	}
//	return 0;
//}
