

### &#128526;[문제 링크](https://www.acmicpc.net/problem/15683)

<br>

<br>

<br>

## 시간

1시간 10분 컷

`28 ms` , `1992 kb`

<br>

<br>

<br>

## 접근법

각 감시카메라 별로 가질 수 있는 감시 방향 상황을 순열조합으로 모두 구한 후, 시뮬레이션 한다. 특히, 감시카메라가 가질 수 있는 각도를 표현하는 것이 관건이었음.

<br>

<br>

<br>

## 코드

```cpp
// BAEK_15683. 감시

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M, MAP[8][8], DIR[8], CMAP[8][8];
struct cpos { int y, x, num; };
// 상우하좌
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int spaceSize = 0, ANS;

vector<vector<int> > cctvs[6] = 
{
	{},
	{ {0}, {1}, {2}, {3} }, // 1 - 0까지
	{ {0, 2}, {1, 3} },	// 2 - 1까지
	{ {0, 1}, {1, 2}, {2, 3}, {3, 0} },	// 3 - 1까지
	{ {0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1} },	// 4 - 2까지
	{ {0, 1, 2, 3} } // 5 - 3까지
};

void comb(vector<int> &cctvDir, vector<cpos> &cctvInMap, int size, int depth)
{
	if (depth == size)
	{
		// DIR에 cctivInMaps의 인덱스에 맞춰 각자의 방향이 정해져있음.
		
		// 원본유지를 위해 맵 복사
		memcpy(CMAP, MAP, sizeof(MAP));
		int vacum = spaceSize;

		for (int i = 0; i < size; i++)
		{
			int cctvNum = cctvInMap[i].num;

			// 예를들어 cctvs[cctvNum]에서 몇번째 상황
			int d = DIR[i]; 

			// ex) {0, 1}
			vector<int> directions = cctvs[cctvNum][d];

			// dir은 0,1,2,3 중 하나
			for (auto dir : directions)
			{
				// dir방향으로 쭉 감시 시작
				int cy = cctvInMap[i].y, cx = cctvInMap[i].x;
				while (true)
				{
					int ny = cy + dy[dir], nx = cx + dx[dir];
					if (ny < 0 || ny > N - 1 || nx < 0 || nx > M - 1) break;
					if (CMAP[ny][nx] == 6) break;

					if ((1 <= CMAP[ny][nx] && CMAP[ny][nx] <= 5) || CMAP[ny][nx] == 7)
					{
						cy = ny, cx = nx;
						continue;
					}
					vacum--;
					CMAP[ny][nx] = 7;
					cy = ny, cx = nx;
				}
			}
		}
		ANS = ANS > vacum ? vacum : ANS;
	}
	else
	{
		for (int i = 0; i < cctvDir[depth]; i++)
		{
			DIR[depth] = i;
			comb(cctvDir, cctvInMap, size, depth + 1);
		}

	}
}

int main()
{
	cin >> N >> M;
	
	vector<cpos> cctvsInMap;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			int a; cin >> a;
			MAP[y][x] = a;
			if (1 <= a && a <= 5) cctvsInMap.push_back({ y, x, a });
			if (a == 0) spaceSize++;
		}
	}
	ANS = spaceSize;

	vector<int> situations;
	for (auto cctv : cctvsInMap)
		situations.push_back(cctvs[MAP[cctv.y][cctv.x]].size());
	
	
	comb(situations, cctvsInMap, situations.size(), 0);

	cout << ANS << endl;


	return 0;
}
```

<br>

<br>

<br>

