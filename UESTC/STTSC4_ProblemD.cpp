/*
Problem D

Not To The Max  

Description 

----------------------------------------------------------------------------------

　　Given a two-dimensional array of positive and negative integers, a sub-rectangle is any contiguous sub-array of size 1*1 or greater located within the whole array. The sum of a rectangle is the sum of all the elements in that rectangle. In this problem the sub-rectangle with the largest sum is referred to as the maximal sub-rectangle.
As an example, the maximal sub-rectangle of the array:

0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2
is in the lower left corner:

9 2
-4 1
-1 8
and has a sum of 15.

----------------------------------------------------------------------------------

　　Your task here has something similar with the problem mentioned above, while you are to find out a non-empty sub-matrix whose elements sum closest to the given integer T.

Input 

　　The input contains several test cases.
　　Each test case begins with three integers n m T, which means there are n rows and m columns in the matrix and our target T as mentioned above. Then n lines follows, each of which consists of m non-negative integers bounded in [0, 10000].

　　You can assume that 0 < n <= 20, 0 < m <= 2000, 0 <= T < 2^15

　　n = 0 and m = 0 means the end of the input, which should not be processed.

Output 

　　For each test case, you are to output a line in the from of "Case #:", # is the test case number indexed from 1, and then another line with the sum of the sub-matrix you found, if there is a tie, you should output the smaller one.

Sample Input 

3 3 0
1 1 1
1 1 1
1 1 1

3 3 0
1 1 1
1 1 1
1 1 0

3 3 10
2 2 4
5 2 0
0 0 0

Sample Output 

Case 1:
1
Case 2:
0
Case 3:
11
 
Source 
厦门大学第四届程序设计竞赛 现场决赛 
*/

//这一题是最大子矩阵的变种，要求的是所有子矩阵中和最接近某个数T的和是多少，如果同样接近，那么取最小的和。
//
//先预处理得到每一列从1到i行的和，用sum[j][i]表示第j列从1到i行的和。 
//
//由于行的范围很小，我们可以通过枚举子矩阵的上下界，确定子矩阵的后界的方法。
//用f[i][j][k]记录上下界分别为k，j，后界为i的所有子矩阵最接近T的和。
//对于f[i][j][k]，首先考虑前界等于后界的情况，此时可以得到和为sum[i][k]-sum[i][j-1]，判断是否为更优解。
//然后考虑前界小于后界的情况，即为f[i-1][j][k]+sum[i][k]-sum[i][j-1]；记为tsum
//对于tsum：
//          如果tsum >= t：
//                   如果此时为更优解，那么更新解，同时令f[i][j][k] = sum[i][k]-sum[i][j-1]，因为
//                   题目中告诉我们数组中的数都大于0，所以，即使tsum不是最优解，不改变前确界的话后面
//                   取到的解都会大于tsum，显然会远离T。
//          如果tsum < t；
//                   如果此时为更优解，那么更新，同时令f[i][j][k] = tsum。
//要考虑的就是这两个情况。
                 
#include <stdio.h>
#include <math.h>

int n,m,t,i,j,k,q,a[30][2100],sum[2100][30],tsum;
int f[2100][30][30],near,tcase;//near记录答案 

int main()
{
    tcase = 0;
    while (scanf("%d %d %d",&n,&m,&t) == 3)
    {
          tcase++;
          near = 19921005;
          for (i = 1;i <= n;i++) //在读入数据时可以得到子矩阵大小为1是的最接近T的near 
          for (j = 1;j <= m;j++)
          {
              scanf("%d",&a[i][j]);
              if (fabs(a[i][j]-t) < fabs(near-t))
                 near = a[i][j];
              else
              if (fabs(a[i][j]-t) == fabs(near-t))
                 if (a[i][j] < near)
                    near = a[i][j];
          }
          for (i = 1;i <= m;i++) //计算第i列从第1行到第j行的和 
          {
              sum[i][0] = 0;
              for (j = 1;j <= n;j++)
                  sum[i][j] = sum[i][j-1]+a[j][i];
          }
          for (j = 1;j <= n;j++) //对f数组赋初值 
          for (k = 1;k <= n;k++)
              f[0][j][k] = 0;
          for (i = 1;i <= m;i++)  
          for (j = 1;j <= n;j++)
          for (k = j;k <= n;k++)
          {
              f[i][j][k] = sum[i][k]-sum[i][j-1]; //首先是前确界等于后确界的情况 
              if (fabs(f[i][j][k]-t) < fabs(near-t)) //更新答案 
                 near = f[i][j][k];
              if (fabs(f[i][j][k]-t) == fabs(near-t)) //如果同样接近那么取小的答案 
              if (f[i][j][k] < near)
                 near = f[i][j][k];
              tsum = f[i][j][k]+f[i-1][j][k]; //当前确界小于后界的时候 
              if (tsum >= t) //大于等于T的情况 
              {
                       if (fabs(tsum-t) < fabs(near-t))
                          near = tsum;
                       if (fabs(tsum-t) == fabs(near-t))
                          if (tsum < near)
                             near = tsum;
              }
              else //小于等于T的情况 
              {
                       f[i][j][k] = tsum;
                       if (fabs(tsum-t) < fabs(near-t))
                          near = tsum;
                       if (fabs(tsum-t) == fabs(near-t))
                          if (tsum < near)
                             near = tsum;
              }    
          }   
          printf("Case %d:\n",tcase); 
          printf("%d\n",near);
    }
    return 0;
}
