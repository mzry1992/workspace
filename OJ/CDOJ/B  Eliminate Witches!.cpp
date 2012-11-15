#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

char buf[1000010];
int len,pre;
char namelist[50010][15];
int totname;

stack<int> fa;
int nowfa;

struct Edge
{
    int to,next;
};
int head[50010],L;
int tail[50010];
Edge edge[100010];

void DFS(int now)
{
    for (int i = head[now];i != -1;i = edge[i].next)
    {
        if (now != 0)
            printf("%d %d\n",now,edge[i].to);
        DFS(edge[i].to);
        if (now != 0)
            printf("%d %d\n",edge[i].to,now);
    }
}

void addedge(int u,int v)
{
    edge[L].to = v;
    edge[L].next = -1;
    if (tail[u] == -1)
        head[u] = L;
    else
        edge[tail[u]].next = L;
    tail[u]=L++;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%s",buf);
        len = strlen(buf);
        totname = 0;
        L = 0;
        while (!fa.empty())
            fa.pop();
        pre = nowfa = 0;
        head[nowfa] = tail[nowfa] = -1;
        fa.push(nowfa);
        for (int i = 0;i <= len;i++)
            if (i == len || buf[i] == '(' || buf[i] == ')' || buf[i] == ',')
            {
                if (pre < i)
                {
                    totname++;
                    for (int j = pre;j < i;j++)
                        namelist[totname][j-pre] = buf[j];
                    namelist[totname][i-pre] = 0;

                    head[totname] = tail[totname] = -1;

                    addedge(nowfa,totname);
                }
                if (buf[i] == '(')
                    fa.push(totname);
                else if (buf[i] == ')')
                    fa.pop();
                nowfa = fa.top();
                pre = i+1;
            }
        printf("%d\n",totname);
        for (int i = 1;i <= totname;i++)
            printf("%s\n",namelist[i]);
        DFS(0);
        puts("");
    }
    return 0;
}
