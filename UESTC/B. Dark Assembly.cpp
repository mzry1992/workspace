#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,k,b[9],l[9];
double res,a;

void Gao(int now,int used)
{
    if (now > n)
    {
        double tres = 0.0,pro,sumb;
        int count;
        for (int i = 0;i < (1<<n);i++)
        {
            pro = 1.0;
            sumb = 0.0;
            count = 0;
            for (int j = 0;j < n;j++)
                if (((i>>j)&1) == 1)
                {
                    pro *= 0.01*l[j+1];
                    count++;
                }
                else
                {
                    pro *= 0.01*(100-l[j+1]);
                    sumb += (double)b[j+1];
                }
            if (count > n/2)
                tres += pro;
            else
                tres += pro*a/(a+sumb);
        }
        res = max(res,tres);
    }
    else
    {
        for (int i = 0;used+i <= k && l[now]+i*10 <= 100;i++)
        {
            l[now] += i*10;
            Gao(now+1,used+i);
            l[now] -= i*10;
        }
    }
}

int main()
{
    while (scanf("%d%d%lf",&n,&k,&a) != EOF)
    {
        for (int i = 1;i <= n;i++)
            scanf("%d%d",&b[i],&l[i]);
        res = 0.0;
        Gao(1,0);
        printf("%.10f\n",res);
    }
    return 0;
}
