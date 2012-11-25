#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct trie
{
    int next[110][26],fail[110],end[110];
    int L,root;
    int newnode()
    {
        for (int i = 0; i < 26; i++)
            next[L][i] = -1;
        end[L++] = 0;
        return L-1;
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
            if (next[now][buf[i]-'a'] == -1)
                next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
        }
        end[now] |= (1<<id);
    }
    void build()
    {
        queue<int> Q;
        for (int i = 0; i < 26; i++)
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
            for (int i = 0; i < 26; i++)
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

int n,m,K;
trie ac;
char buf[20];
const int mod = 20090717;
int dp[2][110][1<<10];

int countbit(int val)
{
    int res = 0;
    for (int i = 0; i < m; i++)
        if (((val>>i)&1) == 1)
            res++;
    return res;
}

int main()
{
    while (true)
    {
        scanf("%d%d%d",&n,&m,&K);
        if (n == 0 && m == 0 && K == 0) break;
        ac.init();
        for (int i = 0; i < m; i++)
        {
            scanf("%s",buf);
            ac.insert(buf,i);
        }
        ac.build();
        memset(dp,0,sizeof(dp));
        dp[0][0][0] = 1;
        bool flag = 0;
        for (int i = 0; i < n; i++,flag = !flag)
        {
            for (int j = 0; j < ac.L; j++)
                for (int end = 0; end < (1<<m); end++)
                    dp[!flag][j][end] = 0;
            for (int j = 0; j < ac.L; j++)
                for (int end = 0; end < (1<<m); end++)
                    if (dp[flag][j][end] > 0)
                        for (int k = 0; k < 26; k++)
                        {
                            int next = ac.next[j][k],nextend = end|ac.end[next];
                            dp[!flag][next][nextend] = (dp[!flag][next][nextend]+dp[flag][j][end])%mod;
                        }
        }
        int res = 0;
        for (int end = 0; end < (1<<m); end++)
            if (countbit(end) >= K)
                for (int i = 0; i < ac.L; i++)
                    res = (res+dp[flag][i][end])%mod;
        printf("%d\n",res);
    }
    return 0;
}
