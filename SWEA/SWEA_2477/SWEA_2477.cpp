// SWEA_2477. 차량 정비소

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

		memset(ca, 0, sizeof(ca));
		memset(cb, 0, sizeof(cb));
		memset(va, 0, sizeof(va));
		memset(vb, 0, sizeof(vb));
	}

	return 0;
}












// validate input -> success
/*cout << N << " " << M << " " << K << " " << A << " " << B << endl;
for (int i = 1; i <= N; i++) cout << ai[i] << " ";
cout << endl;
for (int j = 1; j <= M; j++) cout << bj[j] << " ";
cout << endl;
for (int k = 1; k <= K; k++) cout << tk[k] << " ";
cout << endl;*/
