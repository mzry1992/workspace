#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct trie
{
    int next[1100][4],fail[1100];
    bool end[1100];
    int L,root;
    int charid(char ch)
    {
        if (ch == 'A')  return 0;
        if (ch == 'T')  return 1;
        if (ch == 'C')  return 2;
        return 3;
    }
    int newnode()
    {
        for (int i = 0; i < 4; i++)
            next[L][i] = -1;
        end[L++] = false;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for (int i = 0; i < len; i++)
        {
            if (next[now][charid(buf[i])] == -1)
                next[now][charid(buf[i])] = newnode();
            now = next[now][charid(buf[i])];
        }
        end[now] = true;
    }
    void build()
    {
        queue<int> Q;
        for (int i = 0; i < 4; i++)
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
            end[now] |= end[fail[now]];
            for (int i = 0; i < 4; i++)
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

trie ac;
char buf[1100];
int n,dp[1100][1100];

int main()
{
    int cas = 1;
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        ac.init();
        for (int i = 0; i < n; i++)
        {
            scanf("%s",buf);
            ac.insert(buf);
        }
        ac.build();
        scanf("%s",buf);
        memset(dp,-1,sizeof(dp));
        dp[0][0] = 0;
        int len = strlen(buf);
        for (int i = 0; i < len; i++)
            for (int j = 0; j < ac.L; j++)
                if (dp[i][j] >= 0)
                    for (int k = 0; k < 4; k++)
                    {
                        int next = ac.next[j][k];
                        int nowid = ac.charid(buf[i]);
                        if (ac.end[next] == false)
                        {
                            if (dp[i+1][next] == -1 || dp[i+1][next] > dp[i][j]+((k == nowid)?0:1))
                                dp[i+1][next] = dp[i][j]+((k == nowid)?0:1);
                        }
                    }
        int res = -1;
        for (int i = 0;i < ac.L;i++)
            if (dp[len][i] >= 0)
                if (res == -1 || res > dp[len][i])
                    res = dp[len][i];
        printf("Case %d: %d\n",cas++,res);
    }
    return 0;
}
