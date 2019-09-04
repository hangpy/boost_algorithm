//// BAEK_16235. ���� ����ũ
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int N, M, K, NUTR[11][11], A[11][11], CNT;
//struct tree { int y, x, age; };
//int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
//int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
//
//bool cmp(tree &rhs, tree &lhs)
//{
//	return rhs.age < lhs.age;
//}
//
//int main()
//{
//	ios::sync_with_stdio(0); cin.tie(0);
//	cin >> N >> M >> K; CNT = M;
//	for (int y = 1; y <= N; y++)
//	{
//		for (int x = 1; x <= N; x++)
//		{
//			cin >> A[y][x];
//			NUTR[y][x] = 5;
//		}
//	}
//
//	vector<tree> trees;
//	vector<tree> deaths;
//	for (int i = 1; i <= M; i++)
//	{
//		int y, x, age;
//		cin >> y >> x >> age;
//		trees.push_back({ y, x, age });
//	}
//
//	while (K > 0)
//	{
//		// spring 
//		// � �������� ���̸�ŭ ��� �԰� ���� + 1, ������ �������� ������ ����
//		sort(trees.begin(), trees.end(), cmp);
//		for (int i = 0; i < trees.size(); i++)
//		{
//			int y = trees[i].y, x = trees[i].x, age = trees[i].age;
//			if (NUTR[y][x] >= age)
//			{
//				NUTR[y][x] -= age;
//				trees[i].age += 1;
//			}
//			else
//			{
//				deaths.push_back(trees[i]);
//				trees.erase(trees.begin() + i); i--;
//			}
//		}
//		// summer 
//		// ���� ���� �������� ������� ���ϴ� �ñ�. 
//		// ���� ������ ��ġ�� (���� �������� ���� / 2) ��ŭ NUTR�� ��� �߰�. �Ҽ��� ����
//		for (int i = 0; i < deaths.size(); i++)
//			NUTR[deaths[i].y][deaths[i].x] += deaths[i].age / 2;
//		deaths.clear();
//
//		// fall
//		// ���� ����. 1 �̸� N �ʰ��� ���� ���̰� 1�� ���� ���� X, i = 0~8 �� ����
//		int existing_size = trees.size();
//		for (int i = 0; i < existing_size; i++)
//		{
//			int cy = trees[i].y, cx = trees[i].x, cage = trees[i].age;
//			if (cage % 5 != 0) continue;
//			for (int d = 0; d < 8; d++)
//			{
//				int ny = cy + dy[d], nx = cx + dx[d];
//				if (ny < 1 || ny > N || nx < 1 || nx > N) continue;
//				trees.push_back({ ny, nx, 1 });
//			}
//		}
//		// winter
//		// NUTR�� ��� ĭ�� A[y][x]��ŭ ��� �߰�.
//		for (int y = 1; y <= N; y++)
//			for (int x = 1; x <= N; x++)
//				NUTR[y][x] += A[y][x];
//
//		K--;
//	}
//
//	cout << trees.size() << endl;
//
//	return 0;
//}