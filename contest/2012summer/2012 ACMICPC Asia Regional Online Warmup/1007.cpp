#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Edge
{
    int col,u,v;
    Edge(){}
    Edge(int _col,int _u,int _v)
    {
        col = _col;
        u = _u;
        v = _v;
    }
    bool operator < (const Edge & b)const
    {
        return col < b.col;
    }
};

Edge edge[1000000];
int n,m,k;

int main()
{
    while (true)
    {
        scanf("%d%d%d",&n,&m,&k);
        if (n == 0 && m == 0 && k == 0)
            break;
        for (int i = 0;i < m;i++)
        {
            char ch;
            int u,v;
            scanf(" %c%d%d",&ch,&u,&v);
            u--;
            v--;
            edge[i] = Edge((ch == 'R'),u,v);
        }
        sort(edge,edge+m);

    }
	return 0;
}
