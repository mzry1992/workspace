#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

struct node
{
    friend bool operator < (node a,node b)
    {
        if (a.f == b.f)
            return a.step > b.step;
        return a.f > b.f;
    }
    int p[4][2],step,curmin,f;
};

int n,m,ex,ey,p[4][2];
char mp[8][8];

priority_queue<node> Q;
node now,updata,tmp;

inline bool checkin(int x,int y)
{
    if (x < 0 || x >= n || y < 0 || y >= n) return false;
    return true;
}

inline int Abs(int x)
{
    return (x > 0)?(x):(-x);
}

inline bool check(node cur)
{
    for (int i = cur.curmin; i < m; i++)
        for (int j = i+1; j < m; j++)
            if (Abs(cur.p[j][0]-cur.p[i][0])+Abs(cur.p[j][1]-cur.p[i][1]) == 1)
                return false;
    return true;
}

inline int calchash(node cur)
{
    int res = 0;
    for (int i = cur.curmin; i < m; i++)
    {
        res = res*n+cur.p[i][0];
        res = res*n+cur.p[i][1];
    }
    return res;
}

bool visit[4][6*6*6*6*6*6*6*6];

int Gao()
{
    while (!Q.empty())  Q.pop();
    for (int i = 0; i < m; i++)
    {
        tmp.p[i][0] = p[i][0];
        tmp.p[i][1] = p[i][1];
    }
    tmp.step = 0;
    tmp.curmin = 0;
    Q.push(tmp);
    memset(visit,false,sizeof(visit));
    visit[tmp.curmin][calchash(tmp)] = true;
    while (!Q.empty())
    {
        now = Q.top();
        Q.pop();
        if (now.p[now.curmin][0] == ex && now.p[now.curmin][1] == ey)
        {
            now.curmin++;
            if (now.curmin == m)
                return now.step;
        }
        for (int i = now.curmin; i < m; i++)
            for (int k = 0; k < 4; k++)
                if (checkin(now.p[i][0]+step[k][0],now.p[i][1]+step[k][1]) == true)
                {
                    for (int j = now.curmin;j < m;j++)
                    {
                        updata.p[j][0] = now.p[j][0];
                        updata.p[j][1] = now.p[j][1];
                    }
                    updata.p[i][0] += step[k][0];
                    updata.p[i][1] += step[k][1];
                    updata.step = now.step+1;
                    updata.curmin = now.curmin;
                    if (check(updata) == true)
                        if (visit[updata.curmin][calchash(updata)] == false)
                        {
                            visit[updata.curmin][calchash(updata)] = true;
                            updata.f = updata.step;
                            for (int j = updata.curmin; j < m; j++)
                                updata.f += Abs(updata.p[j][0]-ex)+Abs(updata.p[j][1]-ey);
                            Q.push(updata);
                        }
                }
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0; i < n; i++)
            scanf("%s",mp[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (mp[i][j] == 'x')
                {
                    ex = i;
                    ey = j;
                }
                else if (mp[i][j] >= '1' && mp[i][j] <= '4')
                {
                    p[mp[i][j]-'1'][0] = i;
                    p[mp[i][j]-'1'][1] = j;
                }
        printf("%d\n",Gao());
    }
    return 0;
}
