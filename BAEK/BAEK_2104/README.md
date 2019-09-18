

### &#128526;[문제 링크](https://www.acmicpc.net/problem/2104)

<br>

<br>

<br>

## 시간

걍 오래걸림. 다른사람꺼 보고 풀었다. 너무 어려웠다. 분할정복을 앞으로 더 많이 해야겠음.

<br>

<br>

<br>

## 접근법

히스토그램 문제와 비슷. 케이스를 분할해서 정복

<br>

<br>

<br>

## 코드

```cpp
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll N, A[100000], ANS;


ll dq(int l, int r)
{
	ll ans = 0;
	
    // 기저상황
	if (l == r) return A[l] * A[l];
	
	ll m = (l + r) / 2;
	
    // max값 구하는 부분이 정복, 재귀로 들어가는 것이 분할
	ans = max(dq(l, m), dq(m + 1, r));

    // 분할 기준점에 걸쳐있는 정답 확인을 위한 추가 분할 정복
	ll MIN = A[m], s = m, e = m;
	ll sum = MIN;
    // 이부분을 구현하기 매우 까다로웠다
	while (s > l || e < r)
	{
        // 확장 방향을 판별하기 위한 로직 -> 그 원리를 잘 이해하도록 하자
		int p = s > l ? min(A[s - 1], MIN) : -1;
		int q = e < r ? min(A[e + 1], MIN) : -1;
		if (q >= p)
		{
			e++;
			MIN = q;
			sum += A[e];
		}
		else
		{
			s--;
			MIN = p;
			sum += A[s];
		}
		ans = max(ans, MIN * sum);
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	cout << dq(0, N - 1) << endl;

	return 0;
}

```

<br>

<br>

<br>

