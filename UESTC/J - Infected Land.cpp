#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
#include <set>
using namespace std;

const int step[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int n;
char map[6][6];
int s,sx,sy;
struct node
{
    int step,x,y;
    int mp;
}now;
bool operator<(const node &a  ,const node &b)
    {
        return a.mp < b.mp;
    }
deque<node> Q;
set<string> hash;

node getnode(int step,int x,int y,int mp)
{
    node res;
    res.step = step;
    res.x = x;
    res.y = y;
    res.mp = mp;
    return res;
}

int life(int now)
{
    int res = 0;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
        {
            int tot = 0;
            for (int k = 0;k < 8;k++)
                if (i+step[k][0] >= 0 && i+step[k][0] < n && j+step[k][1] >= 0 && j+step[k][1] < n)
                    if (((now>>((i+step[k][0])*n+j+step[k][1]))&1) == 1)
                        tot++;
            if (((now>>(i*n+j))&1) == 1)
            {
                if (tot == 2 || tot == 3)
                    res = res|(1<<(i*n+j));
            }
            else
            {
                if (tot == 3)
                    res = res|(1<<(i*n+j));
            }
        }
    return res;
}

int BFS()
{
    Q.clear();
    hash.clear();
    Q.push_back(getnode(0,sx,sy,s));
    hash.insert(gethash(getnode(0,sx,sy,s)));
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop_front();
        if (now.mp-(1<<(now.x*n+now.y)) == 0)   return now.step;
        for (int i = 0;i < 8;i++)
        {
            int tx,ty,mp;
            tx = now.x+step[i][0];
            ty = now.y+step[i][1];
            mp = now.mp;
            if (tx >= 0 && tx < n && ty >= 0 && ty < n)
                if (((mp>>(tx*n+ty))&1) == 0)
                {
                    mp = mp^(1<<(now.x*n+now.y));
                    mp = mp|(1<<(tx*n+ty));
                    mp = life(mp);
                    mp = mp|(1<<(tx*n+ty));
                    if (hash.find(getnode(0,tx,ty,mp)) == hash.end())
                    {
                        hash.insert(getnode(0,tx,ty,mp));
                        Q.push_back(getnode(now.step+1,tx,ty,mp));
                    }
                }
        }
    }
    return -1;
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 0;i < n;i++)   scanf("%s",map[i]);
        s = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                if (map[i][j] != '.')
                {
                    s = s|(1<<(i*n+j));
                    if (map[i][j] == '@')
                    {
                        sx = i;
                        sy = j;
                    }
                }
        printf("%d\n",BFS());
    }
}
