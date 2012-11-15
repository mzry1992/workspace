#include<stdio.h>
long long  h(int n)
{
     int i;
     long long sum;
     sum=5;
     for(i=1;i<n;i++)
     sum*=3;
 return sum;
}
 int n;
 int main()
{ int t,ft;
  long long res;
  scanf("%d",&t);
  for(ft=1;ft<=t;ft++)
  {
  scanf("%d",&n);
  res=h(n);
  printf("Case #%d: %lld\n",ft,res);
   }

}
