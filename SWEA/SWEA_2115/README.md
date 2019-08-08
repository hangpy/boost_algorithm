

### &#128526;[문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V4A46AdIDFAWu)

<br>

<br>

<br>

## 시간

3시간 초과... 쉬운 문젠데 아직 연습이 필요하다.

<br>

<br>

<br>

## 접근법

처음에 접근했던 대로 하게되면 10번째 테스트 케이스에서는 돌아가지도 않을 뿐더러 첫번째 말고는 답도 틀리게 나왔다. 순열과 조합을 여러 함수에서 너무 중첩해서 쓰다보니 실수도 많아졌고 시간복잡도 측면에서도 좋지 않았다.

순열과 조합은 잘 구현은 됐지만 지금의 수준을 유지해서는 안된다. 실수를 줄이고 중복되는 계산을 피하는 알고리즘을 짜도록 해야한다.

먼저 M이 주어지는 생황에서의 가로로 주어지는 조합에서의 최대값은 정해져 있다. 하지만 두 일꾼의 작업 박스 조합을 만들고 계산하는 과정에서 중복으로 계산될 수 있다. 즉, 메모이제이션을 통해 각 일꾼의 조합에서 최대값을 구하는 계산의 중복을 피할 수 있다. 해당 계산은 `make_dp`에서 확인할 수 있다.

또한 `make_dp`에서 각 조합의 최대값을 구하는 식에 대해서도 살펴볼 것이 있다. 처음에는 포함하는 벌꿀 통을 하나씩 줄여가면서 새로 조합을 만들어 계산했지만, 이는 확률적인 사고에서 멍청한 생각이었다. 그냥 `2^m`, 즉 각 벌굴의 포함관계를 고려하는 재귀호출 형태의 조합만 고려했으면 됐다.

`calc() 함수` 같이 포함 여부 등, 알고리즘 자체가 트리형태로 표현되는 것은 재귀호출로 간편하게 구현이 가능하다. 유용한 기법이니 잘 알아두도록 하자.

<br>

<br>

<br>

## 고친 코드

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int map[10][10], dp[10][10], boxs[5];

int calc(vector<int>& v, int c, int idx, int sum, int val)
{
	if (sum > c) return 0;
	if (idx == v.size()) return val;
	
	return max(calc(v, c, idx + 1, sum + v[idx], val + pow(v[idx], 2)), calc(v, c, idx + 1, sum, val));
}

int get_max(int y, int x, int c, int n, int m)
{
	vector<int> v;
	for (int i = x; i < x + m; i++)
		v.push_back(map[y][i]);
	return calc(v, c, 0, 0, 0);
}

void make_dp(int n, int m, int c)
{
	memset(dp, 0, sizeof(dp));
	for (int row = 0; row < n; row++)
		for (int i = 0; i < n - m + 1; i++)
			dp[row][i] = get_max(row, i, c, n, m);
}

int find_each_max(int y, int x, int n, int m)
{
	int ans = 0;
	
	for (int i = x + m; i < n; i++)
		ans = max(ans, dp[y][x] + dp[y][i]);
	
	for (int row = y + 1; row < n; row++)
		for (int col = 0; col < n; col++)
			ans = max(ans, dp[y][x] + dp[row][col]);

	return ans;
}


int main()
{
	int T = 0;
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		memset(map, 0, sizeof(map));

		int N, M, C;
		cin >> N >> M >> C;
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				cin >> map[y][x];
		
		make_dp(N, M, C);

		int MAX = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N - M + 1; j++)
				MAX = max(MAX, find_each_max(i, j, N, M));


		cout << "#" << t << " " << MAX << "\n";
	}

	return 0;
}
```

<br>

<br>

<br>

## 실수한 부분

### 중복되는 계산이 있는지 확인해보자. 있다면, 미리 계산해 놓을 수 없는지도 생각해보자

`make_dp()` 함수를 참고하도록 하자

### 트리형태의 이미지화 될 수 있는 알고리즘은 재귀를 고려해본다.

예를들어 `2^m` 형태의 조합이 포함된다.