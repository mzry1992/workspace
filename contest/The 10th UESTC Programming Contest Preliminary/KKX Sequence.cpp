#include<cstdio>
#include<algorithm>
using namespace std;
int a[50],b[50],c[50],ans[50][50];
bool cmp(int x,int y)
{
    return b[x]<b[y];
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
            scanf("%d",&a[i]);
        sort(a,a+n);
        if (n&1)
            for (int i=0,j=0,f=1;i+i<n;i++,j++,f*=-1)
                b[i]=b[n-i-1]=j*f;
        else
            for (int i=0,j=0,f=1;i+i<n;i++,j++,f*=-1)
            {
                b[i]=j*f;
                b[n-i-1]=-j*f;
            }
        for (int i=0;i<n;i++)
            printf("%d ",b[i]);
        puts("");
        for (int i=0;i<n;i++)
            c[i]=i;
        sort(c,c+n,cmp);
        for (int i=0;i<n;i++)
            printf("%d ",c[i]);
        puts("");
        for (int i=0;i<n;i++)
            ans[0][i]=a[c[i]];
        for (int i=1;i<n;i++)
            for (int j=0;j<n-i;j++)
                ans[i][j]=ans[i-1][j+1]-ans[i-1][j];
        printf("%d\n",ans[n-1][0]);
    }
    return 0;
}
