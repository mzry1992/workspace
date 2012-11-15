#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

int n;
char g[5010][5010];

set<int> mp[5010],rmp[5010];
set<int>::iterator it,it2;
set<int> res;

void Gao()
{
    for (int i = 0;i < n;i++)
    {
        mp[i].clear();
        for (int j = 0;j < n;j++)
            if (g[i][j] == '1')
                mp[i].insert(j);
        rmp[i].clear();
        for (int j = 0;j < n;j++)
            if (g[j][i] == '1')
                rmp[i].insert(j);
    }
    for (int i = 0;i < n;i++)
    {
        for (it = mp[i].begin();it != mp[i].end();it++)
        {
            set_intersection(mp[*it].begin(),mp[*it].end(),rmp[i].begin(),rmp[i].end(),insert_iterator<set<int> >(res,res.begin()));
            for (it2 = res.begin();it2 != res.end();it2++)
            {
                printf("%d %d %d\n",i+1,*it+1,*it2+1);
                return;
            }
        }
        mp[i].clear();
    }
    printf("-1\n");
}

int main()
{
    //freopen("in.txt","r",stdin);
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%s",g[i]);
        Gao();
    }
    return 0;
}
