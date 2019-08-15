// SWEA_2477. 차량 정비소

//#include <iostream>
//#include <queue>
//
//using namespace std;
//
////   N: 접수, M: 정비, K: 방문 고객 수, A: 분실 접수, B: 분실 정비
//int T, N, M, K, A, B;
//// ai: 접수 능력, bi: 정비 능력, tk: 고객 방문 시간
//int ai[21], bj[21], tk[1001];
//
//struct aobj
//{
//	int customer_num;
//	int start_time;
//	bool isEmpty = true;
//};
//
//struct bobj
//{
//	int customer_num;
//	int start_time;
//	int a;
//	bool isEmpty = true;
//};
//struct ca { int customer_num, a; };
//struct cab { int customer_num, a, b; };
//
//aobj aboxs[21];
//bobj bboxs[21];
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	freopen("sample_input.txt", "r", stdin);
//
//	cin >> T;
//	for (int t = 1; t <= T; t++)
//	{
//		cin >> N >> M >> K >> A >> B;
//		for (int i = 1; i <= N; i++) cin >> ai[i];
//		for (int j = 1; j <= M; j++) cin >> bj[j];
//		for (int k = 1; k <= K; k++) cin >> tk[k];
//		queue<int> aq;
//		queue<ca> bq;
//		queue<cab> eq;
//
//		int now = 0, cnum = 1;
//		int ANS = 0;
//		int endCustomer = 0;
//		do
//		{
//			while (tk[cnum] <= now && cnum <= K)
//			{
//				aq.push(cnum);
//				cnum++;
//			}
//
//			// 접수창구 차례로 탐방 비어있으면 집어넣기
//			// i는 창구번호
//			for (int i = 1; i <= N; i++)
//			{
//				// 창구가 비어있으면
//				if (aboxs[i].isEmpty)
//				{
//					// 대기열에 사람이 기다리고 있으면
//					if (!aq.empty())
//					{
//						int customer = aq.front(); aq.pop();
//						aboxs[i].customer_num = customer;
//						aboxs[i].start_time = tk[now];
//						aboxs[i].isEmpty = false;
//					}
//				}
//				// 창구에 사람이 있으면
//				else
//				{
//					// 만약 일처리가 끝났으면
//					if (now - aboxs[i].start_time >= ai[i])
//					{
//						// bq로 현재 끝난 고객을 옮김
//						bq.push({ aboxs[i].customer_num, i });
//						// 일단 창구가 비어있음을 표시
//						aboxs[i] = { 0,0,true };
//						// 대기열 손님 있으면 받기
//						if (!aq.empty())
//						{
//							int customer = aq.front(); aq.pop();
//							aboxs[i].customer_num = customer;
//							aboxs[i].start_time = tk[now];
//							aboxs[i].isEmpty = false;
//						}
//					}
//				}
//			}
//
//
//			// 정비 창구 차례로 확인
//			for (int j = 1; j <= M; j++)
//			{
//				// b창구 비어있으면
//				if (bboxs[j].isEmpty)
//				{
//					if (!bq.empty())
//					{
//						ca customer = bq.front(); bq.pop();
//						bboxs[j].customer_num = customer.customer_num;
//						bboxs[j].a = customer.a;
//						bboxs[j].start_time = now;
//						bboxs[j].isEmpty = false;
//					}
//				}
//				// 사람이 있으면
//				else
//				{
//					if (now - bboxs[j].start_time >= bj[j])
//					{
//
//						eq.push({ bboxs[j].customer_num, bboxs[j].a, j });
//						// 일단 창구가 비어있음을 표시
//						bboxs[j] = { 0,0,0,true };
//
//						// 대기열 손님 있으면 받기
//						if (!aq.empty())
//						{
//							ca customer = bq.front(); bq.pop();
//							bboxs[j].customer_num = customer.customer_num;
//							bboxs[j].a = customer.a;
//							bboxs[j].start_time = now;
//							bboxs[j].isEmpty = false;
//						}
//					}
//				}
//			}
//
//			// 마지막 eq확인하기
//			while (!eq.empty())
//			{
//				cab customer = eq.front(); eq.pop();
//				endCustomer++;
//				if (customer.a == A && customer.b == B)
//					ANS += customer.customer_num;
//			}
//
//			if (endCustomer == K) break;
//			now++;
//		} while (true);
//
//		if (ANS == 0) ANS = -1;
//
//		// console out answer
//		cout << "#" << t << " " << ANS << "\n";
//	}
//
//	return 0;
//}
//











// validate input -> success
/*cout << N << " " << M << " " << K << " " << A << " " << B << endl;
for (int i = 1; i <= N; i++) cout << ai[i] << " ";
cout << endl;
for (int j = 1; j <= M; j++) cout << bj[j] << " ";
cout << endl;
for (int k = 1; k <= K; k++) cout << tk[k] << " ";
cout << endl;*/
