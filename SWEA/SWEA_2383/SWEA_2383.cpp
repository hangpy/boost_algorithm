// SWEA_2383. 점심 식사시간

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>

using namespace std;

int T, N, stair_depth[2];
struct pos { int y, x; };
struct info { int stair_num, distance; };

pos stair_pos[2];
pos persons[10];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int cnt = 0;
		cin >> N;
		int s = 0, p = 0;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				int a;
				cin >> a;
				if (a > 1)
				{
					// 0이 1번, 1이 2번
					stair_pos[s] = { y,x };
					stair_depth[s] = a;
					s++;
				}
				if (a == 1)
				{
					persons[p] = { y,x };
					p++;
					cnt++;
				}
			}
		}

		// 맥스값 표현하기
		int min = numeric_limits<int>::max();
		// 각 사람이 계단을 선택하는 순열
		for (int i = 0; i <= cnt; i++)
		{
			vector<int> v(cnt, 1);
			for (int j = 0; j < i; j++) v[j] = 0;

			do
			{
				// 각 사람이 계단까지의 거리 구하기
				vector<info> state;
				for (int p = 0; p < cnt; p++)
				{
					// 0 or 1
					int stair_num = v[p];
					state.push_back({
						stair_num,
						abs(persons[p].y - stair_pos[stair_num].y) + abs(persons[p].x - stair_pos[stair_num].x)
					});
				}

				vector<int> stair_state[2] = { {0,0,0}, {0,0,0} };
				queue<int> q[2];

				// 어짜피 대기열에서 1분 기다릴 것이므로 애초에 1부터 시작
				int time = 1, out = 0;
				while (out < cnt)
				{
					// 처음에 실수 했던 곳! 참조자 반드시 붙여야 원본이 바뀜
					for (auto &head : state)
					{
						// 검사 시점에서 0일 경우 이미 처리가 끝난 경우
						if (head.distance <= 0) continue;
						head.distance--;
						if (head.distance == 0)
							q[head.stair_num].push(1);
					}

					for (int num = 0; num < 2; num++)
					{
						for (int i = 0; i < 3; i++)
						{
							int &ret = stair_state[num][i];
							if (ret > 0)
							{
								// 한칸 내려오기
								ret--;
								// 완료하면 queue에서 빼내오기
								if (ret == 0)
								{
									out++;
									if (!q[num].empty())
									{
										q[num].pop();
										ret = stair_depth[num];
									}
								}
							}
							// 원래 비어있을 때
							else
							{
								if (!q[num].empty())
								{
									q[num].pop();
									ret = stair_depth[num];
								}
							}
						}
					}
					time++;
				}
				min = min > time ? time : min;
			} while (next_permutation(v.begin(), v.end()));
		}

		cout << "#" << t << " " << min << endl;
	}
	return 0;
}