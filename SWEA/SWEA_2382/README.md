

### &#128526;[문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV597vbqAH0DFAVl)

<br>

<br>

<br>

## 접근법

상당히 시간이 많이걸린 문제. 푸는 것 자체는 금방 풀었지만 답이 계속 틀렸는데 왜 틀렸는지 결국 알지 못함. 시간 지나고나서 다시 풀어봐야 할 듯 하다.

그리고 되도록 구조체를 활용하자.

<br>

<br>

<br>

## 찾아내지 못한 논리 오류 코드

```cpp
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int R[1000], C[1000], NUM[1000], DIR[1000];
int MAP[100][100];

int drow[5] = { 0, -1, 1, 0, 0 };
int dcol[5] = { 0, 0, 0, -1, 1 };
int cdir[5] = { 0, 2, 1, 4, 3 };



int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int N, M, K;
		cin >> N >> M >> K;
		for (int k = 0; k < K; k++)
		{
			cin >> R[k] >> C[k] >> NUM[k] >> DIR[k];
			MAP[R[k]][C[k]] = NUM[k];
		}

		/*for (int k = 0; k < K; k++)
		{
			cout << R[k] << " " << C[k] << " " << NUM[k] << " " << DIR[k] << endl;
		}*/
			
		
		for (int m = 1; m <= M; m++)
		{
			// 이동
			for (int k = 0; k < K; k++)
			{
				if (NUM[k] == 0) continue;
				MAP[R[k]][C[k]] -= NUM[k];
				R[k] += drow[DIR[k]];
				C[k] += dcol[DIR[k]];
				MAP[R[k]][C[k]] += NUM[k];
				// 약품에 닿았을 때 방향만 전환
				if (R[k] == 0 || R[k] == N - 1 || C[k] == 0 || C[k] == N - 1)
				{
					MAP[R[k]][C[k]] = (NUM[k] /= 2);
					DIR[k] = cdir[DIR[k]];
				}
			}

			// 합쳐진 군집 찾기
			for (int k = 0; k < K; k++)
			{
				if (NUM[k] == 0) continue;

				// 군집이 서로 만난 경우.
				if (NUM[k] != MAP[R[k]][C[k]])
				{
					int max_cell = k;
					for(int i = k + 1; i < K; i++)
					{
						// 같은 자리에 있을 때
						if (R[i] == R[max_cell] && C[i] == C[max_cell])
						{
							if (NUM[max_cell] < NUM[i])
							{
								NUM[max_cell] = 0;
								max_cell = i;
							}
							else NUM[i] = 0;
						}
						
					}
					NUM[max_cell] = MAP[R[k]][C[k]];
				}
			}
		}
		int rest = 0;
		for (int k = 0; k < K; k++)
			rest += NUM[k];
		
		cout << "#" << t << " " << rest << "\n";
		memset(MAP, 0, sizeof(MAP));
	}

	return 0;
}

```

<br>

<br>

<br>

