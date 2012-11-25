#include<cstdio>
#include<algorithm>
using namespace std;
int a[100000];
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        int idx=0;
        for (int tot=0,x=1;tot<n;x+=2,idx++)
            tot+=x;
        for (int i=0;i<n;i++)
            a[i]=i;
        int t=0,i;
        for (i=n-1;i-idx>=0;i-=idx,t++)
        {
            //printf("%d %d\n",i-idx+1,i+1);
            reverse(a+i-idx+1,a+i+1);
        }
        if (t<idx-1)
        {
            reverse(a+1,a+i+1);
        }
        else if (t<idx)
        {
            reverse(a,a+i+1);
        }
        printf("%d",a[0]+1);
        for (int i=1;i<n;i++)
            printf(" %d",a[i]+1);
        puts("");
    }
    return 0;
}
