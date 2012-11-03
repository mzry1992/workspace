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
          len = 0;
          x[0] = 19921005;
          for (i = 1;i <= n;i++)
          {
              if (y[i] <= x[len])
              {
                       len++;
                       x[len] = y[i];
              }
              else
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
