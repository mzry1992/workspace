#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

int n;
int a[100];
bool use[100];
struct node
{
    int a[100];
    int step;
};
bool visit[1234567];
deque<node> Q;

int gethash(node now)
{
    int res = 0;
    for (int i = 1;i <= n;i++)
        res += res*10+now.a[i];
    return res;
}

node getnode(int a[],int step)
{
    node res;
    for (int i = 1;i <= n;i++)
        res.a[i] = a[i];
    res.step = 0;
    return res;
}

bool isans(node now)
{
    for (int i = 2;i <= n;i++)
        if (now.a[i-1] > now.a[i])  return false;
    return true;
}

node dopop(node now,int pos)
{
    node res;
    res.a[1] = now.a[pos];
    for (int i = 1;i < pos;i++)
        res.a[1+i] = now.a[i];
    for (int i = pos+1;i <= n;i++)
        res.a[i] = now.a[i];
    res.step = now.step+1;
    return res;
}

node doback(node now,int pos)
{
    node res;
    res.a[n] = now.a[pos];
    for (int i = 1;i < pos;i++)
        res.a[i] = now.a[i];
    for (int i = pos+1;i <= n;i++)
        res.a[i-1] = now.a[i];
    res.step = now.step+1;
    return res;
}

int BFS()
{
    memset(visit,false,sizeof(visit));
    Q.clear();
    Q.push_back(getnode(a,0));
    visit[gethash(Q.front())] = true;
    while (!Q.empty())
    {
        node now = Q.front();
        Q.pop_front();
        if (isans(now)) return now.step;
        for (int i = 1;i <= n;i++)
        {
            node updata;
            updata = dopop(now,i);
            if (visit[gethash(updata)] == false)
            {
                visit[gethash(updata)] = true;
                Q.push_back(updata);
            }
            updata = doback(now,i);
            if (visit[gethash(updata)] == false)
            {
                visit[gethash(updata)] = true;
                Q.push_back(updata);
            }
        }
    }
    return 0;
}

void DFS(int depth)
{
    if (depth == n+1)
    {
        for (int i = 1;i <= n;i++)
            printf("%d ",a[i]);
        printf(" : %d\n",BFS());
        return;
    }
    for (int i = 1;i <= n;i++)
    if (use[i] == false)
    {
        a[depth] = i;
        use[i] = true;
        DFS(depth+1);
        use[i] = false;
    }
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        //memset(use,false,sizeof(use));
        //DFS(1);
        for (int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        printf("%d\n",BFS());
    }
}
