#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct trie
{
    int next[60010][2],fail[60010],endr[60010];
    bool endv[60010];
    int L,root;
    int newnode()
    {
        for (int i = 0; i < 2; i++)
            next[L][i] = -1;
        endr[L] = 0;
        endv[L] = false;
        return L++;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char buf[],int id)
    {
        int len = strlen(buf);
        int now = root;
        for (int i = 0; i < len; i++)
        {
            if (next[now][buf[i]-'0'] == -1)
                next[now][buf[i]-'0'] = newnode();
            now = next[now][buf[i]-'0'];
        }
        if (id == -1)
            endv[now] = true;
        else
            endr[now] = 1<<id;
    }
    void build()
    {
        queue<int> Q;
        for (int i = 0; i < 2; i++)
            if (next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while (!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            endv[now] |= endv[fail[now]];
            endr[now] |= endr[fail[now]];
            for (int i = 0; i < 2; i++)
                if (next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
};

int n,m;
char buf[60010];
trie ac;
int pos[100],tot;
int dis[60010],d[100][100];

void Gao(int id)
{
    queue<int> Q;
    memset(dis,-1,sizeof(dis));
    Q.push(pos[id]);
    dis[pos[id]] = 0;
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        for (int i = 0; i < 2; i++)
        {
            int nxt = ac.next[now][i];
            if (ac.endv[nxt] == false && dis[nxt] == -1)
            {
                dis[nxt] = dis[now]+1;
                Q.push(nxt);
            }
        }
    }
    for (int i = 0; i < tot; i++)
        d[id][i] = dis[pos[i]];
}

int dp[1024][100];

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        ac.init();
        for (int i = 0; i < n; i++)
        {
            scanf("%s",buf);
            ac.insert(buf,i);
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%s",buf);
            ac.insert(buf,-1);
        }
        ac.build();
        tot = 0;
        pos[tot++] = 0;
        for (int i = 0; i < ac.L; i++)
            if (ac.endv[i] == false && ac.endr[i] != 0)
                pos[tot++] = i;
        for (int i = 0; i < tot; i++)
            Gao(i);
        memset(dp,-1,sizeof(dp));
        dp[0][0] = 0;
        for (int i = 0; i < (1<<n); i++)
            for (int j = 0; j < tot; j++)
                if (dp[i][j] != -1)
                    for (int k = 0; k < tot; k++)
                        if (d[j][k] != -1)
                        {
                            int newsta = i|ac.endr[pos[k]];
                            if (dp[newsta][k] == -1 || dp[newsta][k] > dp[i][j]+d[j][k])
                                dp[newsta][k] = dp[i][j]+d[j][k];
                        }
        int res = -1;
        for (int i = 0; i < tot; i++)
            if (dp[(1<<n)-1][i] != -1)
                if (res == -1 || res > dp[(1<<n)-1][i])
                    res = dp[(1<<n)-1][i];
        printf("%d\n",res);
    }
    return 0;
}
