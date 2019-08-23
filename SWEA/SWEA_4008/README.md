

### &#128526;[문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeRZV6kBUDFAVH)

<br>

<br>

<br>

## 시간

30분 컷. 많이 쉬운 문제였음.

`88 ms` `12,632 kb`

<br>

<br>

<br>

## 접근법

처음에는 DFS로 풀려고 했으나 가만보니 그냥 순열로 푸는게 훨씬 쉬운 문제였다. 그래서 걍 `next_permutation()` 써서 풀었음. 20분도 안걸리긴 했지만 값이 `마이너스`가 나올 수 있다는 사실을 망각해버린 바람에 디버깅 시간이 좀 추가되었다. 그리고 최대값, 최소값 초기값은 조건대로 둘 수도 있었지만 limits연습을 위해 좀 더 FANCY한 방법으로 초기화 해줌.

<br>

<br>

<br>

## 코드

```cpp
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int T, N, nums[12];

int calc(int lhs, int rhs, int i)
{
	switch (i)
	{
	case 0:
		return lhs + rhs;
		break;
	case 1:
		return lhs - rhs;
		break;
	case 2:
		return lhs * rhs;
		break;
	case 3:
		return lhs / rhs;
		break;
	default:
		break;
	}
}

int main()
{
	
	ios::sync_with_stdio(0); cin.tie(0);

	freopen("sample_input.txt", "r", stdin);

	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		vector<int> ops;
		cin >> N;
		for (int i = 0; i < 4; i++)
		{
			int n; cin >> n;
			for (int j = 0; j < n; j++) ops.push_back(i);
		}
		for (int i = 0; i < N; i++) cin >> nums[i];
        
        // 처음에 실수한 부분. _max = 0 이라고 했었음.
		int _max = numeric_limits<int>::min();
		int _min = numeric_limits<int>::max();
		do
		{
			int tmp = nums[0];
			for (int i = 1; i < N; i++)
				tmp = calc(tmp, nums[i], ops[i - 1]);
			
			_max = max(_max, tmp);
			_min = min(_min, tmp);

		} while (next_permutation(ops.begin(), ops.end()));
		
		int result = abs(_max - _min);

		cout << "#" << t << " " << result << endl;
	}
	return 0;
}

```

<br>

<br>

<br>

## 실수한 부분

### +,- 를 간과하지 말자

