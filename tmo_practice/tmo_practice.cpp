#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;


int main()
{
	/*vector<int> v;
	v.assign({ 1,2,3,4 });
	cout << v.capacity() << endl;
	v.resize(10);
	cout << v.capacity() << endl;
	v.clear();
	cout << v.capacity() << endl;
	v.reserve(20);
	cout << v.capacity() << endl;
	v.assign({ 1,2,3,4,5,6,7,8,9,10 });
	cout << v.capacity() << endl;
	cout << v.size() << endl;
	v.resize(5);
	for (auto i : v)
		cout << i << " ";
	cout << endl;
	v.resize(10);
	for (auto i : v)
		cout << i << " ";
	cout << endl;*/

	vector<int> v(11);
	v[10] = 10;
	for (auto i : v) cout << v[i] << " ";
	cout << endl;

	for (int i = 0; i < v.size(); i++)
	{
		v.erase(v.begin() + i); i--;
		for (int j = 0; j < v.size(); j++)
			cout << v[j] << " ";
		cout << endl;
	}


	return 0;
}