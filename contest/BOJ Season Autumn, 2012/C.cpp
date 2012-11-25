#include <cstdio>
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        int tot=0;
        while (n--)
        {
            int x;
            scanf("%d",&x);
            if (k&1)
                tot^=x&1;
            else
            {
                x%=(k+1);
                if (x==k)
                    tot^=2;
                else
                    tot^=x&1;
            }
        }
        if (tot)
            puts("Alice");
        else
            puts("Bob");
    }
    return 0;
}
