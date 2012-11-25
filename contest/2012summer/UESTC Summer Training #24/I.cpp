#include<cstdio>
int h[1000],typ[1000];
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,f,b;
        scanf("%d%d%d",&n,&f,&b);
        for (int i=0;i<n;i++)
            scanf("%d%d",&h[i],&typ[i]);
        int l=0,r=2000001000;
        while (l<r)
        {
            int mid=(long long)l+r>>1;
            long long tot=0;
            for (int i=0;i<n;i++)
                if (typ[i])
                {
                    if (f-h[i]>mid)
                        continue;
                    tot+=(mid-f+h[i])/(2*f);
                }
                else
                {
                    if (h[i]+f>mid)
                        continue;
                    tot+=1+(mid-f-h[i])/(2*f);
                }
            if (tot>=b)
                r=mid;
            else
                l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}
