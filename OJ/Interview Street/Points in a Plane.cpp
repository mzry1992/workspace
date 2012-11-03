#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct Point
{
    int x,y;
    Point() {}
    Point(int _x,int _y)
    {
        x = _x;
        y = _y;
    }
    Point operator -(const Point& b)const
    {
        return Point(x-b.x,y-b.y);
    }
    int operator *(const Point& b)const
    {
        return x*b.y-y*b.x;
    }
};

int n;
Point p[16],tp[16];

bool check(int sta)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (((sta>>i)&1) == 1)
            tp[cnt++] = p[i];
    for (int i = 2; i < cnt; i++)
        if (((tp[i]-tp[0])*(tp[1]-tp[0])) != 0)
            return false;
    return true;
}

pair<int,int> dp[1<<16];
const int mod = 1000000007;

struct Edge
{
    int val,next;
}edge[43046721];
int head[1<<16],L;

void add(int u,int v)
{
    edge[L].val = v;
    edge[L].next = head[u];
    head[u] = L++;
}

bool can[1<<16];

int main()
{
    int totcas;
    //scanf("%d",&totcas);
    totcas = 50;
    for (int cas = 1; cas <= totcas; cas++)
    {
        //scanf("%d",&n);
        n = 16;
        for (int i = 0; i < n; i++)
            p[i].x = 0,p[i].y = i;
            //p[i].x = rand(),p[i].y = rand();
            //scanf("%d%d",&p[i].x,&p[i].y);
        for (int i = 0; i < (1<<n); i++)
            head[i] = -1;
        L = 0;

        for (int i = 1; i < (1<<n); i++)
        {
            can[i] = check(i);
            if (can[i])
            {
                add(i,i);
                int full=((1<<n)-1)^i;
                for (int j=full; j; j=(j-1)&full)
                    add(j^i,i);
            }
        }
        //cout << L << endl;

        dp[0] = make_pair(0,1);
        for (int i = 1; i < (1<<n); i++)
        {
            dp[i] = make_pair(100,0);
            if (can[i])
            {
                dp[i] = make_pair(1,1);
                continue;
            }
            int tot = 0;
            for (int k=head[i]; k != -1; k = edge[k].next)
            {
                int j=edge[k].val;
                if (dp[i^j].first+1 < dp[i].first)
                    dp[i] = make_pair(dp[i^j].first+1,dp[i^j].second);
                else if (dp[i^j].first+1 == dp[i].first)
                {
                    dp[i].second += dp[i^j].second;
                    if (dp[i].second >= mod)
                        dp[i].second -= mod;
                }
            }
        }
        printf("%d %d\n",dp[(1<<n)-1].first,dp[(1<<n)-1].second);
    }
    return 0;
}
