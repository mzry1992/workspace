#include<stdio.h>
int main()
{
int i,j,n,t;
double z;
scanf("%d",&t);
for(i=1;i<=t;i++)
{
 scanf("%d",&n);
z = 1.0;
 if(n>365)
    z=0.0;
else
  {
   for(j=1;j<=n;j++)
    {
     z*=(365-j+1)*1.0/365.0;
    }

  }
printf("Case #%d:%.4lf\n",i,(1-z));
}
}
