

#include <cstdio>
#include <iostream>
#include <limits>
#include <cstring>
#include <queue>
#include <algorithm>
#include <functional>
#include <string>
#include <typeinfo>

using namespace std;

struct xy
{
	int x, y;
	/*bool operator<(const xy &u)
	{
		if (this->x > u.x) return true;
		else if (this->x == u.x) return this->y > u.y;
		else return false;
	}*/
};


struct cmp
{
	bool operator()(const xy &t, const xy &u)
	{
		/*if (t.x < u.x) return true;
		else if (t.x == u.x) return t.y < u.y;
		else return false;*/
		return t.x < u.x; //less -> max-heap
	}
};


int main()
{
	
	priority_queue<xy, vector<xy>, cmp> pq;
	pq.push({ 1, 3 });
	pq.push({ 1, 4 });
	pq.push({ 2, 1 });
	pq.push({ 2, 3 });
	pq.push({ 2, 10 });

	while (!pq.empty())
	{
		cout << pq.top().x << ", " << pq.top().y << endl;
		pq.pop();
	}
	

	return 0;
}
