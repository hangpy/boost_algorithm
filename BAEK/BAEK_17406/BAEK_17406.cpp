// BAEK_17406.cpp. 배열돌리기4

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, K, MAP[51][51], CMAP[51][51];
struct oper { int y, x, s; };
vector<oper> vopers;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int getMinValue()
{
	int ans = 987654321;
	for (int y = 1; y <= N; y++)
	{
		int tmp = 0;
		for (int x = 1; x <= M; x++) tmp += CMAP[y][x];
		ans = ans > tmp ? tmp : ans;
	}
	return ans;
}

void rotate(oper &operation)
{
	int y = operation.y, x = operation.x, s = operation.s;
	for (int cs = 1; cs <= s; cs++)
	{
		int d = 0; int cnt = 0;
		// manipulate CMAP
		int cy = y - cs, cx = x - cs;
		int tmp = CMAP[cy][cx];
		while (d < 4)
		{
			int ny = cy + dy[d], nx = cx + dx[d];
			int ttmp = CMAP[ny][nx];
			CMAP[ny][nx] = tmp;
			tmp = ttmp;
			cnt++;

			cy = ny, cx = nx;
			if(cnt >= cs * 2) d++, cnt = 0;
		}
	}
}


int main()
{
 
	cin >> N >> M >> K;
	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= M; x++)
			cin >> MAP[y][x];

	for (int i = 0; i < K; i++)
	{
		int y, x, s; cin >> y >> x >> s;
		vopers.push_back({ y, x, s });
	}

	int ans = 987654321;
	vector<int> vturn(vopers.size());
	for (int i = 0; i < vopers.size(); i++) vturn[i] = i;
	do
	{
		memcpy(CMAP, MAP, sizeof MAP);
		// 연산 순서 조합
		for (int i = 0; i < vturn.size(); i++)
		{
			oper operation = vopers[vturn[i]];
			// 각각의 operation 계산
			rotate(operation);
		}

		//  getMinValue with CMAP
		int tmp = getMinValue();
		ans = ans > tmp ? tmp : ans;

	} while (next_permutation(vturn.begin(), vturn.end()));

	cout << ans << endl;

	return 0;
}