

# 코딩 기법 모음

프로그래밍을 하는데 있어서 필수적이고 유용한 기법들을 정리해보자.

<br>

<br>

<br>

시간을 줄이기 위한 scanf 표준 입출력 사용 (예정)

C++에서 무한대 표현하기 (예정)

소수점 밑 반올림 (예정)

우선순위 큐 (priority_queue) 활용 방법 및 중복 방지 (예정)

[순열 조합 구현하기](#순열-조합-구현하기)

묶고 싶은 것은 구조체(struct)를 사용하자 (예정)

방향성 표현하기 (예정)

컨테이너속 노드에 구조체를 통해 상태 추가하기 (예정)

[STL 정렬함수 활용하기](#STL-정렬함수-활용하기)

문자열 처리 관련 STL 활용밥 숙지 (예정)

vector에서 중복 원소 제거하기 (예정)

for문 안에서 증감부 조작으로 로직 간소화하기 (예정)

<br>

<br>

<br>

## 순열 조합 구현하기

### 순열(Permutation)

![](./assets/permutation.gif)

#### m == n 일 때

`#include <algorithm>`의 `next_permutation()` 혹은 `prev_permutation()` 쓰기. 두 함수는 중복되는 수열은 제외시켜서 유용하다.

```cpp
int next_arr[] = { 1,2,3,4,5 };
int len = 0;
cin >> len;
do
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
} 	// 전체 다 할 거라면 next_arr의 원소 개수만큼 더하기
while (next_permutation(next_arr, next_arr + len));


// =========================================
int prev_arr[] = { 5,4,3,2,1 };
do
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
} 	// 전체 다 할 거라면 next_arr의 원소 개수만큼 더하기
while (prev_permutation(prev_arr, prev_arr + len));
```

아래와 같이 직접 구현해서 할 수도 있다.

```cpp
// dfs 활용
void perm(int idx, int depth)
{
	if (depth != -1)
	{
		visited[idx] = true;
		per[depth] = candi[idx];
	}
	// 전역변수 활용할 때
	if (depth == 3)
	{
		// logic
		for (auto i : per)
			cout << i << " ";
		cout << endl;
		visited[idx] = false;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (visited[i] == true) continue;
		perm(i, depth + 1);
		visited[i] = false;
	}
}

int main()
{
    // -1부터 시작
    perm(-1, -1);
    return 0;
}
```

#### m != n 일 때

```cpp
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
    // depth는 0부터 시작하기 때문에 n과 같아졌다는 것은 
    // 길이가 n으로 이미 고정을 완료 했다는 의미
	if (depth == n)
	{
		// 각 순열 케이스에 대한 로직
		for (int i = 0; i < n; i++) cout << arr[i] << " ";
		cout << endl;
	}
	else
	{
		for (int idx = depth; idx < m; idx++)
		{
			swap(arr[idx], arr[depth]); // 최 앞단 고정시키기
			permutation(arr, m, n, depth + 1); // 다음 고정을 위해 depth 이동
			swap(arr[idx], arr[depth]); // return 하면서 다시 원래대로 되돌리기
		}
	}
}

int main()
{
    // depth는 0부터 시작
    permutation(arr, 5, 3, 0);
    return 0;
}
```

주의해야할 점은 기존의 배열을 직접 다루기 때문에 반드시 `read-only`로 각 케이스에 대한 로직을 다루어야 한다.

<br>

### 중복순열(Permutation with Repetition)

![](.\assets\permutation_repitition.gif)

만약 문제가 중복된 결과를 허용하지 않을 경우 아래 구현된 함수는 중복된 원소가 없는 배열을 이용해야 한다. 만약 중복된 원소가 있을 경우, 중복된 원소를 모두 하나만 남겨둔 배열로 재생성한 후 n만 그대로 해서 함수를 호출 하면 된다. 

```cpp
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
	int arr[] = { 1,2,3,4,5 };
	int *t_arr = new int[sizeof(arr) / sizeof(int)];
	
    // 임시 저장할 배열이 필요. 전역, 동적, 스태틱, 지역 중 상황에 따라 택1
	r_permutation(arr, t_arr, 5, 5, 0);

	return 0;
}
```

<br>

### 조합(Combination)

![](./assets/combination.gif)

```cpp
int picked[10];
int data[] = { 1,2,3,4,5,6,7,8,9,10 };

// mCn
void combination(int m, int n, int size)
{
	if (pick == 0)
	{
		// 조합 케이스별 로직을 포함시키는 구간
		for (int i = 0; i < size; i++)
			cout << picked[i] << " ";		
		cout << endl;

		return;
	}
    // 앞으로 픽할 것 보다 후보군이 적을 때
	else if (m < n) return;
	else
	{
		// 먼저 해당 요소를 포함하는 경우를 표현하기 때문에 1번 재귀부터 와야한다.
        // 그렇지 않으면 이미 해당 요소를 덮어쓰는 연산이 시행된 뒤에 return으로 돌아오기 때문에,
        // 10C3의 예시에서는 123만 반복해서 나올 것이다.
		picked[n - 1] = data[m - 1];

		// 엄청 중요!, 아래 두 재귀함수의 순서가 바뀌면 안됨!
		// 1
		combination(m - 1, n - 1, size);
		// 2
		combination(m - 1, n, size);
		
	}
}

```

아래와 같은 구현이 더 쉬운듯 하다.

```cpp
/*
 ==========================================================
 | 좀 더 직관적으로 인덱스를 0부터 하나씩 옮겨가면서 포함관계 연산
 ==========================================================
*/

int d[10] = {1,2,3,4,5,6,7,8,9,10}
int result[10];

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
    // index가 m일 경우 return은 앞으로 뽑을 수 있는 원소가 없는 경우를 제외함을 의미한다.
	else if (index == m) return;
	else
	{
		result[depth] = d[index];
		combination(m, n, depth + 1, index + 1);
		combination(m, n, depth, index + 1);
	}
}
```

<br>

### 중복조합(Combination with Repetition)

![](./assets/combination_repitition.gif)

```cpp
// mHn
void r_combination(int m, int n, int depth, int index)
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
		r_combination(m, n, depth + 1, index);
		r_combination(m, n, depth, index + 1);
	}
}
```

[중복조합 개념글 링크](https://m.blog.naver.com/PostView.nhn?blogId=freewheel3&logNo=220785417706&proxyReferer=https%3A%2F%2Fwww.google.com%2F)

<br>

<br>

<br>

## STL 정렬함수 활용하기

### \<algorithm\> sort() 이해하기

```cpp
template <class RandomAccessIterator>
void sort (RandomAccessIterator first, RandomAccessIterator last);

template <class RandomAccessIterator, class Compare>
void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
```

sort는 기본적으로 오름차순을 기준으로 한다. 또한 인자로 반드시 임의접근 반복자를 사용해야만 한다. 순차접근 반복자를 사용하는 list와 같은 자료구조는 해당 sort를 사용할 수 없다. 비교중에 같은 원소는 원래의 정렬 상태를 보장하진 않는다. 보장하고 싶다면 `stable_sort()`를 참고하도록 하자.

시간복잡도는 대략 인자로 들어가는 두 반복자의 distance에 비례해서 nlogn에 수렴한다.

[sort 참고자료](http://www.cplusplus.com/reference/algorithm/sort/)

<br>

### greater, less 단어 이해하기

```cpp
bool cmp(int t, int u)
{
	return t > u; // greater
    // return t < u; // less
}
```

sort()에서 쓰이는 greater, less는 `왼쪽이 오른쪽에 비해서`를 기준으로 삼는다. 즉, greater ( > )는 내림차순을, less ( < )는 오름차순을 뜻한다. 위와 같은 기준만 잘 숙지한다면 비교연산을 커스터마이징할 때 헷갈릴 일이 없을 것이다.

<br>

### operator < 로 비교하기

< 연산자 재정의를 통한 비교는 아래를 참고.

```cpp
int main()
{
	int arr[10] = { 1,10,8,4,6,7,5,2,3,9 };
	
    // 세 번째 인자를 넣지 않으면 오름차순으로 < 연산을 통해 정렬을 하게 됨.
	sort(arr, arr + 10);

	return 0;
}
```

<br>

### std::비교함수객체로 비교하기

less : 왼쪽 인자가 오른쪽 인자보다 작으면 true 반환

greater : 왼쪽 인자가 오른쪽 인자보다 크면 true 반환

greater\<int\> 뒤에 ()를 붙이는 것은 function object의 임시 객체를 생성하는 것이다.

```cpp
#include <functional>
using namespace std;
int main()
{
	int arr[10] = { 1,10,8,4,6,7,5,2,3,9 };
	
    // greater<int> cmp;
    // sort(arr, arr + 10, cmp)도 가능
	sort(arr, arr + 10, greater<int>());
	for (auto i : arr)
		cout << i << " ";
	cout << endl;

	sort(arr, arr + 10, less<int>());
	for (auto i : arr)
		cout << i << " ";
	cout << endl;
	
	return 0;
}
// 결과
/*
1, 2, 3, 4, 5, 6, 7, 8, 9, 10
10, 9, 8, 7, 6, 5, 4, 3, 2, 1
*/
```

<br>

아래는 \<functional\> STL에 있는 greater (less도 비슷함) struct의 원형 구조이다. greater\<int\>()를 통해 생성된 임시객체에 (const T& x, const T& y)연산을 하게 되면 두 인자를 비교한 결과값을 반환하게 된다. 즉, sort에 다음과 같은 함수의 임시객체를 넣어준다는 뜻은, 배열 혹은 반복자 비교시, 해당 재정의된 함수호출 연산자를 통해 두 값을 비교함을 알 수 있다.

```cpp
template struct greater {
    bool operator() (const T& x, const T& y) const 
    {
        return x>y;
    }
    typedef T first_argument_type;
    typedef T second_argument_type;
    typedef bool result_type;
};
```

### 자체 함수객체로 비교하기

위의 \<functional\> STL의 비교함수객체를 이해했으면 아래의 자체 커스터마이징 함수객체 이용은 쉽게 이해가 가능하다.

```cpp
template <typename T>
bool desc(const T& x, const T& y)
{
	return x > y;
}

template <typename T>
struct asc
{
    // operator 뒤에 ()를 붙이는 것을 까먹기 쉽다.
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};


int main()
{
	int arr[10] = { 1,10,8,4,6,7,5,2,3,9 };

	sort(arr, arr + 10, desc<int>);
	for (auto i : arr)
		cout << i << " ";
	cout << endl;

	sort(arr, arr + 10, asc<int>());
	for (auto i : arr)
		cout << i << " ";
	cout << endl;
	
	return 0;
}
```

<br>

### 연산자 재정의(bool operator<(){})된 객체로 비교하기

구조체를 사용할 경우, 클래스를 사용할 때 보다 더 단순한 형태를 유지할 수 있다.

```cpp
struct xy
{
	int x, y;
	bool operator<(xy &u)
	{
        // 오른쪽이 더 크지 않은 경우에 두 비교 원소를 바꾸는 듯 하다.
        // 즉 true일 때는 두 비교 원소를 그대로 두는 듯 함.
		if (this->x < u.x) return true;
        // 그렇다면 두 비교 원소가 같아도 바꾼다는 뜻인데, 해당 경우
        // y를 기준으로 두 원소의 swap 여부를 판안한다.
		else if (this->x == u.x)
		{
            // 역시 오른쪽 y가 더 큰 경우엔 true를 반환해서 그대로 둔다.
			return this->y < u.y;
		}
        // 그 외의 경우엔 모두 swap한다.
		else return false;
	}
};

int main()
{
	xy arr[10] = { {9, 2}, {9, 5}, {9,4}, {1, 5}, {1, 10},
	{3, 7}, {4, 12}, {11 ,0}, {5, 1}, {-1, 13} };

	vector<xy> varr = { {9, 2}, {9, 5}, {9,4}, {1, 5}, {1, 10},
	{3, 7}, {4, 12}, {11 ,0}, {5, 1}, {-1, 13} };

	sort(arr, arr + 10);
	sort(varr.begin(), varr.end());

	for (auto i : varr) cout << "( " << i.x << ", " << i.y << " )" << " ";
}

/*
결과
( -1, 13 ) ( 1, 5 ) ( 1, 10 ) ( 3, 7 ) ( 4, 12 ) ( 5, 1 ) ( 9, 2 ) ( 9, 4 ) ( 9, 5 ) ( 11, 0 )
*/
```

클래스로 구현할 경우

```cpp
class xy
{
public:
	int x, y;
	xy(int x, int y) : x(x), y(y) {};
    // 이번에는 내림차순으로 구현할 경우
	bool operator<(xy &u)
	{
		if (this->x > u.x) return true;
		else if (this->x == u.x) return this->y > u.y;
		else return false;
	}
};

int main()
{
    // 다음과 같은 문법 모두 가능
	xy arr[10] = { xy(9,2), {9, 5}, {9,4}, {1, 5}, {1, 10},
	{3, 7}, {4, 12}, {11 ,0}, {5, 1}, {-1, 13} };

	vector<xy> varr = { {9, 2}, {9, 5}, {9,4}, {1, 5}, {1, 10},
	{3, 7}, {4, 12}, {11 ,0}, {5, 1}, {-1, 13} };

	vector<xy> varr2;
    // 일반적인 인스턴스 정의
	varr2.push_back(xy(1,2));
    // 구조체 인스턴스 생성과 똑같은 문법 적용 가능
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
```

여기서 눈여겨 볼 문법은 객체를 선언 정의할 때 초기화를  구조체와 같이 `{ }`로 가능하다는 것이다.

<br>

#### STL Pair의 정렬

pair를 sort함수로 정렬할 경우, 기본적으로 pair의 첫번째 원소를 기준으로 정렬하고, 첫번째 원소가 같다면, 두번째 원소를 사용해서 비교하게 된다.

```cpp
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

	sort(arr, arr + 10);
    
    // 내림차순 시
    // sort(arr, arr + 10, greater<pair<int, int> >());
    // '>>'는 컴파일러에 따라 비트연산자로 인식될 가능성이 있으니 한칸 띄어쓰도록 하자.

	for (auto i : arr)
		cout << "(" << i.first << ", " << i.second << ") ";
	cout << endl;

	return 0;
}
// 결과
// 오름차순 (2, 2) (3, -1) (3, 11) (4, 2) (4, 3) (5, -10) (5, 1) (5, 10) (5, 90) (6, 3)
// 내림차순 (6, 3) (5, 90) (5, 10) (5, 1) (5, -10) (4, 3) (4, 2) (3, 11) (3, -1) (2, 2)
```

벡터를 사용할 경우에도 동일한 결과가 나온다.



<br>

<br>

<br>









