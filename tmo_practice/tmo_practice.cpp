

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

struct xy
{
	int x, y;
	/*bool operator<(const xy &u)
	{
		if (this->x > u.x) return true;
		else if (this->x == u.x) return this->y > u.y;
		else return false;
	}*/
};


struct cmp
{
	bool operator()(const xy &t, const xy &u)
	{
		/*if (t.x < u.x) return true;
		else if (t.x == u.x) return t.y < u.y;
		else return false;*/
		return t.x < u.x; //less -> max-heap
	}
};

int n, m;

int answer;
bool safe = false, cont = true;
char map[52][52];


int main()
{
	
	//scanf("%d %d\n", &n, &m);
	//for (int i = 0; i < n; i++) {
	//	//for (int j = 0; j < m; j++) {
	//		scanf("%s", map[i]);
	//	//}
	//	/*getchar();*/
	//}
	//

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		printf("%c", map[i][j]);
	//	}
	//	printf("\n");
	//}

	
	

	// ctrl + shift + space -> 매개변수 목록
	FILE *f = freopen("./input.txt", "r", stdin);
	printf("%p\n", f);

	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	wchar_t str[50];

	
	scanf("%s", str);

	printf("%d %d %d\n", a, b, c);
	printf("%s\n", str);

	


	return 0;
}
