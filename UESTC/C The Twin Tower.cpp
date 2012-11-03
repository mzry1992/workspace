#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int ways[1<<9],wtot;
bool mp[3][3];

void DFS(int nowx,int nowy)
{
    if (nowx == 3)
    {
        cout << "haha" << endl;
        for (int i = 0;i < 3;i++)
        {
            for (int j = 0;j < 3;j++)
                cout << mp[i][j] << ' ';
            cout << endl;
        }
        wtot++;
        return;
    }
    int nx,ny;
    nx = nowx;
    ny = nowy+1;
    if (ny == 3)
    {
        nx++;
        ny = 0;
    }
    if (mp[nowx][nowy] == false)
        DFS(nx,ny);
    else
    {
        if (nowx < 3)
        {
            if (mp[nowx+1][nowy] == true)
            {
                mp[nowx][nowy] = mp[nowx+1][nowy] = false;
                DFS(nx,ny);
                mp[nowx][nowy] = mp[nowx+1][nowy] = true;
            }
        }
        if (nowy < 3)
        {
            if (mp[nowx][nowy+1] == true)
            {
                mp[nowx][nowy] = mp[nowx][nowy+1] = false;
                DFS(nx,ny);
                mp[nowx][nowy] = mp[nowx][nowy+1] = true;
            }
        }
    }
}

void Gao()
{
    for (int i = 1;i < 2;i++)
    {
        for (int j = 0;j < 3;j++)
            for (int k = 0;k < 3;k++)
                if (((i>>(j*3+k))&1) == 1)  mp[j][k] = false;
                else mp[j][k] = true;
        wtot = 0;
        DFS(0,0);
        ways[i] = wtot;
    }
}

int n,a[1<<9][1<<9],dis[1<<9][1<<9],tmp[1<<9][1<<9],mul[1<<9][1<<9];
const int mod = 10007;
const int top = 1<<9;

int power(int x,int y)
{
    int ret=1;
    for (int a=x%mod; y; y>>=1,a=a*a%mod)
        if (y&1) ret=ret*a%mod;
    return ret;
}

void mult(int now)
{
    for (int i = 0;i < top;i++)
        a[i][i] = 1;
    for (int i = 0;i < top;i++)
        for (int j = 0;j < top;j++)
            mul[i][j] = dis[i][j]%mod;
    while (now)
    {
        if (now&1)
        {
            for (int i = 0;i < top;i++)
                for (int j = 0;j < top;j++)
                    tmp[i][j] = 0;
            for (int i = 0;i < top;i++)
                for (int j = 0;j < top;j++)
                    for (int k = 0;k < top;k++)
                        tmp[i][j] = (tmp[i][j]+a[i][k]*mul[k][j])%mod;
            for (int i = 0;i < top;i++)
                for (int j = 0;j < top;j++)
                    a[i][j] = tmp[i][j];
        }
        now >>= 1;
        for (int i = 0;i < top;i++)
            for (int j = 0;j < top;j++)
                tmp[i][j] = 0;
        for (int i = 0;i < top;i++)
            for (int j = 0;j < top;j++)
                for (int k = 0;k < top;k++)
                    tmp[i][j] = (tmp[i][j]+mul[i][k]*mul[k][j])%mod;
        for (int i = 0;i < top;i++)
            for (int j = 0;j < top;j++)
                mul[i][j] = tmp[i][j];
    }
}

int main()
{
    Gao();
    for(int x = 0 ; x <top ;x++)
        for(int y = 0 ; y <top;y++)
            if((x&y) == 0)
                {
                    dis[x][y] = ways[x|y];
                }
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        mult(n);
    }
    cout << ways[1] << endl;
}
