#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,id,a[1000],ta,res,resid;
char com[5];

int main()
{
    int ft = 1;
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        ta = 0;
        printf("Case %d:\n",ft++);
        for (int i = 0;i < n;i++)
        {
            scanf("%s%d",com,&id);
            if (com[0] == 'A')
            {
                res = id;
                resid = -2;
                for (int j = 0;j < ta;j++)
                    if (a[j]%id <= res)
                    {
                        res = a[j]%id;
                        resid = j;
                    }
                printf("%d\n",resid+1);
            }
            else
            {
                a[ta++] = id;
            }
        }
        puts("");
    }
    return 0;
}
