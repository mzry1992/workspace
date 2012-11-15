#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int map[1100][1100];
int n;
int cnt;
int f[1100];
int ys[1100],fys[1100];

int findf(int x)
{
    if (f[x] != x) f[x] = findf(f[x]);
    return f[x];
}

int newmap[1100][1100];

void gaoji(int tn)
{
    for (int i = 1;i <= tn;i++)
        f[i] = i;
    cnt += tn;
    if (tn == 1)    return;
    for (int i = 1;i <= tn;i++)
    for (int j = i+1;j <= tn;j++)
    {
        newmap[i][j] = map[i][j]-2;
        if (newmap[i][j] == 0)
            f[findf(i)] = f[findf(j)];
    }
    for (int i = 1;i <= tn;i++)
    for (int j = i+1;j <= tn;j++)
    {
        if (newmap[i][j] == 1)
        if (findf(i) != findf(j))
        {
            f[findf(i)] = f[findf(j)];
            cnt++;
        }
    }
    for (int i = 1;i <= tn;i++)
        f[i] = findf(f[i]);
    /*
    cout << tn << endl;
    for (int i = 1;i < tn;i++)
    {
        for (int j = i+1;j <= tn;j++)
            cout << newmap[i][j] << ' ';
        cout << endl;
    }
    for (int i = 1;i <= tn;i++)
        cout << f[i] << ' ';
    cout << endl;
    cout << "--------------" << endl;
    */
    int ttn = 0;
    for (int i = 1;i <= tn;i++)
    if (f[i] == i)
    {
        ttn++;
        ys[ttn] = i;
        fys[i] = ttn;
    }
    for (int i = 1;i <= tn;i++)
    for (int j = i+1;j <= tn;j++)
    {
        int fi,fj;
        int tt = newmap[i][j];
        fi = findf(i);
        fj = findf(j);
        fi = fys[fi];
        fj = fys[fj];
        if (fi != fj)
        {
            if (fi > fj)
            {
                int temp = fi;
                fi = fj;
                fj = temp;
            }
            map[fi][fj] = tt;
        }
    }
    gaoji(ttn);
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        memset(map,0,sizeof(map));
        for (int i = 1;i < n;i++)
        for (int j = i+1;j <= n;j++)
            scanf("%d",&map[i][j]);
        cnt = 0;
        gaoji(n);
        printf("%d\n",cnt-n);
    }
}
