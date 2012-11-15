//昨天的原版程序被一个师兄指正有反例数据，今天特地改过来了。再次感谢“___lst”师兄的指正！ 

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
//由于行的范围很小，我们可以通过枚举子矩阵的上下界和后界，标记子矩阵的前界的方法
//最外层两个循环枚举上下界i和j，然后初始化标记前界head为1，初始化计数器tsum为0,内层循环枚举后界tail
//首先，计数器累加上第tail列，第i行到第j行的元素和tsum += sum[tail][j]-sum[tail][i-1] 
//我之前的程序是由于每次当tsum > t时只通过修改后界而忽视的前界的变化，对于此数据：
//1 4 11 
//3 4 6 7  
//答案是4+6
//我的原来程序给出的答案是3+4+6，因为累加到3+4时还未大于7，而累加到6时为13，直接清0，不考虑前界的修改。（但
//是原来的程序也AC了，数据太弱了） 
//而这次我是通过标记前界，每次当tsum >= t时，首先令tsum -= sum[head][j]-sum[head][i-1]，并且令head++，同时更
//新答案，即将前界向后推，直到tsum < t。
//经过这个变化即可处理到所有的情况。 

                 
#include <stdio.h>
#include <math.h>

int n,m,t,i,j,k,q,a[30][2100],sum[2100][30],tsum,ksum,head,tail;
int near,tcase;//near记录答案 

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
          for (i = 1;i <= n;i++)
          for (j = i;j <= n;j++)
          {
              head = 1;
              tsum = 0;
              for (tail = 1;tail <= m;tail++)
              {
                  ksum = sum[tail][j]-sum[tail][i-1];
                  tsum += ksum;
                  while (tsum >= t)
                  {
                        if (head == tail) break;
                        if (fabs(tsum-t) < fabs(near-t))
                           near = tsum;
                        else
                        if (fabs(tsum-t) == fabs(near-t))
                        if (tsum < near)
                           near = tsum;
                        tsum -= sum[head][j]-sum[head][i-1];
                        head++;
          
                  }
                  if (tsum < t)
                  {
                           if (fabs(tsum-t) < fabs(near-t))
                              near = tsum;
                           else
                           if (fabs(tsum-t) == fabs(near-t))
                           if (tsum < near)
                              near = tsum;
                  }
              }
          }
          printf("Case %d:\n",tcase); 
          printf("%d\n",near);
    }
    return 0;
}
