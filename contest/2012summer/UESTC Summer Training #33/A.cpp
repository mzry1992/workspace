#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,res[10];
char buf[20];

void calc(int a)
{
    sprintf(buf,"%d",a);
    for (int i = 0;buf[i] != 0;i++)
        res[buf[i]-'0']++;
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%d",&n);
        memset(res,0,sizeof(res));
        for (int i = 1;i <= n;i++)
            calc(i);
        printf("%d",res[0]);
        for (int i = 1;i < 10;i++)
            printf(" %d",res[i]);
        printf("\n");
    }
	return 0;
}
