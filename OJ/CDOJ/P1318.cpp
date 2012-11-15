#include <iostream>
using namespace std;

const int MAXN = 10000;
const int MAXM = 20000;
int n,m,u,v;
struct graph//邻接边 
{
       int next;
       int to;
}g[MAXN+2*MAXM];
int totg;
int visit[MAXN];//标记结点i是否访问过 
int pre[MAXN];//标记结点i的入栈时间 
int low[MAXN];//标记以该节点为根的子树中任何回边所引用的最小前序编号 
int father[MAXN];//结点i的父节点 
int bic[MAXN]; //双连通分量i的度 
int cnt,ans;

int find(int u,int v)//找是否已经存在边u-->v 
{
    int i;
    for (i = g[u].next;i != -1;i = g[i].next)
        if (g[i].to == v)   return true;
    return false;
}

void addpath(int u,int v)//加边操作 
{
     if (find(u,v) == true)  return;//如果有重边那么不用加 
     totg++;
     g[totg].to = v;   g[totg].next = g[u].next;    g[u].next = totg;
}

void readin()//输入 
{
     int i;
     scanf("%d %d",&n,&m);
     memset(g,-1,sizeof(g));//初始化图 
     totg = n;
     for (i = 1;i <= m;i++)
     {
         scanf("%d %d",&u,&v);
         addpath(u,v);//加边 
         addpath(v,u);
     }
}

void bridgeR(int now)//求图的桥 
{
     int t,v;
     cnt++;      
     pre[now] = cnt;//记录入栈时间    
     low[now] = pre[now];//初始化low 
     visit[now] = true;//标记访问过结点now 
     for (t = g[now].next; t != -1;t = g[t].next)//枚举所有边 
     {
         v = g[t].to;
         if (visit[v] == false)//如果没有访问过 
         {
                      father[v] = now;//记录父节点 
                      bridgeR(v);//访问v 
         }
         if ((low[now] > low[v]) && (father[now] != v)) low[now] = low[v];//更新low 
     }    
}

void work()
{
     int i,j,v;
     memset(visit,false,sizeof(visit));//初始化各个数组 
     memset(pre,0,sizeof(pre));
     memset(low,0,sizeof(low));
     memset(bic,0,sizeof(bic));
     cnt = 0;//入栈时间标记 
     for (i = 1;i <= n;i++)//枚举结点 
     if (visit[i] == false)
     {
                  father[i] = 0;
                  bridgeR(i);
     }
     //结束后low数组就是结点i属于哪个双连通分量 
     for (i = 1;i <= n;i++)
     for (j = g[i].next;j != -1;j = g[j].next)
     {
         v = g[j].to;
         if (low[v] != low[i])//如果两边不在同一个双连通分量，那么计算度 
         {
                    bic[low[v]]++;
                    bic[low[i]]++;
         }
     }
     for (i = 1;i <= n;i++)
     if (bic[i] == 2)//本来是计算度为1的双连通分量数的，但是由于我用的是有向图保存，计算度的时候会有重复，所以就计算度为2的双连通分量了 
        ans++;
     for (i = 1;i <= n;i++)
         cout << i << ' ' << pre[i] << ' ' << low[i] << endl;
     system("pause");
}

void output()
{
     //有ans个度为1的双连通分量，那么至少要添加(ans+1)/2条边才能满足条件 
     printf("%d\n",(ans+1)/2);//输出 
}

int main()
{
    readin();
    work();
    output();
}
