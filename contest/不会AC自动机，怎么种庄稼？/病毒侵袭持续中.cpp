#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct trie
{
    int next[1000*51][128],fail[1000*51],end[1000*51];
    int L,root;
    int newnode(int pos)
    {
        for (int i = 0;i < 128;i++)
            next[pos][i] = -1;
        end[pos] = -1;
        return pos;
    }
    void init()
    {
        L = 0;
        root = newnode(L++);
    }
    void insert(char buf[],int id)
    {
        int len = strlen(buf);
        int now = root;
        for (int i = 0;i < len;i++)
        {
            if (next[now][buf[i]] == -1)
                next[now][buf[i]] = newnode(L++);
            now = next[now][buf[i]];
        }
        end[now] = id;
    }
    void build()
    {
        queue<int> Q;
        for (int i = 0;i < 128;i++)
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
            for (int i = 0;i < 128;i++)
                if (next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    int res[1000];
    void query(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        memset(res,0,sizeof(res));
        for (int i = 0;i < len;i++)
        {
            now = next[now][buf[i]];
            for (int failnow = now;failnow != root;failnow = fail[failnow])
                if (end[failnow] != -1)
                    res[end[failnow]]++;
        }
    }
};

int n;
char dic[1000][51],buf[2000001];
trie ac;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        ac.init();
        for (int i = 0;i < n;i++)
        {
            scanf("%s",dic[i]);
            ac.insert(dic[i],i);
        }
        ac.build();
        scanf("%s",buf);
        ac.query(buf);
        for (int i = 0;i < n;i++)
            if (ac.res[i] != 0)
                printf("%s: %d\n",dic[i],ac.res[i]);
    }
	return 0;
}
