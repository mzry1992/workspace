#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int s,pre[101][20],a[20],res[30];
bool flag;

void Gao(int s,int deep,int suma,double sumb,int last)
{
    if (flag == true)   return;
    if (s == suma)
    {
        if (fabs(sumb-1.0) < 1e-5)
        {
            pre[s][0] = deep;
            for (int i = 0;i < deep;i++)
                pre[s][i+1] = a[i];
            flag = true;
        }
        return;
    }
    if (sumb >= 1.0)    return;
    for (int i = last;suma+i <= s;i++)
    {
        a[deep] = i;
        Gao(s,deep+1,suma+i,sumb+1/(double)i,i);
    }
}

void Ji(int s,int res[])
{
    if (s <= 100)
    {
        for (int i = 0;i <= pre[s][0];i++)
            res[i] = pre[s][i];
        return;
    }
    int tmp[30];
    if ((s&1) == 0)
    {
        Ji((s-2)>>1,tmp);
        res[0] = 1;
        res[1] = 2;
    }
    else
    {
        Ji((s-9)>>1,tmp);
        res[0] = 2;
        res[1] = 3;
        res[2] = 6;
    }
    if (tmp[0] > 0)
    {
        for (int i = 1;i <= tmp[0];i++)
            res[++res[0]] = tmp[i]*2;
    }
    else res[0] = 0;
}

int main()
{
    for (s = 1;s <= 100;s++)
    {
        flag = false;
        pre[s][0] = 0;
        Gao(s,0,0,0.0,1);
    }
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&s);
        Ji(s,res);
        if (res[0] == 0)
            printf("-1\n");
        else
        {
            for (int i = 0;i <= res[0];i++)
                printf("%d ",res[i]);
            printf("\n");
        }
    }
}
