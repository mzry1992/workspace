#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[16],b[4];
int mp[1<<16][24],tt[1<<16];
long long tot[1<<16];
int mp2[1<<16][24],mp3[1<<16][24];
long long res;

void gao(int now,int used)
{
    if (now == 4)
    {
        mp[used][tt[used]++] = b[0]+b[1]*2+b[2]*3+b[3]*4;
        return;
    }
    for (int i = 0; i < 16; i++)
        if (((used>>i)&1) == 0)
        {
            b[now] = a[i];
            gao(now+1,used|(1<<i));
        }
}

void gao3(int now,int used,int last,int a,int b)
{
    if (now == 4)
    {
        for (int i = 0;i < 24;i++)
            for (int j = 0;j < 24;j++)
                if (mp[a][i] == mp[b][j])
                    tot[used]++;
        return;
    }
    for (int i = last+1; i < 16; i++)
        if (((used>>i)&1) == 0)
            gao3(now+1,used|(1<<i),i,a,b|(1<<i));
}

void gao2(int now,int used,int last)
{
    if (now == 4)
    {
        gao3(0,used,-1,used,0);
        return;
    }
    for (int i = last+1; i < 16; i++)
        if (((used>>i)&1) == 0)
            gao2(now+1,used|(1<<i),i);
}

void gao4(int now,int used,int last)
{
    if (now == 8)
    {
        int a = used;
        int b = a^((1<<16)-1);
        res += tot[a]*tot[b];
        return;
    }
    for (int i = last+1; i < 16; i++)
        if (((used>>i)&1) == 0)
            gao4(now+1,used|(1<<i),i);
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    int ft = 1;
    while (true)
    {
        scanf("%d",&a[0]);
        if (a[0] == 0)  break;
        for (int i = 1; i < 16; i++)
            scanf("%d",&a[i]);
        memset(tt,0,sizeof(tt));
        gao(0,0);
        memset(tot,0,sizeof(tot));
        gao2(0,0,-1);
        res = 0;
        gao4(0,0,-1);
        printf("Case %d: %I64d\n",ft++,res);
    }
    return 0;
}