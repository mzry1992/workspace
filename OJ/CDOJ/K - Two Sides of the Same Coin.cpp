#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 1200;
int N;
bool Graph[MaxN+1][MaxN+1];
int Match[MaxN+1];
bool InQueue[MaxN+1],InPath[MaxN+1],InBlossom[MaxN+1];
int Head,Tail;
int Queue[MaxN+1];
int Start,Finish;
int NewBase;
int Father[MaxN+1],Base[MaxN+1];
int Count;
char name[1200][50];
char cando[1200][50];
int val[1200];

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
        if (Base[u] != NewBase) Father[u] = v;
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
        if (Finish > 0) AugmentPath();
    }
}

void PrintMatch()
{
    for (int u = 1;u <= N;u++)
    if (Match[u] > 0)
        Count++;
    printf("%d\n",Count/2);
    for (int u = 1;u <= N;u++)
    if (u < Match[u])
    {
        if (strcmp(cando[u],"statements") == 0)
            printf("%s %s\n",name[u],name[Match[u]]);
        else if (strcmp(cando[u],"testdata") == 0)
            printf("%s %s\n",name[Match[u]],name[u]);
        else
        {
            if (strcmp(cando[Match[u]],"testdata") == 0)
                printf("%s %s\n",name[u],name[Match[u]]);
            else
                printf("%s %s\n",name[Match[u]],name[u]);
        }
    }
}

int Abs(int x)
{
    if (x < 0)  return -x;
    return x;
}

int main()
{
    while (scanf("%d",&N) != EOF)
    {
        int u,v;
        memset(Graph,false,sizeof(Graph));
        for (int i = 1;i <= N;i++)
            scanf("%s%s%d",name[i],cando[i],&val[i]);
        for (int i = 1;i <= N;i++)
        for (int j = 1;j <= N;j++)
        if (i != j)
        if (Abs(val[i]-val[j]) == 2)
        {
            if (strcmp(cando[i],"anything") == 0)
                Graph[i][j] = Graph[j][i] = true;
            if (strcmp(cando[j],"anything") == 0)
                Graph[i][j] = Graph[j][i] = true;
            if (strcmp(cando[i],"statements") == 0 && strcmp(cando[j],"testdata") == 0)
                Graph[i][j] = Graph[j][i] = true;
            if (strcmp(cando[j],"statements") == 0 && strcmp(cando[i],"testdata") == 0)
                Graph[i][j] = Graph[j][i] = true;
        }
        Edmonds();
        PrintMatch();
    }
}
