#include<cstdio>
#include<algorithm>
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int tot=0;
        for (int i=0;i<n*m;i++)
        {
            int x;
            scanf("%d",&x);
            tot+=x;
        }
        if ((n&1)!=(m&1))
            if (tot&1)
                puts("NO");
            else
                puts("YES");
        else if (n&1)
        {
            tot=std::min(n*m-tot,tot);
            if (tot && tot<n)
                puts("NO");
            else if ((tot&1) && tot<m)
                    puts("NO");
            else
                puts("YES");
        }
        else
            puts("YES");
    }
    return 0;
}
