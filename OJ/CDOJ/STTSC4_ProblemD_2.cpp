//�����ԭ�����һ��ʦ��ָ���з������ݣ������صظĹ����ˡ��ٴθ�л��___lst��ʦ�ֵ�ָ���� 

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
//�����еķ�Χ��С�����ǿ���ͨ��ö���Ӿ�������½�ͺ�磬����Ӿ����ǰ��ķ���
//���������ѭ��ö�����½�i��j��Ȼ���ʼ�����ǰ��headΪ1����ʼ��������tsumΪ0,�ڲ�ѭ��ö�ٺ��tail
//���ȣ��������ۼ��ϵ�tail�У���i�е���j�е�Ԫ�غ�tsum += sum[tail][j]-sum[tail][i-1] 
//��֮ǰ�ĳ���������ÿ�ε�tsum > tʱֻͨ���޸ĺ������ӵ�ǰ��ı仯�����ڴ����ݣ�
//1 4 11 
//3 4 6 7  
//����4+6
//�ҵ�ԭ����������Ĵ���3+4+6����Ϊ�ۼӵ�3+4ʱ��δ����7�����ۼӵ�6ʱΪ13��ֱ����0��������ǰ����޸ġ�����
//��ԭ���ĳ���ҲAC�ˣ�����̫���ˣ� 
//���������ͨ�����ǰ�磬ÿ�ε�tsum >= tʱ��������tsum -= sum[head][j]-sum[head][i-1]��������head++��ͬʱ��
//�´𰸣�����ǰ������ƣ�ֱ��tsum < t��
//��������仯���ɴ������е������ 

                 
#include <stdio.h>
#include <math.h>

int n,m,t,i,j,k,q,a[30][2100],sum[2100][30],tsum,ksum,head,tail;
int near,tcase;//near��¼�� 

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
