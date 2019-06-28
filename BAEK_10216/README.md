

### &#128526;[문제 링크](https://www.acmicpc.net/problem/10216)

<br>

<br>

<br>

## 접근법

**인접리스트**를 사용한 **DFS**로 접근. 각 적군 기지에 대해 `두 노드간 거리 <= 반지름의 합` 이면 직접 통신이 가능하다는 것을 알아야 한다. 여기서 도출해야 하는 답은 그룹의 개수이다. `for`로 각 적군 기지를 순회하면서 방문하지 않았던 기지를 만나면 **DFS** 를 통해 인접해 있는 모든 기지의 방문을 1로 바꾼다. 만약 그룹 순회가 끝나면 직접 통신이 되는 기지는 모두 1로 바껴있으므로 `for`문에서 그 다음 인덱스 부터 시작할 때, 아직 `Grouping` 되지 않은 기지를 만났을 때 다시 **DFS**를 시행한다. 즉 **DFS** 함수를 호출할 때마다 카운트를 함으로써 답을 도출하면 된다.

<br>

<br>

<br>

## 핵심 파트

```C++
// make adjcent list
for (int i = 1; i <= N-1; i++)
{
    for (int j = i + 1; j <= N; j++)
    {
        point e1 = ens[i];
        point e2 = ens[j];

        // validate whether direct conn is possible
        if (pow(e1.x - e2.x, 2) + pow(e1.y - e2.y, 2) <= pow(e1.r + e2.r, 2))
        {
            // make adj
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
}
```

#### 꿀팁 &#128273;

제곱근을 구하는 `sqrt`를 쓰면 소숫점 뒷자리가 나오는 부동소수점 형태의 자료형이 된다. 하지만 이는 컴파일 환경마다 자칫 의도치 않은 버그를 발생시킬 수 있다. 후에 `(int)`로 캐스팅해도 값의 손실이 없는  `pow(int 밑, int 지수)`로 양변에 취해줌으로써 소수점을 발생시키지 않는다.

> *정수로 다룰 수 있는 것은 무조건 정수로 다룬다*

<br>

```c++
void dfs(int node)
{	
	// check as visited
	V[node] = 1;

	for (auto n : adj[node])
		if (!V[n]) dfs(n);
}
```

`void` 반환형으로 방문 노드만 체크해 주면 된다.

<br>

<br>

<br>

### 실수한 부분

#### 디테일에 집중하자

반지름 더하는 부분에서 e2를 계속 e1이라고 함. 이런 실수는 하기도 쉽고 디버깅 시 매우 찾기 매우 힘들기 때문에 특히 시간관리가 중요한 코딩 테스트에는 치명적이다. 코드 작성 시에는 정말 작은 부분도 집중해서 코딩하자.

```c++
if (pow(e1.x - e2.x, 2) + pow(e1.y - e2.y, 2) <= pow(e1.r + e2.r, 2))
{
    adj[i].push_back(j);
    adj[j].push_back(i);
}
```

<br>

#### 고정된 크기의 입력값은 최대 길이의 고정된 배열로 받는다

```c++
// 각각의 테스트 케이스에 대해서 적군 진영의 숫자 N (1 ≤ N ≤ 3,000)이 주어진다.
int T, N;
int V[3001];
point ens[3001];
vector<int> adj[3001];
vector<int> ANS;
```

입력값이 최대 길이가 고정되어 있다면 메모리 제한을 넘기지 않는 한, 고정된 배열로 선언을 한다. 아래와 같은 실수를 반복하면 안된다.

```c++
vector< vector<int> > adj(3001);
```

정적 배열로 가능한 것을 굳이 동적 배열을 선언해서 할 필요는 없다. 머리만 아파질 뿐.
<br>

#### 테스트 케이스가 다수일 경우, 반드시 쓴 메모리는 초기화 시켜준다

```c++
// clear for next test case
for (int i = 1; i <= N; i++)
	adj[i].clear();
memset(V, 0, sizeof(V));
```

고정된 길이로 받은 입력값의 메모리(주로 배열)은 `범위기반 for` 보다는 기존의 인덱스를 활용해서 초기화를 다시 시켜준다. 왜냐하면 범위기반으로 초기화 할 경우, 내가 쓰지도 않은 메모리를 다시 초기화 할 수 있기 때문이다.

<br>

[&#128215; 벡터 정리 및 사용법 블로그 링크](https://blockdmask.tistory.com/70)

<br>

<br>

<br>

## 사용한 디버깅 기법

```c++
for(int i = 1; i <= N; i++)
{	
    cout << i << ": ";
    for(auto j : adj[i])
        cout << j << " ";
    cout << endl;
}
```

인접리스트 프린팅함으로써 검증

<br>

<br>

<br>