#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<int> emy[100000];
int n,m;
int b[100000],cnt[100000],sol[100000],tot;

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            emy[i].clear();
            b[i] = cnt[i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            u--;
            v--;
            emy[u].push_back(v);
            emy[v].push_back(u);
            cnt[u]++;
            cnt[v]++;
        }
        tot = 0;
        for (int i = 0; i < n; i++)
            if (cnt[i] > 1)
                sol[tot++] = i;
        if (tot == 0)
        {
            printf("1\n1");
            for (int i = 2; i <= n; i++)
                printf(" %d",i);
            printf("\n");
        }
        else
        {
            while (tot > 0)
            {
                int now = sol[--tot];
                if (cnt[now] < 2)   continue;
                for (int i = 0; i < emy[now].size(); i++)
                    if (b[emy[now][i]] == b[now])
                    {
                        cnt[now]--;
                        cnt[emy[now][i]]--;
                    }
                b[now] = 1-b[now];
                for (int i = 0; i < emy[now].size(); i++)
                    if (b[emy[now][i]] == b[now])
                    {
                        cnt[now]++;
                        cnt[emy[now][i]]++;
                        if (cnt[emy[now][i]] > 1)
                            sol[tot++] = emy[now][i];
                    }
            }
            printf("2\n");
            bool first;
            first = true;
            for (int i = 0;i < n;i++)
                if (b[i] == 0)
                {
                    if (!first) printf(" ");
                    first = false;
                    printf("%d",i+1);
                }
            printf("\n");
            first = true;
            for (int i = 0;i < n;i++)
                if (b[i] == 1)
                {
                    if (!first) printf(" ");
                    first = false;
                    printf("%d",i+1);
                }
            printf("\n");
        }
    }
    return 0;
}
