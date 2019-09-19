

### &#128526;[문제 링크](https://www.acmicpc.net/problem/10775)

<br>

<br>

<br>

## 시간

50분

<br>

<br>

<br>

## 접근법

처음엔 그리디 하게 접근했는데, 그리디 자체가 시간복잡도가 뻑날 가능성이 있었음.

그래서 다시 유니온 파인드로 접근해서 바로바로 가능한 도킹 게이트 부모 배열을 갱신.

이후 find했는데 0을 가리키면 불가능한 것으로 판단.

<br>

<br>

<br>

## 코드

```cpp
// BAEK_10775. 공항

#include <iostream>
#define endl "\n"

using namespace std;

int G, P, parent[100001], air[100000];

int find(int p)
{
	if (p == parent[p]) return p;
	else return parent[p] = find(parent[p]);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> G >> P;
	for (int i = 1; i <= G; i++) parent[i] = i;
	for (int i = 0; i < P; i++) cin >> air[i];

	int cnt = 0;
	for (int i = 0; i < P; i++)
	{
		int toDock = find(air[i]);
		// merge 부분
		if (toDock != 0) parent[toDock] = parent[toDock - 1], cnt++;
		else break;
	}
	cout << cnt << endl;

	return 0;
}
```

<br>

<br>

<br>

## 실수한 부분

### find 내에서 자꾸 merge를 하려고 시도했음.

```cpp
int find(int p)
{
	if (p == parent[p]) return p;
	else return parent[p] = find(parent[p]);
}
```

이렇게 그냥 find만 하면 됐었는데 아래처럼 실수함

```cpp
#include <iostream>
#define endl "\n"

using namespace std;

int G, P, parent[100001], air[100000];

int find(int p)
{
    // 이게 뭔짓이뇨!
	if (p == parent[p])
	{
		parent[p] = parent[p - 1];
		return p;
	}
	else
	{
		int tmp = parent[parent[p]];
		parent[parent[p]] = parent[parent[p] - 1];
		return tmp;
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> G >> P;
	for (int i = 1; i <= G; i++) parent[i] = i;
	for (int i = 0; i < P; i++) cin >> air[i];

	int cnt = 0;
	for (int i = 0; i < P; i++)
	{
		if (find(air[i]) != 0) cnt++;
		else break;
	}
	cout << cnt << endl;

	return 0;
}
```

이럴 경우, 압축과정을 건너 뛰게 되면서 merge가 불가능해짐.