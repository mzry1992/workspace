#include <stdio.h>

int n,i,j,v,tota,f1,f2,a[10000],x[10000],y[10000],f[10000];
long result;

void swap(int *a,int *b)
{
     int t;
     t = *a;
     *a = *b;
     *b = t;
}

void qsort(int l,int r)
{
     int m,tl,tr;
     tl = l;
     tr = r;
     m = a[(tl+tr)/2];
     do
     {
         while (a[tl] < m) tl++;
         while (a[tr] > m) tr--;
         if (tl <= tr)
         {
                swap(&a[tl],&a[tr]);
                swap(&x[tl],&x[tr]);
                swap(&y[tl],&y[tr]);
                tl++;
                tr--;
         }
     }
     while (tl <= tr);
     if (tl < r) qsort(tl,r);
     if (l < tr) qsort(l,tr);
}

int findf(int x)
{
    if (f[x] != x) f[x] = findf(f[x]);
    return f[x];
}

int main()
{
    while (scanf("%d",&n) == 1)
    {
          tota = 0;
          for (i = 1;i <= n;i++)
          {
              for (j = 1;j <= n;j++)
              {
                  scanf("%d",&v);
                  if (i > j)
                  if (v > 0) 
                  {
                     tota++;
                     a[tota] = v;
                     x[tota] = i;
                     y[tota] = j;
                  }
              }
              f[i] = i;
          }
    
          qsort(1,tota);
    
          result = 0;
          i = 1;
          j = 0;
          while (j < n-1) 
          {
                f1 = findf(x[i]);
                f2 = findf(y[i]);
                if (f1 != f2)
                {
                   result += a[i];
                   f[f1] = f2;
                   j++;
                }
                i++;
          }
          
          printf("%ld\n",result);            
    }
    return 0;
}
