

### &#128526;[문제 링크](https://www.acmicpc.net/problem/5052)

<br>

<br>

<br>

## 시간

1시간

<br>

<br>

<br>

## 접근법

트라이 자료구조 이용해서 풀긴했지만 시간복잡도, 공간복잡도가 썩 좋지 못한듯 하다. 트라이 활용은 좀 더 심화적으로 공부해야할 듯 함.

<br>

<br>

<br>

## 코드

```cpp
// BAEK_5052. 전화번호 목록

#include <iostream>
#define endl "\n"
using namespace std;

int T, N;
char num[10001];

struct node
{
    // 이렇게 참거짓 배열을 만들 필요 없음 사실. 해당 노드가 leaf인지만 알려주면 됨.
	bool isLeaf[10]{ false };
	node *arr[10]{ NULL };
};

bool insert(node *cur, int index)
{
	bool ans = true;

	int n = num[index] - '0';

	if (cur->isLeaf[n]) return ans = false;

	if (num[index + 1] == '\0')
	{
		if (cur->arr[n] != NULL) return ans = false;
		cur->arr[n] = new node;
		cur->isLeaf[n] = true;
		return ans;
	}
	else
	{
		if (cur->arr[n] == NULL)
		{
			cur->arr[n] = new node;
			return ans = insert(cur->arr[n], index + 1);
		}
		else ans = insert(cur->arr[n], index + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		node* s = new node;
		cin >> N; int i = 0; bool keep = true;
		for (; i < N; i++)
		{
			cin >> num;
			if (!keep) continue;
			if ((keep = insert(s, 0)) == false) cout << "NO" << endl;
		}
		if (keep) cout << "YES" << endl;
	}
	return 0;
}

```

<br>

<br>

<br>

