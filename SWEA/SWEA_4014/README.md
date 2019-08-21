

### &#128526;[문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeW7FakkUDFAVH)

<br>

<br>

<br>

## 시간

45분 컷! 역대급으로 빨리 풀었던 문제였음. 생각했던 조건이 운이 좋게 문제에서 요구하는 모든 조건과 모두 맞아 떨어졌던 것 같다.

`7ms`, `12,624 kb`

<br>

<br>

<br>

## 접근법

어떤 기존의 특정 알고리즘을 쓴다기 보단, 문제에서 요구하는 조건을 빠짐없이 맞춰서 잘 구현해야 했던 문제였다. 먼저 가로 탐색, 세로 탐색의 상황을 나누고 각 상황에서 한 줄 한 줄 탐색을 할 때 해당 칸의 시점에 맞추워 greedy하게 접근했다. 내가 생각한 조건의 분기는 다음과 같다.

현재 높이가 이전 높이와 2 이상 차이나는 경우, 이전보다 1 높이만큼 오르막인 경우, 이전보다 1 높이만 큼 내리막인 경우, 이전과 높이가 같은 경우. 내 로직에서 중요한 부분은 이전 높이보다 1만큼 내리막인 경우이다. 오르막인 경우에는 이전 높이의 카운트가 X 이상이면 그냥 OK하고 다음 높이로 탐색을 이어나가면 되지만 내리막인 경우, 아직 X만큼의 같은 높이가 나올지 미지수이기 때문이다. 그래서 이때는 down이라는 bool값에 true를 주고 다음 탐색은 down이 true인 분기점으로 가서 해당 높이를 카운트 한다. 그렇게 카운트가 쌓여 X개가 나온 순간 down은 다시 false로,  count는 0으로 갱신하고 다음 탐색을 이어나간다.

이런 로직으로 나가다가 가로줄인 경우 맨 끝점까지 무리없이 탐색이 완료된 경우엔 활주로를 건설하기에 알맞은 지형으로 판단하고 답을 +1 해주도록 한다. 이를 위해 for문 이전에 x를 선언해주었고 for문 마지막에 x==N && down이 false인 경우(down이 true인 경우는 여전히 내리막 경사로를 설치할 가능성을 점치고 있는 중이란 뜻이다. 즉, 한 줄의 탐색이 끝날 때 까지 가능성을 점치지 못했으므로 활주로 건설이 불가능한 것) 카운트 해주면 된다. 

내 코드에서 아쉬운 점은 중복 코드가 너무 많았다는 점. 하지만 빠른 시간 내에 푸는 것이 더 중요하므로 이는 좀 더 연습하면 나아질 듯 하다.

<br>

<br>

<br>

## 코드

```cpp
#include <iostream>
#include <cmath>

using namespace std;

int T, N, X, MAP[20][20];

int main()
{
    
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("sample_input.txt", "r", stdin);
	
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N >> X;
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				cin >> MAP[y][x];

		// 가로줄 탐색
		int result = 0;
		for (int y = 0; y < N; y++)
		{
			int prevh = MAP[y][0];
			int count = 1;
			bool down = false;

			int x;
			for (x = 1; x < N; x++)
			{
				int curh = MAP[y][x];
				if (down == false)
				{
					if (abs(prevh - curh) > 1) break;

					// 1높아졌을 때
					if (curh - prevh == 1)
					{
						// 같은 높이가 X개 이상 있을 때
						if (count >= X)
						{
							prevh = curh;
							count = 1;
							continue;
						}
						else break;
					}
					// 1 낮아졌을 때 앞으로 X개가 나올지 봐야함
					else if (prevh - curh == 1)
					{
						prevh = curh;
						down = true;
						count = 1;

					}
					// 높이가 똑같을 때
					else count++;
				}
				// 내려온 상황일 때 경사로 설치 여부 판단
				else
				{
                    // X 이상개의 같은 높이가 유지되는지 판단
					if (curh == prevh) count++;
                    // 만약 높이가 달라진다면 경사로 설치 불가이므로 다음 줄 탐색
					else break;
                    // X개 이상인 경우 내리막 판단 여부를 false로 갱신하고 경사로를 설치했으니 카운트는 다시 0으로 갱신
					if (count >= X)
					{
						down = false;
						count = 0;
					}
				}
			}
            // down이 true인 경우는 여전히 내리막 경사로를 설치할 수 있는지 판단 중이라는 뜻
			if (down == false && x == N) result++;

		}

		// 세로줄 탐색 -> 가로 탐색과 동일 로직
		for (int x = 0; x < N; x++)
		{
			int prevh = MAP[0][x];
			int count = 1;
			bool down = false;

			int y;
			for (y = 1; y < N; y++)
			{
				int curh = MAP[y][x];
				if (down == false)
				{
					if (abs(prevh - curh) > 1) break;

					if (curh - prevh == 1)
					{
						if (count >= X)
						{
							prevh = curh;
							count = 1;
							continue;
						}
						else break;
					}
					else if (prevh - curh == 1)
					{
						prevh = curh;
						down = true;
						count = 1;

					}
					else count++;
				}
				else
				{
					if (curh == prevh) count++;
					else break;
					if (count >= X)
					{
						down = false;
						count = 0;
					}
				}
			}
			if (down == false && y == N) result++;
		}

		cout << "#" << t << " " << result << "\n";

	}
	return 0;
}
```

<br>

<br>

<br>