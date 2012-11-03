#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int a[8][8],sum[8][8];
double res[64];

long long gcd(long long a,long long b)
{
    if (b == 0) return a;
    return gcd(b,a%b);
}

struct fs
{
    long long a,b;
    void easy()
    {
        if (a == 0)
        {
            b = 1;
            return;
        }
        long long tgcd = gcd(a,b);
        a /= tgcd;
        b /= tgcd;
        if (b < 0)
        {
            a = -a;
            b = -b;
        }
    }
    fs(){}
    fs(long long _a,long long _b)
        {
            a = _a;
            b = _b;
            easy();
        }
    fs Add(fs p)
    {
        fs res = fs(a*p.b+b*p.a,b*p.b);
        res.easy();
        return res;
    }
    fs Sub(fs p)
    {
        fs res = fs(a*p.b-b*p.a,b*p.b);
        res.easy();
        return res;
    }
    fs Mul(fs p)
    {
        fs res = fs(a*p.a,b*p.b);
        res.easy();
        return res;
    }
    fs Div(fs p)
    {
        fs res = fs(a*p.b,b*p.a);
        res.easy();
        return res;
    }
    int CompareTo(fs p)
    {
        fs tmp = fs(a,b).Sub(p);
        if (tmp.a == 0) return 0;
        if (tmp.a < 0)  return -1;
        return 1;
    }
}g[64][64];

inline int getid(int x,int y)
{
    return x*8+y;
}

int main()
{
    while (scanf("%d",&a[0][0]) != EOF)
    {
        for (int i = 1;i < 8;i++)   scanf("%d",&a[0][i]);
        for (int i = 1;i < 8;i++)
            for (int j = 0;j < 8;j++)
                scanf("%d",&a[i][j]);
        for (int i = 0;i < 8;i++)
            for (int j = 0;j < 8;j++)
            {
                sum[i][j] = 0;
                for (int k = 0;k < 4;k++)
                    if (i+step[k][0] >= 0 && i+step[k][0] < 8 && j+step[k][1] >= 0 && j+step[k][1] < 8)
                        sum[i][j] += a[i+step[k][0]][j+step[k][1]];
            }
        for (int i = 0;i < 64;i++)
            for (int j = 0;j < 64;j++)
                g[i][j] = fs(0,1);
        for (int i = 0;i < 8;i++)
            for (int j = 0;j < 8;j++)
            {
                g[getid(i,j)][getid(i,j)] = fs(1,1);
                for (int k = 0;k < 4;k++)
                    if (i+step[k][0] >= 0 && i+step[k][0] < 8 && j+step[k][1] >= 0 && j+step[k][1] < 8)
                        g[getid(i,j)][getid(i+step[k][0],j+step[k][1])] = fs(-a[i][j],sum[i+step[k][0]][j+step[k][1]]);
            }
        for (int i = 0;i < 8;i++)
        {
            for (int j = 0;j < 8;j++)
                cout << g[i][j].a << '/' << g[i][j].b << ' ';
            cout << endl;
        }
        for (int i = 0;i < 63;i++)
        {
            if (g[i][i].CompareTo(fs(0,1)) == 0)
                for (int j = i+1;j < 64;j++)
                    if (g[j][i].CompareTo(fs(0,1)) != 0)
                        for (int k = 0;k < 64;k++)
                            swap(g[i][k],g[j][k]);
            for (int j = 0;j < 64;j++)
                if (i != j)
                    if (g[j][i].CompareTo(fs(0,1)) != 0)
                    {
                        fs tmp = g[j][i].Div(g[i][i]);
                        for (int k = i;k < 64;k++)
                            g[j][k] = g[j][k].Sub(tmp.Mul(g[i][k]));
                    }
        }
        for (int i = 0;i < 8;i++)
        {
            for (int j = 0;j < 8;j++)
                cout << g[i][j].a << '/' << g[i][j].b << ' ';
            cout << endl;
        }
        res[63] = 1.0*(double)g[63][63].b/(double)g[63][63].a;
        cout << res[63] << endl;
        for (int i = 0;i < 64;i++)
            cout << g[i][63].a << '/' << g[i][63].b << ' ' << endl;
    }
}
