// SWEA_2477. ���� �����

//#include <iostream>
//#include <queue>
//
//using namespace std;
//
////   N: ����, M: ����, K: �湮 �� ��, A: �н� ����, B: �н� ����
//int T, N, M, K, A, B;
//// ai: ���� �ɷ�, bi: ���� �ɷ�, tk: �� �湮 �ð�
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
//			// ����â�� ���ʷ� Ž�� ��������� ����ֱ�
//			// i�� â����ȣ
//			for (int i = 1; i <= N; i++)
//			{
//				// â���� ���������
//				if (aboxs[i].isEmpty)
//				{
//					// ��⿭�� ����� ��ٸ��� ������
//					if (!aq.empty())
//					{
//						int customer = aq.front(); aq.pop();
//						aboxs[i].customer_num = customer;
//						aboxs[i].start_time = tk[now];
//						aboxs[i].isEmpty = false;
//					}
//				}
//				// â���� ����� ������
//				else
//				{
//					// ���� ��ó���� ��������
//					if (now - aboxs[i].start_time >= ai[i])
//					{
//						// bq�� ���� ���� ���� �ű�
//						bq.push({ aboxs[i].customer_num, i });
//						// �ϴ� â���� ��������� ǥ��
//						aboxs[i] = { 0,0,true };
//						// ��⿭ �մ� ������ �ޱ�
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
//			// ���� â�� ���ʷ� Ȯ��
//			for (int j = 1; j <= M; j++)
//			{
//				// bâ�� ���������
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
//				// ����� ������
//				else
//				{
//					if (now - bboxs[j].start_time >= bj[j])
//					{
//
//						eq.push({ bboxs[j].customer_num, bboxs[j].a, j });
//						// �ϴ� â���� ��������� ǥ��
//						bboxs[j] = { 0,0,0,true };
//
//						// ��⿭ �մ� ������ �ޱ�
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
//			// ������ eqȮ���ϱ�
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
