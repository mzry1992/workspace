/*
Problem F

Sequence  
 
Description 

����Giving a collection S of points on two dimension plane. (S = {(x0,y0), (x1,y1), ... }) We define a point is greater than another point when all its coordinate on two axis are both greater than or equel to another one. Namely, p is greater than q when xp >= xq and yp >= yq. A sequence is a list points < p1, p2, ... > satisfy that i < j => pi is greater than pj. You can use the elements in S to construct sequences, how many sequences needed to cover a S at least?

Input 

����The input consists of several test cases. Each test case start with a line containing a number n(0 < n <= 1000000), the number of points in S. Then n lines follows, each line containing two number, xi, yi(0 <= xi, yi < 100000), the position of point i. The input end with EOF.

Output 

����You have to print minium number of sequences needed to cover S in a single line for each case.

Sample Input 

4
1 1
2 2
3 3
4 4

4
1 5
2 6
2 3
3 4

Sample Output 

1
2

Source 
���Ŵ�ѧ���Ľ������ƾ��� �ֳ�����
*/ 

//��һ��Ĵ�����Ƕ�άƽ�����½������У���Ŀ������һЩ���꣬��I�����
//��J������������I��������궼���ڵ��ڵ�J���㡣
//�������ǰ���X����Ϊ��һ�ؼ��֣�Y����Ϊ�ڶ��ؼ�����������ֻ��Ҫ����Y��
//�꼴�ɣ���ΪX�����Ѿ������������ˡ�
//��Ŀ������NOIP�ĵ������أ������һ���������ٿ��Ի��ֳɶ��ٸ����������У�
//������Ը���һ����ȷ�Ľ��ۣ�
//һ���������ٿ��Ի��ֳ����������е���������������½������еĳ���.����
//��Dilworth ���� 
//������һ������ݷ�Χ����O(nlogn)���㷨���ɣ�����㷨���ڶ��ֲ��ҡ�
//�������λͬѧ��Ҫѧ�ҵ����򣬺��ã�
 
#include <stdio.h>

int n,i,len,left,right,mid,x[1020000],y[1020000];
         
void qsort(int l,int r)
{
     int tl,tr,m,temp;
     tl = l;
     tr = r;
     m = x[(l+r)/2];
     while (tl < tr)
     {
         while (x[tl] < m) tl++;
         while (x[tr] > m) tr--;
         if (tl <= tr)
         {
                          temp = x[tl]; x[tl] = x[tr]; x[tr] = temp;
                          temp = y[tl]; y[tl] = y[tr]; y[tr] = temp;
                          tl++;
                          tr--;
         }
     }
     if (tl < r) qsort(tl,r);
     if (l < tr) qsort(l,tr);
}

void qsort2(int l,int r)
{
     int tl,tr,m,temp;
     tl = l;
     tr = r;
     m = y[(l+r)/2];
     while (tl < tr)
     {
         while (y[tl] < m) tl++;
         while (y[tr] > m) tr--;
         if (tl <= tr)
         {
                          temp = x[tl]; x[tl] = x[tr]; x[tr] = temp;
                          temp = y[tl]; y[tl] = y[tr]; y[tr] = temp;
                          tl++;
                          tr--;
         }
     }
     if (tl < r) qsort2(tl,r);
     if (l < tr) qsort2(l,tr);
}

int main()
{
    while (scanf("%d",&n) == 1)
    {
          for (i = 1;i <= n;i++)
              scanf("%d %d",&x[i],&y[i]);
          //��Ҫѧ�ҵ�������Ϊ�ҶԶ�ؼ��ֵ�����һ�ϲ�ͨ������
          qsort(1,n); 
          left = 1;
          right = 1;
          while (left < n)
          {
              while ((x[right] == x[left]) && (right <= n)) right++;
              right--;
              qsort2(left,right);
              left = right+1;
              right = left;
          }
          //������ľͿ����ˣ�nlogn�����½������У����X���鲻���½������У�����㷨ֻ�������������
          //����������ܹ�����㷨http://hi.baidu.com/%C4%BE%D7%D3%C8%D5%D4%C8/blog/item/aed271d74da72f2506088b5a.html 
          len = 0; //len��¼��½������еĳ��� 
          x[0] = 19921005; //����X[i]��¼����Ϊi������������е����һ������С�Ƕ��١����� 
          for (i = 1;i <= n;i++)
          {
              if (y[i] <= x[len]) //���С�����һ��������ô���ȼ�һ 
              {
                       len++;
                       x[len] = y[i];
              }
              else //�����ҵ�һ�����һ��������y[i]������������У��޸��������һ������ 
              {
                  left = 0;
                  right = len;
                  while (left < right)
                  {
                        mid = (left+right)/2;
                        if (y[i] >= x[mid])
                           right = mid;
                        else
                            left = mid+1;
                  }
                  x[left] = y[i];
              }
          }
          printf("%d\n",len);
    }
    return 0;
} 
 
