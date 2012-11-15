/*
Problem G

The Lightest Cycle  

Description 

　　Given a directed weighted graph who has at least three nodes, can you find the minimal directed weighted cycle with at least three nodes?

Input 

　　The input contains a single test case.
　　In the first line there is two integer n - the number of nodes in the graph, m - the number of directed edges in the graph. (0 < n <= 100, 0 <= m <= n^2)
　　Then m lines follow, each line contains three integers i j k, which means that there is a directed edge coming from node i to node j with a weight of k (0 <= k < 2^15). 
 
Output 

　　You should output a single line with a single integer presenting the weight of the cycle you have found or "-1" (without quotes) if there isn't any.

Sample Input 

5 7
4 0 19
0 3 20
4 3 50
2 3 1
3 1 10
1 4 2
1 2 39

Sample Output 

50

Source 
厦门大学第四届程序设计竞赛 现场决赛 
*/

//这题题目太水了，求一个有向图的最小环，要求环的节点大于2个。
//开始看成无向图了，挂了几次，后来知道是有向图，这下乐了，一次FLOYD直接搞定。
//由于题目告诉你是有向图，所以，FLOYD算法中的结果dis[i][j]表示从i到j的最短路，dis[j][i]表示从j到i的最短路，
//而且这两条路必然不会是同一条路（因为是有向图了），所以，先一次FLOYD，然后枚举环的两个端点，求出这个环的
//长度（如果是一个环），然后再判断一下这个环的节点数是否大于2，这一点比较好办，可以枚举所有的k寻找是否有
//dis[i][k]+dis[k][j]+dis[j][i] = dis[i][j]+dis[j][i]（如果用语言来理解方程左边就是从i到k再从k到j再从j回到
//i的环长度），如果存在显然可以判断这个环的节点数大于2。（我当初交上去的时候意识到了这一点，可惜数据太弱了） 

#include <stdio.h>   

long n,m,i,j,k,q,s,t,e,map[150][150];
long ans,tans;
long dis[150][150]; //dis数组 

int main()
{
    scanf("%ld %ld",&n,&m);
    for (i = 0;i < n;i++)
    for (j = 0;j < n;j++)
        map[i][j] = -1;
    for (i = 1;i <= m;i++)
    {
        scanf("%ld %ld %ld",&s,&t,&e);
        map[s][t] = e;
    }
    for (j = 0;j < n;j++)
    for (k = 0;k < n;k++)
        dis[j][k] = map[j][k];
    for (k = 0;k < n;k++) //标准的FLOYD，注意循环嵌套，这里很容易出错 
    for (j = 0;j < n;j++)
    for (q = 0;q < n;q++)
    if (dis[j][k] != -1)
    if (dis[k][q] != -1)
    {
       if (dis[j][q] == -1)
          dis[j][q] = dis[j][k]+dis[k][q];
       else
           if (dis[j][q] > dis[j][k]+dis[k][q])
           dis[j][q] = dis[j][k]+dis[k][q];
    }
    ans = -1;
    for (i = 0;i < n;i++) //枚举端点 
    for (j = 0;j < n;j++)
    if (i != j)
    if (dis[i][j] != -1)
    if (dis[j][i] != -1)
    {
                  tans = dis[i][j]+dis[j][i]; 
                  if ((map[i][j] != -1) && (map[j][i] != -1))
                  if (tans == map[i][j]+map[j][i]) //注意这种判断环的点数是否大于2是错误的。 
                     break;
                  if (ans == -1)
                     ans = tans;
                  else
                      if (ans > tans)
                         ans = tans;
    }
    printf("%ld\n",ans);
    //getchar();
    //getchar();
    return 0;
}
        
    
 
