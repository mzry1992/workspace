#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,res,a[110];
int app[110];

int N,w[110],c[110],ud[110];

void DFS2(int now,int sum)
{
    if (now == N)
        ud[sum]++;
    else
        for (int j = 0;j <= c[now];j++)
            DFS2(now+1,w[now]*j+sum);
}

void DFS(int now,int sum,int last)
{
    if (sum == n)
    {
        w[0] = a[0];
        c[0] = 1;
        N = 1;
        for (int i = 1;i < now;i++)
            if (a[i] != w[N-1])
            {
                w[N] = a[i];
                c[N++] = 1;
            }
            else
                c[N-1]++;
        for (int i = 0;i <= n;i++)
            ud[i] = 0;
        DFS2(0,0);
        /*for (int i = 0;i < N;i++)
            cout << i << ' ' << w[i] << ' ' << c[i] << endl;*/
        for (int i = 0;i <= n;i++)
            if (ud[i] != 1)
                return;
        res++;
        for (int i = 0;i < now;i++)
            cout << a[i] << ' ';
        cout << endl;
    }
    if (sum+last > n)   return;
    for (int i = last;sum+i <= n;i++)
    {
        a[now] = i;
        DFS(now+1,sum+i,i);
    }
}

int prime[500],tot;
bool isprime[500];

void getprime()
{
    tot = 0;
    memset(isprime,true,sizeof(isprime));
    for (int i = 2;i < 500;i++)
    {
        if (isprime[i] == true)
            prime[tot++] = i;
        for (int j = 0;j < tot && i*prime[j] < 500;j++)
        {
            isprime[i*prime[j]] = false;
            if (i%prime[j] == 0)    break;
        }
    }
}

int main()
{
    /*freopen("C.txt","w",stdout);
    for (n = 1;n < 50;n++)
    {
        res = 0;
        DFS(0,0,1);
        printf("%d\n",res);
    }
    return 0;*/
    getprime();
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        res = 0;
        DFS(0,0,1);
        printf("Case %d: %d\n",ft,res);
        n++;
        cout << n << endl;
        for (int i = 0;i < tot;i++)
            if (n%prime[i] == 0)
            {
                int tt = 0;
                while (n%prime[i] == 0)
                {
                    tt++;
                    n /= prime[i];
                }
                cout << prime[i] << ' ' << tt << endl;
            }
    }
}
