#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,res[100];
int a[110],b[110];

int check(int ga,int gb,int a,int b)
{
    int res = 0;
    if ((ga > gb && a > b) || (ga == gb && a == b) || (ga < gb && a < b))   res += 2;
    if (ga-gb == a-b)   res += 3;
    if (ga == a)    res ++;
    if (gb == b)    res ++;
    return res;
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        memset(res,0,sizeof(res));
        for (int i = 0;i < m;i++)
        {
            for (int j = 0;j < n+1;j++)
                scanf("%d%d",&a[j],&b[j]);
            for (int j = 1;j <= n;j++)
            {
                //printf("j = %d : %d\n",j,check(a[j],b[j],a[n],b[n]));
                res[j-1] += check(a[j],b[j],a[0],b[0]);
            }
        }
        printf("%d",res[0]);
        for (int i = 1;i < n;i++)
            printf(" %d",res[i]);
        printf("\n");
    }
	return 0;
}
