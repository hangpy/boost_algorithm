// SWEA_1233. 사칙연산 유효성 검사

#include <iostream>
#include <cstring>
#define endl "\n"

using namespace std;

struct node
{
	bool isOperator;
	int left = 0;
	int right = 0;
};

node tree[201];

int dfs(int now)
{
	bool ans = false;
	node &ref = tree[now];

	if (ref.left > 0 || ref.right > 0)
	{
		if (((!ref.left && !ref.right) && !ref.isOperator)
			|| ((ref.left && ref.right) && ref.isOperator)) ans = true;
		else ans = false;
		return (ans && dfs(ref.left)) && (ans && dfs(ref.right));
	}
	else return true;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("input.txt", "r", stdin);
	for (int t = 1; t <= 10; t++)
	{
		memset(tree, 0, sizeof tree);

		int n; cin >> n;
		for (int i = 0; i < n; i++)
		{
			node ver;
			int num; cin >> num;
			char v; cin >> v;
			switch (v)
			{
			case '+': ver.isOperator = true;
				break;
			case '-': ver.isOperator = true;
				break;
			case '*': ver.isOperator = true;
				break;
			case '/': ver.isOperator = true;
				break;
			// when number
			default: ver.isOperator = false;
				break;
			}
			int a[2] = { 0, }, j = 0;
			while (getc(stdin) == ' ')
			{
				cin >> a[j++];
			}

			ver.left = a[0];
			ver.right = a[1];

			tree[num] = ver;
		}
		cout << "#" << t << " " << dfs(1) << endl;
	}
	return 0;
}

/*
4
1 * 2 3
2 + 4
3 4
4 5
*/
