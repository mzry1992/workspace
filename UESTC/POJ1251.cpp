#include<iostream>
using namespace std;

int n,m,i,j,v,ti,tj,f1,f2,tota,totb,a[500],x[500],y[500],f[500];
char sp,tp;
long result;

void swap(int *a,int *b)
{
     int t;
     t = *a;
     *a = *b;
     *b = t;
}

int findf(int p)
{
    if (f[p] != p) f[p] = findf(f[p]);
    return f[p];
}

int main()
{
    cin >> n;
    while (n > 0)
    {
          tota = 0;
          for (i = 1;i <= n-1;i++)
          {
              cin >> sp >> m;
              for (j = 1;j <= m;j++)
              {
                  cin >> tp >> v;
                  tota++;
                  a[tota] = v;
                  x[tota] = sp;
                  y[tota] = tp;
              }
              f[sp] = sp;
          }
          f[sp+1] = sp+1;
          for (i = 1;i <= tota;i++)
          for (j = i;j <= tota;j++)
          if (a[i] > a[j])
          {
                   swap(&a[i],&a[j]);
                   swap(&x[i],&x[j]);
                   swap(&y[i],&y[j]);
          }
          totb = 1;
          result = 0;
          i = 1;
          while (totb <= n-1) 
          {
                f1 = findf(x[i]);
                f2 = findf(y[i]);
                if (f1 != f2)
                {
                       f[f1] = f2;
                       result += a[i];
                       totb++;
                }
                i++;
          }
          cout << result << endl;
          cin >> n;
    }
    return 0;
}
