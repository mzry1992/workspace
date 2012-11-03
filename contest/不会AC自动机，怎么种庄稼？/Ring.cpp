#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
using namespace std;

struct trie
{
    int next[1100][26],fail[1100],end[1100];
    int L,root;
    int newnode()
    {
        for (int i = 0;i < 26;i++)
            next[L][i] = -1;
        end[L++] = 0;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char buf[],int val)
    {
        int len = strlen(buf);
        int now = root;
        for (int i = 0;i < len;i++)
        {
            if (next[now][buf[i]-'a'] == -1)
                next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
        }
        end[now] += val;
    }
    void build()
    {
        queue<int> Q;
        for (int i = 0;i < 26;i++)
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
            end[now] += end[fail[now]];
            for (int i = 0;i < 26;i++)
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

int n,m,h[100];
char buf[100][20];
trie ac;
int dp[51][1100];
char res[51][1100][51],ans[51],tmp[51];

bool cmp(char* a,char* b)
{
    int la = strlen(a);
    int lb = strlen(b);
    if (la == lb)
        return strcmp(a,b) < 0;
    return la < lb;
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0;i < m;i++)
            scanf("%s",buf[i]);
        for (int i = 0;i < m;i++)
            scanf("%d",&h[i]);
        ac.init();
        for (int i = 0;i < m;i++)
            ac.insert(buf[i],h[i]);
        ac.build();
        for (int i = 0;i <= n;i++)
            for (int j = 0;j < ac.L;j++)
                dp[i][j] = -19921005;
        dp[0][0] = 0;
        strcpy(ans,"");
        strcpy(res[0][0],"");
        int resv = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < ac.L;j++)
                if (dp[i][j] >= 0)
                    for (int k = 0;k < 26;k++)
                    {
                        int next = ac.next[j][k];
                        strcpy(tmp,res[i][j]);
                        int len = strlen(tmp);
                        tmp[len] = (char)('a'+k);
                        tmp[++len] = 0;
                        if (dp[i+1][next] < dp[i][j]+ac.end[next] ||
                            (dp[i+1][next] == dp[i][j]+ac.end[next] && cmp(tmp,res[i+1][next])))
                        {
                            dp[i+1][next] = dp[i][j]+ac.end[next];
                            strcpy(res[i+1][next],tmp);
                        }
                        if (resv == -1 || resv < dp[i+1][next] ||
                            (resv == dp[i+1][next] && cmp(res[i+1][next],ans)))
                        {
                            resv = dp[i+1][next];
                            strcpy(ans,res[i+1][next]);
                        }
                    }
        puts(ans);
    }
	return 0;
}
