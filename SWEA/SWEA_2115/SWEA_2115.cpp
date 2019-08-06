// SWEA_2115. 벌꿀채취
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int map[11][11], line[2], worker_1[5], worker_2[5], MAX = 0;

void select_each_box(int n, int m, int c);
int get_max(const int marr[], int m, int c);
void perm(int n, int m, int index, int depth, int c);

int get_max(const int marr[], int m, int c)
{
	int max = 0;
	for (int i = 1; i < m; i++)
	{
		vector<int> v(m, 1);
		for (int j = 0; j < m - i; j++)v[j] = 0;
		int sum = 0, tmp_max = 0;
		do
		{
			for (int k = 0; k < m; k++)
			{
				if (v[k] == 0)
				{
					sum += marr[k];
					tmp_max += pow(marr[k], 2);
				}
			}
			if (sum <= c && max < tmp_max)
				max = tmp_max;

			sum = 0;
			tmp_max = 0;

		} while (next_permutation(v.begin(), v.end()));
	}
	
	return max;
}

void perm(int n, int m, int index, int depth, int c)
{
	if (depth == m)
	{
		// logic line[0], line[1];
		// recursive -> start from index 1 because of map

		memset(worker_1, 0, sizeof(worker_1));
		memset(worker_2, 0, sizeof(worker_2));
		select_each_box(n, m, c);


		return;
	}
	for (int i = index; i <= n; i++)
	{
		line[depth] = i;
		perm(n, m, i, depth + 1, c);
	}
}

void select_each_box(int n, int m, int c)
{
	// when cannot be duplicated
	if (line[0] == line[1])
	{
		for (int left = 1; left < n - 2 * m + 2; left++)
		{
			for (int i = left, idx = 0; i < left + m; i++)
			{
				worker_1[idx] = map[line[0]][i];
				idx++;
			}
			for (int right = left + m; right < n - m + 2; right++)
			{
				for (int j = right, idx = 0; j < right + m; j++)
				{
					worker_2[idx] = map[line[0]][j];
					idx++;
				}
			}
			int tmp_max = get_max(worker_1, m, c) + get_max(worker_2, m, c);
			MAX = max(MAX, tmp_max);

		}
	}
	// when no duplicated
	else
	{
		for (int left = 1; left < n - m + 2; left++)
		{
			for (int i = left, idx = 0; i < left + m; i++)
			{
				worker_1[idx] = map[line[0]][i];
				idx++;
				if (i == left + m - 1)
				{
					for (int right = 1; right < n - m + 2; right++)
					{
						for (int i = right, idx = 0; i < right + m; i++)
						{
							worker_2[idx] = map[line[1]][i];
							idx++;
						}
						int tmp_max = get_max(worker_1, m, c) + get_max(worker_2, m, c);
						MAX = max(MAX, tmp_max);

					}
				}
				
			}

		}
	}
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
		memset(line, 0, sizeof(line));

		int N, M, C;
		cin >> N >> M >> C;
		for (int y = 1; y <= N; y++)
			for (int x = 1; x <= N; x++)
				cin >> map[y][x];
		

		perm(N, M, 1, 0, C);
		
		cout << "#" << t << " " << MAX << "\n";
		MAX = 0;
	}

	//perm(5, 2, 1, 0);

	return 0;
}
