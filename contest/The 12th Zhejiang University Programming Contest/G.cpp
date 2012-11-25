#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Edge
{
    int to,next;
};

Edge edge2[100000];
int head2[50000],L2;
int n,m,p,q,c;
pair<int,int> qj[50000],tmp;

struct Edge2
{
    int l,r,next;
};

Edge2 edge[100000];
int head[50000],L;

void addedge(int u,int v)
{
    edge2[L2].to = v;
    edge2[L2].next = head2[u];
    head2[u] = L2++;
}

void addedge2(int u,int v)
{
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;
}

int main()
{
	int t;
	scanf("%d",&t);
	for (int ft = 1;ft <= t;ft++)
	{
        scanf("%d%d%d%d",&n,&m,&p,&q);
        scanf("%d",&c);
        L2 = L = 0;
        for (int i = 0;i < n;i++)
            head2[i] = head[i] = -1;
        for (int i = 0;i < c;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            u--;
            v--;
            addedge(u,v);
        }
        for (int i = 0;i < n;i++)
        {
            int tot = 0;
            for (int j = head[i];j != -1;j = edge[j].next)
                qj[tot++] = make_pair(max(0,edge[j].to-q+1),min(m-1,edge[j].to+q-1));
            sort(qj,qj+tot);
            tmp = qj[0];
            for (int j = 1;j <= tot;j++)
                if (j == tot || qj[j].first > tmp.second)
                {
                    addedge2(i,tmp.first,tmp.second);
                    tmp = qj[j];
                }
                else
                    tmp.second = max(tmp.second,qj[j].first);
        }
	}
	return 0;
}
