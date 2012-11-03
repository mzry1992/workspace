#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

struct node
{
    int h,s,n,cost;
    node() {}
    node(int _h,int _s,int _n)
    {
        h = _h;
        s = _s;
        n = _n;
    }
};
class cmp
{
public:
    bool operator ()(const node &i,const node &j)
    {
        return i.cost>j.cost;
    }
};

int lh,ls,n,d[101],dp[251][101][41];

int dijkstra()
{
    for (int i = 0; i <= lh; i++)
        for (int j = 0; j <= ls; j++)
            for (int k = 0; k <= n; k++)
                dp[i][j][k] = 199210050;
    dp[lh][0][n] = 0;
    node now,upd;
    now = node(lh,0,n);
    now.cost = 0;
    priority_queue<node,vector<node>,cmp> Q;
    Q.push(now);
    while (!Q.empty())
    {
        now = Q.top();
        Q.pop();
        if (now.h == 0) continue;
        if (now.n == 0) return dp[now.h][now.s][now.n];
        if (now.cost != dp[now.h][now.s][now.n]) continue;

        //Kill one enemy and get his SP increased by 1.
        upd = now;

        upd.n--;
        upd.s++;
        if (upd.s > ls) upd.s = ls;

        upd.h -= upd.n;
        if (upd.h < 0)  upd.h = 0;
        upd.s += upd.n%3;
        if (upd.s > ls) upd.s = ls;

        if (dp[upd.h][upd.s][upd.n] > dp[now.h][now.s][now.n]+1)
        {
            upd.cost = dp[upd.h][upd.s][upd.n] = dp[now.h][now.s][now.n]+1;
            Q.push(upd);
        }

        //Heal himself. Doraemon's HP will increase by floor(0.2*lh).
        upd = now;

        upd.h += floor(0.2*lh);
        if (upd.h > lh) upd.h = lh;

        upd.h -= upd.n;
        if (upd.h < 0)  upd.h = 0;
        upd.s += upd.n%3;
        if (upd.s > ls) upd.s = ls;

        if (dp[upd.h][upd.s][upd.n] > dp[now.h][now.s][now.n]+1)
        {
            upd.cost = dp[upd.h][upd.s][upd.n] = dp[now.h][now.s][now.n]+1;
            Q.push(upd);
        }

        //Use his skill if SP > 0. His skill will kill D[SP] enemies and reset his SP to 0.
        if (now.s > 0)
        {
            upd = now;

            upd.n -= d[upd.s];
            if (upd.n < 0)  upd.n = 0;
            upd.s = 0;

            upd.h -= upd.n;
            if (upd.h < 0)  upd.h = 0;
            upd.s += upd.n%3;
            if (upd.s > ls) upd.s = ls;

            if (dp[upd.h][upd.s][upd.n] > dp[now.h][now.s][now.n]+1)
            {
                upd.cost = dp[upd.h][upd.s][upd.n] = dp[now.h][now.s][now.n]+1;
                Q.push(upd);
            }
        }

        //Do nothing.
        upd = now;

        upd.h -= upd.n;
        if (upd.h < 0)  upd.h = 0;
        upd.s += upd.n%3;
        if (upd.s > ls) upd.s = ls;

        if (dp[upd.h][upd.s][upd.n] > dp[now.h][now.s][now.n]+1)
        {
            upd.cost = dp[upd.h][upd.s][upd.n] = dp[now.h][now.s][now.n]+1;
            Q.push(upd);
        }

    }
    return -1;
}

int main()
{
    while (scanf("%d%d%d",&lh,&ls,&n) != EOF)
    {
        for (int i = 1; i <= ls; i++)
            scanf("%d",&d[i]);
        int res = dijkstra();
        if (res == -1)
            puts("HELP!");
        else
            printf("%d\n",res);
    }
    return 0;
}
