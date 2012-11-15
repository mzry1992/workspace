#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
#include <queue>
using namespace std;

int n,m,sx,sy,ex,ey;
char g[1010][1010];
struct node
{
    int x,y,step;
    node(){}
    node(int _x,int _y,int _step)
        {
            x = _x;
            y = _y;
            step = _step;
        }
}now,tnow;
struct cmp
{
    bool operator ()(node &a,node &b)
        {
            return a.step > b.step;
        }
};
deque<node> tQ;
queue <node,vector<node>,cmp> Q;
bool hash[1010][1010];
int dis[1010][1010];

const int step[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

inline bool check(int x,int y,int i)
{
    if (x+step[i][0] >= 0 && x+step[i][0] < n && y+step[i][1] >= 0 && y+step[i][1] < m) return true;
    return false;
}

void floodfill(int x,int y,int stepnow)
{
    tQ.clear();
    tQ.push_back(node(x,y,stepnow));
    while (!tQ.empty())
    {
        tnow = tQ.front();
        tQ.pop_front();
        Q.push(tnow);
        hash[tnow.x][tnow.y] = true;
        for (int i = 0;i < 4;i++)
            if (check(tnow.x,tnow.y,i) == true)
                if (hash[tnow.x+step[i][0]][tnow.y+step[i][1]] == false && g[tnow.x+step[i][0]][tnow.y+step[i][1]] == 'X')
                    tQ.push_back(node(tnow.x+step[i][0],tnow.y+step[i][1],tnow.step));
    }
}

int BFS()
{
    while (!Q.empty())  Q.pop();
    memset(hash,false,sizeof(hash));
    floodfill(sx-1,sy-1,0);
    while (!Q.empty())
    {
        now = Q.top();
        Q.pop();
        if (now.x == ex-1 && now.y == ey-1) return now.step;
        //cout << now.x << ' ' << now.y << ' ' << now.step << endl;
        for (int i = 0;i < 4;i++)
            if (check(now.x,now.y,i) == true)
                if (hash[now.x+step[i][0]][now.y+step[i][1]] == false)
                {
                    if (g[now.x+step[i][0]][now.y+step[i][1]] == '.')
                    {
                        Q.push(node(now.x+step[i][0],now.y+step[i][1],now.step+1));
                        hash[now.x+step[i][0]][now.y+step[i][1]] = true;
                    }
                    else
                        floodfill(now.x+step[i][0],now.y+step[i][1],now.step);
                }
    }
}

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        for (int i = 0;i < n;i++)   scanf("%s",g[i]);
        scanf("%d%d",&sx,&sy);
        scanf("%d%d",&ex,&ey);
        printf("%d\n",BFS());
    }
    return 0;
}
