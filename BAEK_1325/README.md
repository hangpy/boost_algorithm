

### &#128526;[문제 링크](https://www.acmicpc.net/problem/1325)

<br>

<br>

<br>

## 접근법

**인접리스트를 이용한 DFS**로 접근하면 손쉽게 풀린다. 특히, 네트워크의 신뢰관계를 인접리스트로 표현하는 것이 관건이었던 문제다. 나머지는 문제에 맞게 놓치는 부분 없이만 구현 하면 된다.

<br>

<br>

<br>

## 핵심 파트

```C++
int dfs(int node)
{
	int ans(1);
	for (auto next_node : adj[node])
	{
		if (!visted[next_node])
		{
			visted[next_node] = true;
			ans += dfs(next_node);
		}
	}
	return ans;
}
```

```c++
int MAX(0);
for (int i = 1; i <= N; i++)
{
    if (check[i])
    {
        visted[i] = true;
        check[i] = dfs(i);
        if (MAX < check[i])
        {
            MAX = check[i];
            ans.clear();
            ans.push_back(i);
        }
        else if (MAX == check[i]) ans.push_back(i);
        else;
        // again initialize
        memset(visted, 0, sizeof(visted));
    }
}	
```

`dfs`로 각 시작 가능한 컴퓨터로부터의 감염 컴퓨터 수를 구함과 동시에 `MAX`값을 구하는 로직. 연습하면 코드 길이를 훨씬 더 줄일 수 있을 듯 하다.

#### 꿀팁 &#128273;

```c++
int ans(1); // 반드시 1 이상으로 초기화
ans += dfs(next_node); // return시 축적을 위해
return ans; // 최종 상황에서 리턴할 때 1을 반환할 것이다.
```

어느 특정 상황까지 거쳐간 노드의 갯수를 샐 때는 위와 같은 구조의 `dfs` 재귀 함수를 쓰면 편하다.

<br>

<br>

<br>

## 실수한 부분

```c++
#include <string.h>
memset(dest, 0, sizeof(dest));
```

`memset()` 함수를 이용해 초기화를 할 때는 반드시 `string.h` 헤더를 포함시키자.

<br>

<br>

<br>

## 생각할 거리

링크를 통해 다른 사람의 정답을 메모리는 많이 잡아먹지만 압도적으로 빠른 성능을 보이는 코드가 있다. 어떤 알고리즘을 썼는지 고민할 필요가 있어보인다.

<br>

<br>

<br>