

### &#128526;[문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV6c6bgaIuoDFAXy)

<br>

<br>

<br>

## 시간

오래걸림... 시뮬레이션 진짜 연습 많이해야할 듯 함

<br>

<br>

<br>

## 접근법

내 기준으로 정말 머리가 꼬이는 시뮬레이션 문제였다. 문제를 이해하는 거 자체는 쉬웠으나 그냥 직관적으로 구현하면 되는 것을 최적화부터 생각을 하니 꼬일 수 밖에.

조건에 따라 구현을 일단 잘 하는 것이 첫 번째 포인트고, 그 담에 종료시점을 잘 생각해서 `whlie` 루프문을 잘 굴리는 것이 두 번째 포인트였다.

구현 자체에서의 포인트는 역시 `queue`를 잘 활용하는 것이었음.

분명 최적화를 위해 `queue`를 쓰지 않는 방법이 있는 것 같은데 다음에 다시 시도해 봐야할 듯 함.

<br>

<br>

<br>

## 코드

```cpp
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

//   N: 접수, M: 정비, K: 방문 고객 수, A: 분실 접수, B: 분실 정비
int T, N, M, K, A, B;
// ai: 접수 능력, bi: 정비 능력, tk: 고객 방문 시간
int ai[21], bj[21], tk[1001], tka[1001];
int va[21], sa[21], ca[21], vb[21], sb[21], cb[21];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("sample_input.txt", "r", stdin);

	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N >> M >> K >> A >> B;
		for (int i = 1; i <= N; i++) cin >> ai[i];
		for (int j = 1; j <= M; j++) cin >> bj[j];
		for (int k = 1; k <= K; k++) cin >> tk[k];

		int now = 0, cnum = 1;
		int ANS = 0;
		int endCustomer = 0;

		queue<int> aq;
		queue<int> bq;
	
		while (endCustomer < K)
		{
			while (cnum <= K && tk[cnum] <= now)
			{
				aq.push(cnum);
				cnum++;
			}

			// 접수 처리
			for (int i = 1; i <= N; i++)
			{
				// 비어있을 때
				if (va[i] == 0)
				{
					if (!aq.empty())
					{
						int customer = aq.front(); aq.pop();
						va[i] = 1;
						sa[i] = now;
						ca[i] = customer;
						tka[customer] = i;
					}
				}
				// 이제 처리를 마치고 bq로 보낼때
				else
				{
					// 처리시간이 끝났을 때
					if (now - sa[i] == ai[i])
					{
						bq.push(ca[i]);
						va[i] = 0;
						ca[i] = 0;
						// 대기열에 사람이 있을 때
						if (!aq.empty())
						{
							int customer = aq.front(); aq.pop();
							va[i] = 1;
							ca[i] = customer;
							sa[i] = now;
							tka[customer] = i;
						}
					}
				}
			}

			// 정비 처리
			for (int j = 1; j <= M; j++)
			{
				// 비어 있을 때
				if (vb[j] == 0)
				{
					if (!bq.empty())
					{
						int customer = bq.front(); bq.pop();
						vb[j] = 1;
						sb[j] = now;
						cb[j] = customer;
						endCustomer++;
						if (tka[customer] == A && j == B) ANS += customer;
						
					}
				}
				// 사람이 있을 때
				else
				{
					// 만약 처리가 끝나면
					if (now - sb[j] == bj[j])
					{
						vb[j] = 0;
						if (!bq.empty())
						{
							int customer = bq.front(); bq.pop();
							vb[j] = 1;
							sb[j] = now;
							cb[j] = customer;
							endCustomer++;
							if (tka[customer] == A && j == B) ANS += customer;
						}
					}
				}
			}
			now++;
		}

		if (ANS == 0) ANS = -1;

		cout << "#" << t << " " << ANS << "\n";
        
        // 반드시 초기화를 시켜줘야 함.
		memset(ca, 0, sizeof(ca));
		memset(cb, 0, sizeof(cb));
		memset(va, 0, sizeof(va));
		memset(vb, 0, sizeof(vb));
	}

	return 0;
}
```

<br>

<br>

<br>

## 실수한 부분

### 이전의 데이터가 그대로 남아있는 상태에서 다음 테스트 케이스에 영향을 미칠 수 있음.

반드시 초기화 하도록 하자.