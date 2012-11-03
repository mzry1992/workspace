/*
Problem F

Sequence  
 
Description 

　　Giving a collection S of points on two dimension plane. (S = {(x0,y0), (x1,y1), ... }) We define a point is greater than another point when all its coordinate on two axis are both greater than or equel to another one. Namely, p is greater than q when xp >= xq and yp >= yq. A sequence is a list points < p1, p2, ... > satisfy that i < j => pi is greater than pj. You can use the elements in S to construct sequences, how many sequences needed to cover a S at least?

Input 

　　The input consists of several test cases. Each test case start with a line containing a number n(0 < n <= 1000000), the number of points in S. Then n lines follows, each line containing two number, xi, yi(0 <= xi, yi < 100000), the position of point i. The input end with EOF.

Output 

　　You have to print minium number of sequences needed to cover S in a single line for each case.

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
厦门大学第四届程序设计竞赛 现场决赛
*/ 

//这一题的大意就是二维平面的最长下降子序列，题目给定了一些坐标，第I个点比
//第J个点大的条件是I点横纵坐标都大于等于第J个点。
//首先我们按照X坐标为第一关键字，Y坐标为第二关键字排序，这样只需要考虑Y坐
//标即可，因为X坐标已经是升序排列了。
//题目类似于NOIP的导弹拦截，求的是一个序列至少可以划分成多少个上升子序列，
//这里可以给出一个明确的结论：
//一个序列至少可以划分成上升子序列的数量等于它的最长下降子序列的长度.（详
//见Dilworth 定理） 
//对于这一题的数据范围，用O(nlogn)的算法即可，这个算法基于二分查找。
//（建议各位同学不要学我的排序，好烂）
 
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
          //不要学我的排序，因为我对多关键字的排序一窍不通！！！
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
          //看下面的就可以了，nlogn版的最长下降子序列，最后X数组不是下降子序列，这个算法只能用来算最长长度
          //我在这里介绍过这个算法http://hi.baidu.com/%C4%BE%D7%D3%C8%D5%D4%C8/blog/item/aed271d74da72f2506088b5a.html 
          len = 0; //len记录最长下降子序列的长度 
          x[0] = 19921005; //数组X[i]记录长度为i的最长不降子序列的最后一个数最小是多少。。。 
          for (i = 1;i <= n;i++)
          {
              if (y[i] <= x[len]) //如果小于最后一个数，那么长度加一 
              {
                       len++;
                       x[len] = y[i];
              }
              else //否则找到一个最后一个数大于y[i]的最长不降子序列，修改它的最后一个数。 
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
 
