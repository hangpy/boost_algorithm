

### &#128526;[문제 링크](https://www.acmicpc.net/problem/2667)

<br>

<br>

<br>

## 접근법

**위상정렬**로 접근. 각 건물이 지어지는 것은 방향성을 갖고, 사이클이 없는 DAG(Directed Acyclic Graph)로 표현 가능하다. 각 건물이 지어질 수 있는 최소 시간은 해당 건물이 지어지기 위해 사전에 지어져야 되는 건물의 최소시간에 자신의 시간을 더한 것. 사실 **DP**로도 접근이 가능할 듯.

<br>

<br>

<br>

## 핵심 파트

```C++
while (!q.empty())
{
    int curr = q.front();
    q.pop();
    for (int next : adj[curr])
    {
        min_time[next] = max(min_time[curr] + time[next], min_time[next]);
        if (--indegree[next] == 0) q.push(next);
    }
}
```

<br>

<br>

<br>

## 실수한 부분

아래와 같이 해야되는 것을

```c++
min_time[next] = max(min_time[curr] + time[next], min_time[next]);
```

다음과 같이 두 번 오답이 계속 나왔음.

```c++
min_time[next] = min_time[curr] + time[next]
```

```
min_time[next] = min(min_time[curr] + time[next], min_time[next]);
```

<br>

<br>

<br>


