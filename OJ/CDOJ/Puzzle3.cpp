#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

char step[1<<24];
bool inq[1<<24];

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

void Gao()
{
    queue<int> Q;
    int sta = 0,now;
    for (int i = 1; i <= 4; i++)
        sta = setbit(1,setbit(1,sta,1,i),2,i);
    Q.push(sta);
    step[sta] = 0;
    inq[sta] = true;
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            sta = shiftrow0(now,i);
            if (inq[sta] == false)
            {
                step[sta] = step[now]+1;
                inq[sta] = true;
                Q.push(sta);
            }
            sta = shiftrow1(now,i);
            if (inq[sta] == false)
            {
                step[sta] = step[now]+1;
                inq[sta] = true;
                Q.push(sta);
            }
        }
        for (int i = 0; i < 6; i++)
        {
            sta = shiftcol0(now,i);
            if (inq[sta] == false)
            {
                step[sta] = step[now]+1;
                inq[sta] = true;
                Q.push(sta);
            }
            sta = shiftcol1(now,i);
            if (inq[sta] == false)
            {
                step[sta] = step[now]+1;
                inq[sta] = true;
                Q.push(sta);
            }
        }
    }
}

char mp[4][7];

int main()
{
    Gao();
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        for (int i = 0; i < 4; i++)
            scanf("%s",mp[i]);
        int sta,res = 19921005;
        sta = 0;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 6; j++)
                if (mp[i][j] == 'G')
                    sta = setbit(1,sta,i,j);
        res = min(res,(int)step[sta]);
        sta = 0;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 6; j++)
                if (mp[i][j] == 'W')
                    sta = setbit(1,sta,i,j);
        res = min(res,(int)step[sta]);
        sta = 0;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 6; j++)
                if (mp[i][j] == 'B')
                    sta = setbit(1,sta,i,j);
        res = min(res,(int)step[sta]);
        printf("Case %d: %d\n",ft,res);
    }
    return 0;
}
