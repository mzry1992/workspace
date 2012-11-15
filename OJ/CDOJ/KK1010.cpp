#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int f[1200000],a[200000];
bool visible[1200000];
int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

int main()
{
    int n,m,x,y,l;
    int ft = 0;
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)
            break;
        l=n;
        for (int i=0;i<n;i++) a[i]=i;
        for (int i = 0;i < n+m;i++)
        {
            f[i] = i;
            //a[i] = i;
        }
        for (int i = 1;i <= m;i++)
        {
            char ch;
            scanf(" %c",&ch);
            if (ch == 'M')
            {
                scanf("%d%d",&x,&y);
                f[findf(a[x])]=findf(a[y]);
            }
            else
            {
                scanf("%d",&x);
                l++;
                a[x]=l;
                f[a[x]]=a[x];
            }
        }

        for (int i = 0;i < n+m;i++)
            visible[i] = false;
        int cnt = 0;
        for (int i = 0;i < n;i++)
        {
            x = findf(a[i]);
            //cout<<x<<" ";
            if (visible[x] == false)
            {
                cnt++;
                visible[x] = true;
            }
        }
        ft++;
        printf("Case #%d: %d\n",ft,cnt);
    }
}
