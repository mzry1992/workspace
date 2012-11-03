/*
Problem D

Not To The Max  

Description 

----------------------------------------------------------------------------------

����Given a two-dimensional array of positive and negative integers, a sub-rectangle is any contiguous sub-array of size 1*1 or greater located within the whole array. The sum of a rectangle is the sum of all the elements in that rectangle. In this problem the sub-rectangle with the largest sum is referred to as the maximal sub-rectangle.
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

����Your task here has something similar with the problem mentioned above, while you are to find out a non-empty sub-matrix whose elements sum closest to the given integer T.

Input 

����The input contains several test cases.
����Each test case begins with three integers n m T, which means there are n rows and m columns in the matrix and our target T as mentioned above. Then n lines follows, each of which consists of m non-negative integers bounded in [0, 10000].

����You can assume that 0 < n <= 20, 0 < m <= 2000, 0 <= T < 2^15

����n = 0 and m = 0 means the end of the input, which should not be processed.

Output 

����For each test case, you are to output a line in the from of "Case #:", # is the test case number indexed from 1, and then another line with the sum of the sub-matrix you found, if there is a tie, you should output the smaller one.

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
���Ŵ�ѧ���Ľ������ƾ��� �ֳ����� 
*/

//��һ��������Ӿ���ı��֣�Ҫ����������Ӿ����к���ӽ�ĳ����T�ĺ��Ƕ��٣����ͬ���ӽ�����ôȡ��С�ĺ͡�
//
//��Ԥ����õ�ÿһ�д�1��i�еĺͣ���sum[j][i]��ʾ��j�д�1��i�еĺ͡� 
//
//�����еķ�Χ��С�����ǿ���ͨ��ö���Ӿ�������½磬ȷ���Ӿ���ĺ��ķ�����
//��f[i][j][k]��¼���½�ֱ�Ϊk��j�����Ϊi�������Ӿ�����ӽ�T�ĺ͡�
//����f[i][j][k]�����ȿ���ǰ����ں����������ʱ���Եõ���Ϊsum[i][k]-sum[i][j-1]���ж��Ƿ�Ϊ���Ž⡣
//Ȼ����ǰ��С�ں����������Ϊf[i-1][j][k]+sum[i][k]-sum[i][j-1]����Ϊtsum
//����tsum��
//          ���tsum >= t��
//                   �����ʱΪ���Ž⣬��ô���½⣬ͬʱ��f[i][j][k] = sum[i][k]-sum[i][j-1]����Ϊ
//                   ��Ŀ�и������������е���������0�����ԣ���ʹtsum�������Ž⣬���ı�ǰȷ��Ļ�����
//                   ȡ���Ľⶼ�����tsum����Ȼ��Զ��T��
//          ���tsum < t��
//                   �����ʱΪ���Ž⣬��ô���£�ͬʱ��f[i][j][k] = tsum��
//Ҫ���ǵľ��������������
                 
#include <stdio.h>
#include <math.h>

int n,m,t,i,j,k,q,a[30][2100],sum[2100][30],tsum;
int f[2100][30][30],near,tcase;//near��¼�� 

int main()
{
    tcase = 0;
    while (scanf("%d %d %d",&n,&m,&t) == 3)
    {
          tcase++;
          near = 19921005;
          for (i = 1;i <= n;i++) //�ڶ�������ʱ���Եõ��Ӿ����СΪ1�ǵ���ӽ�T��near 
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
          for (i = 1;i <= m;i++) //�����i�дӵ�1�е���j�еĺ� 
          {
              sum[i][0] = 0;
              for (j = 1;j <= n;j++)
                  sum[i][j] = sum[i][j-1]+a[j][i];
          }
          for (j = 1;j <= n;j++) //��f���鸳��ֵ 
          for (k = 1;k <= n;k++)
              f[0][j][k] = 0;
          for (i = 1;i <= m;i++)  
          for (j = 1;j <= n;j++)
          for (k = j;k <= n;k++)
          {
              f[i][j][k] = sum[i][k]-sum[i][j-1]; //������ǰȷ����ں�ȷ������ 
              if (fabs(f[i][j][k]-t) < fabs(near-t)) //���´� 
                 near = f[i][j][k];
              if (fabs(f[i][j][k]-t) == fabs(near-t)) //���ͬ���ӽ���ôȡС�Ĵ� 
              if (f[i][j][k] < near)
                 near = f[i][j][k];
              tsum = f[i][j][k]+f[i-1][j][k]; //��ǰȷ��С�ں���ʱ�� 
              if (tsum >= t) //���ڵ���T����� 
              {
                       if (fabs(tsum-t) < fabs(near-t))
                          near = tsum;
                       if (fabs(tsum-t) == fabs(near-t))
                          if (tsum < near)
                             near = tsum;
              }
              else //С�ڵ���T����� 
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
