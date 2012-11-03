#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef std::vector<int> IntArray;

struct Network
{
    struct Edge{int n,v,c;};
    struct Vert{int e,o,l;};
    typedef std::vector<Edge> EdgeSet;
    typedef std::vector<Vert> VertSet;
    int _s,_t;
    VertSet _V;
    EdgeSet _E;
    void Reset(int n,int s,int t);
    void InsertEdge(int u,int v,int c);
    int Dinic();
};

void Network::Reset(int n,int s,int t)
{
    _V.resize(n);
    _E.clear();
    for (_s = 0;_s < n;_s++)
    {
        _V[_s].e = _V[_s].l = _V[_s].o = -1;
    }
    _s = s,_t = t;
}

void Network::InsertEdge(int u,int v,int c)
{
    Edge e;
    e.v = v,e.c = c,e.n = _V[u].e;
    _V[u].e = _E.size();
    _E.push_back(e);
    e.v = u,e.c = 0,e.n = _V[v].e;
    _V[v].e = _E.size();
    _E.push_back(e);
}

int Network::Dinic()
{
    int maxflow = 0;
    int u,v,e,ee,f;
    IntArray q;
    _E.resize(_E.size()+1);
    _E.back().v = _s;
    while (true)
    {
        for (u = 0;u < _V.size();u++)
            _V[u].l = -1;
        _V[_s].l = f = 0;
        _V[_s].o = _V[_s].e;
        q.clear();
        q.push_back(_s);
        while (f < (int)q.size())
        {
            u = q[f++];
            for (e = _V[u].e;e != -1;e = _E[e].n)
            {
                v = _E[e].v;
                if (_V[v].l == -1 && _E[e].c > 0)
                {
                    _V[v].o = _V[v].e;
                    _V[v].l = _V[u].l+1;
                    q.push_back(v);
                }
            }
        }
        if (_V[_t].l == -1) break;
        q.clear();
        q.push_back(_E.size()-1);
        while (!q.empty())
        {
            u = _E[q.back()].v;
            if (u == _t)
            {
                for (f = INT_MAX,e = 1;e < (int)q.size();e++)
                    if (_E[q[e]].c < f)
                        f = _E[q[e]].c,u = e;
                for (e = 1;e < q.size();e++)
                {
                    _E[q[e]].c -= f;
                    _E[q[e]^1].c += f;
                }
                maxflow += f;
                q.resize(u);
            }
            else
            {
                for (e = _V[u].o;e != -1;e = _E[e].n)
                {
                    if (_V[_E[e].v].l < 0 || _E[e].c < 1)
                        continue;
                    if (_V[_E[e].v].l == _V[u].l+1)
                        break;
                }
                if ((_V[u].o = e) != -1)
                    q.push_back(e);
                else
                {
                    q.pop_back();
                    _V[u].l = -1;
                }
            }
        }
    }
    return maxflow;
}

Network g;
int n,m;

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        g.Reset(n+2,0,n+1);
        g.InsertEdge(0,1,n*2);
        for (int i = 1;i <= n;i++)
        {
            int cnt,v;
            scanf("%d",&cnt);
            for (int j = 1;j <= cnt;j++)
            {
                scanf("%d",&v);
                g.InsertEdge(i,v,1);
            }
            g.InsertEdge(i,n+1,2);
        }
        cout << g.Dinic() << endl;
    }
}
