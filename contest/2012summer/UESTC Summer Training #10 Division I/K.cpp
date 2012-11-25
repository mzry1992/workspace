#include<cstdio>
#include<cstring>
int a[2000000];
int flag[10000];
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int m;
        scanf("%d",&m);
        memset(flag,-1,sizeof(flag));
        for (int i=0;i<m;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            if (r-l>=9999)
            {
                puts("0");
                continue;
            }
            bool flags=0;
            for (int j=l-1;j<r && !flags;j++)
                if (flag[a[j]-1]==i)
                    flags=1;
                else
                    flag[a[j]-1]=i;
            if (flags)
            {
                puts("0");
                continue;
            }
            int pre=-1000000000,ans=100000000;
            for (int j=0;j<10000;j++)
                if (flag[j]==i)
                {
                    if (ans>j-pre)
                        ans=j-pre;
                    pre=j;
                }
            printf("%d\n",ans);
        }
    }
    return 0;
}
