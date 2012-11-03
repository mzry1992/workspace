#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

const int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
bool map[250][250];
int n,m;
struct node
{
    int x,y;
};
int f[250*250];

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

vector<node> Q;

int main()
{
    freopen("CDOJ1480.in","w",stdout);
    cout << 100 << endl;
    for (int i = 1;i <= 50;i++)
    {
        memset(map,false,sizeof(map));
        n = rand()%100+100;
        m = rand()%100+100;
        map[1][1] = map[n][m] = true;
        Q.clear();
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
        if ((!(i == 1 && j == 1)) && (!(i == n && j == m)))
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
        cout << n << ' ' << m << endl;
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= m;j++)
                cout << (1^map[i][j]) << ' ';
            cout << endl;
        }
    }
    for (int i = 1;i <= 50;i++)
    {
        memset(map,false,sizeof(map));
        n = rand()%100+100;
        m = rand()%100+100;
        map[1][1] = map[n][m] = true;
        Q.clear();
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
        if ((!(i == 1 && j == 1)) && (!(i == n && j == m)))
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
        cout << n << ' ' << m << endl;
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= m;j++)
                cout << (1^map[i][j]) << ' ';
            cout << endl;
        }
    }
}
