#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct trie
{
    int next[700000][26],fail[700000],deep[700000];
    int L,root;
    int newnode()
    {
        for (int i = 0;i < 26;i++)
            next[L][i] = -1;
        return L++;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    int insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for (int i = 0;i < len;i++)
        {
            if (next[now][buf[i]-'a'] == -1)
                next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
            deep[now] = i+1;
        }
        return now;
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

    int last[700000],cnt[700000][2];
    //last[i]: 上一次到达i节点的长度
    //cnt[i][0]: 重叠有效时到i节点的次数
    //cnt[i][1]: 重叠无效时到i节点的次数（贪心）

    void query(char buf[])
    {
        int len = strlen(buf);
        for (int i = 0;i < L;i++)
        {
            last[i] = -1;
            for (int j = 0;j < 2;j++)
                cnt[i][j] = 0;
        }
        int now = root;
        for (int i = 0;i < len;i++)
        {
            now = next[now][buf[i]-'a'];
            for (int failnow = now;failnow != root;failnow = fail[failnow])
            {
                cnt[failnow][0]++;
                if (i-last[failnow] >= deep[failnow])
                {
                    last[failnow] = i;
                    cnt[failnow][1]++;
                }
            }
        }
    }
};

char s[110000],buf[10];
trie ac;
int n,typ[110000],pos[110000];

int main()
{
    int cas = 0;
    while (scanf("%s",s) != EOF)
    {
        ac.init();
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
        {
            scanf("%d%s",&typ[i],buf);
            pos[i] = ac.insert(buf);
        }
        ac.build();
        ac.query(s);
        printf("Case %d\n",++cas);
        for (int i = 0;i < n;i++)
            printf("%d\n",ac.cnt[pos[i]][typ[i]]);
        printf("\n");
    }
	return 0;
}
