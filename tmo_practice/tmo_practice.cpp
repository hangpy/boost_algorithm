// tmo_practice.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <queue>

using namespace std;

struct vertex
{
	int num;
	int value;
};

struct cmp
{
public:
	bool operator()(vertex t, vertex u)
	{
		return t.value > u.value;
	}
};



int main()
{
	priority_queue<vertex, vector<vertex>, cmp> pq;
	pq.push({ 1, 5 });
	pq.push({ 2, 2 });
	pq.push({ 3, 7 });

	while (!pq.empty())
	{
		cout << pq.top().num << ": " << pq.top().value << endl;
		pq.pop();
	}
    return 0;
}

