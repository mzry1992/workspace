#include<stdio.h>
#include<string.h>
int v[105],c[105],b[100005][2];
int main()
{
    int n,m,i,j,count,num;
    while(scanf("%d%d",&n,&m),n&&m)
    {
        memset(b,0,sizeof(b));
        for(i=1;i<=n;i++)
        scanf("%d",&v[i]);
        for(i=1;i<=n;i++)
        scanf("%d",&c[i]);
        b[0][0]=1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            b[j][1]=0;
            for(j=0;j<=m;j++)
            if(b[j][0]==0)
            {
                num=j-v[i];
                if(num>=0)
                {
                    if(b[num][0]!=0&&b[num][1]<c[i])
                    {
                        b[j][0]=1;
                        b[j][1]=b[num][1]+1;
                    }
                }
            }
        }
        count=0;
        for(i=1;i<=m;i++)
        {
            if(b[i][0]!=0)
            count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
