// SWEA_2115. 벌꿀채취
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int map[10][10], dp[10][10], boxs[5];

int calc(vector<int>& v, int c, int idx, int sum, int val)
{
	if (sum > c) return 0;
	if (idx == v.size()) return val;
	
	return max(calc(v, c, idx + 1, sum + v[idx], val + pow(v[idx], 2)), calc(v, c, idx + 1, sum, val));
}

int get_max(int y, int x, int c, int n, int m)
{
	vector<int> v;
	for (int i = x; i < x + m; i++)
		v.push_back(map[y][i]);
	return calc(v, c, 0, 0, 0);
}

void make_dp(int n, int m, int c)
{
	memset(dp, 0, sizeof(dp));
	for (int row = 0; row < n; row++)
		for (int i = 0; i < n - m + 1; i++)
			dp[row][i] = get_max(row, i, c, n, m);
}

int dfs(int y, int x, int n, int m)
{
	int ans = 0;
	
	for (int i = x + m; i < n; i++)
		ans = max(ans, dp[y][x] + dp[y][i]);
	
	for (int row = y + 1; row < n; row++)
		for (int col = 0; col < n; col++)
			ans = max(ans, dp[y][x] + dp[row][col]);

	return ans;
}


int main()
{
	int T = 0;
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		memset(map, 0, sizeof(map));

		int N, M, C;
		cin >> N >> M >> C;
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				cin >> map[y][x];
		
		make_dp(N, M, C);

		int MAX = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N - M + 1; j++)
				MAX = max(MAX, dfs(i, j, N, M));


		cout << "#" << t << " " << MAX << "\n";
	}

	return 0;
}


//#include <stdio.h>
//#include <string.h>
//int n, m, c;
//int arr[12][12];
//int honey[6];
//int max = 0;
//int num[3][4];  //가로로 max, x, y 세로,: 가장 큰, 다음에 큰
//void dfs(int x, int sum, int db) {
//
//	if (sum > c)
//		return;
//
//	if (max < db)
//		max = db;
//
//	for (int i = x + 1; i < m; i++) {
//		if (sum + honey[i] <= c)
//			dfs(i, sum + honey[i], db + honey[i] * honey[i]);
//	}
//}
//
//void func(int x, int y) {
//
//	int i;
//
//	for (i = 0; i < m; i++) {
//		honey[i] = arr[x][y + i];     //후보 꿀들 배열에 저장
//		//printf("%d ",honey[i]);
//	}
//	//printf("\n");
//	// 합이 C이하인 것 찾아 제곱하기
//	int tempmax;    //탐색할때 각각의 최대값 임시 저장
//	for (i = 0; i < m; i++) {
//
//		dfs(i, honey[i], honey[i] * honey[i]);
//	}
//
//	//범위 확인 --> 지금 현재 최대값과 비교해서 범위 겹치는지도 확인해야함
//
//	if (max > num[0][0]) {   //가장 큰 값 갱신
//		//범위 겹치는지 확인
//
//
//		if (x == num[0][1] && y >= num[0][2] && y <= num[0][2] + m) {    //범위 겹칠 경우
//			num[0][0] = max;
//			num[0][1] = x;
//			num[0][2] = y;
//		}
//
//		else {   //범위 안겹치는 경우
//			num[1][0] = num[0][0];
//			num[1][1] = num[0][1];
//			num[1][2] = num[0][2];
//			num[0][0] = max;
//			num[0][1] = x;
//			num[0][2] = y;
//
//		}
//	}
//	else if (max > num[1][0]) {    //다음 큰 값 갱신
//		if (x == num[0][1] && y >= num[0][2] && y <= num[0][2] + m) {
//
//		}
//		else {
//			num[1][0] = max;
//			num[1][1] = x;
//			num[1][2] = y;
//		}
//	}
//
//}
//
//int main(void) {
//	int T;
//	scanf("%d", &T);
//	for (int tc = 1; tc <= T; tc++) {
//		scanf("%d %d %d", &n, &m, &c);
//		int i, j;
//		for (i = 0; i < n; i++) {
//			for (j = 0; j < n; j++) {
//				scanf("%d", &arr[i][j]);
//			}
//		}
//
//
//		for (i = 0; i < n; i++) {
//			for (j = 0; j <= n - m; j++) {
//				func(i, j);
//				max = 0;
//			}
//		}
//
//		printf("#%d %d\n", tc, num[0][0] + num[1][0]);
//
//		memset(honey, 0, sizeof(honey));
//		memset(arr, 0, sizeof(arr));
//		memset(num, 0, sizeof(num));
//		max = 0;
//	}
//	return 0;
//}