// SWEA_1949. 등산로 조정
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct pos { int y, x, h; };
int T, N, K, MAP[9][9], V[9][9];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

// 트리를 그려서 재귀호출 형태를 맞춰줌
// 딱 한번만 높이를 팔 수 있다는 조건을 처음에 빼먹는 실수를 함. cnt를 인자로 넣어줬어야함. 
int dfs(pos curr, int val, int cnt)
{
	// 이후 max()를 통해 result 업데이트
	int result = val;
	int cy = curr.y, cx = curr.x, ch = curr.h;
	// 진입하면 바로 방문 체크
	V[cy][cx] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = cy + dy[i], nx = cx + dx[i];
		// 경계선 넘거나 현재 경로 탐색중 방문했던 곳이면 무시
		if (ny < 1 || ny > N || nx < 1 || nx > N || V[ny][nx]) continue;

		// 고정된 데이터를 다룰 경우 참조자를 쓰자
		int &nh = MAP[ny][nx];
		if (nh < ch) 
			result = max(result, dfs({ ny, nx, nh }, val + 1, cnt));
		else
		{
			// 기회가 남았을 때만 가능
			if (cnt > 0 && nh - K < ch)
				result = max(result, dfs({ ny, nx, ch - 1 }, val + 1, cnt - 1));
			else continue;
		}
	}
	// 빠져나가면서 다른 경우를 위해 벡트레킹
	V[cy][cx] = 0;
	// 반환된 경로들 중 가장 큰 값을 반환
	return result;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("sample_input.txt", "r", stdin);
	cin >> T;
	
	for (int t = 1; t <= T; t++)
	{
		int tmp_max = 0;
		vector<pos> highs;
		cin >> N >> K;
		// 입력과 동시에 가장 높은 봉우리를 벡터에 저장
		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++)
			{
				int h;
				cin >> h;
				MAP[y][x] = h;
				if (h == tmp_max) highs.push_back({ y, x, h });
				
				// 만약 새로운 높은 봉우리가 나왔을 경우 벡터를 청소하고 새로 넣기 시작
				else if (h > tmp_max)
				{
					tmp_max = h;
					highs.clear();
					highs.push_back({ y, x, h });
				}
				else continue;
			}
		}
		
		int ANS = 0;
		// 각 높은 봉우리에 대해서 DFS 실시
		for (auto h : highs) ANS = max(ANS, dfs(h, 1, 1));
		cout << "#" << t << " " << ANS << "\n";
	}

	return 0;
}
