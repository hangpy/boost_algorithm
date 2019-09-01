// BAEK_15684. 사다리 조작

#include <iostream>
#include <algorithm>
using namespace std;

int N, M, H, V[31][11];
struct line { int a, b; };
line candis[30 * 9];

int doGame(int b)
{
	int a = 1;
	while (a <= H)
	{
		if (V[a][b]) a++, b++;
		else if (V[a][b - 1]) a++, b--;
		else a++;
	}
	return b;
}

bool isAllSame()
{
	bool isSame = true;
	for(int c = 1; c <= N; c++)
	{
		if (c != doGame(c))
		{
			isSame = false;
			break;
		}
	}
	return isSame;
}

int dfs(int cnt, int index, int size) 
{
	int ans = 4;
	if (cnt == 4) return ans;
	

	if (isAllSame()) return cnt;
	else
	{
		for (int i = index; i < size; i++)
		{
			int a = candis[i].a, b = candis[i].b;
			if (V[a][b]) continue;
			if (b > 1 && V[a][b - 1]) continue;
			if (b < N - 1 && V[a][b + 1]) continue;

			V[a][b] = 1;
			ans = min(ans, dfs(cnt + 1, i, size));
			V[a][b] = 0;
		}
		return ans;
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> H;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		V[a][b] = 1;
	}
	int size = 0;
	for (int b = 1; b < N; b++)
	{
		for (int a = 1; a <= H; a++)
		{
			if (V[a][b]) continue;
			if (b > 1 && V[a][b - 1]) continue;
			if (b < N - 1 && V[a][b + 1]) continue;
			candis[size] = { a, b }; size++;
		}
	}
	int ans = dfs(0, 0, size);
	if (ans == 4) cout << -1 << endl;
	else cout << ans << endl;

 	return 0;
}
