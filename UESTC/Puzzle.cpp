#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

inline int setbit(int val,int sta,int x,int y)
{
    if (val == 0)   return sta&~(1<<(6*x+y));
    else return sta|(1<<(6*x+y));
}

inline int getbit(int sta,int x,int y)
{
    return (sta>>(6*x+y))&1;
}

inline int shiftrow0(int sta,int row)
{
    int res = sta;
    for (int j = 0; j < 6; j++)
        res = setbit(getbit(sta,row,j),res,row,(j+5)%6);
    return res;
}

inline int shiftrow1(int sta,int row)
{

    int res = sta;
    for (int j = 0; j < 6; j++)
        res = setbit(getbit(sta,row,j),res,row,(j+1)%6);
    return res;
}

inline int shiftcol0(int sta,int col)
{
    int res = sta;
    for (int j = 0; j < 4; j++)
        res = setbit(getbit(sta,j,col),res,(j+3)%4,col);
    return res;
}

inline int shiftcol1(int sta,int col)
{

    int res = sta;
    for (int j = 0; j < 4; j++)
        res = setbit(getbit(sta,j,col),res,(j+1)%4,col);
    return res;
}

bool inq[1<<24];
char mp[4][7];
queue<pair<int,int> > Q;

int Gao()
{
    while (!Q.empty())  Q.pop();
    memset(inq,false,sizeof(inq));
    int now,sta,endsta,step;
    endsta = 0;
    for (int i = 1; i <= 4; i++)
        endsta = setbit(1,setbit(1,endsta,1,i),2,i);
    sta = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 6; j++)
            if (mp[i][j] == 'G')
                sta = setbit(1,sta,i,j);
    Q.push(make_pair(sta,0));
    inq[sta] = true;
    sta = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 6; j++)
            if (mp[i][j] == 'B')
                sta = setbit(1,sta,i,j);
    Q.push(make_pair(sta,0));
    inq[sta] = true;
    sta = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 6; j++)
            if (mp[i][j] == 'W')
                sta = setbit(1,sta,i,j);
    Q.push(make_pair(sta,0));
    inq[sta] = true;
    while (!Q.empty())
    {
        now = Q.front().first;
        step = Q.front().second;
        Q.pop();
        if (now == endsta)  return step;
        for (int i = 0; i < 4; i++)
        {
            sta = shiftrow0(now,i);
            if (inq[sta] == false)
            {
                inq[sta] = true;
                Q.push(make_pair(sta,step+1));
            }
            sta = shiftrow1(now,i);
            if (inq[sta] == false)
            {
                inq[sta] = true;
                Q.push(make_pair(sta,step+1));
            }
        }
        for (int i = 0; i < 6; i++)
        {
            sta = shiftcol0(now,i);
            if (inq[sta] == false)
            {
                inq[sta] = true;
                Q.push(make_pair(sta,step+1));
            }
            sta = shiftcol1(now,i);
            if (inq[sta] == false)
            {
                inq[sta] = true;
                Q.push(make_pair(sta,step+1));
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
        for (int i = 0; i < 4; i++)
            scanf("%s",mp[i]);
        printf("Case %d: %d\n",ft,Gao());
    }
    return 0;
}
