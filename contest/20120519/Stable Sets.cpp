#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,a[110],b[110],p[110];
char buf[1100];

void Gao(int a[])
{
    m = 0;
    gets(buf);
    int len = strlen(buf);
    for (int i = 0;i < len;i++)
        if (buf[i] >= '0' && buf[i] <= '9')
        {
        }
        else
            i++;
}

int main()
{
	while (true)
	{
	    scanf("%d",&n);
	    if (n == 0) break;
        gets(buf);
        Gao(a);
        Gao(b);
	}
	return 0;
}
