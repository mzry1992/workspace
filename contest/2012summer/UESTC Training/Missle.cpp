#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int rel[2000],app[2000];
int n,k,m;
pair<int,int> a[2000];

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d%*d%d%d",&n,&k,&m);
        for (int i = 0; i < n; i++)
            scanf("%d%d",&a[i].first,&a[i].second);
        memset(rel,-1,sizeof(rel));
        for (int i = 0; i < m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            if (u < v)  swap(u,v);
            u--,v--;
            rel[u] = v;
        }
        sort(a,a+n);
        int res = -1,j,cnt = 0;
        memset(app,0,sizeof(app));
        for (j = 0; j < n; j++)
            if (rel[j] < 0)
            {
                app[a[j].second-1]++;
                if (app[a[j].second-1] == 1)
                    cnt++;
                if (cnt == k)   break;
            }
            else
                break;
        if (cnt == k)
            res = a[j].first-a[0].first;
        for (int i = 1; i < n; i++)
        {
            app[a[i-1].second-1]--;
            if (app[a[i-1].second-1] == 0)
                cnt--;
            while (j < n && cnt < k)
            {
                if (rel[j] < i)
                {
                    app[a[j].second-1]++;
                    if (app[a[j].second-1] == 1)
                        cnt++;
                    if (cnt == k)   break;
                    j++;
                }
                else
                    break;
            }
            if (cnt == k)
            {
                if (res == -1 || res > a[j].first-a[i].first)
                    res = a[j].first-a[i].first;
            }
        }
        printf("Case #%d: %d\n",cas,res);
    }
    return 0;
}
