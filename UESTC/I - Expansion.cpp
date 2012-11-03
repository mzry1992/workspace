#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,tim;
struct Rect
{
    int x0,y0,x1,y1;
};
Rect r[100],ta,tb;
char s[100][100010];

void gao(Rect& a,char f)
{
    if (f == 'L')
        a.x0--;
    else if (f == 'R')
        a.x1++;
    else if (f == 'U')
        a.y1++;
    else
        a.y0--;
}

bool ji(Rect a,Rect b)
{
    if (a.x0 >= b.x1)   return false;
    if (b.x0 >= a.x1)   return false;
    if (a.y0 >= b.y1)   return false;
    if (b.y0 >= a.y1)   return false;
    return true;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&tim);
        for (int i = 0;i < n;i++)
        {
            scanf("%d%d%d%d",&r[i].x0,&r[i].y0,&r[i].x1,&r[i].y1);
            scanf("%s",s[i]);
        }
        int res = 19921005;
        for (int i = 0;i < n;i++)
            for (int j = i+1;j < n;j++)
            {
                if (ji(r[i],r[j]) == true)
                {
                    res = 0;
                    continue;
                }
                ta = r[i];
                tb = r[j];
                for (int now = 1;now <= tim;now++)
                {
                    if (now >= res) break;
                    gao(r[i],s[i][now-1]);
                    gao(r[j],s[j][now-1]);
                    if (ji(r[i],r[j]) == true)
                    {
                        res = now;
                        break;
                    }
                }
                r[i] = ta;
                r[j] = tb;
            }
        if (res == 19921005)    res = -1;
        printf("%d\n",res);
    }
    return 0;
}
