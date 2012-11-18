#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,h,t;
vector<int> edges[100000];

void check()
{
	for (int i = 0;i < n;i++)
		sort(edges[i].begin(),edges[i].end());
}

int main()
{
    while (scanf("%d%d%d%d",&n,&m,&h,&t) != EOF)
    {
        for (int i = 0; i < n; i++)
            edges[i].clear();
        for (int i = 0; i < m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            u--;
            v--;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        check();
    }
    return 0;
}
