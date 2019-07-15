

### &#128526;[문제 링크](https://www.acmicpc.net/problem/9935)

<br>

<br>

<br>

## 접근법

단순히 생각나는 것으로 접근하면 시간초과로 틀릴 확률이 매우 높은 의외로 난이도 있던 문제였다.이 문제 또한 **거꾸로 생각해보기**를 적용하면 풀릴 수 있는 문제였다. 또한, stack으로 푼다고는 하지만, stack의 느낌 보다는 vector의 인덱스를 잘 조작하는 것이 포인트였다. 왜냐하면 stack의 pop()연산은 사실 필요가 없기 때문이다. 문자열을 선형적으로 탐색하며 비교할 때, 비교하고자 하는 문자의 가장 마지막 문자를 기준으로 비교하는 것도 하나의 방법이 될 수 있다.

<br>

<br>

<br>

## 핵심 파트

<br>

```c++
char str[1000001], bomb[37];
char result[1000001];

int main()
{
	scanf("%s %s", str, bomb);

	int n = strlen(str), m = strlen(bomb);
	int ri(0);
	for (int i = 0 ; i <= n; i++, ri++)
	{
		if (i == n) result[ri] = '\0';
		result[ri] = str[i];
		if (result[ri] == bomb[m - 1])
			if (!strncmp(result + ri - m + 1, bomb, m))
				ri -= m;
	}
    // 여기서 ri--를 해줘야한다. 직전의 반복문에서 ri++를 하고 비교연산 후 반복문이 멈췄기 때문.
	ri--;
	if(ri != 0) printf("%s\n", result);
	else printf("%s\n", "FRULA");

    return 0;
}
```



#### 꿀팁 &#128273;

```c++
scanf("%s %s", str, bomb); // 굳이 scanf()를 두 번 나눠서 할 필요 없다는 점~
```

위와같이 할 수 있음을 기억!

```cpp
for (int i = 0 ; i <= n; i++, ri++)
```

for문의 증감부를 잘 활용하면 머릿속에서 좀 더 쉽게 정리하면서 반복문을 구현할 수 있다. 위와 같은 경우, 모든 연산을 끝낸 후, i와 ri를 조작함을 바로 알 수 있다.

```cpp
!strncmp(result + ri - m + 1, bomb, m)
```

`<cstring>` 내의 문자열 처리 함수를 잘 기억해 두자. 참고로 위의 함수는 문자열이 일치할 때 1이 아닌 **0을 반환**한다.

<br>

<br>

<br>

## 실수한 부분

### 반례찾기

처음에는 문자열 폭발 이후, 폭발 시작 위치에서 -1한 지점부터만 다시 탐색하면 되는줄 알았지만 아니었다.

<br>

<br>

<br>


