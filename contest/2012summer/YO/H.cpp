#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int mark[4],tmark[4],pmark[4],cntbit[1<<16];
int win[5][10],tot[5],cov[4][16][4];
int n,m,a[4][16],res,len;

bool check(int msk,int spos)
{
    for (int j = spos; j < n; j++)
        tmark[j] = mark[j];
    for (int i = 0; i < m*m; i++)
        if (((msk>>i)&1) == 1)
            for (int j = spos; j < n; j++)
                tmark[j] |= cov[spos][i][j];
    bool prewin = true,nowwin;
    for (int i = spos; i < n; i++)
    {
        nowwin = false;
        for (int j = 0; j < tot[m]; j++)
            if ((tmark[i]&win[m][j]) == win[m][j])
                nowwin = true;
        if (nowwin == true && prewin == false)  return false;
        prewin = nowwin;
    }
    return true;
}

void cover(int msk,int spos)
{
    for (int i = 0; i < m*m; i++)
        if (((msk>>i)&1) == 1)
            for (int j = spos; j < n; j++)
                mark[j] |= cov[spos][i][j];
}

void uncover(int msk,int spos)
{
    for (int i = 0; i < m*m; i++)
        if (((msk>>i)&1) == 1)
            for (int j = spos; j < n; j++)
                mark[j] ^= cov[spos][i][j];
}

void DFS(int now)
{
    if (now == n)
    {
        if (res == 0)   res = len;
        else
            res = min(res,len);
    }
    else if (now == 0)
    {
        for (int i = 0; i < tot[m]; i++)
            if (check(win[m][i],now) == true)
            {
                len += cntbit[win[m][i]];
                cover(win[m][i],now);
                DFS(now+1);
                len -= cntbit[win[m][i]];
                uncover(win[m][i],now);
            }
    }
    else
    {
        for (int i = 0; i < tot[m]; i++)
            if ((mark[now]&win[m][i]) == win[m][i])
            {
                DFS(now+1);
                return;
            }
        for (int i = 0; i < tot[m]; i++)
        {
            int msk = (mark[now]&win[m][i])^win[m][i];
            if (check(msk,now) == true)
            {
                for (int j = 0; j < m*m; j++)
                    if (((msk>>j)&1) == 1)
                    {
                        int tmp = msk^(1<<j);
                        if (check(tmp,now) == true)
                        {
                            len += cntbit[msk];
                            cover(msk,now);
                            DFS(now+1);
                            len -= cntbit[msk];
                            uncover(msk,now);
                            break;
                        }
                    }
            }
            else if (now == 1 && n == 4)
            {
                for (int j = now; j < n; j++)
                    pmark[j] = mark[j];
                for (int j = 0; j < m*m; j++)
                    if (((msk>>j)&1) == 1)
                        for (int k = now; k < n; k++)
                            pmark[k] |= cov[now][j][k];
                for (int j = 0; j < tot[m]; j++)
                {
                    int tmsk = (pmark[now+1]&win[m][j])^win[m][j];
                    if (check(tmsk,now) == true)
                    {
                        len += cntbit[tmsk]+cntbit[msk];
                        cover(tmsk,now);
                        cover(msk,now);
                        DFS(now+2);
                        uncover(tmsk,now);
                        uncover(msk,now);
                        len -= cntbit[tmsk]+cntbit[msk];
                    }
                }
            }
        }
    }
}

int main()
{
    tot[3] = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            win[3][tot[3]] |= (1<<(i*3+j));
        tot[3]++;
    }
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
            win[3][tot[3]] |= (1<<(i*3+j));
        tot[3]++;
    }
    win[3][tot[3]++] = (1<<0)|(1<<4)|(1<<8);
    win[3][tot[3]++] = (1<<2)|(1<<4)|(1<<6);

    tot[4] = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            win[4][tot[4]] |= (1<<(i*4+j));
        tot[4]++;
    }
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
            win[4][tot[4]] |= (1<<(i*4+j));
        tot[4]++;
    }
    win[4][tot[4]++] = (1<<0)|(1<<5)|(1<<10)|(1<<15);
    win[4][tot[4]++] = (1<<3)|(1<<6)|(1<<9)|(1<<12);

    for (int i = 0; i < (1<<16); i++)
    {
        cntbit[i] = 0;
        for (int j = i; j; j^=j&-j)
            cntbit[i]++;
    }

    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m*m; j++)
                scanf("%d",&a[i][j]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m*m; j++)
                for (int k = 0; k < n; k++)
                {
                    cov[i][j][k] = 0;
                    for (int q = 0; q < m*m; q++)
                        if (a[k][q] == a[i][j])
                            cov[i][j][k] |= (1<<q);
                }
        memset(mark,0,sizeof(mark));
        res = len = 0;
        DFS(0);
        printf("%d\n",res);
    }
    return 0;
}
