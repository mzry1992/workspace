#include <stdio.h>

int tcase,fcase;
int n,m,i,j,a,b,flag;
int map[210][210];//保存各个球的重量关系，我用的是邻接边存储。 
int indegree[210];//保存各点的入度 
int ans[210];//保存答案
int AOV[210];//保存拓扑序列 

int solve()//主要过程 
{
     int i,j,k,use[210];
     for (i = 1;i <= n;i++)//标记结点I是否已经删除 
         use[i] = false;
     for (i = 1;i <= n;i++)//需要找到N个结点加入到拓扑序列中 
     {
         for (j = n;j >= 1;j--)//由于输出要求，首先考虑结点标号大的结点 
         if (use[j] == false)
             if (indegree[j] == 0) break;
         if (j == 0)//如果没有找到入度为0的结点 
         {
               flag = false;//标记无解 
               return 0;//退出 
         }
         AOV[i] = j;//否则加入到拓扑序列中 
         use[j] = true;//标记J点被删除 
         for (k = 1;k <= map[j][0];k++)//与J点相连的点的入度减1 
             indegree[map[j][k]]--;
     }
     j = n;//质量最大为N 
     for (i = 1;i <= n;i++)//根据拓扑顺序赋予质量 
     {
         ans[AOV[i]] = j;//第AOV[I]个球质量为J 
         j--;//下一个球质量为J-1 
     }
     return 0;
}

int main()
{
    scanf("%d",&tcase);
    for (fcase = 1;fcase <= tcase;fcase++)
    {
        scanf("%d %d",&n,&m);
        for (i = 1;i <= n;i++)//初始化邻接边数组和入度数组 
        {
            map[i][0] = 0;
            indegree[i] = 0;
        }
        for (i = 1;i <= m;i++)//读入数据 
        {
            scanf("%d %d",&a,&b);
            map[b][0]++;//构建一个与数据相反的图 
            map[b][map[b][0]] = a;
            indegree[a]++;
        }
        flag = true;//标记是否有解 
        solve();//处理 
        if (flag == true)//如果有解，那么依次输出各个球的重量 
        {
                 for (i = 1;i < n;i++)
                     printf("%d ",ans[i]);
                 printf("%d\n",ans[n]);//注意最后一个球的重量后面没有空格，否则会PE 
        }
        else
            printf("-1\n");//否则输出-1 
    }
    return 0;
}
