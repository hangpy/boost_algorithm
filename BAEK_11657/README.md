

### &#128526;[문제 링크](https://www.acmicpc.net/problem/11657)

<br>

<br>

<br>

## 접근법

간선의 가중치에 '음'의 수가 있으므로 **벨만 포드 알고리즘**으로 접근.

[벨만포드 개념정리 블로그 글](https://victorydntmd.tistory.com/104?category=686701)

<br>

<br>

<br>

## 핵심 파트

```C++
#define INF 2147483647
struct road
{
	int from, to, time;
};
road edges[6001];
```

벨만 포드에서 굳이 인접리스트 자료구조를 구현할 필요가 없다. 어짜피 모든 간선에 대해서 조사를 할 것이기 떄문.

```c++
scanf("%d %d", &N, &M);
for (int m = 1; m <= M; m++)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    edges[m] = { a, b, c };
}
```

시간 효율을 위해 표준입출력 함수 중에 `cin` 대신 `scanf`를 쓰도록 하자.

```c++
for (int n = 1; n <= N; n++) dist[n] = INF;
int ANS(0);
dist[1] = 0;
for (int n = 1; n <= N; n++)
{
    for(int m = 1; m <= M; m++)
    {
        road edge = edges[m];
        if (dist[edge.from] != INF && dist[edge.to] > dist[edge.from] + edge.time)
        {
            dist[edge.to] = dist[edge.from] + edge.time;
            if (n == N) ANS = -1;
        }
	}
}
```

벨만 포드에 대해 확실히 이해를 했다면 다음과 같은 적은 줄의 코드로 구현이 가능.

<br>

<br>

<br>

## 실수한 부분

처음에는 굉장히 비효율적으로 문제를 풀었다. 벨만 포드가 맞긴 하지만, 정확한 이해를 하고 풀지 않았으므로 어찌보면 당연했던 결과. 특히 시작 점을 제외한 모든 정점 `N-1` 번 동안 모든 `간선`에 대해서만 조사를 하면 됐다.

<br>

<br>

<br>

