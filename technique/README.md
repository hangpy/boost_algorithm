

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
while (next_permutation(prev_arr, prev_arr + len));
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
/*
 ================================================
 + 
 +
 ================================================
*/

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

