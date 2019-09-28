//// BAEK_17471. °Ô¸® ¸à´õ¸µ
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstring>
//#include <cmath>
//#define endl "\n"
//
//using namespace std;
//
//int N, gCity[10], visit[10];
//vector<int> adj[10];
//
//bool search(int now, int target)
//{
//	visit[now] = 1;
//	bool isFinded = false;
//	if (now == target) return isFinded = true;
//	for (int i = 0; i < adj[now].size(); i++)
//	{
//		if (visit[adj[now][i]]) continue;
//		isFinded = isFinded | search(adj[now][i], target);
//	}
//	visit[now] = 0;
//	return isFinded;
//}
//
//
//void setOppositeToVisit(vector<int> &v)
//{
//	memset(visit, 0, sizeof visit);
//	for (int i = 0; i < v.size(); i++) visit[v[i]] = 1;
//}
//
//bool validate(vector<int> &a, vector<int> &b)
//{
//	bool isConnected = true;
//
//	// validate a
//
//	int len = a.size();
//	for (int i = 0; i < len - 1; i++)
//	{
//		for (int j = i + 1; j < len; j++)
//		{
//			setOppositeToVisit(b);
//			// check the connection between i and j
//			if (!search(a[i], a[j])) return false;
//		}
//	}
//	// validate b
//
//	len = b.size();
//	for (int i = 0; i < len - 1; i++)
//	{
//		for (int j = i + 1; j < len; j++)
//		{
//			setOppositeToVisit(a);
//			// check the connection between i and j
//			if (!search(b[i], b[j])) return false;
//		}
//	}
//	return isConnected;
//}
//
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0);
//	cin >> N;
//
//	for (int i = 0; i < N; i++) cin >> gCity[i];
//
//	for (int i = 0; i < N; i++)
//	{
//		int k; cin >> k;
//		for (int j = 0; j < k; j++)
//		{
//			int a; cin >> a;
//			adj[i].push_back(a - 1);
//		}
//	}
//
//	vector<int> v(N, 0);
//	for (int i = 0; i < N; i++) v[i] = i;
//
//	int ans = 987654321;
//	bool canDivide = false;
//	for (int i = 1; i <= N / 2; i++)
//	{
//		vector<int> tmpv(N, 1);
//		for (int j = 0; j < i; j++) tmpv[j] = 0;
//
//		do
//		{
//			vector<int> a;
//			vector<int> b;
//			for (int k = 0; k < N; k++)
//			{
//				if (tmpv[k] == 0) a.push_back(k);
//				else b.push_back(k);
//			}
//
//			if (!validate(a, b)) continue;
//			else canDivide = true;
//
//			int sumA = 0;
//			for (int i = 0; i < a.size(); i++) sumA += gCity[a[i]];
//			int sumB = 0;
//			for (int i = 0; i < b.size(); i++) sumB += gCity[b[i]];
//
//			int result = abs(sumA - sumB);
//			ans = ans > result ? result : ans;
//
//		} while (next_permutation(tmpv.begin(), tmpv.end()));
//	}
//
//	if (canDivide) cout << ans << endl;
//	else cout << -1 << endl;
//
//	return 0;
//}
