#include<cstdio>

int nc[40],nd[40],l;

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int c,d;
        scanf("%d%d",&c,&d);
        if ((c&d)!=c)
        {
            puts("-1");
            continue;
        }
        for (l = 0;d;d /= 2,c /= 2,l++)
            nd[l] = d%2,nc[l] = c%2;
        int a=0,b=0;
        bool first=1;
        for (int i=l-1;i>=0;i--)
            if (!nd[i])
                continue;
            else if (nc[i])
            {
                a|=1<<i;
                b|=1<<i;
            }
            else if (first)
            {
                b|=1<<i;
                first=0;
            }
            else
                a|=1<<i;
        printf("%d %d\n",a,b);
    }
    return 0;
}
