#include <iostream>
#include <queue>
using namespace std;

const int MAXV = 20000;
const int MAXE = 200000;
const int MAX = 1000000000;
int tc,fc;
int n,m,tu,tv,tl;
struct graph
{
       int v,l,next;
}g[MAXV+MAXE];//邻接表 
int totg;
int start,end;
int dis[MAXV][2],ans[MAXV][2];//距离，有多少条路 
int visit[MAXV][2];//表示状态是否到达过 
struct node//优先队列 
{
       int v,flag;
       node(int tv,int tflag) {v = tv;flag = tflag;}
       bool operator < (const node temp) const
       {
            return dis[v][flag] > dis[temp.v][temp.flag];//小根堆 
       }
};

void addpath(int tu,int tv,int tl)//增加一条边 
{
     totg++;
     g[totg].v = tv;    g[totg].l = tl;    g[totg].next = g[tu].next;  g[tu].next = totg;
}

void readin()//读入数据 
{
     int i;
     scanf("%d %d",&n,&m);
     memset(g,-1,sizeof(g));//赋初值 
     totg = n;
     for (i = 1;i <= m;i++)
     {
         scanf("%d %d %d",&tu,&tv,&tl);
         addpath(tu,tv,tl);//加边 
     }     
     scanf("%d %d",&start,&end);//读入出发点，目的地 
}

void work()//dijkstra 
{
     int i,v,l,u,flag,temp;
     memset(ans,0,sizeof(ans));
     memset(visit,false,sizeof(visit));
     for (i = 1;i <= n;i++)
         dis[i][0] = dis[i][1] = MAX;//赋最大值 
     priority_queue<node> Q;//构造优先队列Q 
     while (!Q.empty())   Q.pop();//如果Q不为空那么清空 
     Q.push(node(start,0));//加入初始状态 
     dis[start][0] = 0;
     ans[start][0] = 1;
     while (!Q.empty())//如果队列不为空 
     {
           node top = Q.top();//取队头 
           Q.pop();//弹出队头 
           u = top.v;  flag = top.flag;
           if (visit[u][flag] == true) continue;//如果访问过这个状态那么跳过 
           visit[u][flag] = true;//标记访问过这个状态 
           for (i = g[u].next;i != -1;i = g[i].next)//枚举所有相邻的点 
           {
               v = g[i].v;       l = g[i].l;
               temp = dis[u][flag]+l;//新的距离 
               if (temp < dis[v][0])//情况1 
               {
                                  if (dis[v][0] != MAX) 
                                  {
                                                dis[v][1] = dis[v][0];
                                                ans[v][1] = ans[v][0];
                                                Q.push(node(v,1));
                                  }
                                  dis[v][0] = temp;
                                  ans[v][0] = ans[u][flag];
                                  Q.push(node(v,0));
               }
               else
               if (temp == dis[v][0])            ans[v][0] += ans[u][flag];//情况2 
               else
               if (temp < dis[v][1])//情况3 
               {
                                  dis[v][1] = temp;
                                  ans[v][1] = ans[u][flag];
                                  Q.push(node(v,1));
               }
               else  
               if (temp == dis[v][1])            ans[v][1] += ans[u][flag];//情况4 
           }
     }
}

void output()//输出 
{
     if (dis[end][0] == dis[end][1]-1)         ans[end][0] += ans[end][1];//如果存在比最短路长1的次短路 
     printf("%d\n",ans[end][0]);//输出答案 
}

int main()
{
    scanf("%d",&tc);
    for (fc = 1;fc <= tc;fc++)
    {
        readin();//读入 
        work();//Dijkstra 
        output();//输出 
    }
    return 0;
}
