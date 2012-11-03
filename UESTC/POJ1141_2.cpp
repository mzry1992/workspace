#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[110];
int c[110][110],b[110][110];
void output(int x,int y)
{
     if(x>y)  return ;
     if(x==y)
     {
         if(a[x]=='('||a[x]==')')
             printf("()");
         else
             printf("[]"); 
     }
     else
     {
          if(b[x][y]==-1)
          {
              printf("%c",a[x]);
              output(x+1,y-1);
              printf("%c",a[y]);
          }             
          else
          {
              output(x,b[x][y]);
              output(b[x][y]+1,y);
          }
     }
}                  
int main()
{
    while(gets(a))
    {
        int r,k,i,j;
        int g=strlen(a);
        if(!g)
        { printf("\n"); continue;}
        memset(c,0,sizeof(c));
        for(i=0;i<g;i++)  c[i][i]=1;
        for(r=1;r<g;r++)
        {
             for(i=0;i<g-r;i++)
             {
                  j=i+r;
                  c[i][j]=1000000;
                  if((a[i]=='('&&a[j]==')')||(a[i]=='['&&a[j]==']'))                               
                  {
                      if(c[i][j]>c[i+1][j-1])
                         c[i][j]=c[i+1][j-1],b[i][j]=-1;
                  }
                  //else
                  //{
                      for(k=i;k<j;k++)
                      {
                          if(c[i][k]+c[k+1][j]<c[i][j])
                              c[i][j]=c[i][k]+c[k+1][j],b[i][j]=k;
                      }
                  //}
             }
        }
        output(0,g-1);
        printf("\n");
    }
    return 0;
}                                                          
