#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int n;
int s[20][20],t[20][20];
struct status
{
    int now[20][20];
    int g;
    int h;
}snow;
int IDAans;
const int step[2][2] = {{0,1},{1,0}};

int calcf(int now[20][20])
{
    int res = 0;
    for (int i = 1;i <= n;i++)
    for (int j = 1;j <= 12;j++)
        if (now[i][j] != t[i][j])
            res++;
    return res;
}

void DFS(int stepnow,int depth)
{
    if (snow.h == 0)
    {
        if (IDAans > stepnow)
            IDAans = stepnow;
        return;
    }
    if (stepnow > depth)
        return;
    for (int i = 1;i <= n;i++)
    for (int j = 1;j <= 12;j++)
    for (int k = 0;k < 2;k++)
    {
        int tx,ty;
        tx = i+step[k][0];
        ty = j+step[k][1];
        if (tx <= n && ty <= 12)
        if (snow.now[i][j] != snow.now[tx][ty])
        {
            int tg,th;
            tg = stepnow;
            th = snow.h;
            int temp = snow.now[i][j];
            snow.now[i][j] = snow.now[tx][ty];
            snow.now[tx][ty] = temp;
            int kh,kg;
            kh = calcf(snow.now);
            kg = stepnow+1;
            cout << kh << ' ' << kg << ' ' << depth << endl;
            if (kh+kg <= depth)
            {
                snow.g = kg;
                snow.h = kh;
                DFS(snow.g+1,depth);
            }
            snow.g = stepnow;
            snow.h = th;
            temp = snow.now[i][j];
            snow.now[i][j] = snow.now[tx][ty];
            snow.now[tx][ty] = temp;
        }
    }
}

int IDAstar()
{
    int depth = 0;

    while (true)
    {
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= 12;j++)
            snow.now[i][j] = s[i][j];
        snow.h = calcf(snow.now);
        snow.g = 0;
        IDAans = 19930703;
        DFS(0,depth);
        if (IDAans != 19930703)
            return IDAans;
        depth++;
    }
}

int main()
{
    //freopen("IDA能不能过这一题呢？这是个很复杂的问题~.txt","r",stdin);
    //freopen("out1.txt","w",stdout);
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
            printf("%d\n",IDAstar());
    }
}
