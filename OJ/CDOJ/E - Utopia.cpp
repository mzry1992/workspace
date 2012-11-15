#include <cstdio>
#include <iostream>
using namespace std;

int n,m;
int f1,f2,l;
int Qa,Qb;

struct nodetype
{
       int next;
       int tail;
       int node;
       int dis;
}nodelist[101000],no[50100];
struct question
{
       int next;
       int node;
       int no;
}Qlist[3000100],Q[1500100];
int totn;
int dis[50100];
int ans[1500100];
int f[50100];
int mark[50100];
int Qc[150100];

void add(int s,int t,int d)
{
     mark[s] = true;
     totn++;
     nodelist[totn].node = t;
     nodelist[totn].next = 0;
     nodelist[totn].dis = d;
     if (no[s].next == 0)
                    no[s].tail = no[s].next = totn;
     else
     {
         nodelist[no[s].tail].next = totn;
         no[s].tail = totn;
     }
}

void addQ(int s,int t,int n)
{
     totn++;
     Qlist[totn].next = 0;
     Qlist[totn].node = t;
     Qlist[totn].no = n;
     if (Q[s].next == 0)
        Q[s].next = totn;
     else
     {
         int temp = Q[s].next;
         Q[s].next = totn;
         Qlist[totn].next = temp;
     }
}

int find(int x)
{
    if (f[x] != x) f[x] = find(f[x]);
    return f[x];
}

void DFS(int u,int dist)
{
     int i,j,v,LCA;
     dis[u] = dist;
     for (i = no[u].next;i != 0;i = nodelist[i].next)
     {
             v = nodelist[i].node;
             DFS(v,dist+nodelist[i].dis);
             f[v] = u;
     }
     for (i = Q[u].next;i != 0;i = Qlist[i].next)
     {
         v = Qlist[i].node;
         if (mark[v] == true)
         {
                LCA = find(v);
                ans[Qlist[i].no] = LCA;
        }
     }
     mark[u] = true;
}

int delet(int s,int t)
{
     int now,v,pre;
     now = no[s].next;
     v = nodelist[now].node;
     if (v == t)
     {
           no[s].next = nodelist[now].next;
           return 0;
     }
     pre = now;
     now = nodelist[now].next;
     while (now != 0)
     {
           v = nodelist[now].node;
           if (v == t)
           {
                 nodelist[pre].next = nodelist[now].next;
                 return 0;
           }
           pre = now;
           now = nodelist[now].next;
     }
     return 0;
}

void creat(int u)
{
     int i,v;
     for (i = no[u].next;i != 0;i = nodelist[i].next)
     {
         v = nodelist[i].node;
         delet(v,u);
         creat(v);
     }
}

int main()
{
    int ft = 0;
    while (scanf("%d",&n) != EOF)
    {
        totn = 0;
        for (int i = 1;i <= n;i++)
        {
            Q[i].next = 0;
            no[i].next = 0;
        }
        for (int i = 1;i <= n-1;i++)
        {
            scanf("%d%d",&f1,&f2);
            f1++;
            f2++;
            add(f1,f2,1);
            add(f2,f1,1);
        }
        creat(1);
        scanf("%d",&m);
        totn = 0;
        for (int i = 1;i <= m;i++)
        {
            ans[i*3-2] = ans[i*3-1] = ans[i*3] = 0;
            scanf("%d%d%d",&Qa,&Qb,&Qc[i]);
            Qa++;
            Qb++;
            Qc[i]++;
            addQ(Qa,Qb,i*3-2);
            addQ(Qb,Qa,i*3-2);
            if (Qa == Qb)
                ans[i*3-2] = Qa;
            addQ(Qa,Qc[i],i*3-1);
            addQ(Qc[i],Qa,i*3-1);
            if (Qa == Qc[i])
                ans[i*3-1] = Qa;
            addQ(Qc[i],Qb,i*3);
            addQ(Qb,Qc[i],i*3);
            if (Qc[i] == Qb)
                ans[i*3] = Qb;
        }
        for (int i = 1;i <= n;i++)
        {
            f[i] = i;
            mark[i] = false;
        }
        DFS(1,0);
        ft++;
        printf("Case %d:\n",ft);
        for (int i = 1;i <= m;i++)
        {
            if ((ans[i*3-2] == ans[i*3] && ans[i*3-1] == Qc[i]) ||
                (ans[i*3-2] == ans[i*3-1] && ans[i*3] == Qc[i]))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
