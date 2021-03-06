// SDS_LV2_1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

// for starting from 1 with easier perception, len += 1
int ingredients[11][9][9]{ 0 }, problems[6][9][9]{ 0 }, T, N, Q, now_t, now_q;
int assembled[9][9]{ 0 }, case_visited[11]{ 0 };
vector<int> ANS[31], each_case, each_rot;

/*bool cmp_color(int (*problem)[9], int (*assembled)[9], int len)
{
	bool ans = true;
	for (int i = 1; i <= len; i++)
	{
		for (int j = 1; j <= len; j++)
		{
			if (problem[i][j] != assembled[i][j])
			{
				ans = false;
				break;
			}
		}
	}
	return ans;
}*/

// depth는 각 조합안의 원소 개수
bool rot_dfs(int depth)
{
	
	bool didMatch = false;
	if (each_rot.size() == depth)
	{

		cout << endl;
		// 각 중복 순열에 대해 덮어쓰고 매칭까지
		bool didEndure = true;
		for (int i = 1; i <= 8; i++)
		{
			bool break_check = false;
			for (int j = 1; j <= 8; j++)
			{

				// 회전 중복 순열
				for (int order = 0; order < depth; order++)
				{
					// assembled는 일단 원래 흰판
					// 각 회전별 덮어쓰기
					int c;
					int angle = each_rot[order] * 90;
					if (angle == 0)
					{
						c = ingredients[each_case[order]][i][j];
					}
					else if (angle == 90)
					{
						c = ingredients[each_case[order]][9-j][i];
					}
					else if (angle == 180)
					{
						c = ingredients[each_case[order]][9-i][9-j];
					}
					else // angle == 270
					{
						c = ingredients[each_case[order]][j][9-i];
					}
					// 투명하지 않으면 덮어쓰기
					if (!c) assembled[i][j] = c;
				}

				// 바로 타겟과 안맞으면 break;
				if (problems[now_q][i][j] != assembled[i][j])
				{
					break_check = true;
					didEndure = false;
					break;
				}

				if (break_check) break;
			}
			if (break_check) break;
		}
		// 위의 이중 for문이 끝까지 돌았으면 완벽히 매칭이 된 것.
		didMatch = didEndure;
		// false면 false를 반환
		if (didMatch == true)
			return didMatch;
		else
			return didMatch;
	}

	for (int i = 0; i < 4; i++)
	{
		each_rot.push_back(i);
		if (didMatch = rot_dfs(depth)) break;
		each_rot.pop_back();
	}
	return didMatch;
}



bool dfs(int depth)
{
	
	bool didFind = false;
	if (each_case.size() == depth)
	{
		// 각 조합 안의 회전 가능한 조합에 대한 일치 여부 판단.
		bool cmp = rot_dfs(depth);

		if (cmp) // 일치하면
		{
			cout << "if(cmp)" << endl;
			ANS[now_t].push_back(depth);
			for (auto num : each_case)
				ANS[now_t].push_back(num);
			didFind = true;
			return didFind;
		}
		else // 불일치
			return didFind;
	}

	for (int i = 1; i <= N; i++)
	{
		if (case_visited[i]) continue;
		case_visited[i] = 1;
		each_case.push_back(i);
		if (didFind = dfs(depth)) break;
		each_case.pop_back();
		case_visited[i] = 0;
	}
	return didFind;
}



int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		now_t = t;
		cin >> N;
		for (int n = 1; n <= N; n++)
		{
			// cin N개의 재료 컬러
			for (int i = 1; i <= 8; i++)
			{
				for (int j = 1; j <= 8; j++)
				{
					char c;
					int color(0);
					cin >> c;
					switch (c)
					{
					case '.': color = 0; break;
					case 'R': color = 1; break;
					case 'Y': color = 2; break;
					case 'B': color = 3; break;
					default:
						break;
					}
					ingredients[n][i][j] = color;
				}
			}
		}
		cin >> Q;
		for (int q = 1; q <= Q; q++)
		{
			// cin Q개의 각 T에서 도출할 문제들의 컬러
			for (int i = 1; i <= 8; i++)
			{
				for (int j = 1; j <= 8; j++)
				{
					char c;
					int color(0);
					cin >> c;
					switch (c)
					{
					case 'W': color = 0; break;
					case 'R': color = 1; break;
					case 'Y': color = 2; break;
					case 'B': color = 3; break;
					default:
						break;
					}
					problems[q][i][j] = color;
				}
			}
		}


		// logic
		for(int q = 1; q <= Q; q++)
		{
			// about problem[q][9][9]
			now_q = q;

			// 최소값을 구해야 하므로 필요한 판 갯수 1부터 시작
			for (int min = 1; min <= N; min++)
			{
				// 각 개수만큼 N개의 재료에 대해 순열로 상황 비교
				if (dfs(min)) break;
			}
			// for next, initialize
			memset(case_visited, 0, sizeof(case_visited));
			each_case.clear();
			each_rot.clear();
		}	
	}


	// cout answers
	for (int t = 1; t <= T; t++)
	{
		cout << "#" << t << " ";
		for (auto i : ANS[t])
		{
			cout << i << " ";
		}
		cout << endl;
	}
	
    return 0;
}

