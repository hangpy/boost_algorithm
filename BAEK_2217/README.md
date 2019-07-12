

### &#128526;[문제 링크](https://www.acmicpc.net/problem/2217)

<br>

<br>

<br>

## 접근법

처음엔 디피로 접근했지만 디피가 아니라 그리디 알고리즘이었음. 

<br>

<br>

<br>

## 핵심 파트

```cpp
#include <cstdio>
#include <algorithm>

using namespace std;

int N, greedy[100000];

int main()
{
	scanf("%d", &N);
	for (int n = 0; n < N; n++) scanf("%d", &greedy[n]);
	
    // 나의 로직에선 정렬이 핵심이었음
    sort(greedy, greedy+N);
	
	int MAX(0);
	int curr(0);
	for (int i = 0; i < N; i++)
	{
        // 필요 없는 계산은 하지 않겠다라는 의지
		if (greedy[i] == curr) continue;
		int curr_max = (N - i) * greedy[i];
		if (MAX < curr_max) MAX = curr_max;
	}

	printf("%d\n", MAX);

    return 0;
}
```

<br>

<br>

<br>

## 실수한 부분

일반 배열 정렬.

```cpp
sort(arr, arr + length);
```

