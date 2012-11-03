#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n,m;

void genstr(int len)
{
    for (int i = 0;i < len;i++)
        printf("%c",rand()%26+'a');
    printf("\n");
}

int main()
{
    freopen("5792.txt","w",stdout);
    n = m = 5;
    for (int ft = 0;ft < 10;ft++)
    {
        printf("%d %d\n",n,m);
        for (int i = 0;i < n+m;i++)
            genstr(5);
    }
    printf("0 0\n");
	return 0;
}
