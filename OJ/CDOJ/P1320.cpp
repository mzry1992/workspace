#include <stdio.h>

int n,m,i;
int x[10100],y[10100],w[10100];//存储边的信息 
int ans;//保存答案 
int f[110];//保存各点的父节点（kruskal算法） 

void swap(int i,int j)//交换结点 
{
     int temp;
     temp = x[i]; x[i] = x[j]; x[j] = temp;
     temp = y[i]; y[i] = y[j]; y[j] = temp;
     temp = w[i]; w[i] = w[j]; w[j] = temp;
}

void qsort(int l,int r)//快速排序 
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

int findf(int x)//并查集的寻找根节点过程 
{
    if (f[x] != x) f[x] = findf(f[x]);//路径压缩 
    return f[x];
}

int solve()//主过程 
{
     int min,max;//记录生成树中的最小边权值和最大边权值 
     int i,j;
     int n1,n2,f1,f2; 
     int tot;//生成树中已经存在多少条边 
     for (i = 1;i <= m+1-(n-1);i++)//枚举最小边 
     {
         min = w[i];//最小边权值 
         for (j = 1;j <= n;j++)//对F数组赋初值 
             f[j] = j;
         j = i;//确定了最小边，生成树中的其他边大小一定大于最小边，所以，小于最小边的边应该被忽略 
         tot = 0;
         while (1 == 1)
         {
             n1 = x[j]; 
             n2 = y[j];
             f1 = findf(n1);
             f2 = findf(n2);
             if (f1 != f2)//如果不构成环 
             {
                    f[f1] = f2;//合并 
                    tot++;//边数量加一 
                    if (tot == n-1)//由于边是按照权值升序排列，所以，最大边一定是最后一个加入的边 
                    { 
                          max = w[j];
                          if (max-min < ans) //更新答案 
                             ans = max-min;
                          break;//退出 
                    }
             }
             j++;//判断下一条边 
             if (j > m) //如果没有边可以选择了，那么退出 
              break;
             if (w[j]-min >= ans)//如果此时的边权值减去最小边权值大于答案，那么肯定无法得到更优解，可以退出 
              break;
         }
     }
     return 0;
}

int main()
{
    scanf("%d %d",&n,&m);
    while (!((n == 0) && (m == 0)))
    {
          for (i = 1;i <= m;i++)
              scanf("%d %d %d",&x[i],&y[i],&w[i]);
          qsort(1,m);//排序 
          ans = 19921005;//对ans赋初值 
          solve();//处理 
          if (ans != 19921005)//如果有答案（即ans被修改过） 
             printf("%d\n",ans);//那么输出答案 
          else
              printf("-1\n",ans);//否则说明无解 
          scanf("%d %d",&n,&m);
    }
    return 0;
}
