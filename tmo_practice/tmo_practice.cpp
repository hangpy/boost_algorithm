

#include <cstdio>
#include <iostream>
#include <limits>
#include <string.h>
#include <queue>

using namespace std;


int main()
{
	int i(1);

	for (int q = 0, p = 1; q < 5&& p < 10; i++, q += 2, p *= 2, cout << "[증감부]")
	{
		cout << q << " " << p << " " << i << endl;
	}

	return 0;
}