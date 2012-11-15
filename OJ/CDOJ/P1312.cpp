#include <stdio.h>

int n,m,i,j;
int f1,f2,l;
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
int totn;//nodelist一共有多少个点 
int dis[50000];//SPFA中保存距离的数组 
int start,end;//保存图的一个端点和距离这个端点最远的点 

void add(int s,int t,int d)//加入一条从s到t长度为d的边 
{
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

int SPFA(int s)//SPFA！！ 
{
    int d[400000],head,tail,now;//队列 
    int use[50000];//标记结点 
    int i,j,tans;//返回答案用的 
    for (i = 1;i <= n;i++)//对各个数组赋初值 
    {
        use[i] = false;
        dis[i] = -19921005;//边要弄一个尽量小的值！可能会问了，如果这样的话SPFA怎么进行松弛操作呢？注意下，这是一个树，所以每个节点只会光顾一次，所以，所有结点只会松弛一次！ 
    }
    head = tail = 1;//初始化队列 
    d[1] = s;
    use[s] = true;//标记S点 
    dis[s] = 0;//S点到S点的距离肯定是0了 
    while (head <= tail)//如果队列不为空 
    {
          now = d[head];//取出队头 
          use[now] = false;//释放结点 
          head++;//队头+1 
          for (i = no[now].next;i != 0;i = nodelist[i].next)//枚举此结点的所有邻接点（赞下C语言的for循环的灵活性，太令人吃惊了！） 
          {
                if (dis[nodelist[i].node] < nodelist[i].dis+dis[now])//标准的SPFA了，注意这里是小于号，没关系，仔细考虑下，所有的结点只会松弛一次，那么，对数组初值设定为足够小，然后，松弛的时候用小于号判断，这样不是就能保证每个结点只能松弛一次呢？如果不这样的话，注意到我们用链表保存的图，所以，会有环（即S-->T-->S），而且是负环，如果不这样判断每个结点只松弛一次的话，会死循环的！       
                if (nodelist[i].node != s)//注意，这是一个树，每个结点只能光临一次！！！ 
                {//这里和SPFA一样了 
                   dis[nodelist[i].node] = nodelist[i].dis+dis[now];
                   if (use[nodelist[i].node] == false)
                   {
                      use[nodelist[i].node] = true;
                      tail++;
                      d[tail] = nodelist[i].node;
                   }
                }
          }
    }
    j = 0;//记录与S点最远的点到S点的距离 
    tans = 0;//记录这个点是哪个点 
    for (i = 1;i <= n;i++) 
    if (dis[i] < j)//注意我们的边是负数。 
    {
               j = dis[i];//更新 
               tans = i;
    }
    return tans;//返回这个点 
}

int main()
{
    scanf("%d %d",&n,&m);
    for (i = 1;i <= n;i++)//对邻接表初始化 
        no[i].next = 0;
    totn = 0; 
    for (i = 1;i <= m;i++)
    {
        scanf("%d %d %d",&f1,&f2,&l);
        getchar();//最后那个字符直接忽略掉吧，我是不知道改怎么读入了，而且我没有发现这个字母有什么实际用处。 
        getchar();//还要读入一个回车！ 
        //注意，SPFA要求的是最短路，而题目是最长路，我们不妨把距离改成负数，那么不就是可以把最长路变成最短路吗？而且由于这是一个树，所以，每个点只需要遍历一次即可，所以，不需要担心负环的问题，不过，前提还是要对SPFA稍稍改动一下 
        add(f1,f2,-l);//加入f1-->f2 
        add(f2,f1,-l);//加入f2--f1
    }
    start = SPFA(1);//首先，找到树的一个端点 
    end = SPFA(start);//然后找到另一个端点 
    printf("%d\n",-dis[end]);//输出最长路的长度，由于边我们改成了负数，我们要加个负号让他变回正数。 
    return 0;
}
