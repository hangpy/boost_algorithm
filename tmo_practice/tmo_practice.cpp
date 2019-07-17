

#include <cstdio>
#include <iostream>
#include <limits>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int cnt;
int d[10] = { 1,2,3,4,5,6,7,8,9,10 };
int result[10];

// nCk
//void combination(int rest, int pick, int size)
//{
//	if (pick == 0)
//	{
//		// logic
//		for (int i = 0; i < size; i++)
//			cout << pi[i] << " ";		
//		cout << endl;
//
//		return;
//	}
//	else if (rest < pick) return;
//	else
//	{
//		// 일단 포함한다는 전제하에 그 위에 덮어쓸 계획인 것임.
//		pi[pick - 1] = cand[rest - 1];
//
//		// 엄청 중요!, 아래 두 재귀함수의 순서가 바뀌면 안됨!
//		// 1
//		combination(rest - 1, pick - 1, size);
//		// 2
//		combination(rest - 1, pick, size);
//		
//	}
//}


void combination(int m, int n, int depth, int index)
{
	if (depth == n)
	{
		// logic
		for (int i = 0; i < n; i++)
			cout << result[i] << " ";
		cout << endl;

		return;
	}
	else if (index == m) return;
	else
	{
		result[depth] = d[index];
		combination(m, n, depth + 1, index + 1);
		combination(m, n, depth, index + 1);
	}
}

// mHn
void r_combination(int m, int n, int depth, int index)
{
	if (depth == n)
	{
		cnt++;
		// logic
		for (int i = 0; i < n; i++)
			cout << result[i] << " ";
		cout << endl;

		return;
	}
	else if (index == m) return;
	else
	{
		result[depth] = d[index];
		r_combination(m, n, depth + 1, index);
		r_combination(m, n, depth, index + 1);
	}
}

template<typename T>
void swap(T *a, T *b)
{
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

// mPn
template<typename T>
void permutation(T arr[], int m, int n, int depth)
{
	if (depth == n)
	{
		// 각 순열 케이스에 대한 로직
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	else
	{
		for (int idx = depth; idx < m; idx++)
		{
			swap(arr[idx], arr[depth]); // 최 앞단 고정시키기
			permutation(arr, m, n, depth + 1);
			swap(arr[idx], arr[depth]); // return 하면서 다시 원래대로 되돌리기
		}
		
	}
}

// mΠn
template<typename T>
void r_permutation(T arr[], T t_arr[], int m, int n, int depth)
{
	if (depth == n)
	{
		// 각 중복 순열 케이스에 대한 로직
		for (int i = 0; i < n; i++)
			cout << t_arr[i] << " ";
		cout << endl;
		cnt++;
	}
	else
	{
		for (int idx = 0; idx < m; idx++)
		{
			t_arr[depth] = arr[idx];
			r_permutation(arr, t_arr, m, n, depth + 1);
		}

	}
}


int main()
{
	/*int arr[] = { 1,1,1,4,5 };
	int len = 0;
	cin >> len;
	do
	{
		cnt++;
		for (int i = 0; i < len; i++)
			cout << arr[i] << " ";
		cout << endl;
	} while (next_permutation(arr, arr + len));
	cout << cnt << endl;*/

	//combination(5, 3, 0, 0);
	r_combination(3, 3, 0, 0);
	cout << cnt << endl;

	return 0;
}