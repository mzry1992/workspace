#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n,m,pa,pb,c,mc;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        pa = pb = 0;
        for (int i = 0;i < 1<<n;i++)
        {
            c = mc = 0;
            for (int j = 0;j < n;j++)
                if (((i>>j)&1) == 1)
                {
                    c++;
                    mc = max(mc,c);
                }
                else
                    c = 0;
            if (mc >= m) pa++;
            pb++;
        }
        printf("%.2f\n",(double)pa/pb);
    }
    return 0;
}
