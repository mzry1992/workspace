#include<cstdio>
int N,M;
int max(int x,int y)
{
    if (x<y) return y;
    else return x;
}
int get(int x)
{
    int ret=0;
    for (int i=1;i<=x;i<<=1)
        ret+=x/(i<<1)*i+max(0,x%(i<<1)-i+1);
    return ret;
}
bool check(int x)
{
    int i,j;
    for (i=0,j=0;i<M && j<N;i++)
    {
        int l=j,r=N;
        while (l<r)
        {
            int mid=(l+r+1)/2;
            if (get(mid)-get(j)<=x)
                l=mid;
            else
                r=mid-1;
        }
        if (l==j) return 0;
        j=l;
    }
    if (j<N) return 0;
    else return 1;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    N=(1<<n)-1;
    M=m;
    int l=0,r=N*N;
    while (l<r)
    {
        int mid=(l+r)/2;
        if (check(mid))
            r=mid;
        else
            l=mid+1;
    }
    printf("%d\n",l);
    return 0;
}
