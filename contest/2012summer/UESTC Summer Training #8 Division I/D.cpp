#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Point
{
    int x,y,id;
};

bool vis[200000];
Point p[300000];
int n,m;
int flag[2000100];

bool cmpx(const Point& a,const Point& b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

bool cmpy(const Point& a,const Point& b)
{
    if (a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0;i < n;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            p[i].y += 1000000;
            p[i].x += 1000000;
            p[i].id = i+1;
            vis[i] = false;
        }
        int tn = n;
        for (int i = 0;i < m;i++)
        {
            char typ;
            int pos;
            scanf(" %c%d",&typ,&pos);
            if (typ == 'H')
            {
                p[n].y = pos+1000000;
                p[n++].x = -1;
            }
            else
            {
                p[n].x = pos+1000000;
                p[n++].y = -1;
            }
        }
        sort(p,p+n,cmpx);
        queue<int> Q;
        bool flag2 = true;
        memset(flag,-1,sizeof(flag));
        for (int i = 0;i < n;i++)
            if (p[i].x != -1)
            {
                //printf("first : %d %d %d\n",p[i].x,p[i].y,p[i].id);

                if (p[i].y == -1)
                {
                    while (!Q.empty())
                    {
                        int now = Q.front();
                        vis[flag[now]] = true;
                        flag[now] = 0;
                        Q.pop();
                    }
                    if (flag2 == true)
                        memset(flag,0,sizeof(flag));
                    flag2 = false;
                }
                else
                {
                    if (flag[p[i].y] <= 0)
                        Q.push(p[i].y);
                    if (flag[p[i].y] == 0)
                        vis[p[i].id] = true;
                    flag[p[i].y] = p[i].id;
                }
            }
        /*or (int i = 1;i <= tn;i++)
            if (vis[i] == true)
                printf("%d ",i);
        printf("\n");
        memset(vis,false,sizeof(vis));*/

        sort(p,p+n,cmpy);
        while (!Q.empty())  Q.pop();
        flag2 = true;
        for (int i = 0;i < n;i++)
            if (p[i].y != -1)
            {
                if (p[i].x == -1)
                {
                    while (!Q.empty())
                    {
                        int now = Q.front();
                        vis[flag[now]] = true;
                        flag[now] = 0;
                        Q.pop();
                    }
                    if (flag2 == true)
                        memset(flag,0,sizeof(flag));
                    flag2 = false;
                }
                else
                {
                    if (flag[p[i].x] <= 0)
                        Q.push(p[i].x);
                    if (flag[p[i].x] == 0)
                        vis[p[i].id] = true;
                    flag[p[i].x] = p[i].id;
                }
            }
        int cnt = 0;
        for (int i = 1;i <= tn;i++)
            if (vis[i])
            {
                //printf("%d ",i);
                cnt++;
            }
        //printf("\n");

        if (cnt*10 >= tn*6)
            puts("PASSED");
        else
            puts("FAILED");
    }
	return 0;
}
