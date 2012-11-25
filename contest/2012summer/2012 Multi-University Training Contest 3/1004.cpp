#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Trie
{
    int next[16000][10],fail[16000];
    int end[16000];
    int root,L;
    int newnode(int pos)
    {
        for (int i = 0; i < 10; i++)
            next[pos][i] = -1;
        end[pos] = 0;
        return pos;
    }
    void init()
    {
        L = 0;
        root = newnode(L++);
    }
    int getch(char ch)
    {
        return ch-'0';
    }
    void insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for (int i = 0; i < len; i++)
        {
            if (next[now][getch(buf[i])] == -1)
                next[now][getch(buf[i])] = newnode(L++);
            now = next[now][getch(buf[i])];
        }
        end[now]++;
    }
    void build()
    {
        queue<int> Q;
        for (int i = 0; i < 10; i++)
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
            for (int i = 0; i < 10; i++)
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

Trie ac;
int n,m,len,res;
char buf[11];
bool vis[16000];

void DFS(int cur,int pos,int lim)
{
    if (cur == len)
    {
        if (vis[pos] == false)
        {
            res += ac.end[pos];
            vis[pos] = true;
        }
        if (lim > 0)
            for (int i = 0; i < 10; i++)
                DFS(cur,ac.next[pos][i],lim-1);
        return;
    }
    DFS(cur+1,ac.next[pos][buf[cur]-'0'],lim);
    if (lim > 0)
    {
        for (int i = 0; i < 10; i++)
        {
            DFS(cur+1,ac.next[pos][i],lim-1);
            DFS(cur,ac.next[pos][i],lim-1);
        }
        DFS(cur+1,pos,lim-1);
    }
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d%d",&n,&m);
        ac.init();
        for (int i = 0; i < n; i++)
        {
            scanf("%s",buf);
            ac.insert(buf);
        }
        ac.build();
        printf("Case #%d:\n",cas);
        for (int i = 0; i < m; i++)
        {
            int k;
            scanf("%s%d",buf,&k);
            res = 0;
            len = strlen(buf);
            memset(vis,false,sizeof(vis));
            DFS(0,ac.root,k);
            printf("%d\n",res);
        }
    }
    return 0;
}
