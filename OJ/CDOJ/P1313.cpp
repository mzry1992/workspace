#include <stdio.h>

int n,m,k,i,j;
int f1,f2,l;
int Qa,Qb;
/*
��������Ĵ��淽ʽ 
*/
struct nodetype//����������ͣ������棩 
{
       int next;//��һ����� 
       int tail;//��¼�����β��� 
       int node;//��¼��ǰ����������Ǹ�ũ�� 
       int dis;//��¼�˵��붥��ľ��� 
}nodelist[100000],no[50000];//nodelistΪ��������no���涥�� 
struct question//����ѯ�ʵ����� 
{
       int next;//��һ������ͷ����ѯ�� 
       int node;//ѯ�ʵ���һ���� 
       int no;//ѯ�ʵı�� 
}Qlist[100000],Q[50000];//Qlist������Q����ͷ��㣨���㣩 
int totn;
int dis[50000];//�����I�������ľ��� 
int ans[50000];//����� 
int f[50000];//���游�ڵ� 
int mark[50000];//��ǽ�� 

void add(int s,int t,int d)//����һ����s��t����Ϊd�ı� 
{
     mark[s] = true; 
     totn++;//����+1 
     nodelist[totn].node = t;//��� 
     nodelist[totn].next = 0;//��һ����㣬0����NUL 
     nodelist[totn].dis = d;//���� 
     if (no[s].next == 0)//�����ǰ����ı���Ϊ0��ֱ�Ӽ��ں��� 
                    no[s].tail = no[s].next = totn;
     else
     {
         nodelist[no[s].tail].next = totn;   //������������ĩβ 
         no[s].tail = totn;   //����ĩβָ�� 
     }
}

void addQ(int s,int t,int n)//�����ѯ���������add�������� 
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
     
int find(int x)//���Ҹ��ڵ㣬˳��·��ѹ�� 
{
    if (f[x] != x) f[x] = find(f[x]);
    return f[x];
}

void DFS(int u,int dist)//LCA�����㷨 
{
     int i,j,v,LCA;
     dis[u] = dist;//��¼u�����ڵ�ľ��� 
     for (i = no[u].next;i != 0;i = nodelist[i].next)//����u��ÿ������v 
     {
             v = nodelist[i].node; 
             DFS(v,dist+nodelist[i].dis);//������ȥ��ע��v�����ڵ�ľ������ 
             f[v] = u;//�ϲ����� 
     }
     for (i = Q[u].next;i != 0;i = Qlist[i].next)//���ڹ���u��ÿ��ѯ�� 
     {
         v = Qlist[i].node;
         if (mark[v] == true)//���v�������� 
         {
                                     LCA = find(v);//�����ǵĹ������ȣ�����v�ĸ��ڵ㣩 
                                     ans[Qlist[i].no] = dis[u]+dis[v]-2*dis[LCA];//�������u�����ĸ��ڵ�ľ������v�����ĸ��ڵ�ľ����ȥ���������ǵ�LCA�������ڵ�ľ��루����ͼ��֪���ˣ� 
         }
     }
     mark[u] = true;//��ǽ��u�������� 
}

int delet(int s,int t)//ɾ������Ҫ�ıߣ���ͼ����һ�������������st��ʾɾ����s��t�ı� 
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

void creat(int u)//������uΪ���ڵ��� 
{
     int i,v;
     for (i = no[u].next;i != 0;i = nodelist[i].next)
     {
         v = nodelist[i].node;
         delet(v,u);//ɾ����v��u�ı� 
         creat(v);//������ȥ 
     }
}

int main()
{
    scanf("%d %d",&n,&m);
    for (i = 1;i <= n;i++)
    {
        Q[i].next = 0;
        no[i].next = 0;
    }
    totn = 0; 
    for (i = 1;i <= m;i++)
    {
        scanf("%d %d %d",&f1,&f2,&l);
        getchar();     
        getchar(); 
        add(f1,f2,l);
        add(f2,f1,l);
    } 
    creat(1);//������ 
    scanf("%d",&k);
    totn = 0;
    for (i = 1;i <= k;i++)
    {
        scanf("%d %d",&Qa,&Qb);
        addQ(Qa,Qb,i);
        addQ(Qb,Qa,i);
    }
    for (i = 1;i <= n;i++)//��ʼ�� 
    {
        f[i] = i;
        mark[i] = false;
    }
    DFS(1,0);//LCATarjan�㷨
    for (i = 1;i <= k;i++)
        printf("%d\n",ans[i]);//��ӡ�� 
    return 0;
}
