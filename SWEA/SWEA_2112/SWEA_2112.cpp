// SWEA_2112. 보호필름

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

				// 원본		  // 복사본
int T, D, W, K, film[13][20], rfilm[13][20];
int depth[13] = { 0,1,2,3,4,5,6,7,8,9,10,11,12 };

// 복사본을 검사해야함.
bool inspect()
{
	int x = 0;
	for (x; x < W; x++)
	{
		int prev = -1, cnt = 0;
		int y = 0;
		for (y; y < D; y++)
		{
			if (rfilm[y][x] != prev) prev = rfilm[y][x], cnt = 1;
			else cnt++;

			if (cnt >= K) break;
		}
		if (y == D) break;
	}
	if (x != W) return false;
	else return true;
}

// 순열을 위한 dfs
// vs: 뽑은 줄 담고 있음, rvs: 각 줄의 A,B 선택, index: 순열을 위한 인덱스
bool dfs(vector<int>& vs, vector<int>& rvs, int index)
{
	bool pass = false;

	if (index == vs.size())
	{
		// 각 줄 뽑기에서 A, B 조합 완료
		// 맵 복사
		memcpy(rfilm, film, sizeof(film));
		for (int i = 0; i < vs.size(); i++)
		{
			int line = vs[i];
			for (int j = 0; j < W; j++) 
				rfilm[line][j] = rvs[i];
		}
		return inspect();
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			rvs[index] = i;
			pass = (pass | dfs(vs, rvs, index + 1));
		}
	}
	return pass;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> D >> W >> K;
		for (int y = 0; y < D; y++)
			for (int x = 0; x < W; x++)
				cin >> film[y][x];

		// 약물투여를 K-1만에 성공하지 못한다면 최종 투여는 K가 될 것 -> K는 계산 필요 없음.
		int inj = 0; // injection
		for (inj; inj < K; inj++)
		{
			int pass = false;
			vector<int> v(D, 1);
			for (int i = 0; i < inj; i++) v[i] = 0;
			// 줄 뽑기
			do
			{
				vector<int> vs;
				for (int s = 0; s < D; s++)
					if (v[s] == 0) 
						vs.push_back(depth[s]);

				vector<int> rvs(vs.size(), 0);
				//뽑은 줄 넘겨주기
				if (dfs(vs, rvs, 0))
				{
					pass = true;
					break;
				}
			} while (next_permutation(v.begin(), v.end()));

			if (pass == true) break;
		}
		
		cout << "#" << t << " " << inj << endl;
	}
	return 0;
}
