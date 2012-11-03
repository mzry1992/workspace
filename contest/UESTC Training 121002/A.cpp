#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char buf[10000];
int len;
int b,g;

int main()
{
	int totcas;
	scanf("%d",&totcas);
    gets(buf);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    gets(buf);
	    len = strlen(buf);
	    b = g = 0;
	    for (int i = 0;i < len;i++)
	    {
	        if (buf[i] == 'b' || buf[i] == 'B') b++;
	        if (buf[i] == 'g' || buf[i] == 'G') g++;
	    }
	    printf("%s is ",buf);
	    if (g > b)  puts("GOOD");
	    else if (g == b)    puts("NEUTRAL");
	    else puts("A BADDY");
	}
    return 0;
}

