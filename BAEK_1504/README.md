

### &#128526;[문제 링크](https://www.acmicpc.net/problem/1504)

<br>

<br>

<br>

## 접근법

다익스트라를 세번 함으로써 문제 답을 구할 수 있음. 필요 없는 계산은 하지 않으면서 다익스트라를 세번 반복하는 것이 문제의 핵심이었음. 특히 a -> b로 가는 최단 경로는 b -> a로 가는 최단 경로와 같다는 것이 키 포인트 였다.

<br>

<br>

<br>

## 핵심 파트

```C++
void dijkstra(int start_node)
{
	dist[start_node] = 0;
	long long currDist = dist[start_node];
	pq.push({start_node, 0});
	while (!pq.empty())
	{
		if (dist[X] != -1 && dist[Y] != -1) break;
		candi toUpdate = pq.top();
		pq.pop();
		currDist = toUpdate.minDist;
		if (dist[toUpdate.node] == -1)
			dist[toUpdate.node] = currDist;
		for (auto next : adj[toUpdate.node])
			if (dist[next.vertex] == -1)
				pq.push({ next.vertex, currDist + next.edge });
	}
	// initialize pq
	while (!pq.empty()) pq.pop();
}
```

#### 꿀팁 &#128273;

```c++
struct candi
{
	int node;
	long long minDist;
};

struct cmp
{
	bool operator()(candi t, candi u)
	{
		// 치명적이었던 실수 구간. u를 t로 씀.
        // 오름차순은 다음과 같이 해야함.
		return t.minDist > u.minDist;
        // 내림차순
        // return t.minDist < u.minDist;
	}
};

priority_queue<candi, vector<candi>, cmp> pq;
```

우선순위 큐를 상황에 맞게 커스터마이징 할 수 있다. 위와 같은 기법을 잘 기억할 수 있도록 하자.

[우선순위 큐 도움 많이된 글](https://koosaga.com/9)

<br>

<br>

<br>

## 실수한 부분

```c++
struct cmp
{
	bool operator()(candi t, candi u)
	{
		// 치명적이었던 실수 구간. u를 t로 씀.
		return t.minDist > u.minDist;
	}
};
```

위와 같이 u를 t라고 쓰고 거의 한시간 넘게 해당 부분만 찾은 것 같다. 위와 같은 실 수는 하기도 쉽고, 하게 되면 눈에 잘 안들어오기 때문에 디버깅도 매우 까다롭다. 제발 이런 실수는 좀 하지 말자. 벌써 두번 째 하는 듯 하다.

```c++
long long ANS(0);

if (interXY == -1) ANS = -1;
else
{
    if ((one_to_X == -1 || Y_to_N == -1) && (one_to_Y != -1 && X_to_N != -1)) ANS = one_to_Y + interXY + X_to_N;
    else if ((one_to_X != -1 && Y_to_N != -1) && (one_to_Y == -1 || X_to_N == -1)) ANS = one_to_X + interXY + Y_to_N;
    else ANS = min(one_to_Y + interXY + X_to_N, one_to_X + interXY + Y_to_N);
}
```

`첫째 줄에 두 개의 정점을 지나는 최단 경로의 길이를 출력한다. 그러한 경로가 없을 때에는 -1을 출력한다.`

위와 같은 출력 제약사항을 눈여겨 보지 않고 바로 코딩해버렸다. 이 또한 아무리 코딩을 잘해도 치명적인 실수다.

### 요약

1.  비교 연산자 할 때, 제발 대상체를 헷갈리지 말자.
2.  입출력 등, 제약사항을 반드시 확인하고 넘어가자.

<br>

<br>

<br>

