#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct Tree
{
    int l,r;
};

Tree buf[30000];
int L,now;
vector<int> tree[11],tres;
vector<vector<int> > res[11];

int DFS(int root)
{
    int nl,nr;
    if (buf[root].l == -1)
        nl = 1;
    else
        nl = DFS(buf[root].l);
    tres[now++] = nl;
    if (buf[root].r == -1)
        nr = 1;
    else
        nr = DFS(buf[root].r);
    return nl+nr;
}

void Gao()
{
    tree[0].push_back(-1);
    L = 0;
    for (int i = 1; i <= 10; i++)
        for (int j = 0; j <= i-1; j++)
            for (int l = 0; l < tree[j].size(); l++)
                for (int r = 0; r < tree[i-1-j].size(); r++)
                {
                    buf[L].l = tree[j][l];
                    buf[L].r = tree[i-1-j][r];
                    tree[i].push_back(L);
                    L++;
                }
    for (int i = 1; i <= 10; i++)
    {
        tres.resize(i);
        for (int j = 0; j < tree[i].size(); j++)
        {
            now = 0;
            DFS(tree[i][j]);
            res[i].push_back(tres);
        }
        sort(res[i].begin(),res[i].end());
    }
}

int n;

int main()
{
    Gao();
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        tres.resize(n);
        for (int i = 0; i < n; i++)
            scanf("%d",&tres[i]);
        printf("%d\n",(int)(lower_bound(res[n].begin(),res[n].end(),tres)-res[n].begin()+1));
    }
    return 0;
}
