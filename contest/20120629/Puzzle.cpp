#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct trie
{
    int next[50100][26],end[50100],fail[50100];
    int L,root,n;

    int newnode()
    {
        for (int i = 0;i < n;i++)
            next[L][i] = -1;
        end[L++] = false;
        return L-1;
    }

    void init(int _n)
    {
        n = _n;
        L = 0;
        root = newnode();
    }

    void insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for (int i = 0;i < len;i++)
        {
            if (next[now][buf[i]-'A'] == -1)
                next[now][buf[i]-'A'] = newnode();
            now = next[now][buf[i]-'A'];
        }
        end[now] = true;
    }

    void build()
    {
        queue<int> Q;
        for (int i = 0;i < n;i++)
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
            for (int i = 0;i < n;i++)
                if (next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }

    int dis[50100],tim[50100];
    bool inq[50100],del[50100];

    int check()
    {
        queue<int> Q;
        memset(dis,63,sizeof(dis));
        memset(inq,false,sizeof(inq));
        memset(tim,0,sizeof(tim));
        dis[root] = 0;
        inq[root] = true;
        Q.push(root);

        while (!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            inq[now] = false;

            tim[now]++;
            if (tim[now] == L)
                return 0;

            for (int i = 0;i < n;i++)
                if (end[next[now][i]] == false)
                {
                    if (dis[next[now][i]] > dis[now]-1)
                    {
                        dis[next[now][i]] = dis[now]-1;
                        if (inq[next[now][i]] == false)
                        {
                            inq[next[now][i]] = true;
                            Q.push(next[now][i]);
                        }
                    }
                }
        }

        int res = 0;
        for (int i = 0;i < L;i++)
            res = min(res,dis[i]);
        return -res;
    }

};

trie ac;
char buf[60];
int n,m;

int main()
{
    int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%d%d",&n,&m);
	    ac.init(n);
	    for (int i = 0;i < m;i++)
	    {
	        scanf("%s",buf);
	        ac.insert(buf);
	    }
	    ac.build();
	    int len = ac.check();
	    if (len == 0)
            puts("No");
        else
        {
        }
	}
	return 0;
}
