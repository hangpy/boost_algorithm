

# 알고리즘 카테고리

문제를 풀면서 반복적으로 실수할 가능성이 높은 부분은 반드시 정리하고 실수를 반복해선 안된다. 



<br>

<br>

<br>

## &#128297; 컴파일 환경

Using IDE **MS Visual Studio**

Windows SDK version: **10.0.17763.0**

<br>

<br>

<br>

## &#128518; 실수 모음

[BFS 중복 카운트 실수](./BAEK_2667#실수한-부분)

[인접리스트 방향성 고려](./BAEK_2606#실수한-부분)

[고정된 크기의 입력값을 받을 때](./BAEK_10216#실수한-부분)

[시간, 메모리 제약사항 부터 확인](./BAEK_1890#실수한-부분)

[정답의 크기를 고려한 자료형 선언](./BAEK_1890#출력-형태의-자료형을-반드시-확인하라)

[종료 시점을 로직에 포함 여부 고려](./BAEK_1890#로직이-종료되는-순간의-조건을-항상-생각한다)

[필요 없는 계산은 피하기](./BAEK_1890#필요-없는-계산은-시간-효율을-위해-시키지-않는다)

[비교연산자 대상체 실수하지 말 것](./BAEK_1504#실수한-부분)

[입출력 제약사항 반드시 확인할 것](./BAEK_1504#실수한-부분)

[비어있는 queue 또는 stack에서 계속 front(), pop() 시도](./BAEK_3190#실수한-부분)

[DFS로 특정 깊이까지 퍼짐 표현하기](./SWEA/SWEA_5644#실수한-부분)

[대입과 축적을 헷갈리지 말자. 축적의 경우 반드시 초기화할 것!](./SWEA/SWEA_4012#실수한-부분)

[정렬시, 유효한 시작 인덱스를 반드시 확인할 것!](./BAEK/BAEK_1197#실수한-부분)

[중복되는 연산을 확인하고 미리 계산할 수 있는지 생각해보자!](./SWEA/SWEA_2115#실수한-부분)

<br>

<br>

<br>

## &#128526; C++ 기법 모음

시간을 줄이기 위한 scanf 표준 입출력 사용 (예정) (scanf, cin 상황별 사용 요령)

std::ios_base::sync_with_stdio(false); cin.tie(NULL)로 표준입력속도 끌어올리기 (예정)

C++에서 무한대 표현하기 (예정)

소수점 밑 반올림 (예정)

데이터 저장시 인덱스로 구별이 가능하다면 모두 배열로 구현하자 (예정)

[우선순위 큐 (priority_queue) 활용 방법 및 중복 방지](./technique/#우선순위-큐-활용하기)

[순열조합, 중복순열 표현하기](./technique#순열-조합-구현하기)

묶고 싶은 것은 구조체(struct)를 사용하자 (예정)

[배열로 방향과 같은 변화 표현하기](./technique/#배열로-방향과-같은-변화-표현하기)

컨테이너속 노드에 구조체를 통해 상태 추가하기 (예정)

[STL 정렬함수 활용하기](./technique/#STL-정렬함수-활용하기)

문자열 처리 관련 STL 활용밥 숙지 (예정)

vector에서 중복 원소 제거하기 (예정)

for문 안에서 증감부 조작으로 로직 간소화하기 (예정)

<br>

<br>

<br>

## &#128531; Visual Studio 활용

반례 체계적으로 찾기 (예정)

F5 key로 바로 다음 중단점으로 이동하기 (예정)

ctrl + shift + space로 매개변수 확인

도구 - 설정 - 키보드 - 주석 단축키 변경 (Ctrl + /, Ctrl + Shift + /)

자동 인덴트 조정 (들여쓰기 조정) (파일 전체: Ctrl + K + D, 선택: Ctrl  + K + F) (or Alt + F8)

함수 정의로 이동: F12

직전 커서 위치로 이동: Ctrl + - (다음커서: Ctrl + Shift + -)

동시에 여러줄 직사각형 형태로 입력: Alt + 커서로 직사각형 모양으로 드래그

전체 변수명 바꾸기: 현재 변수 위치에서 Ctrl + R 두번

Ctrl + / 안먹힐 때: 시스템 키보드 입력이 Microsoft가 아닐경우: Window + Space로 되돌리기

Window + Shift + S : 부분스크린샷

<br>

<br>

<br>

## &#128534; 에러별  대처 요령 모음

[Expression: deque iterator not dereferencable](./errors#Queue가-비어있는데-참조를-시도할-때) (예정)

<br>

<br>

<br>

## &#128509;알고리즘 구현 연습

[Union-Find (Disjoing Set) (서로소 집합)](./algorithms/UnionFind)

[Binary Search (이진 검색)](./algorithms/AL_BinarySearch)

<br>

<br>

<br>

## &#128507;자료구조 구현 연습

[Binary Tree (이진 트리)](./data_structure/DS_BinaryTree)

<br>

<br>

<br>

## &#128511; 알고리즘에 대한 직관적, 의미론적인 접근

[재귀함수(Recursive Function)에 대한 프로그래밍적 고찰](./intuitive/#재귀함수에-대한-고찰)

<br>

<br>

<br>

## &#127813; DFS, BFS

[BEAK 2606. 바이러스](./BAEK_2606)

[BEAK 2667. 단지번호붙이기](./BAEK_2667)

[BAEK 10216. Count Circle Groups](./BAEK_10216)

[BAEK 1890. 점프](./BAEK_1890) (풀 수는 있지만 DFS, BFS로 풀 경우 각각 시간, 메모리 제한 초과)

[BAEK 1325. 효율적인 해킹](./BAEK_1325)

[BAEK 3055. 탈출](./BAEK_3055)

<br>

<br>

<br>

## &#127817; DP

[BAEK 1890. 점프](./BAEK_1890)

[BAEK 9095. 1, 2, 3 더하기](./BAEK_9095)

[algospot. WILDCARD](./solving_strategy/p218_inter_wildcard/p218_inter_wildcard.cpp)

<br>

<br>

<br>



## &#127816; Simulation

[BAEK 3190. 뱀](./BAEK_3190)

[SWEA 5650. 핀볼 게임](./SWEA/SWEA_5650)

[SWEA 5644. 무선 충전](./SWEA/SWEA_5644)

[SWEA 5648. 원자소멸 시뮬레이션](./SWEA/SWEA_5648)

[SWEA 2382. 미생물 격리](./SWEA/SWEA_2382)

[SWEA 4012. 요리사 (조합, 순열 문제)](./SWEA/SWEA_4012)

[SWEA 2115. 벌꿀채취](./SWEA/SWEA_2115)

<br>

<br>

<br>



## &#127820; Greedy

[BAEK 2217. 로프](./BAEK_2217)

[BAEK 4716. 풍선](./BAEK_4716)

<br>

<br>

<br>



## &#127821; 위상정렬

[BAEK 1516. 게임개발](./BAEK_1516)

<br>

<br>

<br>



## &#127815; 최단경로 문제 (SSP, ASP)

[BAEK 1504. 특정한 최단 경로 (다익스트라)](./BAEK_1504)

[BAEK 11657. 타임머신 (벨만 포드)](./BAEK_11657)

<br>

<br>

<br>

## &#127819;최소 스패닝 트리 (MST)

[BAEK 1197. 최소 스패닝 트리](./BAEK/BAEK_1197)  (Kruskal 이용)

<br>

<br>

<br>

## &#127826; 문자열 처리

[BAEK 3613. Java vs C++](./BAEK_3613)

[BAEK 9935. 문자열 폭발](./BAEK_9935)

<br>

<br>

<br>