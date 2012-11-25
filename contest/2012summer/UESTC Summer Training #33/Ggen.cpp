#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
	freopen("G.in","w",stdout);
	int n = 10;
	printf("%d\n",n);
	for (int i = 0;i < n;i++)
	{
	    int m = 200;
	    int len = 50;
	    for (int j = 0;j < m;j++)
	    {
	        for (int k = 0;k < len;k++)
                putchar(rand()%26+'A');
            len += rand()%5;
            len = min(100,len);
	        if (j+1 < m)
                printf(";");
	    }
	    puts("");
	}
	return 0;
}
