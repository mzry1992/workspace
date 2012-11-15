#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
struct task
{
    int time,from,to;
    int f;//-1 - go down; 1 - go up;
    bool go;
}t[200];
struct cursta
{
    int pos,time,sta,go;//0 - stop; -1 - go down; 1 - go up;
    int nextstop;
    int f;
    int peo[200],totp;
    int leave;
}cur;

int getF(cur now)
{
    if (now.sta != 0)
        return now.sta;
    if (now.totp == )
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&cur.pos,&n);
        cur.sta = 0;
        cur.time = 0;
        cur.totp = 0;
        cur.nextstop = 0;
        cur.leave = n;
        cur.f = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%d%d%d",&t[i].time,&t[i].from,&t[i].to);
            t[i].go = false;
            if (t[i].to > t[i].from)
                t[i].f = 1;
            else
                t[i].f  = -1;
        }
        while (cur.leave)
        {
            int f = getF(cur);
        }
    }
}
