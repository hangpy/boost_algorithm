// BAEK_2869.달팽이는 올라가고 싶다

#include <iostream>
using namespace std;
int A, B, V;
int main()
{
	cin >> A >> B >> V;
	cout << (V - A) / (A - B) + 1 * ((V - A) % (A - B) != 0) + 1 << endl;
	return 0;
}