#include <cstdio>
#include <cstring>

using namespace std;

char str[1000001], bumb[37];
char result[1000001];

int main()
{
	scanf("%s", str);
	scanf("%s", bumb);
	int bli = strlen(bumb) - 1;
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
	}

    return 0;
}

