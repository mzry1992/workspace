#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int n;
int s[20][20],t[20][20];
struct status
{
    int step;
    int now[20][20];
    int f;
    bool operator < (const status &temp) const
    {
        return f+step > temp.f+temp.step;
    }
};
priority_queue<status> Q;

status copyto(int step,int f,int now[20][20])
{
    status temp;
    temp.step = 0;
    temp.f = f;
    for (int i = 1;i <= n;i++)
    for (int j = 1;j <= 12;j++)
        temp.now[i][j] = now[i][j];
    return temp;
}

int calcf(int now[20][20])
{
    int res = 0;
    for (int i = 1;i <= n;i++)
    for (int j = 1;j <= 12;j++)
        if (now[i][j] != t[i][j])
            res++;
    return res;
}

status copyto2(status now,int x,int y,int ch)
{
    status temp = now;
    temp.step++;
    if (ch == 1)
    {
        int tt;
        tt = temp.now[x][y];
        temp.now[x][y] = temp.now[x][y+1];
        temp.now[x][y+1] = tt;
    }
    else
    {
        int tt;
        tt = temp.now[x][y];
        temp.now[x][y] = temp.now[x+1][y];
        temp.now[x+1][y] = tt;
    }
    temp.f = calcf(temp.now);
    return temp;
}

int BFS()
{
    while (!Q.empty())
        Q.pop();
    Q.push(copyto(0,calcf(s),s));
    while (!Q.empty())
    {
        status snow = Q.top();
        Q.pop();
        if (snow.f == 0)
            return snow.step;
        for (int i = 1;i < n;i++)
        for (int j = 1;j < 12;j++)
        {
            if (snow.now[i][j] != snow.now[i][j+1])
                Q.push(copyto2(snow,i,j,1));
            if (snow.now[i][j] != snow.now[i+1][j])
                Q.push(copyto2(snow,i,j,2));
        }
    }
    return 0;
}

int main()
{
    freopen("IDA能不能过这一题呢？这是个很复杂的问题~.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    while (true)
    {
        scanf("%d",&n);
        if (n == 0)
            break;
        memset(s,0,sizeof(s));
        memset(t,0,sizeof(t));
        int sums,sumt;
        sums = sumt = 0;
        for (int i = 1;i <= n;i++)
        {
            int ta;
            scanf("%d",&ta);
            for (int j = 1;j <= 12;j++)
            {
                s[i][j] = ta%2;
                ta /= 2;
                sums += s[i][j];
            }
        }
        for (int i = 1;i <= n;i++)
        {
            int ta;
            scanf("%d",&ta);
            for (int j = 1;j <= 12;j++)
            {
                t[i][j] = ta%2;
                ta /= 2;
                sumt += t[i][j];
            }
        }
        if (sums != sumt)
            printf("Impossible\n");
        else
            printf("%d\n",BFS());
    }
}
