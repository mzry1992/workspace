#include <stdio.h>

int tcase,fcase;
int n,m,i,j,k;
int x[11000],y[11000],w[11000];//保存边的信息 
int f[110];//记录节点I的父节点 
int use[110];//保存MST的信息 
int sum;
bool flag;//标记MST是否唯一，如果唯一则为true。 

int getsum()//通过use数组求MST的权值和 
{
    int result = 0,i;
    for (i = 1;i <= n-1;i++)//遍历MST的N-1条边，累加边权值 
        result += w[use[i]];
    return result;
}
    
int findf(int x)//并查集的查找父节点操作 
{
    if (x != f[x]) f[x] = findf(f[x]);//路径压缩 
    return f[x];
}

int MST()//Kruskal算法主题 
{
     int i,j,f1,f2,n1,n2;
     for (i = 1;i <= n;i++)//首先构建一个森林，每颗树只有一个节点 
         f[i] = i;
     j = 1;//J保存当前处理到第J条边 
     for (i = 1;i <= n-1;i++)//加入N-1条边 
     {
         while (1 == 1)
         {
               while (w[j] == 19921005) j++;//对于特殊标记的边直接跳过 
               n1 = x[j];
               n2 = y[j];
               f1 = findf(n1);
               f2 = findf(n2);
               if (f1 != f2)//如果不会构成环 
               {
                  f[f1] = f2;//合并两棵树 
                  use[i] = j;//MST的第I条边为J 
                  j++;//J++ 
                  break;
               }
               else
                   j++;//如果构成环那么放弃这条边         
         }
     }
     return 0;
}
     
void swap(int i,int j)
{
     int temp;
     temp = x[i]; x[i] = x[j]; x[j] = temp;
     temp = y[i]; y[i] = y[j]; y[j] = temp;
     temp = w[i]; w[i] = w[j]; w[j] = temp;
}

void qsort(int l,int r)//按权值排序 
{
     int tl,tr,m;
     tl = l;
     tr = r;
     m = w[(tl+tr)/2];
     while (tl < tr)
     {
           while (w[tl] < m) tl++;
           while (w[tr] > m) tr--;
           if (tl <= tr)
           {
                  swap(tl,tr);
                  tl++;
                  tr--;
           }
     }
     if (tl < r) qsort(tl,r);
     if (l < tr) qsort(l,tr);
}

int work()//删边过程 
{
    int tuse[110],i,j,tsum,tw;
    for (i = 1;i <= n-1;i++)//记录原有的MST的边信息 
        tuse[i] = use[i];
    for (i = 1;i <= n-1;i++)//枚举N-1条边 
    {
        tw = w[tuse[i]];
        w[tuse[i]] = 19921005;//特殊标记这条边 
        MST();//重新计算MST 
        tsum = getsum();//获得新MST的边权值和 
        if (tsum == sum)//判断与原来的边权值和是或否相等 
        {
                 flag = false;//标记MST不唯一。 
                 return 0;//已知MST不唯一，那么继续删除其他边已经没有意义了，可以直接退出过程。 
        }
        w[tuse[i]] = tw;//恢复被删除的边 
    }
    return 0;
}
     
int main()
{
    scanf("%d",&tcase);
    for (fcase = 1;fcase <= tcase;fcase++)
    {
        scanf("%d %d",&n,&m);
        for (i = 1;i <= m;i++)
            scanf("%d %d %d",&x[i],&y[i],&w[i]);
        qsort(1,m);//排序 
        flag = true;
        MST();//第一次MST 
        sum = getsum();
        work();//删边 
        if (flag == true)//输出 
           printf("%d\n",sum);
        else
            printf("Not Unique!\n");
    }
    return 0;
}
