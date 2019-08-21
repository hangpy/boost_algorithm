

### &#128526;[문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpFQaAQMDFAUq)

<br>

<br>

<br>

## 시간

35분 컷. 삼성 문제 치고는 코드도 짧고 쉬웠다.

`19ms`, `12,624 kb`

<br>

<br>

<br>

## 접근법

전형적인 DFS 재귀호출 문제였다. 재귀호출을 사용할 때의 트리 형태의 함수호출 구조를 파악만 잘 한다면 어렵지 않게 풀 수 있었던 문제였다. 재귀호출을 안하고도 풀 수 있지만 빠른 시간안에 별 조건 없이 풀기 위해선 재귀호출만큼 쉬운 접근은 없었던 것 같다.

<br>

<br>

<br>

## 코드

```cpp
// SWEA_1952. 수영장
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int T, D1, M1, M3, Y1, plan[13];
// 좀더 FANCY하게 무한대를 표현하는 방법. 알아두면 요긴하다.
const int INF = numeric_limits<int>::max();

int dfs(int mounth)
{
	int days = plan[mounth];
	int pay = INF;

    // 12월이 넘어갔다는 얘기는 모든 지불 계획을 완료 했다는 뜻이므로 0을 반환
	if (mounth > 12) return 0;
	else
	{
        // 일 결제부터 차례대로 최소 값을 구해나간다.
        
		// 일 결제
		pay = min(pay, D1 * days + dfs(mounth + 1));
		// 월 결제
		pay = min(pay, M1 + dfs(mounth + 1));
		// 3달 결제;
		pay = min(pay, M3 + dfs(mounth + 3));
		// 1년 결제;
		pay = min(pay, Y1 + dfs(mounth + 12));
	}
	return pay;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> D1 >> M1 >> M3 >> Y1;
		for (int y = 1; y <= 12; y++) cin >> plan[y];

		int result = dfs(1);
		cout << "#" << t << " " << result << "\n";
	}
	return 0;
}
```

<br>

<br>

<br>