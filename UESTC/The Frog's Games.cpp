#include<cstdio>
#include<algorithm>
using namespace std;
int a[500001],L,n,m;
bool check(int x)
{
    for (int i=0,pos=0,j=0;i<m;i++)
    {
        int pre=j;
        for (;j<n;j++)
            if (a[j]-pos>x)
                break;
        if (pre==j)
            return 0;
        if (j==n)
            return 1;
        pos=a[j-1];
    }
    return 0;
}
int main()
{
    while (scanf("%d%d%d",&L,&n,&m)!=EOF)
    {
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        a[n++]=L;
        sort(a,a+n);
        int l=0,r=L;
        while (l<r)
        {
            int mid=l+r>>1;
            if (check(mid))
                r=mid;
            else
                l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}

