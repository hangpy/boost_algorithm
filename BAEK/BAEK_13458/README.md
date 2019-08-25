

### &#128526;[문제 링크](https://www.acmicpc.net/problem/13458)

<br>

<br>

<br>

## 시간

15분 컷.

`124 ms`, `5892kb`

<br>

<br>

<br>

## 접근법

각 반마다의 최소 셤감독 수를 그리디 하게 찾아냄. 너무 쉬웠는데 왜 정답률이 낮지? 아마도 `long long` 자료형으로 답을 도출했어야 되는 것 때문에 그런게 아닌가 싶다.

<br>

<br>

<br>

## 코드

```cpp
// BAEK_13458. 시험감독

#include <iostream>

using namespace std;

int N, A[1000000], B, C;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	cin >> B >> C;

	long long min = 0;
	
	for (int i = 0; i < N; i++)
	{
		min++;
		A[i] -= B;
		if (A[i] > 0)
		{
			int a = A[i] / C;
			int b = A[i] % C;
			min += a;
			if (b != 0) min++;
		}
	}

	cout << min << endl;

	return 0;
}
```

<br>

<br>

<br>