#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct node
{
    int now,step;
    node(){}
    node(int _now,int _step)
        {
            now = _now;
            step = _step;
        }
};

bool visit[1200];

int BFS(int n,int m)
{
    queue<node> Q;
    Q.push(node(0,0));
    memset(visit,false,sizeof(visit));
    visit[0] = true;
    while (!Q.empty())
    {
        node now = Q.front();
        Q.pop();
        if (now.now == n)    return now.step;
        for (int i = 0;i <= min(now.now,m);i++)
            if (now.now+m-2*i >= 0 && now.now+m-2*i <= n)
                if (n-now.now-m+2*i >= 0 && n-now.now-m+2*i <= n)
                    if (m-i <= n-now.now)
                        if (visit[now.now+m-2*i] == false)
                        {
                            visit[now.now+m-2*i] = true;
                            Q.push(node(now.now+m-2*i,now.step+1));
                        }
    }
    return -1;
}

int Gao(int n,int m)
{
    return 0;
    if (n%2 == 1 && m%2 == 0)   return -1;
    if (m == 1) return n;
    if (n == m*2)   return 2;
    if (m%2 == 0)
    {
        int k = m/2;
        int j = n/2-k+1;
        if (j == 1) return 1;
        if (j <= k) return 3;
        if (j == k+1)   return 2;
        j -= (k+1);
        return (3+(j-1)/k);
    }
    else
    {
        int k = (m+1)/2;
        int j = n-m+1;
        if (j == 1) return 1;
        if (j == 2) return m+1;
        if (n%2 == 1)
        {
            j = n-(m+2);
            j /= 2;
            return 3+2*(j/m);
        }
        else
        {
            if (n > m*2)
            {
                j = n-m*2;
                j /= 2;
                j--;
                return 4+2*(j/m);
            }
            else
            {
                m = n-m;
                j = n-m*2;
                j /= 2;
                j--;
                return 4+2*(j/m);
            }
            return 0;
        }
    }
}

long long Ji(long long n,long long m)
{
    if (n%2 == 1 && m%2 == 0)   return -1;
    if (m == 1) return n;
    if (n == m*2)   return 2;
    if (m%2 == 0)
    {
        int k = m/2;
        int j = n/2-k+1;
        if (j == 1) return 1;
        if (j <= k) return 3;
        if (j == k+1)   return 2;
        j -= (k+1);
        return (3+(j-1)/k);
    }
    else
    {
        int k = (m+1)/2;
        int j = n-m+1;
        if (j == 1) return 1;
        if (j == 2) return m+1;
        if (n%2 == 1)
        {
            j = n-(m+2);
            j /= 2;
            return 3+2*(j/m);
        }
        else
        {
            if (n > m*2)
            {
                j = n-m*2;
                j /= 2;
                j--;
                return 4+2*(j/m);
            }
            else
            {
                m = n-m;
                j = n-m*2;
                j /= 2;
                j--;
                return 4+2*(j/m);
            }
            return 0;
        }
    }
}

int main()
{
    freopen("Inverting Cups.txt","w",stdout);
    printf("%5d:",0);
    for (int m = 1;m <= 100;m++)
        printf("%5d",m);
    printf("\n");
    for (int n = 1;n <= 100;n++)
    {
        printf("%5d:",n);
        for (int m = 1;m <= n;m++)
            printf("%5d",BFS(n,m)-Gao(n,m));
        printf("\n");
    }
    return 0;
    unsigned long long a,b;
    while (scanf("%I64d%I64d",&a,&b) != EOF)
    {
        if (Ji(a,b) == -1)  printf("No Solution!\n");
        else printf("%I64d\n",Ji(a,b));
    }
}
