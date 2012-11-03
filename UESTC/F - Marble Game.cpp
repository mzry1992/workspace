#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <queue>
using namespace std;

int n,m,w;
set<string> hash;
string s;
int xj[10][2];
int g[5][5];
set<string>::iterator it;
struct sta
{
    string now;
    int step;
    int leav;
    bool operator < (const sta &a) const
    {
        //if (a.leav == leav)
            return step < a.step;
        //return leav < a.leav;
    }
};
priority_queue<sta> Q;

sta getsta(string now,int step,int leav)
{
    sta res;
    res.now = now;
    res.step = step;
    res.leav = leav;
    return res;
}

sta turnleft(sta now)
{
    sta res;
    res.step = now.step+1;
    res.now = now.now;
    int tg[10][10];
    memset(tg,0,sizeof(tg));
    for (int i = 1;i <= m;i++)
    if (res.now[2*(i-1)] != '4')
    {
        tg[res.now[2*(i-1)]-'0'][res.now[2*(i-1)+1]-'0'] = i;
        tg[xj[i][0]][xj[i][1]] = -i;
    }
    while (true)
    {
        bool move = false;
        for (int i = 0;i < n;i++)
        for (int j = 1;j < n;j++)
        if (tg[i][j] > 0)
        if ((g[i][j]&1) == 0)
        {
            if (tg[i][j-1] == 0)
            {
                tg[i][j-1] = tg[i][j];
                tg[i][j] = 0;
                move = true;
            }
            else if (tg[i][j-1] < 0)
            {
                if (tg[i][j-1]+tg[i][j] == 0)
                {
                    tg[i][j-1] = tg[i][j] = 0;
                    move = true;
                }
                else
                {
                    res.step = -1;
                    return res;
                }
            }
        }
        if (move == false)  break;
    }
    for (int i = 1;i <= m;i++)
        res.now[2*(i-1)] = res.now[2*(i-1)+1] = '4';
    res.leav = 0;
    for (int i = 0;i < n;i++)
    for (int j = 0;j < n;j++)
    if (tg[i][j] > 0)
    {
        res.leav++;
        res.now[2*(tg[i][j]-1)] = (char)(i+'0');
        res.now[2*(tg[i][j]-1)+1] = (char)(j+'0');
    }
    return res;
}

sta turnright(sta now)
{
    sta res;
    res.step = now.step+1;
    res.now = now.now;
    int tg[10][10];
    memset(tg,0,sizeof(tg));
    for (int i = 1;i <= m;i++)
    if (res.now[2*(i-1)] != '4')
    {
        tg[res.now[2*(i-1)]-'0'][res.now[2*(i-1)+1]-'0'] = i;
        tg[xj[i][0]][xj[i][1]] = -i;
    }
    while (true)
    {
        bool move = false;
        for (int i = 0;i < n;i++)
        for (int j = n-2;j >= 0;j--)
        if (tg[i][j] > 0)
        if (((g[i][j]>>2)&1) == 0)
        {
            if (tg[i][j+1] == 0)
            {
                tg[i][j+1] = tg[i][j];
                tg[i][j] = 0;
                move = true;
            }
            else if (tg[i][j+1] < 0)
            {
                if (tg[i][j+1]+tg[i][j] == 0)
                {
                    tg[i][j+1] = tg[i][j] = 0;
                    move = true;
                }
                else
                {
                    res.step = -1;
                    return res;
                }
            }
        }
        if (move == false)  break;
    }
    for (int i = 1;i <= m;i++)
        res.now[2*(i-1)] = res.now[2*(i-1)+1] = '4';
    res.leav = 0;
    for (int i = 0;i < n;i++)
    for (int j = 0;j < n;j++)
    if (tg[i][j] > 0)
    {
        res.leav++;
        res.now[2*(tg[i][j]-1)] = (char)(i+'0');
        res.now[2*(tg[i][j]-1)+1] = (char)(j+'0');
    }
    return res;
}

sta turnup(sta now)
{
    sta res;
    res.step = now.step+1;
    res.now = now.now;
    int tg[10][10];
    memset(tg,0,sizeof(tg));
    for (int i = 1;i <= m;i++)
    if (res.now[2*(i-1)] != '4')
    {
        tg[res.now[2*(i-1)]-'0'][res.now[2*(i-1)+1]-'0'] = i;
        tg[xj[i][0]][xj[i][1]] = -i;
    }
    while (true)
    {
        bool move = false;
        for (int i = 1;i < n;i++)
        for (int j = 0;j < n;j++)
        if (tg[i][j] > 0)
        if (((g[i][j]>>1)&1) == 0)
        {
            if (tg[i-1][j] == 0)
            {
                tg[i-1][j] = tg[i][j];
                tg[i][j] = 0;
                move = true;
            }
            else if (tg[i-1][j] < 0)
            {
                if (tg[i-1][j]+tg[i][j] == 0)
                {
                    tg[i-1][j] = tg[i][j] = 0;
                    move = true;
                }
                else
                {
                    res.step = -1;
                    return res;
                }
            }
        }
        if (move == false)  break;
    }
    for (int i = 1;i <= m;i++)
        res.now[2*(i-1)] = res.now[2*(i-1)+1] = '4';
    res.leav = 0;
    for (int i = 0;i < n;i++)
    for (int j = 0;j < n;j++)
    if (tg[i][j] > 0)
    {
        res.leav++;
        res.now[2*(tg[i][j]-1)] = (char)(i+'0');
        res.now[2*(tg[i][j]-1)+1] = (char)(j+'0');
    }
    return res;
}

sta turndown(sta now)
{
    sta res;
    res.step = now.step+1;
    res.now = now.now;
    int tg[10][10];
    memset(tg,0,sizeof(tg));
    for (int i = 1;i <= m;i++)
    if (res.now[2*(i-1)] != '4')
    {
        tg[res.now[2*(i-1)]-'0'][res.now[2*(i-1)+1]-'0'] = i;
        tg[xj[i][0]][xj[i][1]] = -i;
    }
    while (true)
    {
        bool move = false;
        for (int i = n-2;i >= 0;i--)
        for (int j = 0;j < n;j++)
        if (tg[i][j] > 0)
        if (((g[i][j]>>3)&1) == 0)
        {
            if (tg[i+1][j] == 0)
            {
                tg[i+1][j] = tg[i][j];
                tg[i][j] = 0;
                move = true;
            }
            else if (tg[i+1][j] < 0)
            {
                if (tg[i+1][j]+tg[i][j] == 0)
                {
                    tg[i+1][j] = tg[i][j] = 0;
                    move = true;
                }
                else
                {
                    res.step = -1;
                    return res;
                }
            }
        }
        if (move == false)  break;
    }
    for (int i = 1;i <= m;i++)
        res.now[2*(i-1)] = res.now[2*(i-1)+1] = '4';
    res.leav = 0;
    for (int i = 0;i < n;i++)
    for (int j = 0;j < n;j++)
    if (tg[i][j] > 0)
    {
        res.leav++;
        res.now[2*(tg[i][j]-1)] = (char)(i+'0');
        res.now[2*(tg[i][j]-1)+1] = (char)(j+'0');
    }
    return res;
}

int BFS(int tleav)
{
    hash.clear();
    hash.insert(s);
    while (!Q.empty())
        Q.pop();
    Q.push(getsta(s,0,tleav));
    sta now,updata;
    while (!Q.empty())
    {
        now = Q.top();
        Q.pop();
        if (now.leav == 0)  return now.step;
        updata = turnleft(now);
        if (updata.step != -1)
        {
            it = hash.find(updata.now);
            if (it == hash.end())
            {
                hash.insert(updata.now);
                Q.push(updata);
            }
        }
        updata = turnright(now);
        if (updata.step != -1)
        {
            it = hash.find(updata.now);
            if (it == hash.end())
            {
                hash.insert(updata.now);
                Q.push(updata);
            }
        }
        updata = turnup(now);
        if (updata.step != -1)
        {
            it = hash.find(updata.now);
            if (it == hash.end())
            {
                hash.insert(updata.now);
                Q.push(updata);
            }
        }
        updata = turndown(now);
        if (updata.step != -1)
        {
            it = hash.find(updata.now);
            if (it == hash.end())
            {
                hash.insert(updata.now);
                Q.push(updata);
            }
        }
    }
    return -1;
}

int main()
{
    int ft = 0;
    while (true)
    {
        scanf("%d%d%d",&n,&m,&w);
        if (n == 0 && m == 0 && w == 0) break;
        s = "";
        for (int i = 1;i <= m;i++)
        {
            int tx,ty;
            scanf("%d%d",&tx,&ty);
            s = s+(char)(tx+'0')+(char)(ty+'0');
        }
        for (int i = 1;i <= m;i++)
            scanf("%d%d",&xj[i][0],&xj[i][1]);
        bool flag = true;
        int tleav = m;
        for (int i = 1;i <= m;i++)
        for (int j = 1;j <= m;j++)
        {
            int x1,x2,y1,y2;
            x1 = s[2*(i-1)]-'0';
            y1 = s[2*(i-1)+1]-'0';
            x2 = xj[j][0];
            y2 = xj[j][1];
            if (x1 == x2 && y1 == y2)
            if (i != j)
                flag = false;
            else
            {
                s[2*(i-1)] = s[2*(i-1)+1] = '4';
                tleav--;
            }
        }
        memset(g,0,sizeof(g));
        for (int i = 1;i <= w;i++)
        {
            int x1,x2,y1,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if (x1 == x2)
            {
                if (y1 > y2)
                {
                    int temp = y1;
                    y1 = y2;
                    y2 = temp;
                }
                g[x1][y1] = g[x1][y1]|(1<<2);
                g[x1][y2] = g[x1][y2]|(1<<0);
            }
            else
            {
                if (x1 > x2)
                {
                    int temp = x1;
                    x1 = x2;
                    x2 = temp;
                }
                g[x1][y1] = g[x1][y1]|(1<<3);
                g[x2][y1] = g[x2][y1]|(1<<1);
            }
        }
        int res = BFS(tleav);
        ft++;
        printf("Case %d: ",ft);
        if (flag == false)
            res = -1;
        if (res == -1)
            printf("impossible\n\n");
        else
            printf("%d moves\n\n",res);
    }
}
