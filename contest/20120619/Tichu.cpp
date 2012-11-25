#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct cards
{
    int v;
    char cv,s;
    bool operator < (const cards& b)const
    {
        return v < b.v;
    }
}a[13],b[13];
char buf[3];
int cnt;

void split(int sta)
{
    cnt = 0;
    for (int i = 0;i < 13;i++)
        if (((sta>>i)&1) == 1)
            b[cnt++] = a[i];
}

bool issingle()
{
    return cnt == 1;
}

bool ispair()
{
    return cnt == 2 && b[0].v == b[1].v;
}

bool isthree()
{
    return cnt == 3 && b[0].v == b[1].v && b[0].v == b[2].v;
}

bool isfour()
{
    return cnt == 4 && b[0].v == b[1].v && b[0].v == b[2].v && b[0].v == b[3].v;
}

bool isfullhouse()
{
    return cnt == 5 && b[0].v == b[1].v && b[3].v == b[4].v && (b[2].v == b[1].v || b[2].v == b[3].v);
}

bool isstraight()
{
    if (cnt < 5)    return false;
    for (int i = 1;i < cnt;i++)
        if (b[i].v != b[i-1].v+1) return false;
    return true;
}

bool can[1<<13];
int dp[1<<13],pre[1<<13],use[1<<13];

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    for (int i = 0;i < 13;i++)
	    {
            scanf("%s",buf);
            a[i].cv = buf[0];
            a[i].s = buf[1];
            if (buf[0] == 'A')      a[i].v = 14;
            else if (buf[0] == 'K') a[i].v = 13;
            else if (buf[0] == 'Q') a[i].v = 12;
            else if (buf[0] == 'J') a[i].v = 11;
            else if (buf[0] == 'T') a[i].v = 10;
            else                    a[i].v = buf[0]-'0';
	    }
        sort(a,a+13);
        memset(can,false,sizeof(can));
        for (int sta = 1;sta < 1<<13;sta++)
        {
            split(sta);
            can[sta] = issingle()||ispair()||isthree()||isfour()||isfullhouse()||isstraight();
        }
        memset(dp,-1,sizeof(dp));
        dp[0] = 0;
        for (int sta = 0;sta < 1<<13;sta++)
            if (dp[sta] != -1)
            {
                int nsta = (~sta)&((1<<13)-1);
                for (int i = nsta;i;i = (i-1)&nsta)
                    if (can[i] == true)
                    {
                        if (dp[sta|i] == -1 || dp[sta|i] > dp[sta]+1)
                        {
                            dp[sta|i] = dp[sta]+1;
                            pre[sta|i] = sta;
                            use[sta|i] = i;
                        }
                    }
            }
        printf("%d\n",dp[(1<<13)-1]);
        for (int now = (1<<13)-1;now;now = pre[now])
        {
            split(use[now]);
            for (int i = 0;i+1 < cnt;i++)
                printf("%c%c ",b[i].cv,b[i].s);
            printf("%c%c\n",b[cnt-1].cv,b[cnt-1].s);
        }
    }
	return 0;
}
