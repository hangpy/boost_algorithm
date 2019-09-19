

### &#128526;[문제 링크](https://www.acmicpc.net/problem/4195)

<br>

<br>

<br>

## 시간

endl 하나때문에 너무 오래걸렸던 문제.

<br>

<br>

<br>

## 접근법

map을 이용해서 인풋값의 문자열을 인덱싱 해주는게 첫 번째 포인트.

Union-Find를 이용해서 그룹핑

<br>

<br>

<br>

## 코드

```cpp
// BAEK_4195. 친구 네트워크

#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#define endl "\n"

using namespace std;

int T, F, parent[200002], cnt[200002];

int find(int p)
{
	if (parent[p] == p) return p;
	else return parent[p] = find(parent[p]);
}

void merge(int l, int r)
{
	int leftParent = find(l);
	int rightParent = find(r);

	if (leftParent == rightParent) return;

	if (leftParent > rightParent) swap(leftParent, rightParent);

	parent[rightParent] = leftParent;
	cnt[leftParent] += cnt[rightParent];
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> F;
		int num = 0;
		map<string, int> nameMap;
		for (int i = 0; i < F; i++)
		{
			string f1, f2;
			cin >> f1 >> f2;
			if (nameMap.count(f1) == 0) nameMap[f1] = num, parent[num] = num, cnt[num++] = 1;
			if (nameMap.count(f2) == 0) nameMap[f2] = num, parent[num] = num, cnt[num++] = 1;

			merge(nameMap[f1], nameMap[f2]);

			cout << cnt[find(nameMap[f1])] << endl;
		}
	}
	return 0;
}
```

<br>

<br>

<br>

## 실수한 부분

### `endl`는 아예 쓰지를 말자!

```cpp
#define endl "\n"
cout << cnt[find(nameMap[f1])] << endl;
```

`endl`를 쓸 경우, flush처리로 인해 "\n"처리보다 100배 이상이 느리다. 반드시 명심하도록 하자.

<br>

### map에서 중복 확인 쉽고 직관적으로 하기

먼저 `insert`를 시도하고 뭐할 필요도 없다

```cpp
if (nameMap.count(f1) == 0) nameMap[f1] = num, parent[num] = num, cnt[num++] = 1;
if (nameMap.count(f2) == 0) nameMap[f2] = num, parent[num] = num, cnt[num++] = 1;
```

카운트를 하고 해당 키,값이 없을 경우, `[]` 연산을 통해 키, 값을 삽입해준다. `insert()`의 반환 값을 통해 확인하는 방법도 있지만 이 방법이 더 직관적이고 기억에도 오래남는다.