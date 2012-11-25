#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 111;
int N;
bool Graph[MaxN][MaxN];
int Match[MaxN];
bool InQueue[MaxN],InPath[MaxN],InBlossom[MaxN];
int Head,Tail;
int Queue[MaxN+1];
int Start,Finish;
int NewBase;
int Father[MaxN],Base[MaxN];
int Count;

void CreateGraph()
{
    int u,v;
    memset(Graph,false,sizeof(Graph));
    int m;
    scanf("%d%d",&N,&m);
    for (int i = 0;i < m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        Graph[u][v] = Graph[v][u] = true;
    }
}
void Push(int u)
{
    Queue[Tail] = u;
    Tail++;
    InQueue[u] = true;
}
int Pop()
{
    int res = Queue[Head];
    Head++;
    return res;
}
int FindCommonAncestor(int u,int v)
{
    memset(InPath,false,sizeof(InPath));
    while (true)
    {
        u = Base[u];
        InPath[u] = true;
        if (u == Start) break;
        u = Father[Match[u]];
    }
    while (true)
    {
        v = Base[v];
        if (InPath[v])  break;
        v = Father[Match[v]];
    }
    return v;
}
void ResetTrace(int u)
{
    int v;
    while (Base[u] != NewBase)
    {
        v = Match[u];
        InBlossom[Base[u]] = InBlossom[Base[v]] = true;
        u = Father[v];
        if (Base[u] != NewBase)
            Father[u] = v;
    }
}
void BlossomContract(int u,int v)
{
    NewBase = FindCommonAncestor(u,v);
    memset(InBlossom,false,sizeof(InBlossom));
    ResetTrace(u);
    ResetTrace(v);
    if (Base[u] != NewBase) Father[u] = v;
    if (Base[v] != NewBase) Father[v] = u;
    for (int tu = 1;tu <= N;tu++)
        if (InBlossom[Base[tu]])
        {
            Base[tu] = NewBase;
            if (!InQueue[tu])   Push(tu);
        }
}
void FindAugmentingPath()
{
    memset(InQueue,false,sizeof(InQueue));
    memset(Father,0,sizeof(Father));
    for (int i = 1;i <= N;i++)
        Base[i] = i;
    Head = Tail = 1;
    Push(Start);
    Finish = 0;
    while (Head < Tail)
    {
        int u = Pop();
        for (int v = 1;v <= N;v++)
            if (Graph[u][v] && (Base[u] != Base[v]) && (Match[u] != v))
            {
                if ((v == Start) || ((Match[v] > 0) && (Father[Match[v]] > 0)))
                    BlossomContract(u,v);
                else if (Father[v] == 0)
                {
                    Father[v] = u;
                    if (Match[v] > 0)
                        Push(Match[v]);
                    else
                    {
                        Finish = v;
                        return;
                    }
                }
            }
    }
}
void AugmentPath()
{
    int u,v,w;
    u = Finish;
    while (u > 0)
    {
        v = Father[u];
        w = Match[v];
        Match[v] = u;
        Match[u] = v;
        u = w;
    }
}
void Edmonds()
{
    memset(Match,0,sizeof(Match));
    for (int u = 1;u <= N;u++)
        if (Match[u] == 0)
        {
            Start = u;
            FindAugmentingPath();
            if (Finish > 0)
                AugmentPath();
        }
}

int id[MaxN],totid,cnt[MaxN];

bool solve(int i)
{
    memset(cnt,0,sizeof(cnt));
    for (int j = 1;j <= N;j++)
        if (Graph[i][j])
            cnt[id[j]]++;
    for (int j = 1;j <= totid;j++)
        if (cnt[j] == 1)
        {
            id[i] = j;
            return true;
        }
    for (int j = 1;j <= totid;j++)
        if (cnt[j] == 2)
        {
            for (int k = 1;k <= N;k++)
                if (Graph[i][k])
                {
                    id[k] = 0;
                    id[i] = j;
                    if (solve(k))
                        return true;
                    id[k] = j;
                    id[i] = 0;
                }
        }
    return false;
}

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    CreateGraph();
	    Edmonds();
	    memset(id,0,sizeof(id));
	    totid = 1;
	    for (int i = 1;i <= N;i++)
            if (Match[i] > 0 && id[i] == 0)
                id[i] = id[Match[i]] = totid++;
        totid--;

        for (int i = 1;i <= N;i++)
            if (id[i] == 0)
                solve(i);

        for (int i = 1;i <= N;i++)
            printf("%d ",id[i]);
        printf("\n");
	}
	return 0;
}
