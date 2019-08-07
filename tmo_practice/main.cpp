#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int arr[5] = { 1, 3, 6, 7, 12 };

int get_max(int n, int c, int idx, int sum, int val)
{
	if (sum > c) return 0;
	else if (idx == n) return val;

	// �б�
	int left = get_max(n, c, idx + 1, sum + arr[idx], val + pow(arr[idx], 2));
	int right = get_max(n, c, idx + 1, sum, val);

	// ��� �б����� ���ƿ� �� ó��
	int result = max(left, right);

	return result;
}


int main()
{

	cout << get_max(5, 13, 0, 0, 0) << endl;

	return 0;
}