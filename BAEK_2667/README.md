

### &#128526;[문제 링크](https://www.acmicpc.net/problem/2667)

<br>

<br>

<br>

## 접근법

**BFS**로 접근. 1을 만나게 될 경우 해당 지점으로부터 BFS로 모두 인접한 점들의 수를 탐색하면서 0으로 만든 후 카운트를 한다. 그리고 더이상 인접한 점이 1이 없게되면 인접한 1의 개수를  `vector`에 삽입. 그렇게 할 경우, `for`문의 기능으로 1을 발견했던 지점 다음부터 다시 탐색을 시작하고 아까 셌던 1은 모두 0으로 대체되었기 때문에 중복으로 세질 가능성은 없다.

모든 탐색이 끝나면 `vector`를 `<algorithm>`의 `sort`를 활용해 정렬한 후, `size`와 범위기반 `for`문을 이용해 정답을 출력.

<br>

<br>

<br>

## 핵심 파트

```C++
for (int i = 0; i < N; i++)
{
    for (int j = 0; j < N; j++)
    {
        if (map[i][j] == 1)
        {
            int cnt(1);
            queue<pii> q;
            q.push({ i, j });
            map[i][j] = 0;
            // searching
            while (!q.empty())
            {
                int now_row = q.front().first;
                int now_col = q.front().second;
                q.pop();

                // map[next_row][next_col] = 0;
				// cnt++;
                // 위의 위치에 위 구문을 놓을 경우 중복으로 세는 경우가 발생.

                // move drow, dcol
                for (int k = 0; k < 4; k++) 
                {
                    int next_row = now_row + drow[k];
                    int next_col = now_col + dcol[k];
                    if (map[next_row][next_col] == 0 || next_row < 0 || 
                        next_row > N-1 || next_col < 0 || next_col > N-1) continue;
                    q.push({ next_row, next_col });
                    map[next_row][next_col] = 0;
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
    }
}
```

<br>

<br>

<br>

### 실수한 부분

중간 주석 부분을 보면 `queue`에서 `pop()`을 시킬 때 0으로 설정하고 카운트를 샜는데 그럴 경우, 중복으로 카운트를 하는 경우가 발생한다.

```
0 1 1
0 1 1
1 1 1
```

이런경우 `dx = { 1, 0, -1, 0 }, dy = { 0, -1, 0, 1 }` 과 같이 6방향부터 시계방향으로 탐색을 할 경우, `{1,2}, {2,2}` 위치에서 각각 두 번, 세 번 중복으로 `BFS` 큐에 삽입됨을 알 수 있다.

<br>

<br>

<br>

## 사용한 디버깅 기법

```c++
#include <Windows.h>
Sleep(1000);
system("cls");
```

원하는 스크린샷을 시간의 흐름에 따라 확인할 수 있다. `dfs`, `bfs` 활용할 때 알고리즘의 진행 과정을 직관적으로 살필 때 특히 유용할 듯. 맵 밑에 필요한 정보를 추가로 보이게 하면 디버깅 효과는 배가 된다.

<br>

<br>

<br>