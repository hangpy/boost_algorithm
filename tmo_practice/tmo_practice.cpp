// tmo_practice.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <cstdio>
#include <iostream>
#include <limits>
#include <string.h>
#include <queue>

using namespace std;

struct node
{
	int num, value;
};

struct cmp
{
	bool operator()(node t, node u)
	{
		return t.value > u.value;
	}
};

int main()
{
	priority_queue<node, vector<node>, cmp> pq;
	pq.push({ 1, 4 });
	pq.push({ 2, 4 });
	pq.push({ 2, 1 });
	pq.push({ 3, 8 });
	pq.push({ 4, -10 });

	while (!pq.empty())
	{
		cout << pq.top().num << ": " << pq.top().value << endl;
		pq.pop();
	}

	
	return 0;
}