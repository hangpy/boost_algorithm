

### &#128526;[문제 링크](https://www.acmicpc.net/problem/3190)

<br>

<br>

<br>

## 접근법

게임의 규칙, 및 순서를 논리적으로 순서에 맞게 잘 따라가는 것이 관건. 특히나 head와 현재 snake의 상태를 저장하기 위한 queue를 쓴 것이 하나의 포인트.

<br>

<br>

<br>

## 핵심 파트

<br>

```c++
// drow[0], dcol[0]
DIR = 0;
TIME = 0;
map[1][1] = 1;
snake.push({ 1,1 });
pos head = { 1, 1 };
while (true)
{
    TIME++;

    int nrow = head.row + drow[DIR];
    int ncol = head.col + dcol[DIR];

    // if crush to the wall or to snake itself
    if (nrow > N || nrow < 1 || ncol > N || ncol < 1 ||
        map[nrow][ncol] == 1) break;

    // if there is no apple, erase tail
    if (map[nrow][ncol] != 2)
    {
        pos tail = snake.front();
        map[tail.row][tail.col] = 0;
        snake.pop();
    }

    map[nrow][ncol] = 1;
    snake.push({ nrow, ncol });
    head = { nrow, ncol };

    // if it is time to change direction, pop node from changes and change direction
    // !!!WARNING!!!

    /*
		if we don't limit if(!changes.empty()) it will be faced with below error.
		Expression: deque iterator not dereferencable
	*/
    if (!changes.empty())
    {
        if (TIME == changes.front().time)
        {
            DIR = changeDirection(changes.front().direc);
            changes.pop();
        }
    }
}
```



#### 꿀팁 &#128273;

방향 바꾸기 표현

```c++
int drow[4] = { 0, 1, 0, -1 };
int dcol[4] = { 1, 0, -1, 0 };

int changeDirection(int leftOrRight)
{
	if (leftOrRight == 0) // left
	{
		if (DIR > 0) return --DIR;
		else return 3;
	}
	else
	{
		if (DIR < 3) return ++DIR;
		else return 0;
	}
}
```



<br>

<br>

<br>

## 실수한 부분

`queue` 에러

```
Expression: deque iterator not dereferencable
```

위의 에러는 비어있는 큐에서 참조, 즉 pop() 혹은 front()와 같은 연산을 시도할 때 발생한다. 해당 에러 메시지를 받았다면 제일 먼저, 큐와 관련된 로직을 확인하는 것이 순서다.

<br>

<br>

<br>


