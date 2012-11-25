#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

void getS()
{
    int id = rand()%17576;
    do
    {
        putchar('A'+id%26);
        id/=26;
    }while (id);
}

int main()
{
	freopen("F.in","w",stdout);
	int n = 1000;
	int m = 39000;
	int k = rand()%1000;
	printf("%d %d %d\n",n,m,k);
	for (int i = 0;i < n;i++)
	{
	    getS();
	    puts("");
	}
	int pre = 0;
	for (int i = 0;i < m;i++)
	{
	    int op = 0;
	    if (pre == 1)
            op = rand()%2;
	    if (op == 0)
	    {
	        printf("ADD(");
            getS();
            puts(")");
            pre = 1;
	    }
	    else
	    {
            puts("ROTATE");
            pre = 0;
	    }
	}
    return 0;
}

