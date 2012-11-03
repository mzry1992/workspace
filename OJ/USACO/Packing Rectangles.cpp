/*
ID: muziriy3
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX(X,Y) (X>Y?X:Y)
#define MIN(X,Y) (X>Y?Y:X)
using namespace std;

struct rec
{
    int x,y;
}r[4],tr[4],res[200];
int mins,tots;
const int pl[24][4] =   {
                            {0,1,2,3},{0,1,3,2},{0,2,1,3},{0,2,3,1},{0,3,1,2},{0,3,2,1},
                            {1,0,2,3},{1,0,3,2},{1,2,0,3},{1,2,3,0},{1,3,0,2},{1,3,2,0},
                            {2,0,1,3},{2,0,3,1},{2,1,0,3},{2,1,3,0},{2,3,0,1},{2,3,1,0},
                            {3,0,1,2},{3,0,2,1},{3,1,0,2},{3,1,2,0},{3,2,0,1},{3,2,1,0}
                        };
bool cmp(rec a,rec b)
{
    return (a.x < b.x);
}

void updata(int tx,int ty)
{
    int ts = tx*ty;
    if (ts < mins)
    {
        mins = ts;
        tots = 1;
        res[0].x = MIN(tx,ty);
        res[0].y = MAX(tx,ty);
    }
    else if (ts == mins)
    {
        bool flag;
        flag = true;
        for (int i = 0;i < tots;i++)
        if (res[i].x == MIN(tx,ty))
        if (res[i].y == MAX(tx,ty))
        {
            flag = false;
            break;
        }
        if (flag == true)
        {
            res[tots].x = MIN(tx,ty);
            res[tots].y = MAX(tx,ty);
            tots++;
        }
    }
}

int main()
{
    freopen("packrec.in","r",stdin);
    freopen("packrec.out","w",stdout);
    for (int i = 0;i < 4;i++)
        scanf("%d%d",&r[i].x,&r[i].y);
    mins = 19921005;
    tots = 0;
    for (int a0 = 0;a0 <= 1;a0++)
    for (int a1 = 0;a1 <= 1;a1++)
    for (int a2 = 0;a2 <= 1;a2++)
    for (int a3 = 0;a3 <= 1;a3++)
    for (int p = 0;p < 24;p++)
    {
        if (a0 == 0)    tr[0].x = r[pl[p][0]].x,tr[0].y = r[pl[p][0]].y;
        else            tr[0].x = r[pl[p][0]].y,tr[0].y = r[pl[p][0]].x;
        if (a1 == 0)    tr[1].x = r[pl[p][1]].x,tr[1].y = r[pl[p][1]].y;
        else            tr[1].x = r[pl[p][1]].y,tr[1].y = r[pl[p][1]].x;
        if (a2 == 0)    tr[2].x = r[pl[p][2]].x,tr[2].y = r[pl[p][2]].y;
        else            tr[2].x = r[pl[p][2]].y,tr[2].y = r[pl[p][2]].x;
        if (a3 == 0)    tr[3].x = r[pl[p][3]].x,tr[3].y = r[pl[p][3]].y;
        else            tr[3].x = r[pl[p][3]].y,tr[3].y = r[pl[p][3]].x;
        int tx,ty;
        tx = tr[0].x+tr[1].x+tr[2].x+tr[3].x;
        ty = MAX(tr[0].y,MAX(tr[1].y,MAX(tr[2].y,tr[3].y)));
        updata(tx,ty);
        tx = MAX(tr[0].x,tr[1].x+tr[2].x+tr[3].x);
        ty = tr[0].y+MAX(tr[1].y,MAX(tr[2].y,tr[3].y));
        updata(tx,ty);
        tx = MAX(tr[0].x,tr[2].x+tr[3].x)+tr[1].x;
        ty = tr[0].y+MAX(tr[1].y-tr[0].y,MAX(tr[2].y,tr[3].y));
        updata(tx,ty);
        tx = tr[0].x+MAX(tr[1].x,tr[2].x)+tr[3].x;
        ty = MAX(tr[0].y,MAX(tr[1].y+tr[2].y,tr[3].y));
        updata(tx,ty);
        tx = tr[2].x+tr[3].x;
        ty = MAX(tr[0].y+tr[3].y,tr[1].y+tr[2].y);
        if (tr[2].y > tr[3].y)
            tx = MAX(tx,tr[0].x+tr[2].x);
        if (tr[2].y < tr[0].y+tr[3].y)
            tx = MAX(tx,tr[0].x+tr[1].x);
        if (tr[2].y < tr[3].y)
            tx = MAX(tx,tr[1].x+tr[3].x);
        tx = MAX(MAX(tx,tr[0].x),tr[1].x);
        updata(tx,ty);
    }
    sort(res,res+tots,cmp);
    printf("%d\n",mins);
    for (int i = 0;i < tots;i++)
        printf("%d %d\n",res[i].x,res[i].y);
}
