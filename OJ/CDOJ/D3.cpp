#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int step[4][2] = {{-1,0},{0,1},{0,-1},{1,0}};
struct node
{
    int p[4][2],step,curmin;
};

int n,m,ex,ey,p[4][2];
char mp[8][8];

node Q[2][2000010];
int head[2],tail[2];
node now,updata,tmp;

bool checkin(int x,int y)
{
    if (x < 0 || x >= n || y < 0 || y >= n) return false;
    return true;
}

inline int Abs(int x)
{
    return (x > 0)?(x):(-x);
}

bool check(node cur)
{
    for (int i = cur.curmin; i < m; i++)
        for (int j = i+1; j < m; j++)
            if (Abs(cur.p[j][0]-cur.p[i][0])+Abs(cur.p[j][1]-cur.p[i][1]) == 1)
                return false;
    return true;
}

int calchash(node cur)
{
    int res = 0;
    for (int i = 0; i < m; i++)
    {
        res = res*n+cur.p[i][0];
        res = res*n+cur.p[i][1];
    }
    return res;
}

int visit[2][6*6*6*6*6*6*6*6];
int co;

int Gao()
{
    head[0] = head[1] = tail[0] = tail[1] = 0;
    memset(visit,-1,sizeof(visit));
    for (int i = 0; i < m; i++)
    {
        tmp.p[i][0] = p[i][0];
        tmp.p[i][1] = p[i][1];
    }
    tmp.step = 0;
    tmp.curmin = 0;
    visit[0][calchash(tmp)] = 0;
    Q[0][tail[0]++] = tmp;
    for (int i = 0; i < m; i++)
    {
        tmp.p[i][0] = ex;
        tmp.p[i][1] = ey;
    }
    tmp.step = 0;
    tmp.curmin = m;
    visit[1][calchash(tmp)] = 0;
    Q[1][tail[1]++] = tmp;
    co = 0;
    while ((head[0] < tail[0]) && (head[1] < tail[1]))
    {
        co++;
        now = Q[0][head[0]++];
        if (now.p[now.curmin][0] == ex && now.p[now.curmin][1] == ey)
            now.curmin++;
        int sta = calchash(now);
        if (visit[1][sta] > -1)
            return now.step+visit[1][sta];
        for (int i = now.curmin; i < m; i++)
            for (int k = 0; k < 4; k++)
                if (checkin(now.p[i][0]+step[k][0],now.p[i][1]+step[k][1]) == true)
                {
                    for (int j = 0; j < m; j++)
                    {
                        updata.p[j][0] = now.p[j][0];
                        updata.p[j][1] = now.p[j][1];
                    }
                    updata.step = now.step+1;
                    updata.curmin = now.curmin;
                    updata.p[i][0] += step[k][0];
                    updata.p[i][1] += step[k][1];
                    sta = calchash(updata);
                    if (visit[0][sta] == -1)
                        if (check(updata) == true)
                        {
                            visit[0][sta] = updata.step;
                            Q[0][tail[0]++] = updata;
                        }
                        else
                            visit[0][sta] = -2;
                }
        now = Q[1][head[1]++];
        sta = calchash(now);
        if (visit[0][sta] > -1)
            return now.step+visit[0][sta];
        for (int i = now.curmin; i < m; i++)
            for (int k = 0; k < 4; k++)
                if (checkin(now.p[i][0]+step[k][0],now.p[i][1]+step[k][1]) == true)
                {
                    for (int j = 0; j < m; j++)
                    {
                        updata.p[j][0] = now.p[j][0];
                        updata.p[j][1] = now.p[j][1];
                    }
                    updata.step = now.step+1;
                    updata.curmin = now.curmin;
                    updata.p[i][0] += step[k][0];
                    updata.p[i][1] += step[k][1];
                    sta = calchash(updata);
                    if (visit[1][sta] == -1)
                        if (check(updata) == true)
                        {
                            visit[1][sta] = updata.step;
                            Q[1][tail[1]++] = updata;
                        }
                        else
                            visit[1][sta] = -2;
                }
        if (now.curmin > 0)
        {
            bool flag = true;
            for (int i = now.curmin; i < m; i++)
                if (Abs(now.p[i][0]-ex)+Abs(now.p[i][1]-ey) == 1)
                {
                    flag = false;
                    break;
                }
            if (flag == true)
            {
                for (int k = 0; k < 4; k++)
                    if (checkin(now.p[now.curmin-1][0]+step[k][0],now.p[now.curmin-1][1]+step[k][1]) == true)
                    {
                        for (int j = 0; j < m; j++)
                        {
                            updata.p[j][0] = now.p[j][0];
                            updata.p[j][1] = now.p[j][1];
                        }
                        updata.step = now.step+1;
                        updata.curmin = now.curmin-1;
                        updata.p[now.curmin-1][0] += step[k][0];
                        updata.p[now.curmin-1][1] += step[k][1];
                        sta = calchash(updata);
                        if (visit[1][sta] == -1)
                            if (check(updata) == true)
                            {
                                visit[1][sta] = updata.step;
                                Q[1][tail[1]++] = updata;
                            }
                            else
                                visit[1][sta] = -2;
                    }
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
        //cout << co << endl;
    }
    return 0;
}
