#include <cstdio>
#include <cstring>

using namespace std;

char str[1000001], bomb[37];
char result[1000001];

int main()
{
	scanf("%s %s", str, bomb);
	/*int bli = strlen(bumb) - 1;
	int strLen = strlen(str);
	int ri = 0;
	for (int i = 0; i < strLen; i++)
	{
		result[ri] = str[i];
		if (result[ri] == bumb[bli])
		{
			int bi = bli;
			int tmp_ri = ri;
			while (true)
			{
				if (result[tmp_ri] == bumb[bi])
				{
					if (bi == 0)
					{
						ri = tmp_ri;
						break;
					}
					tmp_ri--; bi--;
				}
				else
				{
					ri++;
					break;
				}
			}
		}
		else ri++;
	}
	
	if (ri == 0) printf("%s\n", "FRULA");
	else
	{
		for (int i = 0; i < ri; i++) printf("%c", result[i]);
		printf("\n");
	}*/
	
	int n = strlen(str), m = strlen(bomb);
	int ri(0);
	for (int i = 0 ; i <= n; i++, ri++)
	{
		if (i == n) result[ri] = '\0';
		result[ri] = str[i];
		if (result[ri] == bomb[m - 1])
			if (!strncmp(result + ri - m + 1, bomb, m))
				ri -= m;
	}
	ri--;
	if(ri != 0) printf("%s\n", result);
	else printf("%s\n", "FRULA");

    return 0;
}

