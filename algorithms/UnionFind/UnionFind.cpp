#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int find(int pVertex, vector<int>& parent)
{
	if (parent[pVertex] == pVertex) return pVertex;
	else return parent[pVertex] = find(parent[pVertex], parent);
}

void merge(int pLeft, int pRight, vector<int>& parent, vector<int>& level)
{
	int leftParent = find(pLeft, parent);
	int rightParent = find(pRight, parent);

	if (leftParent == rightParent) return;

	if (level[leftParent] < level[rightParent])
		swap(leftParent, rightParent);
	parent[rightParent] = leftParent;
	level[leftParent] = max(level[leftParent], level[rightParent] + 1);
}


int main()
{

	int V, E;
	cin >> V >> E;

	vector<int> parent(V+1);
	vector<int> level(V+1);
	
	for (int i = 1; i < parent.size(); i++)
	{
		parent[i] = i;
		level[i] = 0;
	}

	for (int e = 1; e <= E; e++)
	{
		int l, r;
		cin >> l >> r;
		if (l > r) swap(l, r);
		merge(l, r, parent, level);
	}

	for (auto v : parent)
		cout << find(v, parent) << " ";
	cout << endl;
	
	for (auto v : level)
		cout << v << " ";
	cout << endl;

	/*
	입력
	10 8
	10 5
	1 2
	5 1
	9 4
	4 3
	6 4
	4 7
	7 8

	결과
	0 1 1 4 4 1 4 4 4 4 1
	0 2 0 0 1 1 0 0 0 0 0
	*/
	

	return 0;
}
