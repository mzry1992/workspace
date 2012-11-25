#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

const int move[6][12] = {{2, 3, 4, 5, 6, 12, 7, 8, 9, 10, 11, 1},
    {12, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 6},
    {1, 2, 3, 4, 5, 12, 6, 7, 8, 9, 10, 11},
    {1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12, 6},
    {12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
    {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 1}
};

long long fac[13];

long long Hash(int a[])
{
    long long res = 0;
    for (int i = 0;i < 12;i++)
        res += a[i]*fac[i];
    return res;
}

void UnHash(long long msk,int a[])
{
    for (int i = 0;i < 12;i++,msk /= 12)
        a[i] = msk%12;
}

struct HashMap
{
    const static int mod = 10000007;
    int head[mod];
    struct hash_tables
    {
        long long key;
        int val,next;
    }ele[10000007];
    int N;
    void clear()
    {
        memset(head,255,sizeof(head));
        N = 0;
    }
    int& operator [](long long x)
    {
        for (int i = head[x%mod];i != -1;i = ele[i].next)
            if (ele[i].key == x)
                return ele[i].val;
        ele[N].key = x;
        ele[N].val = 0;
        ele[N].next = head[x%mod];
        head[x%mod] = N++;
        return ele[N-1].val;
    }
};

HashMap dist;

void preBFS()
{
    queue<long long > Q;
    int now[12],nxt[12];
    long long hnow, hnxt;

    for (int i = 0; i < 12; i++)
        now[i] = i;
    hnow = Hash(now);

    Q.push(hnow);

    dist.clear();
    dist[hnow] = 1;

    int tot = 0;

    while (!Q.empty())
    {
        hnow = Q.front();
        Q.pop();

        UnHash(hnow,now);

        if (dist[hnow] == 11)
            return;

        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 12; j++)
                nxt[j] = now[move[i][j] - 1];
            hnxt = Hash(nxt);
            if (dist[hnxt] == 0)
            {
                dist[hnxt] = dist[hnow] + 1;
                Q.push(hnxt);
            }
        }
    }
}

HashMap dist2;

int BFS(int a[])
{
    queue<long long > Q;
    int now[12],nxt[12];
    long long hnow, hnxt;

    for (int i = 0; i < 12; i++)
        now[i] = a[i];
    hnow = Hash(now);

    Q.push(hnow);

    dist2.clear();
    dist2[hnow] = 1;

    int tot = 0;

    while (!Q.empty())
    {
        hnow = Q.front();
        Q.pop();

        UnHash(hnow,now);

        if (dist[hnow] != 0)
        {
            int res = dist2[hnow]-1;
            res += dist[hnow]-1;
            return res;
        }

        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 12; j++)
                nxt[j] = now[move[i][j] - 1];
            hnxt = Hash(nxt);
            if (dist2[hnxt] == 0)
            {
                dist2[hnxt] = dist2[hnow] + 1;
                Q.push(hnxt);
            }
        }
    }
}

int a[12];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out2.txt","w",stdout);
    fac[0] = 1;
    for (int i = 1;i <= 12;i++)
        fac[i] = fac[i-1]*12;

    preBFS();
    int totcas;
    scanf("%d", &totcas);
    for (int cas = 0; cas < totcas; cas++)
    {
        for (int i = 0; i < 12; i++)
        {
            scanf("%d", &a[i]);
            a[i]--;
        }
        int ans = BFS(a);
        printf("%d\n",ans);
    }
    return 0;
}
