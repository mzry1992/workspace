#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct trie
{
    int next[210*500][128],fail[210*500],end[210*500];
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
    /*-----------------------*/
    bool res[500];
    bool query(char buf[],int n,int webid)
    {
        int len = strlen(buf);
        int now = root;
        for (int i = 0;i < n;i++)
            res[i] = false;
        bool hasres = false;
        for (int i = 0;i < len;i++)
        {
            now = next[now][buf[i]];
            for (int failnow = now;failnow != root;failnow = fail[failnow])
                if (end[failnow] != -1)
                {
                    res[end[failnow]] = true;
                    hasres = true;
                }
        }
        if (hasres == false)    return false;
        printf("web %d:",webid);
        for (int i = 0;i < n;i++)
            if (res[i] == true)
                printf(" %d",i+1);
        printf("\n");
        return true;
    }
};

int n,m;
char buf[11000];
trie ac;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        ac.init();
        for (int i = 0;i < n;i++)
        {
            scanf("%s",buf);
            ac.insert(buf,i);
        }
        ac.build();
        int totweb = 0;
        scanf("%d",&m);
        for (int i = 0;i < m;i++)
        {
            scanf("%s",buf);
            if (ac.query(buf,n,i+1) == true)
                totweb++;
        }
        printf("total: %d\n",totweb);
    }
	return 0;
}
