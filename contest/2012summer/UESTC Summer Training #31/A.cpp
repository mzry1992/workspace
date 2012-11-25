#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        in[v-1].insert(u-1);
        out[u-1].insert(v-1);
    }
    for (int i=0;i<n;i++)
        time[i]=0;
    int q;
    scanf("%d",&q);
    int nowtime=1;
    for (int i=0;i<q;i++)
    {
        int typ,a,b;
        scanf("%d%d%d",&typ,&a,&b);
        a--;b--;
        if (typ==1)
        {
            if (time[a]<time[b])
            {
                if (out[a].find(find(b))!=out[a].end())
                    puts("YES");
                else
                    puts("NO");
            }
            else
                if (in[b].find(find(a))!=in[b].end())
                    puts("YES");
                else
                    puts("NO");
        }
        else
        {
            if (find(a)==find(b))
                continue;
            fa[find(a)]=find(b);
        }
    }
	return 0;
}
