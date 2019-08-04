

### &#128526;[문제 링크](https://www.acmicpc.net/problem/1197)

<br>

<br>

<br>

## 접근법

MST 대표 문제. Union-Find를 이용해서 풀이.

<br>

<br>

<br>

## 구현 코드

```C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, E;
struct edge{int a, b, w;};
edge arr_edge[100001];
int parent[10001];
int level[10001];

int find(int child)
{
	if (parent[child] == child) return child;
	else return parent[child] = find(parent[child]);
}

void merge(int a, int b)
{
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) return;
	
	if (level[pa] < level[pb]) swap(pa, pb);
	
	parent[pb] = pa;
	level[pa] = min(level[pa], level[pb] + 1);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> V >> E;

	for (int i = 1; i <= E; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		if (a > b) swap(a, b);
		arr_edge[i] = { a, b, w };
	}

	for (int i = 1; i <= V; i++) parent[i] = i;

	// 실수! 그대로 arr_edge부터 시작하면 인덱스를 0포함해서 하기때문에 안됨.
	sort(arr_edge+1, arr_edge + E+1, [](edge& t, edge& u) -> bool {
		return t.w < u.w;
	});

	int sum = 0, cnt = 0;
	for (int i = 1; i <= E; i++)
	{
		int a = arr_edge[i].a, b = arr_edge[i].b, w = arr_edge[i].w;
		if (find(a) != find(b))
		{
			sum += w;
			merge(a, b);
			cnt++;
			if (cnt == V - 1) break;
		}
	}

	cout << sum << "\n";

	return 0;
}

/*
6 9
1 2 5
3 2 2
4 3 6
5 4 4
5 6 10
6 1 1
5 1 1
4 1 -100
2 5 9

답: -91
*/
```



<br>

<br>

## 실수한 부분

#### 정렬할 때, 시작 인덱스를 반드시 확인하자!

```cpp
for (int i = 1; i <= E; i++)
{
    int a, b, w;
    cin >> a >> b >> w;
    if (a > b) swap(a, b);
    arr_edge[i] = { a, b, w };
}

for (int i = 1; i <= V; i++) parent[i] = i;

// 실수! 그대로 arr_edge부터 시작하면 인덱스를 0포함해서 하기때문에 안됨.
sort(arr_edge+1, arr_edge + E+1, [](edge& t, edge& u) -> bool {
    return t.w < u.w;
});
```

인덱스 시작이 0이면 주소값 그대로, 1부터 시작이면 +1을 해주도록 하자. 끝점 또한 +1해주어야함. 끝점은 배열의 가장 끝 원소를 가리키는게 아니고 그 다음을 가리켜야 한다.

또한 sort()에서 비교함수 커스텀해줄 때, 참조자 쓰는 것 잊지 말도록 하자.