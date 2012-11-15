#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

const int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
bool map[450][450],visit[450][450][2];
int n,m;
struct node
{
    int x,y;
};
int f[450*450];

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

node getnode(int x,int y)
{
    node res;
    res.x = x;
    res.y = y;
    return res;
}

struct wall
{
    int x,y,d,t;
};

wall getwall(int x,int y,int d,int t)
{
    wall res;
    res.x = x;
    res.y = y;
    res.d = d;
    res.t = t;
    return res;
}

vector<node> Q;
vector<wall> W,D;

int main()
{
    freopen("CDOJ1479.in","w",stdout);
    cout << 20 << endl;
    for (int ii = 1;ii <= 10;ii++)
    {
        memset(map,false,sizeof(map));
        n = rand()%200+100;
        m = rand()%200+100;
        int ex,ey;
        ex = (rand()%(n/2)+1);
        ey = (rand()%(m/2)+1);
        double sx,sy;
        sx = (double)(ex)+(double)(rand()%100)/100;
        sy = (double)(ey)+(double)(rand()%100)/100;
        map[1][1] = map[ex][ey] = true;
        Q.clear();
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
        if ((!(i == 1 && j == 1)) && (!(i == ex && j == ey)))
            Q.push_back(getnode(i,j));
        random_shuffle(Q.begin(),Q.end());
        for (int i = 1;i <= n*m;i++)
            f[i] = i;
        for (int pos = 0;pos < Q.size();pos++)
        {
            if (findf(1) == findf(n*m)) break;
            map[Q[pos].x][Q[pos].y] = true;
            for (int i = 0;i < 4;i++)
            {
                int tx,ty;
                tx = Q[pos].x+step[i][0];
                ty = Q[pos].y+step[i][1];
                if (tx >= 1 && tx <= n && ty >= 1 && ty <= m)
                if (map[tx][ty] == true)
                    f[findf((tx-1)*m+ty)] = (Q[pos].x-1)*m+Q[pos].y;
            }
        }
        W.clear();
        memset(visit,false,sizeof(visit));
        for (int i = 2;i <= n;i += 2)
        for (int j = 2;j <= m;j += 2)
        if (map[i][j] == false)
        {
            int posx,posy;
            posx = i/2;
            posy = j/2;
            if (visit[i][j][1] == false)
            for (int k = 1;i+2*(k-1)+1 <= n;k++)
            if (map[i+1+2*(k-1)][j] == true)
            {
                W.push_back(getwall(posx,posy,1,k));
                break;
            }
            else
                visit[i+2*(k-1)][j][1] = true;
            if (visit[i][j][0] == false)
            for (int k = 1;j+2*(k-1)+1 <= m;k++)
            if (map[i][j+2*(k-1)+1] == true)
            {
                W.push_back(getwall(posx,posy,0,k));
                break;
            }
            else
                visit[i][j+2*(k-1)][0] = true;
        }
        D.clear();
        for (int i = 2;i < n;i += 2)
        for (int j = 2;j < m;j += 2)
        {
            int posx,posy;
            posx = i/2;
            posy = j/2;
            if (map[i+1][j] == true)
            {
                int p = rand()%10;
                if (p <= 9)
                    D.push_back(getwall(posx,posy,1,1));
            }
            if (map[i][j+1] == true)
            {
                int p = rand()%10;
                if (p == 1)
                    D.push_back(getwall(posx,posy,0,1));
            }
        }
        cout << W.size() << ' ' << D.size() << endl;
        for (int i = 0;i < W.size();i++)
            cout << W[i].x-1 << " " << W[i].y-1 << ' ' << W[i].d << ' ' << W[i].t << endl;
        for (int i = 0;i < D.size();i++)
            cout << D[i].x-1 << " " << D[i].y-1 << ' ' << D[i].d <<  endl;
        cout << sx-1 << ' ' << sy-1 << endl;
    }
    for (int i = 1;i <= 10;i++)
    {
        memset(map,false,sizeof(map));
        n = rand()%200+100;
        m = rand()%200+100;
        int ex,ey;
        ex = (rand()%(n/2)+1);
        ey = (rand()%(m/2)+1);
        double sx,sy;
        sx = (double)(ex)+(double)(rand()%100)/100;
        sy = (double)(ey)+(double)(rand()%100)/100;
        map[1][1] = map[ex][ey] = true;
        Q.clear();
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
        if ((!(i == 1 && j == 1)) && (!(i == ex && j == ey)))
            Q.push_back(getnode(i,j));
        random_shuffle(Q.begin(),Q.end());
        for (int i = 1;i <= n*m;i++)
            f[i] = i;
        for (int pos = 0;pos < Q.size();pos++)
        {
            for (int i = 0;i < 4;i++)
            {
                int tx,ty;
                tx = Q[pos].x+step[i][0];
                ty = Q[pos].y+step[i][1];
                if (tx >= 1 && tx <= n && ty >= 1 && ty <= m)
                if (map[tx][ty] == true)
                    f[findf((tx-1)*m+ty)] = (Q[pos].x-1)*m+Q[pos].y;
            }
            if (findf(1) == findf(n*m)) break;
            map[Q[pos].x][Q[pos].y] = true;
        }
        W.clear();
        memset(visit,false,sizeof(visit));
        for (int i = 2;i <= n;i += 2)
        for (int j = 2;j <= m;j += 2)
        if (map[i][j] == false)
        {
            int posx,posy;
            posx = i/2;
            posy = j/2;
            if (visit[i][j][1] == false)
            for (int k = 1;i+2*(k-1)+1 <= n;k++)
            if (map[i+1+2*(k-1)][j] == true)
            {
                W.push_back(getwall(posx,posy,1,k));
                break;
            }
            else
                visit[i+2*(k-1)][j][1] = true;
            if (visit[i][j][0] == false)
            for (int k = 1;j+2*(k-1)+1 <= m;k++)
            if (map[i][j+2*(k-1)+1] == true)
            {
                W.push_back(getwall(posx,posy,0,k));
                break;
            }
            else
                visit[i][j+2*(k-1)][0] = true;
        }
        D.clear();
        for (int i = 2;i < n;i += 2)
        for (int j = 2;j < m;j += 2)
        {
            int posx,posy;
            posx = i/2;
            posy = j/2;
            if (map[i+1][j] == true)
            {
                int p = rand()%10;
                if (p <= 9)
                    D.push_back(getwall(posx,posy,1,1));
            }
            if (map[i][j+1] == true)
            {
                int p = rand()%10;
                if (p == 1)
                    D.push_back(getwall(posx,posy,0,1));
            }
        }
        cout << W.size() << ' ' << D.size() << endl;
        for (int i = 0;i < W.size();i++)
            cout << W[i].x-1 << " " << W[i].y-1 << ' ' << W[i].d << ' ' << W[i].t << endl;
        for (int i = 0;i < D.size();i++)
            cout << D[i].x-1 << " " << D[i].y-1 << ' ' << D[i].d <<  endl;
        cout << sx-1 << ' ' << sy-1 << endl;
    }
}
