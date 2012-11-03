#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct trie
{
    int next[50*10001][26],fail[50*10001],end[50*10001],root,L;
    int newnode(int node)
    {
        for (int i = 0; i < 26; i++)
            next[node][i] = -1;
        end[node] = 0;
        return node;
    }
    void init()
    {
        L = 0;
        root = newnode(L++);
    }
    void insert(char s[])
    {
        int len = strlen(s);
        int now = root;
        for (int i = 0; i < len; i++)
        {
            if (next[now][s[i]-'a'] == -1)
                next[now][s[i]-'a'] = newnode(L++);
            now = next[now][s[i]-'a'];
        }
        end[now]++;
    }
    void build()
    {
        queue<int> Q;
        fail[root] = root;
        for (int i = 0; i < 26; i++)
            if (next[root][i] != -1)
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
            else
                next[root][i] = root;
        while (!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for (int i = 0; i < 26; i++)
                if (next[now][i] != -1)
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
                else
                    next[now][i] = next[fail[now]][i];
        }
    }
    int query(char buf[])
    {
        int len = strlen(buf);
        int res = 0,now = 0;
        for (int i = 0; i < len; i++)
        {
            now = next[now][buf[i]-'a'];
            for (int failnow = now; failnow != root; failnow = fail[failnow])
            {
                res += end[failnow];
                end[failnow] = 0;
            }
        }
        return res;
    }
};

int n;
trie ac;
char buf[1000001];

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d",&n);
        ac.init();
        for (int i = 0; i < n; i++)
        {
            scanf("%s",buf);
            ac.insert(buf);
        }
        ac.build();
        scanf("%s",buf);
        printf("%d\n",ac.query(buf));
    }
    return 0;
}
