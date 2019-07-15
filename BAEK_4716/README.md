

### &#128526;[문제 링크](https://www.acmicpc.net/problem/4716)

<br>

<br>

<br>

## 접근법

그리디를 어떤식으로 적용시키는가가 관건이었던 문제였다. 중간에 A나 B의 풍선이 모잘라서 불가피하게 다른 풍선을 가지러 갈 때의 상황을 고려하고, 그 상황에서의 거리가 최소가 될 수 있는 상황을 수식으로 나타내면 된다. 즉, A와 B의 각각 거리의 차가 가장 많이나는 팀부터 풍선을 배분하면 된다.

또한 여기서도 **거꾸로 생각해보기**가 아주 유용한 문제였다. 문제에선 A, B에서 각 팀으로 이동한다고 하지만, 굳이 그럴필요 없이 각 팀에서 A, B로 이동할 수 있다고 생각할 수 있다. 그렇게 할 경우, 각 팀에대해서 위에서 말한 A, B거리의 차의 내림차순으로 순차적으로 탐색하면 된다. 각 팀에서의 그리디한 선택을 하면 되는것!

<br>

<br>

<br>

## 핵심 파트

<br>

```c++
struct team
{
	int size, a, b;
};

bool cmp(team t, team u)
{
	return abs(t.a - t.b) > abs(u.a - u.b);
}

int main()
{
	while (true)
	{
		int N, A, B;
		scanf("%d %d %d", &N, &A, &B);
		if (N == 0 && A == 0 && B == 0) break;
		for (int n = 1; n <= N; n++)
		{
			int size, a, b;
			scanf("%d %d %d", &size, &a, &b);
			v.push_back({ size, a, b });
		}
        
        // 위의 customized된 비교로 소팅하는 것이 관건!
		sort(v.begin(), v.end(), cmp);
		
		int grossLen(0);
		// logic for greedy
		for (auto t : v)
		{
			if (t.a > t.b)
			{
				if (B - t.size >= 0)
				{
					grossLen += t.size * t.b;
					B -= t.size;
				}
				else
				{
					int rest = abs(B - t.size);
					grossLen += B * t.b;
					B = 0;
					grossLen += rest * t.a;
					A -= rest;
				}
			}
			else
			{
				if (A - t.size >= 0)
				{
					grossLen += t.size * t.a;
					A -= t.size;
				}
				else
				{
					int rest = abs(A - t.size);
					grossLen += A * t.a;
					A = 0;
					grossLen += rest * t.b;
					B -= rest;
				}
			}
		}
		ans.push_back(grossLen);
		// initialize global vector
		v.clear();
	}
	for (auto i : ans) printf("%d\n", i);
    return 0;
}
```



#### 꿀팁 &#128273;

```c++
bool cmp(team t, team u)
{
	return abs(t.a - t.b) > abs(u.a - u.b);
}
sort(v.begin(), v.end(), cmp);
```

정렬 커스터마이징하기

<br>

<br>

<br>


