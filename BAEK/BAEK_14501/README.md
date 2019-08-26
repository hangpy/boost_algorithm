

### &#128526;[문제 링크](https://www.acmicpc.net/problem/14500)

<br>

<br>

<br>

## 시간

15분 컷. 삼성문제 치고는 너무 쉬웠다.

`0 ms`, `1988 kb`

<br>

<br>

<br>

## 접근법

재귀함수 트리를 그려보면서 접근하면 굉장히 쉬운 문제였다.

<br>

<br>

<br>

## 코드

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

int N, T[16], P[16];

int dfs(int day)
{
	int sum = 0;
	int pay = P[day], len = T[day];
	if (day > N) return sum;
	else
	{
		if(day + len <= N+1) sum = max(sum, pay + dfs(day + len));
		sum = max(sum, dfs(day + 1));
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> T[i] >> P[i];
	
	cout << dfs(1) << endl;

	cout << endl;

	return 0;
}
```

<br>

<br>

<br>

