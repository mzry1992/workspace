#include <cstdio>
int num[30],a[30];
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        int full=1<<n;
        for (int i=0;i<full;i++)
        {
            int l=0;
            for (int j=i;j;j /= 2)
                num[l++]=j%2;
            a[l-1]=num[l-1];
            for (int i=l-2;i>=0;i--)
                a[i]=num[i+1]^num[i];
            int out=0;
            for (int j=0;j<l;j++)
                if (a[j])
                    out|=1<<j;
            printf("%d\n",out);
        }
    }
    return 0;
}
