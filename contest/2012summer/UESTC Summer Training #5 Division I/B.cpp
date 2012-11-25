#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int lc,fail[70];
int nxt[70][2][2][70][4];
bool dp[70][2][2][70],flag[70][2][2][70];
bool sa[70],sb[70],sc[70],tsc[70];
long long a,b,p;

bool DP(int pos,int u,int d,int ppos)
{
    if (pos == 60)
        return ppos == lc;
    if (flag[pos][u][d][ppos])  return dp[pos][u][d][ppos];
    flag[pos][u][d][ppos] = true;
    int op = 0,ed = 1;
    if (u == 1) ed = sb[pos];
    if (d == 1) op = sa[pos];
    int nu,nd,nppos;
    for (int i = op; i <= ed; i++)
    {
        nd = nu = 0;
        if (u == 1 && i == ed)  nu = 1;
        if (d == 1 && i == op)  nd = 1;
        nppos = ppos;
        if (ppos < lc)
        {
            if (sc[ppos] == i)  nppos++;
            else
                nppos = fail[ppos];
        }
        if (DP(pos+1,nu,nd,nppos) == true)
        {
            nxt[pos][u][d][ppos][0] = nu;
            nxt[pos][u][d][ppos][1] = nd;
            nxt[pos][u][d][ppos][2] = nppos;
            nxt[pos][u][d][ppos][3] = i;
            dp[pos][u][d][ppos] = true;
            return true;
        }
    }
    dp[pos][u][d][ppos] = false;
    return false;
}

bool check(int op,int ed)
{
    for (int i = op; i <= ed; i++)
        if (tsc[i] != sc[i-op])  return false;
    return true;
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%lld%lld%lld",&a,&b,&p);
        for (int i = 59; i >= 0; i--)
        {
            sa[i] = a%2;
            a /= 2;
            sb[i] = b%2;
            b /= 2;
        }
        lc = 0;
        while (p)
        {
            sc[lc++] = p%2;
            p /= 2;
        }
        reverse(sc,sc+lc);

        //for (int i = 0;i < lc;i++)
        //    printf("%d",sc[i]);
        //printf("\n");

        fail[0] = 0;
        for (int i = 1; i < lc; i++)
        {
            for (int j = 0; j <= i; j++)
                tsc[j] = sc[j];
            tsc[i] = 1-tsc[i];
            //for (int j = 0;j <= i;j++)
            //    printf("%d",tsc[j]);
            //printf("\n");
            fail[i] = 0;
            for (int j = 0; j <= i; j++)
                if (check(j,i) == true)
                {
                    fail[i] = i-j+1;
                    break;
                }
        }

        memset(flag,false,sizeof(flag));
        printf("Case %d: ",cas);
        if (DP(0,1,1,0) == true)
        {
            int pos,u,d,ppos;
            int npos,nu,nd,nppos;
            pos = 0;
            u = 1;
            d = 1;
            ppos = 0;
            long long res = 0;
            while (true)
            {
                res = res*2+nxt[pos][u][d][ppos][3];
                npos = pos+1;
                nu = nxt[pos][u][d][ppos][0];
                nd = nxt[pos][u][d][ppos][1];
                nppos = nxt[pos][u][d][ppos][2];
                pos = npos;
                u = nu;
                d = nd;
                ppos = nppos;
                if (pos == 60)  break;
            }
            printf("%lld\n",res);
        }
        else
            puts("NONE");
    }
    return 0;
}
