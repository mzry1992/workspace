#include <iostream>
using namespace std;

const int MAXN = 10000;
const int MAXM = 20000;
int n,m,u,v;
struct graph//�ڽӱ� 
{
       int next;
       int to;
}g[MAXN+2*MAXM];
int totg;
int visit[MAXN];//��ǽ��i�Ƿ���ʹ� 
int pre[MAXN];//��ǽ��i����ջʱ�� 
int low[MAXN];//����Ըýڵ�Ϊ�����������κλر������õ���Сǰ���� 
int father[MAXN];//���i�ĸ��ڵ� 
int bic[MAXN]; //˫��ͨ����i�Ķ� 
int cnt,ans;

int find(int u,int v)//���Ƿ��Ѿ����ڱ�u-->v 
{
    int i;
    for (i = g[u].next;i != -1;i = g[i].next)
        if (g[i].to == v)   return true;
    return false;
}

void addpath(int u,int v)//�ӱ߲��� 
{
     if (find(u,v) == true)  return;//������ر���ô���ü� 
     totg++;
     g[totg].to = v;   g[totg].next = g[u].next;    g[u].next = totg;
}

void readin()//���� 
{
     int i;
     scanf("%d %d",&n,&m);
     memset(g,-1,sizeof(g));//��ʼ��ͼ 
     totg = n;
     for (i = 1;i <= m;i++)
     {
         scanf("%d %d",&u,&v);
         addpath(u,v);//�ӱ� 
         addpath(v,u);
     }
}

void bridgeR(int now)//��ͼ���� 
{
     int t,v;
     cnt++;      
     pre[now] = cnt;//��¼��ջʱ��    
     low[now] = pre[now];//��ʼ��low 
     visit[now] = true;//��Ƿ��ʹ����now 
     for (t = g[now].next; t != -1;t = g[t].next)//ö�����б� 
     {
         v = g[t].to;
         if (visit[v] == false)//���û�з��ʹ� 
         {
                      father[v] = now;//��¼���ڵ� 
                      bridgeR(v);//����v 
         }
         if ((low[now] > low[v]) && (father[now] != v)) low[now] = low[v];//����low 
     }    
}

void work()
{
     int i,j,v;
     memset(visit,false,sizeof(visit));//��ʼ���������� 
     memset(pre,0,sizeof(pre));
     memset(low,0,sizeof(low));
     memset(bic,0,sizeof(bic));
     cnt = 0;//��ջʱ���� 
     for (i = 1;i <= n;i++)//ö�ٽ�� 
     if (visit[i] == false)
     {
                  father[i] = 0;
                  bridgeR(i);
     }
     //������low������ǽ��i�����ĸ�˫��ͨ���� 
     for (i = 1;i <= n;i++)
     for (j = g[i].next;j != -1;j = g[j].next)
     {
         v = g[j].to;
         if (low[v] != low[i])//������߲���ͬһ��˫��ͨ��������ô����� 
         {
                    bic[low[v]]++;
                    bic[low[i]]++;
         }
     }
     for (i = 1;i <= n;i++)
     if (bic[i] == 2)//�����Ǽ����Ϊ1��˫��ͨ�������ģ������������õ�������ͼ���棬����ȵ�ʱ������ظ������Ծͼ����Ϊ2��˫��ͨ������ 
        ans++;
     for (i = 1;i <= n;i++)
         cout << i << ' ' << pre[i] << ' ' << low[i] << endl;
     system("pause");
}

void output()
{
     //��ans����Ϊ1��˫��ͨ��������ô����Ҫ���(ans+1)/2���߲����������� 
     printf("%d\n",(ans+1)/2);//��� 
}

int main()
{
    readin();
    work();
    output();
}
