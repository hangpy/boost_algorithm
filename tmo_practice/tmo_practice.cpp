

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

//struct xy
//{
//	int x, y;
//	bool operator<(xy &u)
//	{
//		if (this->x < u.x) return true;
//		else if (this->x == u.x)
//		{
//			return this->y < u.y;
//		}
//		else return false;
//	}
//};

class xy
{
public:
	int x, y;
	xy(int x, int y) : x(x), y(y) {};
	bool operator<(xy &u)
	{
		if (this->x > u.x) return true;
		else if (this->x == u.x) return this->y > u.y;
		else return false;
	}
};


int main()
{
	xy arr[10] = { xy(9,2), {9, 5}, {9,4}, {1, 5}, {1, 10},
	{3, 7}, {4, 12}, {11 ,0}, {5, 1}, {-1, 13} };

	vector<xy> varr = { {9, 2}, {9, 5}, {9,4}, {1, 5}, {1, 10},
	{3, 7}, {4, 12}, {11 ,0}, {5, 1}, {-1, 13} };

	vector<xy> varr2;
	varr2.push_back(xy(1,2));
	varr2.push_back({ 1,3 });
	varr2.push_back({ 10,0 });
	varr2.push_back(xy(10, -10));
	xy obj = xy(10, 5);
	varr2.push_back(obj);
	

	sort(arr, arr + 10);
	sort(varr.begin(), varr.end());
	sort(varr2.begin(), varr2.end());

	for (auto i : arr)
		cout << "( " << i.x << ", " << i.y << " )" << " ";
	
	return 0;
}
