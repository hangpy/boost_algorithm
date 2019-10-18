// BAEK_17135. ĳ�� ���潺

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define endl "\n"

using namespace std;
//			��������		   gTmpMap���� ����
int N, M, D, gMap[16][15], gTmpMap[16][15], visit[16][15];
struct pos { int y, x; };
struct qpos { int y, x, d; };
// �� �� ��
int dy[3] = {0, -1, 0};
int dx[3] = {-1, 0, 1};

pos getEnemy(pos &archar)
{
	memset(visit, 0, sizeof visit);
	pos enemyToKill = { -1, -1 };
	queue<qpos> q;
	q.push({ archar.y, archar.x, 0 });
	while (!q.empty())
	{
		bool whileBreak = false;
		qpos now = q.front(); q.pop();
		int py = now.y, px = now.x, pd = now.d;
		for (int i = 0; i < 3; i++)
		{
			int ny = py + dy[i], nx = px + dx[i], nd = pd + 1;
			if (ny == N || ny < 0 || nx < 0 || nx > M-1 || nd > D || visit[ny][nx]) continue;
			
			// ���� �ش� ĭ�� ���̸� ���� ������
			if (gTmpMap[ny][nx])
			{
				enemyToKill = { ny, nx };
				whileBreak = true;
				break;
			}
			else
			{
				q.push({ ny, nx, nd });
				visit[ny][nx] = 1;
			}
		}
		if (whileBreak) break;
	}
	return enemyToKill;
}


int doGame(vector<pos> &archars, int enemyCnt)
{
	int cnt = enemyCnt;
	int kill = 0;
	// ���� ��� ������ ������ ���� ����
	while (cnt > 0)
	{
		queue<pos> toKill;
		for (unsigned int i = 0; i < archars.size(); i++)
		{
			pos enemPos = getEnemy(archars[i]);
			if (enemPos.y != -1) toKill.push(enemPos);
		}

		// �ü��κ��� ���Ӵ��� �� ���� cnt--, toKill++;
		while (!toKill.empty())
		{
			pos enemy = toKill.front(); toKill.pop();
			if (gTmpMap[enemy.y][enemy.x] == 1)
			{
				gTmpMap[enemy.y][enemy.x] = 0;
				cnt--;
				kill++;
			}
		}

		// N-1�� �� �� ���� -> cnt -= �� ��
		for (int x = 0; x < M; x++) if (gTmpMap[N-1][x]) cnt--;

		// �� ���� ������ �̵�
		for (int y = N - 1; y > 0; y--)
			for (int x = 0; x < M; x++)
				gTmpMap[y][x] = gTmpMap[y - 1][x];
		for (int x = 0; x < M; x++) gTmpMap[0][x] = 0;
	}
	return kill;
}


int main()
{
	cin >> N >> M >> D;
	int enemyCnt = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> gMap[y][x];
			if (gMap[y][x]) enemyCnt++;
		}
	}
		

	int ans = 0;
	vector<int> vComb(M, 1);
	for (int i = 0; i < 3; i++) vComb[i] = 0;
	// �� ����
	do
	{
		// �ü� ��ġ ����
		vector<pos> archars;
		for (int i = 0; i < M; i++)
			if (!vComb[i]) archars.push_back({ N, i });
		
		// ���ӽ���
		memcpy(gTmpMap, gMap, sizeof gMap);
		int tmp = doGame(archars, enemyCnt);
		ans = ans < tmp ? tmp : ans;

	} while (next_permutation(vComb.begin(), vComb.end()));

	cout << ans << endl;

	return 0;
}