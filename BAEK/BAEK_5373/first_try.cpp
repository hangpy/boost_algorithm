//// BAEK_5373. 큐빙
//
//#include <iostream>
//#include <cstring>
//#include <vector>
//
//using namespace std;
//
//int T;
//vector<char> U = { 'r','r','r','b','b','b','o','o','o','g','g','g' };
//vector<char> D = { 'r','r','r','b','b','b','o','o','o','g','g','g' };
//vector<char> F = { 'g','g','g','w','w','w','b','b','b','y','y','y' };
//vector<char> B = { 'g','g','g','w','w','w','b','b','b','y','y','y' };
//vector<char> L = { 'o','o','o','w','w','w','r','r','r','y','y','y' };
//vector<char> R = { 'o','o','o','w','w','w','r','r','r','y','y','y' };
//
//// '+': 시계방향, '-': 반시계방향, side반대 빼고 다 바뀜
//void rotate(char side, char d)
//{
//	if (side == 'L' && d == '-')
//	{
//		char tmp[3] = {};
//		for (int i = 0; i < 3; i++) tmp[i] = L[0], L.erase(L.begin());
//		for (int i = 0; i < 3; i++) L.push_back(tmp[i]);
//		U[0] = L[6], U[8] = L[2], D[0] = L[8], D[8] = L[0];
//		F[3] = L[5], F[11] = L[9], B[3] = L[3], B[11] = L[11];
//	}
//	if (side == 'L' && d == '+')
//	{
//		char tmp[3] = {};
//		for (int i = 0; i < 3; i++) tmp[i] = L[L.size() - 1], L.erase(L.end() - 1);
//		for (int i = 0; i < 3; i++) L.insert(L.begin(), tmp[i]);
//		U[0] = L[6], U[8] = L[2], D[0] = L[8], D[8] = L[0];
//		F[3] = L[5], F[11] = L[9], B[3] = L[3], B[11] = L[11];
//
//	}
//	if (side == 'R' && d == '-')
//	{
//		char tmp[3] = {};
//		for (int i = 0; i < 3; i++) tmp[i] = R[R.size() - 1], R.erase(R.end() - 1);
//		for (int i = 0; i < 3; i++) R.insert(R.begin(), tmp[i]);
//		U[2] = R[6], U[6] = R[2], D[2] = R[8], D[6] = R[0];
//		F[5] = R[5], F[9] = R[9], B[5] = R[3], B[9] = R[7];
//	}
//	if (side == 'R' && d == '+')
//	{
//		char tmp[3] = {};
//		for (int i = 0; i < 3; i++) tmp[i] = R[0], R.erase(R.begin());
//		for (int i = 0; i < 3; i++) R.push_back(tmp[i]);
//		U[2] = R[6], U[6] = R[2], D[2] = R[8], D[6] = R[0];
//		F[5] = R[5], F[9] = R[9], B[5] = R[3], B[9] = R[7];
//	}
//	if (side == 'U' && d == '-')
//	{
//		char tmp[3] = {};
//		for (int i = 0; i < 3; i++) tmp[i] = U[U.size() - 1], U.erase(U.end() - 1);
//		for (int i = 0; i < 3; i++) U.insert(U.begin(), tmp[i]);
//		L[6] = U[0], L[2] = U[8], R[6] = U[2], R[2] = U[6];
//		F[2] = U[11], F[6] = U[3], B[2] = U[9], B[6] = U[5];
//	}
//	if (side == 'U' && d == '+')
//	{
//		char tmp[3] = {};
//		for (int i = 0; i < 3; i++) tmp[i] = U[0], U.erase(U.begin());
//		for (int i = 0; i < 3; i++) U.push_back(tmp[i]);
//		L[6] = U[0], L[2] = U[8], R[6] = U[2], R[2] = U[6];
//		F[2] = U[11], F[6] = U[3], B[2] = U[9], B[6] = U[5];
//	}
//	if (side == 'D' && d == '-')
//	{
//		char tmp[3] = {};
//		for (int i = 0; i < 3; i++) tmp[i] = D[0], D.erase(D.begin());
//		for (int i = 0; i < 3; i++) D.push_back(tmp[i]);
//		L[0] = D[8], L[8] = D[0], R[0] = D[6], R[8] = D[2];
//		F[0] = D[11], F[8] = D[3], B[0] = D[9], B[8] = D[5];
//	}
//	if (side == 'D' && d == '+')
//	{
//		char tmp[3] = {};
//		for (int i = 0; i < 3; i++) tmp[i] = D[D.size() - 1], D.erase(D.end() - 1);
//		for (int i = 0; i < 3; i++) D.insert(D.begin(), tmp[i]);
//		L[0] = D[8], L[8] = D[0], R[0] = D[6], R[8] = D[2];
//		F[0] = D[11], F[8] = D[3], B[0] = D[9], B[8] = D[5];
//	}
//	if (side == 'F' && d == '-')
//	{
//		char tmp[3] = {};
//		for (int i = 0; i < 3; i++) tmp[i] = F[0], F.erase(F.begin());
//		for (int i = 0; i < 3; i++) F.push_back(tmp[i]);
//		U[3] = F[6], U[11] = F[2], D[3] = F[8], D[11] = F[0];
//		L[5] = F[3], L[9] = F[11], R[5] = F[5], R[9] = F[9];
//	}
//	if (side == 'F' && d == '+')
//	{
//		char tmp[3] = {};
//		for (int i = 0; i < 3; i++) tmp[i] = F[F.size() - 1], F.erase(F.end() - 1);
//		for (int i = 0; i < 3; i++) F.insert(F.begin(), tmp[i]);
//		U[3] = F[6], U[11] = F[2], D[3] = F[8], D[11] = F[0];
//		L[5] = F[3], L[9] = F[11], R[5] = F[5], R[9] = F[9];
//	}
//	if (side == 'B' && d == '-')
//	{
//		char tmp[3] = {};
//		for (int i = 0; i < 3; i++) tmp[i] = B[B.size() - 1], B.erase(B.end() - 1);
//		for (int i = 0; i < 3; i++) B.insert(B.begin(), tmp[i]);
//		U[5] = B[6], U[9] = B[2], D[5] = B[8], D[9] = B[0];
//		L[3] = B[3], L[11] = B[11], R[3] = B[5], R[11] = B[9];
//	}
//	if (side == 'B' && d == '+')
//	{
//		char tmp[3] = {};
//		for (int i = 0; i < 3; i++) tmp[i] = B[0], B.erase(B.begin());
//		for (int i = 0; i < 3; i++) B.push_back(tmp[i]);
//		U[5] = B[6], U[9] = B[2], D[5] = B[8], D[9] = B[0];
//		L[3] = B[3], L[11] = B[11], R[3] = B[5], R[11] = B[9];
//	}
//	char ans[3][3] = {};
//	for (int y = 0; y < 3; y++)
//	{
//		if (y == 0)
//			for (int i = 0; i < 3; i++) ans[y][i] = B[i + 3];
//		if (y == 1)
//			ans[y][0] = L[4], ans[y][1] = 'w', ans[y][2] = R[4];
//		if (y == 2)
//			for (int i = 0; i < 3; i++) ans[y][i] = F[i + 3];
//	}
//	for (int y = 0; y < 3; y++)
//	{
//		for (int x = 0; x < 3; x++)
//			cout << ans[y][x];
//		cout << endl;
//	}
//	cout << endl;
//}
//
//
//int main()
//{
//	cin >> T;
//	for (int t = 1; t <= T; t++)
//	{
//		// init
//		vector<char> BU(U), BD(D), BF(F), BB(B), BL(L), BR(R);
//
//		int N; cin >> N;
//		// logic
//		for (int i = 0; i < N; i++)
//		{
//			char side, d;
//			cin >> side >> d;
//			rotate(side, d);
//		}
//		// answer
//		for (int y = 0; y < 3; y++)
//		{
//			if (y == 0)
//				for (int i = 0; i < 3; i++) cout << B[i + 3];
//			if (y == 1)
//				cout << L[4], cout << 'w', cout << R[4];
//			if (y == 2)
//				for (int i = 0; i < 3; i++) cout << F[i + 3];
//			cout << endl;
//		}
//		U = BU, D = BD, F = BF, B = BB, L = BL, R = BR;
//	}
//	return 0;
//}
//
//
////char ans[3][3] = {};
////for (int y = 0; y < 3; y++)
////{
////	if (y == 0)
////		for (int i = 0; i < 3; i++) ans[y][i] = B[i + 3];
////	if (y == 1)
////		ans[y][0] = L[4], ans[y][1] = 'w', ans[y][2] = R[4];
////	if (y == 2)
////		for (int i = 0; i < 3; i++) ans[y][i] = F[i + 3];
////}
////for (int y = 0; y < 3; y++)
////{
////	for (int x = 0; x < 3; x++)
////		cout << ans[y][x];
////	cout << endl;
////}
//
//
//
//// restore
///*memcpy(U, BU, sizeof U), memcpy(D, BD, sizeof D), memcpy(F, BF, sizeof F);
//memcpy(B, BB, sizeof B), memcpy(L, BL, sizeof L), memcpy(R, BR, sizeof R);*/
//
//
///*memcpy(BU, U, sizeof U), memcpy(BD, D, sizeof D), memcpy(BF, F, sizeof F);
//memcpy(BB, B, sizeof B), memcpy(BL, L, sizeof L), memcpy(BR, R, sizeof R);*/
