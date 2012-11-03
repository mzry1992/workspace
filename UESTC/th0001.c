#include<stdio.h>
int main()
{
    int n,a[3][3],b[3][3],c[3][3],i,j,k,l;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<3;j++)
          for(k=0;k<3;k++)
            scanf("%d",&a[j][k]);
        for(j=0;j<3;j++)
          for(k=0;k<3;k++)
            scanf("%d",&b[j][k]);

        for(j=0;j<3;j++)
         for(k=0;k<3;k++)
         {
             c[j][k] = 0;
          for(l=0;l<3;l++)
           c[j][k]=c[j][k]+a[j][l]*b[l][k];
         }



        for(j=0;j<3;j++)
          {
              for(k=0;k<3;k++)
           {
               printf("%d ",c[j][k]);
               if(k==2) printf("\n");
           }
          }

   }
}
