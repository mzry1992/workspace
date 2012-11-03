#include<stdio.h>
int h(int n)
{
     int i,sum;
     for(i=1,sum=5;i<n;i++)
     {if(n==1) sum=sum;
     else
         sum=sum*3;
     }
 return sum;
}
int n;
int main()
{ int t;
  int ft,res;
  scanf("%d",t);
  for(ft=1;ft<=t;ft++){
  scanf("%d",&n);
  res=h(n);
  printf("Case #%d: %lld\n",ft,res);}

}
