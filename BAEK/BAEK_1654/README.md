

### &#128526;[문제 링크](https://www.acmicpc.net/problem/1654)

<br>

<br>

<br>

## 시간

1시간 20분

`8ms`, `2064 KB`

<br>

<br>

<br>

## 접근법

입력받을 때 최대값을 저장하고 1부터 MAX 값 사이에서 중간값을 갱신해가며 이분탐색을 한다.

<br>

<br>

<br>

## 코드

```cpp
// BAEK_1654. 랜선자르기

#include <iostream>

using namespace std;

long long K, N, LANS[10000], MAX, ANS;

void bs(long long s, long long e)
{
	if (s == e)
	{
		int sum = 0;
		for (int i = 0; i < K; i++) sum += (LANS[i] / e);
		if (sum >= N)
		{
			ANS = ANS < e ? e : ANS;
			return;
		}
		return;
	}

	long long middle = (s + e) / 2;
	
	int sum = 0;
	for (int i = 0; i < K; i++) sum += (LANS[i] / middle);

	if (sum >= N)
	{
		ANS = ANS < middle ? middle : ANS;
		if (middle == s) bs(middle + 1, e);
		else bs(middle, e);
	}
	else bs(s, middle);
}

int main()
{
	cin >> K >> N;
	for (int i = 0; i < K; i++)
	{
		cin >> LANS[i];
		MAX = MAX < LANS[i] ? LANS[i] : MAX;
	}
	bs(1, MAX);
	cout << ANS << endl;

	return 0;
}

```

<br>

<br>

<br>

## 실수한 부분

### 중간 임시결과값에 대한 자료형을 망각하지 말자!

```cpp
long long middle = (s + e) / 2;
// 원래 long long이 아니라 int로 선언했었음
```

이부분 때문에 무려 1시간을 날려먹었다. 랜선의 길이 조건이 `2^32-1` 로 주어지면서 무조건 `int`로 생각했지만 두 값을 더하면서 `int` 값의 범위를 초과할 수 있음을 생각했어야 한다. 반드시 임시 결과값을 생각하자

또한 다음과 같은 경우 자칫 잘못하면 두 값을 더하는 경우에서 무한 루프가 돌게된다. 무한루프가 도는 이유에 대해서는 내부 동작에 대한 이해가 좀 더 필요한 듯 하다.

<br>

### 이분 탐색에서 양측 값을 모두 검사 할 수 있는 종료조건을 구현하자.

```cpp
void bs(long long s, long long e)
{
    // 종료조건!!!!
	if (s == e)
	{
		int sum = 0;
		for (int i = 0; i < K; i++) sum += (LANS[i] / e);
		if (sum >= N)
		{
			ANS = ANS < e ? e : ANS;
			return;
		}
		return;
	}

	long long middle = (s + e) / 2;
	
	int sum = 0;
	for (int i = 0; i < K; i++) sum += (LANS[i] / middle);

	if (sum >= N)
	{
		ANS = ANS < middle ? middle : ANS;
        // 종료조건의 바로 전단계!!!!
		if (middle == s) bs(middle + 1, e);
		else bs(middle, e);
	}
	else bs(s, middle);
}
```

모든 중간값은 왼쪽 값을 기준으로 한다. 즉, 중간값과 왼쪽 값이 같다면 왼쪽 값과 오른쪽 값이 연이어 있다는 의미이다. 기준은 왼쪽 값으로 했기 때문에 이 전에 왼쪽 값에 대해선 이미 middle 값으로 연산이 이루어진 상태다. 때문에, 중간값과 왼쪽 값이 같다면 왼쪽값의 매개변수를 middle + 1로 줌으로써 최종적으로 콜스택에 쌓인 함수의 두 매개변수 값은 같은 상태인 것이다. 그 다음 왼쪽값과 오른쪽 값이 같은 경우 마지막으로 연산을 시행하고 가능하다면 정답을 갱신하고나서 return을 통해 재귀함수를 종료한다.

<br>

<br>

<br>