// BAEK_5052. 전화번호 목록

#include <iostream>
#define endl "\n"
using namespace std;

int T, N;
char num[10001];

struct node
{
	bool isLeaf[10]{ false };
	node *arr[10]{ NULL };
};

bool insert(node *cur, int index)
{
	bool ans = true;

	int n = num[index] - '0';

	if (cur->isLeaf[n]) return ans = false;

	if (num[index + 1] == '\0')
	{
		if (cur->arr[n] != NULL) return ans = false;
		cur->arr[n] = new node;
		cur->isLeaf[n] = true;
		return ans;
	}
	else
	{
		if (cur->arr[n] == NULL)
		{
			cur->arr[n] = new node;
			return ans = insert(cur->arr[n], index + 1);
		}
		else ans = insert(cur->arr[n], index + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		node* s = new node;
		cin >> N; int i = 0; bool keep = true;
		for (; i < N; i++)
		{
			cin >> num;
			if (!keep) continue;
			if ((keep = insert(s, 0)) == false) cout << "NO" << endl;
		}
		if (keep) cout << "YES" << endl;
	}
	return 0;
}
