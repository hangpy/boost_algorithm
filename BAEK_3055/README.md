

### &#128526;[문제 링크](https://www.acmicpc.net/problem/3055)

<br>

<br>

<br>

## 접근법

하나의 BFS로직으로 홍수와 고슴도치의 이동 가능한 경로를 모두 표현 가능.

<br>

<br>

<br>

## 핵심 파트

<br>

```c++
for (auto W : wv)
{
    q.push(W);
}
q.push(S);

bool isAnswer = false;
memset(mem, -1, sizeof(mem));
mem[S.row][S.col] = 0;

while (!q.empty())
{
    bool toBreak = false;

    pos curr = q.front();

    q.pop();

    int crow = curr.row;
    int ccol = curr.col;
    bool isWater = curr.isWater;

    if (isWater)
    {
        for (int i = 0; i < 4; i++)
        {
            int nrow = crow + drow[i];
            int ncol = ccol + dcol[i];

            if (nrow > R || nrow < 1 || ncol > C || ncol < 1 ||
                forest[nrow][ncol] <= -1) continue;
            forest[nrow][ncol] = -1;
            q.push({ nrow, ncol, true });
        }
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            int nrow = crow + drow[i];
            int ncol = ccol + dcol[i];

            if (nrow > R || nrow < 1 || ncol > C || ncol < 1 ||
                forest[nrow][ncol] == -1 || mem[nrow][ncol] >= 0) continue;
            mem[nrow][ncol] = mem[crow][ccol] + 1;
            q.push({ nrow, ncol, false });

            if (nrow == D.row && ncol == D.col)
            {
                ANS = mem[nrow][ncol];
                toBreak = true;
                isAnswer = true;
                break;
            }
        }
    }

    if (toBreak) break;
}
```

`queue`에서 나온 점이 홍수인지, 고슴도치인지 판별하는 것이 관건

#### 꿀팁 &#128273;

```c++
struct pos
{
	int row, col;
	bool isWater;
};
```

컨테이너에 담겨있는 노드를 꺼내 당시 집어넣었던 노드의 상태에 따른 로직을 구별하고 싶다면 위처럼, `struct`에 `isWater`처럼 상태를 나타내는 변수를 포함시킬 수 있다.

<br>

<br>

<br>

## 실수한 부분

#### 문제를 똑바로 읽자

홍수 발생 지점이 다수일 수 있는 것을 간과했다. '하나' 또는 '여러개'라는 키워드에 유의하면서 글을 읽도록 하자.

<br>

<br>

<br>


