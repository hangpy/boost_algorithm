#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

int bs(int arr[], int target, int start, int end)
{
	int mid = (start + end) / 2;
	
	if (arr[mid] == target) return mid;

	if (mid == start)
	{
		if (arr[start] == target) return start;
		else if (arr[end] == target) return end;
		else return -1;
	}
	
	if (arr[mid] > target) return bs(arr, target, start, mid);
	else return bs(arr, target, mid + 1, end);
}



int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8, 9, 10 };

	/*int target = 8;
	int idx = bs(arr, target, 0, sizeof(arr) / sizeof(int) - 1);*/

	for(auto i : arr)
		cout << bs(arr, i, 0, sizeof(arr) / sizeof(int) - 1) << " ";
	cout << endl;
	
	
	/*if (idx > -1)
		cout << target << " is found" << endl;
	else
		cout << "Failed to find" << endl;*/
	
}
