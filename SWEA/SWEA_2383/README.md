

### &#128526;[문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5-BEE6AK0DFAVl)

<br>

<br>

<br>

## 시간

1시간 15분 컷. 좋다. 점점 빨라진다. 더 빨라야 한다. 

`54 ms`, `12,648 kb`

<br>

<br>

<br>

## 접근법

해당 문제는 BFS문제가 아니라 순열조합을 이용한 시뮬레이션임을 파악하는게 첫번째 포인트이다. 각 사람이 1번, 2번 계단 중에 무엇을 선택할 것인지에 대한 상황을 모두 분기해야한다. 여기서 나는 `next_permutation()`과 `for` 을 조합하여 따로 함수를 구현하지 않았다. 선택지가 두 개일 때 유용한 기법인 듯 하다.

이후 순열이 결정된 각 상황에서 시간을 늘리는 시뮬레이션을 돌리면 된다. 그리고 최소값이 구해질 때마다 답을 갱신해나가면 된다.

<br>

<br>

<br>

## 코드

```cpp
// SWEA_2383. 점심 식사시간

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>

using namespace std;

int T, N, stair_depth[2];
struct pos { int y, x; };
struct info { int stair_num, distance; };

pos stair_pos[2];
pos persons[10];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("sample_input.txt", "r", stdin);

	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int cnt = 0;
		cin >> N;
		int s = 0, p = 0;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				int a;
				cin >> a;
				if (a > 1)
				{
					// 0이 1번, 1이 2번
					stair_pos[s] = { y,x };
					stair_depth[s] = a;
					s++;
				}
				if (a == 1)
				{
					persons[p] = { y,x };
					p++;
					cnt++;
				}
			}
		}

		// 맥스값 표현하기
		int min = numeric_limits<int>::max();
		// 각 사람이 계단을 선택하는 순열
		for (int i = 0; i <= cnt; i++)
		{
			vector<int> v(cnt, 1);
			for (int j = 0; j < i; j++) v[j] = 0;

			do
			{
				// 각 사람이 계단까지의 거리 구하기
				vector<info> state;
				for (int p = 0; p < cnt; p++)
				{
					// 0 or 1
					int stair_num = v[p];
					state.push_back({
						stair_num,
						abs(persons[p].y - stair_pos[stair_num].y) + abs(persons[p].x - stair_pos[stair_num].x)
					});
				}

				vector<int> stair_state[2] = { {0,0,0}, {0,0,0} };
				queue<int> q[2];

				// 어짜피 대기열에서 1분 기다릴 것이므로 애초에 1부터 시작
				int time = 1, out = 0;
				while (out < cnt)
				{
					// 처음에 실수 했던 곳! 참조자 반드시 붙여야 원본이 바뀜
					for (auto &head : state)
					{
                        // 검사 시점에서 0일 경우 이미 처리가 끝난 경우
						if (head.distance <= 0) continue;
						head.distance--;
						if (head.distance == 0)
							q[head.stair_num].push(1);
					}

					for (int num = 0; num < 2; num++)
					{
						for (int i = 0; i < 3; i++)
						{
							int &ret = stair_state[num][i];
							if (ret > 0)
							{
								// 한칸 내려오기
								ret--;
								// 완료하면 queue에서 빼내오기
								if (ret == 0)
								{
									out++;
									if (!q[num].empty())
									{
										q[num].pop();
										ret = stair_depth[num];
									}
								}
							}
							// 원래 비어있을 때
							else
							{
								if (!q[num].empty())
								{
									q[num].pop();
									ret = stair_depth[num];
								}
							}
						}
					}
					time++;
				}
				min = min > time ? time : min;
			} while (next_permutation(v.begin(), v.end()));
		}

		cout << "#" << t << " " << min << endl;
	}
	return 0;
}
```

<br>

<br>

<br>

## 실수한 부분

### 범위기반 for문을 사용할 때 값 복사에 주의하자

```cpp
// 처음에는 &head가 아닌 head라고 썼었음.
for (auto &head : state)
{
    if (head.distance <= 0) continue;
    head.distance--;
    if (head.distance == 0)
        q[head.stair_num].push(1);
}
```

인덱스를 활용한 for문의 경우 직접 접근을 해서 변수를 선언하고 값 복사를 하는 참사를 범하지 않는 이상 별 문제가 없다. 하지만 범위기반 for문을 사용할 경우 위와 같은 실수를 할 확률이 굉장히 높다.

범위기반 for문에서 참조자를 붙이지 않을 경우,  auto 뒤에 있는 변수에 해당 컨테이너의 접근 요소를 복사한다. 그리고 for문에서 다루는 변수는 복사한 값이기 때문에 원본에 영향을 주지 않는다. 즉, 원본을 직접 손봐야 하는 로직의 경우 상태 변화에 의한 루프 종료조건을 만족시키지 못해 무한루프에 빠질 수도 있다. 해결방법은 간단하다. 직접 원본을 고치고 싶은 경우 auto 뒤에 `&`를 붙여주면 된다.

> 매우 자주 할 수 있는 실수이므로 반드시 염두하면서 구현하자.

<br>

### 시간의 흐름에 대한 제약 조건을 놓치지 말자.

사실 이 문제는 다소 운이 좋았다. 맨 처음에는 답보다 1만큼씩 낮게 나왔기 때문에 그냥 time의 초기값을 1로 둠으로써 간단히 답을 도출할 수는 있었다. 하지만 이게 시간의 흐름 제약에 조건이 있을 경우에는 다소 해맬 수 있는 요소가 다분한 실수다.

이 문제에서 내가 맨 처음에 놓쳤던 조건은 ***계단에 도착하고 1분 뒤에 계단을 내려가기 시작한다***는 것이다. 해당 조건은 조건부 제약이 아니라 단순 중간에 끼어진 절대적인 조건이기 때문에 그냥 1분만 추가해주면 되지만 조건부였을 경우, 난 아마 깊은 디버깅의 늪에 빠졌을 것이다.

> 반드시 시간의 흐름 제약 조건을 빠짐없이 확인하고 또 확인하자.

### 







