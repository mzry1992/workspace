#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;

struct Point
{
    int x,y;
    Point() {}
    Point(int _x,int _y)
    {
        x = _x,y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x-b.x,y-b.y);
    }
    long long operator *(const Point &b)const
    {
        return (long long)x*b.y-(long long)y*b.x;
    }
};

map<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int> > > mp;
map<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int> > >::iterator it;

struct Edge
{
    int to,next;
};
Edge edge[6000000];
int head[1000000],L;
int ind[1000000];
Point p[1000000][3];
int n;

void addedge(int u,int v)
{
    //printf("%d --> %d\n",u,v);
    ind[v]++;
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;
}

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%d",&n);
	    mp.clear();
	    for (int i = 0;i < n;i++)
	    {
            for (int j = 0;j < 3;j++)
                scanf("%d%d",&p[i][j].x,&p[i][j].y);
            for (int j = 0;j < 3;j++)
            {
                Point pl = p[i][j];
                Point pr = p[i][(j+1)%3];
                if (pl.x == pr.x)   continue;

                if (pl.x > pr.x)
                    swap(pl,pr);

                int typ = 0;
                Point tp = p[i][(j+2)%3];
                if ((tp-pl)*(pr-pl) < 0)  typ = 1;

                mp[make_pair(make_pair(pl.x,pr.x),pl.y-pr.y)].push_back(make_pair(make_pair(pl.y,typ),i));
            }
	    }

        L = 0;
        for (int i = 0;i < n;i++)
        {
            ind[i] = 0;
            head[i] = -1;
        }

	    for (it = mp.begin();it != mp.end();it++)
	    {
	        sort(it->second.begin(),it->second.end());
//	        printf("((%d, %d), %d) : ",it->first.first.first,it->first.first.second,it->first.second);
//	        for (int i = 0;i < it->second.size();i++)
//                printf("((%d, %d), %d) ",it->second[i].first.first,it->second[i].first.second,it->second[i].second);
//            printf("\n");
	        for (int i = 0;i+1 < it->second.size();i++)
                addedge(it->second[i].second,it->second[i+1].second);
	    }

        queue<int> Q;
        for (int i = 0;i < n;i++)
            if (ind[i] == 0)
                Q.push(i);
        while (!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            printf("%d ",now+1);

            for (int i = head[now];i != -1;i = edge[i].next)
            {
                ind[edge[i].to]--;
                if (ind[edge[i].to] == 0)
                    Q.push(edge[i].to);
            }
        }
        printf("\n");
	}
    return 0;
}

