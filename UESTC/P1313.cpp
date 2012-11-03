#include <stdio.h>

int n,m,k,i,j;
int f1,f2,l;
int Qa,Qb;
/*
采用链表的储存方式 
*/
struct nodetype//定义结点的类型（链表储存） 
{
       int next;//下一个结点 
       int tail;//记录链表的尾结点 
       int node;//记录当前结点代表的是那个农场 
       int dis;//记录此点与顶点的距离 
}nodelist[100000],no[50000];//nodelist为保存链表，no保存顶点 
struct question//定义询问的类型 
{
       int next;//下一个关于头结点的询问 
       int node;//询问的另一个点 
       int no;//询问的编号 
}Qlist[100000],Q[50000];//Qlist存链表，Q保存头结点（顶点） 
int totn;
int dis[50000];//保存点I到树根的距离 
int ans[50000];//保存答案 
int f[50000];//保存父节点 
int mark[50000];//标记结点 

void add(int s,int t,int d)//加入一条从s到t长度为d的边 
{
     mark[s] = true; 
     totn++;//总数+1 
     nodelist[totn].node = t;//结点 
     nodelist[totn].next = 0;//下一个结点，0代表NUL 
     nodelist[totn].dis = d;//距离 
     if (no[s].next == 0)//如果当前顶点的边数为0，直接加在后面 
                    no[s].tail = no[s].next = totn;
     else
     {
         nodelist[no[s].tail].next = totn;   //否则加在链表的末尾 
         no[s].tail = totn;   //更改末尾指针 
     }
}

void addQ(int s,int t,int n)//加入查询，和上面的add过程类似 
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
     
int find(int x)//查找父节点，顺便路径压缩 
{
    if (f[x] != x) f[x] = find(f[x]);
    return f[x];
}

void DFS(int u,int dist)//LCA的主算法 
{
     int i,j,v,LCA;
     dis[u] = dist;//记录u到根节点的距离 
     for (i = no[u].next;i != 0;i = nodelist[i].next)//对于u的每个孩子v 
     {
             v = nodelist[i].node; 
             DFS(v,dist+nodelist[i].dis);//遍历下去，注意v到根节点的距离计算 
             f[v] = u;//合并集合 
     }
     for (i = Q[u].next;i != 0;i = Qlist[i].next)//对于关于u的每个询问 
     {
         v = Qlist[i].node;
         if (mark[v] == true)//如果v遍历过了 
         {
                                     LCA = find(v);//求他们的公共祖先（就是v的根节点） 
                                     ans[Qlist[i].no] = dis[u]+dis[v]-2*dis[LCA];//距离就是u到树的根节点的距离加上v到树的根节点的距离减去两倍的他们的LCA到树根节点的距离（画个图就知道了） 
         }
     }
     mark[u] = true;//标记结点u遍历过了 
}

int delet(int s,int t)//删除不必要的边，把图构成一个数，函数入口st表示删除从s到t的边 
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

void creat(int u)//构造以u为根节点树 
{
     int i,v;
     for (i = no[u].next;i != 0;i = nodelist[i].next)
     {
         v = nodelist[i].node;
         delet(v,u);//删除从v到u的边 
         creat(v);//构造下去 
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
    creat(1);//构造树 
    scanf("%d",&k);
    totn = 0;
    for (i = 1;i <= k;i++)
    {
        scanf("%d %d",&Qa,&Qb);
        addQ(Qa,Qb,i);
        addQ(Qb,Qa,i);
    }
    for (i = 1;i <= n;i++)//初始化 
    {
        f[i] = i;
        mark[i] = false;
    }
    DFS(1,0);//LCATarjan算法
    for (i = 1;i <= k;i++)
        printf("%d\n",ans[i]);//打印答案 
    return 0;
}
