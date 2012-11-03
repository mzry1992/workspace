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
}g[MAXV+MAXE];//�ڽӱ� 
int totg;
int start,end;
int dis[MAXV][2],ans[MAXV][2];//���룬�ж�����· 
int visit[MAXV][2];//��ʾ״̬�Ƿ񵽴�� 
struct node//���ȶ��� 
{
       int v,flag;
       node(int tv,int tflag) {v = tv;flag = tflag;}
       bool operator < (const node temp) const
       {
            return dis[v][flag] > dis[temp.v][temp.flag];//С���� 
       }
};

void addpath(int tu,int tv,int tl)//����һ���� 
{
     totg++;
     g[totg].v = tv;    g[totg].l = tl;    g[totg].next = g[tu].next;  g[tu].next = totg;
}

void readin()//�������� 
{
     int i;
     scanf("%d %d",&n,&m);
     memset(g,-1,sizeof(g));//����ֵ 
     totg = n;
     for (i = 1;i <= m;i++)
     {
         scanf("%d %d %d",&tu,&tv,&tl);
         addpath(tu,tv,tl);//�ӱ� 
     }     
     scanf("%d %d",&start,&end);//��������㣬Ŀ�ĵ� 
}

void work()//dijkstra 
{
     int i,v,l,u,flag,temp;
     memset(ans,0,sizeof(ans));
     memset(visit,false,sizeof(visit));
     for (i = 1;i <= n;i++)
         dis[i][0] = dis[i][1] = MAX;//�����ֵ 
     priority_queue<node> Q;//�������ȶ���Q 
     while (!Q.empty())   Q.pop();//���Q��Ϊ����ô��� 
     Q.push(node(start,0));//�����ʼ״̬ 
     dis[start][0] = 0;
     ans[start][0] = 1;
     while (!Q.empty())//������в�Ϊ�� 
     {
           node top = Q.top();//ȡ��ͷ 
           Q.pop();//������ͷ 
           u = top.v;  flag = top.flag;
           if (visit[u][flag] == true) continue;//������ʹ����״̬��ô���� 
           visit[u][flag] = true;//��Ƿ��ʹ����״̬ 
           for (i = g[u].next;i != -1;i = g[i].next)//ö���������ڵĵ� 
           {
               v = g[i].v;       l = g[i].l;
               temp = dis[u][flag]+l;//�µľ��� 
               if (temp < dis[v][0])//���1 
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
               if (temp == dis[v][0])            ans[v][0] += ans[u][flag];//���2 
               else
               if (temp < dis[v][1])//���3 
               {
                                  dis[v][1] = temp;
                                  ans[v][1] = ans[u][flag];
                                  Q.push(node(v,1));
               }
               else  
               if (temp == dis[v][1])            ans[v][1] += ans[u][flag];//���4 
           }
     }
}

void output()//��� 
{
     if (dis[end][0] == dis[end][1]-1)         ans[end][0] += ans[end][1];//������ڱ����·��1�Ĵζ�· 
     printf("%d\n",ans[end][0]);//����� 
}

int main()
{
    scanf("%d",&tc);
    for (fc = 1;fc <= tc;fc++)
    {
        readin();//���� 
        work();//Dijkstra 
        output();//��� 
    }
    return 0;
}
