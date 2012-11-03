#include <iostream>
#include <cstdio>
using namespace std;

int n;
struct graph
{
    int x1,x2,y;
}g[110000];
int MH;
int dp[110000][2];

void qsort(int l,int r)
{
    int mid = (l+r)/2;
    int tl = l;
    int tr = r;
    do
    {
        while (g[tl].y > g[mid].y) tl++;
        while (g[tr].y < g[mid].y) tr--;
        if (tl <= tr)
        {
            graph temp = g[tl];
            g[tl] = g[tr];
            g[tr] = temp;
            tl++;
            tr--;
        }
    }while (tl <= tr);
    if (tl < r) qsort(tl,r);
    if (l < tr) qsort(l,tr);
}

int updata0(int now)
{
    int min = 1993070300;
    for (int i = now-1;i >= 1;i--)
    if (g[i].y-g[now].y <= MH)
    {
        if (g[i].y == g[now].y)
            continue;
        if ((g[now].x1 <= g[i].x1) && (g[i].x1 <= g[now].x2))
            if (dp[i][0]+g[i].x1-g[now].x1+g[i].y-g[now].y < min)
                min = dp[i][0]+g[i].x1-g[now].x1+g[i].y-g[now].y;
        if ((g[now].x1 <= g[i].x2) && (g[i].x2 <= g[now].x2))
            if (dp[i][1]+g[i].x1-g[now].x1+g[i].y-g[now].y < min)
                min = dp[i][1]+g[i].x2-g[now].x1+g[i].y-g[now].y;
    }
    else return min;
    return min;
}

int updata1(int now)
{
    int min = 1993070300;
    for (int i = now-1;i >= 1;i--)
    if (g[i].y-g[now].y <= MH)
    {
        if (g[i].y == g[now].y)
            continue;
        if ((g[now].x1 <= g[i].x1) && (g[i].x1 <= g[now].x2))
            if (dp[i][0]+g[now].x2-g[i].x1+g[i].y-g[now].y < min)
                min = dp[i][0]+g[now].x2-g[i].x1+g[i].y-g[now].y;
        if ((g[now].x1 <= g[i].x2) && (g[i].x2 <= g[now].x2))
            if (dp[i][1]+g[now].x2-g[i].x2+g[i].y-g[now].y < min)
                min = dp[i][1]+g[now].x2-g[i].x2+g[i].y-g[now].y;
    }
    else return min;
    return min;
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 1;i <= n;i++)
            scanf("%d%d%d",&g[i].x1,&g[i].x2,&g[i].y);
        scanf("%d",&MH);
        qsort(1,n);
        for (int i = 1;i <= n;i++)
            dp[i][0] = dp[i][1] = -1;
        dp[1][0] = 0;
        dp[1][1] = (g[1].x2-g[1].x1);
        for (int i = 2;i <= n;i++)
        {
            dp[i][0] = updata0(i);
            dp[i][1] = updata1(i);
        }
        int min = 1993070300;
        for (int i = n;i >= 1;i--)
        if (g[i].y <= MH)
        {
            bool f1,f2;
            f1 = f2 = true;
            for (int j = i+1;j <= n;j++)
            {
                if ((g[j].x1 <= g[i].x1) && (g[i].x1 <= g[j].x2))
                    f1 = false;
                if ((g[j].x1 <= g[i].x2) && (g[i].x2 <= g[j].x2))
                    f2 = false;
            }
            if (f1)
                if (dp[i][0]+g[i].y < min)
                    min = dp[i][0]+g[i].y;
            if (f2)
                if (dp[i][1]+g[i].y < min)
                    min = dp[i][1]+g[i].y;
        }
        else
            break;
        if (min == 1993070300)
            printf("TP\n");
        else
            printf("%d\n",min);
    }
}
