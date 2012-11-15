#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int step[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int n,m;
char mp[9][9];
int ex,ey;
int bit[9];

inline int getbit(int sta,int pos)
{
    return sta/bit[pos]%bit[1];
}

inline int setbit(int sta,int pos,int val)
{
    return sta/bit[pos+1]*bit[pos+1]+val*bit[pos]+sta%bit[pos];
}

int f[2][6*6][6*6];
bool inq[5][6*6*6*6][6*6*6*6];

struct node
{
    int stax,stay,nowm,step,h;
    node() {}
    node(int _stax,int _stay,int _nowm,int _step)
    {
        stax = _stax;
        stay = _stay;
        nowm = _nowm;
        step = _step;
        CalcH();
    }
    friend bool operator < (const node& a,const node& b)
    {
        if (a.step+a.h == b.step+b.h)
            return a.step > b.step;
        return a.step+a.h > b.step+b.h;
    }
    void CalcH()
    {
        if (nowm == 0)  h = 0;
        else if (nowm < 3)   h = f[nowm-1][stax][stay];
        else if (nowm == 3)
        {
            int tx,ty;
            tx = setbit(setbit(0,0,getbit(stax,0)),1,getbit(stax,1));
            ty = setbit(setbit(0,0,getbit(stay,0)),1,getbit(stay,1));
            h = f[1][tx][ty];
            tx = setbit(0,0,getbit(stax,2));
            ty = setbit(0,0,getbit(stay,2));
            h += f[0][tx][ty];
        }
        else if (nowm == 4)
        {
            int tx,ty;
            tx = setbit(setbit(0,0,getbit(stax,0)),1,getbit(stax,1));
            ty = setbit(setbit(0,0,getbit(stay,0)),1,getbit(stay,1));
            h = f[1][tx][ty];
            tx = setbit(setbit(0,0,getbit(stax,2)),1,getbit(stax,3));
            ty = setbit(setbit(0,0,getbit(stay,2)),1,getbit(stay,3));
            h += f[1][tx][ty];
        }
    }
};

node now,upd;

void Gao()
{
    queue<node> Q;
    now = node(setbit(0,0,ex),setbit(0,0,ey),0,0);
    memset(f,63,sizeof(f));
    memset(inq,false,sizeof(inq));
    f[now.nowm][now.stax][now.stay] = now.step;
    inq[now.nowm][now.stax][now.stay] = true;
    Q.push(now);
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();
        inq[now.nowm][now.stax][now.stay] = false;
        if (now.nowm == 0)
        {
            bool check = true;
            if (abs(getbit(now.stax,0)-ex)+abs(getbit(now.stay,0)-ey) <= 1) check = false;
            if (check == true)
            {
                upd = node(setbit(now.stax,1,ex),setbit(now.stay,1,ey),1,now.step);
                if (f[upd.nowm][upd.stax][upd.stay] > upd.step)
                {
                    f[upd.nowm][upd.stax][upd.stay] = upd.step;
                    if (inq[upd.nowm][upd.stax][upd.stay] == false)
                    {
                        inq[upd.nowm][upd.stax][upd.stay] = true;
                        Q.push(upd);
                    }
                }
            }
        }
        for (int i = 0; i <= now.nowm; i++)
        {
            int x = getbit(now.stax,i);
            int y = getbit(now.stay,i);
            for (int j = 0; j < 4; j++)
            {
                int tx = x+step[j][0];
                int ty = y+step[j][1];
                if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
                bool check = true;
                for (int k = 0; k <= now.nowm; k++)
                    if (i != k)
                        if (abs(getbit(now.stax,k)-tx)+abs(getbit(now.stay,k)-ty) <= 1)
                        {
                            check = false;
                            break;
                        }
                if (check == true)
                {
                    upd = node(setbit(now.stax,i,tx),setbit(now.stay,i,ty),now.nowm,now.step+1);
                    if (f[upd.nowm][upd.stax][upd.stay] > upd.step)
                    {
                        f[upd.nowm][upd.stax][upd.stay] = upd.step;
                        if (inq[upd.nowm][upd.stax][upd.stay] == false)
                        {
                            inq[upd.nowm][upd.stax][upd.stay] = true;
                            Q.push(upd);
                        }
                    }
                }
            }
        }
    }
}

int x[9],y[9];

int Astar()
{
    now.stax = now.stay = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mp[i][j] >= '1' && mp[i][j] <= '4')
                now.stax = setbit(now.stax,m-(mp[i][j]-'0'),i),now.stay = setbit(now.stay,m-(mp[i][j]-'0'),j);
    now.nowm = m;
    now.step = 0;
    now.CalcH();
    priority_queue<node> Q;
    memset(inq,false,sizeof(inq));
    inq[now.nowm][now.stax][now.stay] = true;
    Q.push(now);
    while (!Q.empty())
    {
        now = Q.top();
        Q.pop();
        if (now.h == 0) return now.step;
        for (int i = 0; i < now.nowm; i++)
            x[i] = getbit(now.stax,i),y[i] = getbit(now.stay,i);
        if (x[now.nowm-1] == ex && y[now.nowm-1] == ey)
        {
            upd = node(setbit(now.stax,now.nowm-1,0),setbit(now.stay,now.nowm-1,0),now.nowm-1,now.step);
            if (inq[upd.nowm][upd.stax][upd.stay] == false)
            {
                inq[upd.nowm][upd.stax][upd.stay] = true;
                Q.push(upd);
            }
        }
        for (int i = 0; i < now.nowm; i++)
            for (int j = 0; j < 4; j++)
            {
                int tx = x[i]+step[j][0];
                int ty = y[i]+step[j][1];
                if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
                bool check = true;
                for (int k = 0; k < now.nowm; k++)
                    if (i != k)
                        if (abs(x[k]-tx)+abs(y[k]-ty) <= 1)
                        {
                            check = false;
                            break;
                        }
                if (check == true)
                {
                    upd = node(setbit(now.stax,i,tx),setbit(now.stay,i,ty),now.nowm,now.step+1);
                    if (inq[upd.nowm][upd.stax][upd.stay] == false)
                    {
                        inq[upd.nowm][upd.stax][upd.stay] = true;
                        Q.push(upd);
                    }
                }
            }
    }
    return -1;
}

int main()
{
    for (int cas = 1; cas <= 10; cas++)
    {
        char filein[10],fileout[10];
        sprintf(filein,"%d.in",cas);
        sprintf(fileout,"%d.out",cas);
        freopen(filein,"r",stdin);
        freopen(fileout,"w",stdout);
        bit[0] = 1;
        for (int i = 1; i < 9; i++)
            bit[i] = bit[i-1]*6;
        int t = 1;
        //scanf("%d",&t);
        for (int ft = 1; ft <= t; ft++)
        {
            scanf("%d%d",&n,&m);
            for (int i = 0; i < n; i++)
                scanf("%s",mp[i]);
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (mp[i][j] == 'x')
                        ex = i,ey = j;
            Gao();
            printf("%d\n",Astar());
        }
    }
    return 0;
}
