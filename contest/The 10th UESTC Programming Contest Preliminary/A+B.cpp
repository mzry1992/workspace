#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int p,n,a[10000],b[10000],c[10000],q,pos,val;
char com;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&p,&n);
        for (int i = n-1;i >= 0;i--)
            scanf("%d",&a[i]);
        for (int i = n-1;i >= 0;i--)
            scanf("%d",&b[i]);
        scanf("%d",&q);
        printf("Case #%d:\n",ft);
        for (int i = 0;i < q;i++)
        {
            scanf(" %c",&com);
            if (com == 'C')
            {
                scanf(" %c%d%d",&com,&pos,&val);
                if (com == 'A')
                    a[pos] = val;
                else
                    b[pos] = val;
            }
            else
            {
                scanf("%d",&pos);
                for (int i = 0;i < n;i++)
                    c[i] = a[i]+b[i];
                c[n] = 0;
                for (int i = 0;i < n;i++)
                {
                    c[i+1] += c[i]/p;
                    c[i] %= p;
                }
                printf("%d\n",c[pos]);
            }
        }
    }
	return 0;
}
