#include <cstdio>
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        memset(pos,-1,sizeof(pos));
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            ev[L++]=EV(i-pos[a[i]]+1,0);
            ev[L++]=EV(n-i+1,1);
            ev[L++]=EV(n-1-pre[i]+1,2);
            pos[a[i]]=i;
        }
        for (int i
        int m;
        scanf("%d",&m);
    }
    return 0;
}
