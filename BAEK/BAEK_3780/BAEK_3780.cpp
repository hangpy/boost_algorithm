// BAEK_3780. 네트워크 연결

#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long ll;

int T, N, PARENT[20001], LENGTH[20001];

// 압축!!!!
int find(int p)
{
	if (PARENT[p] == p) return p;
	else
	{
		// 여기서 이걸 안해줘서 계속 시간초과 났던거임
		// n시간 안에서 갱신까지 해줬어야 했음.
		int tp = find(PARENT[p]);
		LENGTH[p] += LENGTH[PARENT[p]];
		PARENT[p] = tp;
		return tp;
	}
}

// 센터 i를 기업 j에 연결한다
void merge(int i, int j)
{
	PARENT[i] = j;
	LENGTH[i] = abs(i - j) % 1000;
}


int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		for (int i = 1; i <= N; i++) PARENT[i] = i;
		while (1)
		{
			char mode;
			cin >> mode;
			if (mode == 'O') break;
			if (mode == 'E')
			{
				int com; cin >> com;
				// 압축과정 필요
				find(com);
				cout << LENGTH[com] << "\n";
			}
			if (mode == 'I')
			{
				int center = 0, com = 0;
				cin >> center >> com;
				merge(center, com);
			}
		}
		// 실수하기 쉬운 초기화
		memset(LENGTH, 0, sizeof LENGTH);
	}
	return 0;
}



// 시간 초과의 원인 중 하나였던 함수
//int getLength(int com)
//{
//	if (com == PARENT[com]) return 0;
//	return LENGTH[com] + getLength(PARENT[com]);
//}