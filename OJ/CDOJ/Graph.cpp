#include<cstdio>
#include<cstring>
bool mp[100][100];
int a[100][100];
int solve(int n)
{
    memset(mp,0,sizeof(mp));
    int ret=0;
    for (int k=0;k<n && ret!=-1;k++)
        for (int j=0;j<n && ret!=-1;j++)
            if (j!=k)
                for (int i=0;i<n && ret!=-1;i++)
                    if (i!=k && i!=j)
                        if (a[i][j]>a[i][k]+a[k][j])
                            ret=-1;
                        else if (a[i][j]==a[i][k]+a[k][j])
                            mp[i][j]=1;
    if (ret==-1) return -1;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            ret+=mp[i][j];
    return n*(n-1)-ret;
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int cas=1;cas<=t;cas++)
    {
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        int ans=solve(n);
        printf("Case %d: ",cas);
        if (ans==-1)
            puts("impossible");
        else
            printf("%d\n",ans);
    }
    return 0;
}
