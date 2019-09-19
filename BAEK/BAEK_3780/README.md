

### &#128526;[문제 링크](https://www.acmicpc.net/problem/3780)

<br>

<br>

<br>

## 시간

많은 연습이 필요하다. 계속 시간초과가 났었음.

<br>

<br>

<br>

## 접근법

문제 해석이 다소 힘들었던 문제다. 그림을 그려가면서 문제를 완벽히 이해하고 문제를 풀도록 하자.

처음의 모든 기업은 각자 스스로가 센터라는 것을 먼저 인지했어야 했다. 

<br>

<br>

<br>

## 코드

```cpp
// BAEK_3780. 네트워크 연결

#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long ll;

int T, N, PARENT[20001], LENGTH[20001];

// 압축!!!!
int find(int p)
{
	if (PARENT[p] == p) return p;
	else
	{
		// 여기서 이걸 안해줘서 계속 시간초과 났던거임
		// n시간 안에서 갱신까지 해줬어야 했음.
		int tp = find(PARENT[p]);
		LENGTH[p] += LENGTH[PARENT[p]];
		PARENT[p] = tp;
		return tp;
	}
}

// 센터 i를 기업 j에 연결한다
void merge(int i, int j)
{
	PARENT[i] = j;
	LENGTH[i] = abs(i - j) % 1000;
}


int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		for (int i = 1; i <= N; i++) PARENT[i] = i;
		while (1)
		{
			char mode;
			cin >> mode;
			if (mode == 'O') break;
			if (mode == 'E')
			{
				int com; cin >> com;
				// 압축과정 필요
				find(com);
				cout << LENGTH[com] << "\n";
			}
			if (mode == 'I')
			{
				int center = 0, com = 0;
				cin >> center >> com;
				merge(center, com);
			}
		}
		// 실수하기 쉬운 초기화
		memset(LENGTH, 0, sizeof LENGTH);
	}
	return 0;
}

```

<br>

<br>

<br>

## 실수한 부분

### 압축 과정을 반드시 거쳐야 한다.

```cpp
int find(int p)
{
	if (PARENT[p] == p) return p;
	else
	{
		int tp = find(PARENT[p]);
        // 여기서 이걸 안해줘서 계속 시간초과 났던거임
		// n시간 안에서 갱신까지 해줬어야 했음.
		LENGTH[p] += LENGTH[PARENT[p]];
		PARENT[p] = tp;
		return tp;
	}
}
```

최종 센터를 찾고 다시 return 되면서 마치 거꾸로의 순서로 연산이 가능했음을 인지했어야 했다. Union-Find의 압축과정을 다소 응용한 것이다. 이런 기법은 비단 Union-Find뿐 아니라 재귀를 이용하는 많은 알고리즘에서 활용할 수 있으니 잘 알아두도록 하자.

<br>

### 테스트 케이스가 여러 개인 경우, 전역 변수 초기화 반드시 고려하자!

```cpp
// 실수하기 쉬운 초기화
memset(LENGTH, 0, sizeof LENGTH);
```

이거 안하면 답 틀린다.