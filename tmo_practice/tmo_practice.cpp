

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

template <typename T>
bool desc(const T& x, const T& y)
{
	return x > y;
}

template <typename T>
struct asc
{
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}

};

int main()
{
	pair<int, int> arr[10] = {
		pair<int, int>(5, 10),
		pair<int, int>(5, 1),
		pair<int, int>(5, -10),
		pair<int, int>(6, 3),
		pair<int, int>(4, 3),
		pair<int, int>(5, 90),
		pair<int, int>(4, 2),
		pair<int, int>(2, 2),
		pair<int, int>(3, -1),
		pair<int, int>(3, 11)
	};

	sort(arr, arr + 10, greater<pair<int, int> >());

	for (auto i : arr)
		cout << "(" << i.first << ", " << i.second << ") ";
	cout << endl;

	pair<int, int> a = pair<int, int>(1, 5);
	pair<int, int> b = pair<int, int>(2, 6);
	a.swap(b);
	cout << a.first << ", " << a.second << endl;

	
	auto c = make_pair(1, string("abc"));

	

	//cout << c.first << ", " << c.second << endl;
	cout << typeid(c).name() << endl;
	cout << c.first << ", " << c.second << endl;
	
	return 0;
}
