// BAEK_9938. 방 청소

#include <iostream>
#include <cstring>
#include <utility>
#define endl "\n"

using namespace std;

int N, L, parent[300001], V[300001];

int find(int p)
{
	if (parent[p] == p) return p;
	else return parent[p] = find(parent[p]);
}

void merge(int a, int b)
{
	int ap = find(a), bp = find(b);
	if (ap == bp) return;
	if (ap > bp) swap(ap, bp);
	parent[bp] = ap;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> L;
	for (int i = 1; i <= L; i++) parent[i] = i;
	for (int i = 1; i <= N; i++)
	{
		int a, b; cin >> a >> b; 
		int tmp = 0;

		if (!V[a]) V[a] =1, cout << "LADICA" << endl;
		else if (!V[b]) V[b] = 1, cout << "LADICA" << endl;
		else if((tmp = find(a)) == -1)
		{
			V[tmp] = 1; cout << "LADICA" << endl;
		}
		else if ((tmp = find(b)) == -1)
		{
			V[tmp] = 1; cout << "LADICA" << endl;
		}
		else cout << "SMECE" << endl;
		merge(a, b);
	}
	return 0;
}

/*
10 8
1 2 
1 2 
1 3 
3 4 
1 3 
5 8 
7 6 
6 7 
7 5 
8 7

*/
