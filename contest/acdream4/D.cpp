#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

struct Draw
{
    int typ;
    int a,b,c,d;
};
Draw d[110];
char buf[20];
int n,m,q;

struct Event
{
    int l,r;
    Event() {}
    Event(int _l,int _r)
    {
        l = max(0,_l);
        r = min(m-1,_r);
    }
    bool operator <(const Event& b)const
    {
        if (l == b.l)
            return r < b.r;
        return l < b.l;
    }
};
Event e[300];
int tote;

int main()
{
    while (scanf("%d%d%d",&n,&m,&q) != EOF)
    {
        for (int i = 0; i < q; i++)
        {
            scanf("%s%d%d%d",buf,&d[i].a,&d[i].b,&d[i].c);
            if (buf[0] == 'C')
                d[i].typ = 0;
            else if (buf[0] == 'D')
                d[i].typ = 1;
            else if (buf[0] == 'R')
            {
                d[i].typ = 2;
                scanf("%d",&d[i].d);
            }
            else
                d[i].typ = 3;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            tote = 0;
            for (int j = 0; j < q; j++)
            {
                if (d[j].typ == 0)
                {
                    if (abs(i-d[j].a) > d[j].c)
                        continue;
                    int dy = (int)sqrt(1.0*d[j].c*d[j].c-1.0*(i-d[j].a)*(i-d[j].a));
                    while (dy*dy+(i-d[j].a)*(i-d[j].a) > d[j].c*d[j].c)
                        dy--;
                    while ((dy+1)*(dy+1)+(i-d[j].a)*(i-d[j].a) <= d[j].c*d[j].c)
                        dy++;
                    e[tote++] = Event(d[j].b-dy,d[j].b+dy);
                }
                else if (d[j].typ == 1)
                {
                    if (abs(i-d[j].a) > d[j].c)
                        continue;
                    int dy = d[j].c-abs(i-d[j].a);
                    e[tote++] = Event(d[j].b-dy,d[j].b+dy);
                }
                else if (d[j].typ == 2)
                {
                    if (i < d[j].a || i > d[j].a+d[j].c-1)
                        continue;
                    e[tote++] = Event(d[j].b,d[j].b+d[j].d-1);
                }
                else
                {
                    if (i < d[j].a || i > d[j].a+(d[j].c+1)/2-1)
                        continue;
                    int dy = (d[j].c+1)/2-(i-d[j].a);
                    e[tote++] = Event(d[j].b-dy+1,d[j].b+dy-1);
                }
            }
            sort(e,e+tote);

            if (tote > 0)
            {
//                printf("No.%d : ",i);
//                for (int j = 0; j < tote; j++)
//                    printf("(%d ==> %d) ",e[j].l,e[j].r);
//                printf("\n");

                int nowl,nowr;
                nowl = e[0].l;
                nowr = e[0].r;
                for (int j = 1; j <= tote; j++)
                    if (j == tote || e[j].l > nowr)
                    {
                        ans += nowr-nowl+1;
                        nowl = e[j].l;
                        nowr = e[j].r;
                    }
                    else
                        nowr = max(nowr,e[j].r);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
