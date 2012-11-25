#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,typ[20];
int res;

void DFS(int now,int pre)
{
    if (now == m)
        res++;
    else
    {
        int op;
        if (typ[now] == 1)
            op = 0;
        else
            op = pre;
        for (int i = op;i < n;i++)
            DFS(now+1,i);
    }
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0;i < m;i++)
            typ[i] = 2;
        int k;
        scanf("%d",&k);
        for (int i = 0;i < k;i++)
        {
            int v;
            scanf("%d",&v);
            typ[v] = 1;
        }
        res = 0;
        DFS(0,0);
        printf("%d\n",res);
    }
	return 0;
}
