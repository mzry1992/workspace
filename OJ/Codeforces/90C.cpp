#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct subj
{
    long long a,b;
    int c,id;
    friend bool operator < (const subj& a,const subj& b)
    {
        if (a.c == b.c)
        {
            if (a.b == b.b)
                return a.a < b.a;
            return a.b < b.b;
        }
        return a.c < b.c;
    }
};

subj s[60];
int n,m,k;

//记得I64d
struct node
{
    int id,tot,k;
    node(){}
    node(int _id,int _tot,int _k)
    {
        id = _id;
        tot = _tot;
        k = _k;
    }
};

queue<node> Q;
node now;
long long dp[50][50][110],newval;
bool inq[50][50][110];
node pre[50][50][110];

void output(node now)
{
    if (now.tot > 1)
        output(pre[now.id][now.tot][now.k]);
    cout << s[now.id].id+1 << ' ' << s[now.id].a+now.k << endl;
}

int main()
{
    while (scanf("%d%d%d",&n,&m,&k) != EOF)
    {
        for (int i = 0;i < m;i++)
        {
            cin >> s[i].a >> s[i].b >> s[i].c;
            s[i].id = i;
        }
        sort(s,s+m);
        memset(dp,0,sizeof(dp));
        memset(inq,false,sizeof(inq));
        while (!Q.empty())  Q.pop();
        for (int i = 0;i < m;i++)
            for (int j = 0;j <= s[i].b-s[i].a;j++)
            {
                Q.push(node(i,1,j));
                dp[i][1][j] = s[i].a+j;
                inq[i][1][j] = true;
            }
        long long res = 0;
        node resnode;
        while (!Q.empty())
        {
            now = Q.front();
            Q.pop();
            inq[now.id][now.tot][now.k] = false;
            if (now.tot == n)
            {
                if (res < dp[now.id][now.tot][now.k])
                {
                    res = dp[now.id][now.tot][now.k];
                    resnode = now;
                }
                continue;
            }
            for (int i = now.id+1;i < m;i++)
                if (s[i].c > s[now.id].c)
                {
                    newval = (s[now.id].a+now.k)*k;
                    if (newval >= s[i].a && newval <= s[i].b)
                    {
                        if (dp[i][now.tot+1][newval-s[i].a] < dp[now.id][now.tot][now.k]+newval)
                        {
                            dp[i][now.tot+1][newval-s[i].a] = dp[now.id][now.tot][now.k]+newval;
                            pre[i][now.tot+1][newval-s[i].a] = now;
                            if (inq[i][now.tot+1][newval-s[i].a] == false)
                            {
                                inq[i][now.tot+1][newval-s[i].a] = true;
                                Q.push(node(i,now.tot+1,newval-s[i].a));
                            }
                        }
                    }
                    newval = (s[now.id].a+now.k)+k;
                    if (newval >= s[i].a && newval <= s[i].b)
                    {
                        if (dp[i][now.tot+1][newval-s[i].a] < dp[now.id][now.tot][now.k]+newval)
                        {
                            dp[i][now.tot+1][newval-s[i].a] = dp[now.id][now.tot][now.k]+newval;
                            pre[i][now.tot+1][newval-s[i].a] = now;
                            if (inq[i][now.tot+1][newval-s[i].a] == false)
                            {
                                inq[i][now.tot+1][newval-s[i].a] = true;
                                Q.push(node(i,now.tot+1,newval-s[i].a));
                            }
                        }
                    }
                }
        }
        if (res == 0)
            printf("NO\n");
        else
        {
            printf("YES\n");
            output(resnode);
        }
    }
    return 0;
}
