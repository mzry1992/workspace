#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int pos[1000001];
long long ans[1000001];
int ev[3000000];
bool cmp(int a,int b)
{
    return abs(a)<abs(b);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (!n)
            break;
        memset(pos,-1,sizeof(pos));
        int L=0;
        for (int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            ev[L++]=-(i-pos[x]+1);
            ev[L++]=-(n-i+1);
            ev[L++]=n-pos[x]+1;
            pos[x]=i;
        }
        sort(ev,ev+L,cmp);
        long long det=n;
        for (int i=1,j=0;i<=n;i++)
        {
            while (j<L && abs(ev[j])==i)
            {
                if (ev[j]>0)
                    det++;
                else
                    det--;
                j++;
            }
            ans[i]=ans[i-1]+det;
        }
        int m;
        scanf("%d",&m);
        while (m--)
        {
            int x;
            scanf("%d",&x);
            printf("%I64d\n",ans[x]);
        }
    }
    return 0;
}
