#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>

typedef std::vector<int> IntArray;

struct Network
{
   struct Edge
   {
   int n; // next adjacent edge
   int v; // to which vertex
   int c; // residual capacity
   };
   struct Vert
   {
   int e; // first adjacent edge
   int o; // first out-edge in the level-network
   int l; // level in the network
   };
   typedef std::vector<Edge> EdgeSet;
   typedef std::vector<Vert> VertSet;
   int _s, _t;
   VertSet _V;
   EdgeSet _E;
   // interfaces
   void Reset(int n, int s, int t);
   void InsertEdge(int u, int v, int c);
   int Dinic();
};

void Network::Reset(int n, int s, int t)
{
   _V.resize(n);
   _E.clear();
   for (_s = 0; _s < n; _s++)
   {
   _V[_s].e = -1;
   _V[_s].l = -1;
   _V[_s].o = -1;
   }
   _s = s, _t = t;
}

void Network::InsertEdge(int u, int v, int c)
{
   Edge e;
   // we add the forward edge and a residual one whose
   // initial capacity is 0 adjacently
   e.v = v, e.c = c, e.n = _V[u].e;
   _V[u].e = _E.size();
   _E.push_back(e);
   e.v = u, e.c = 0, e.n = _V[v].e;
   _V[v].e = _E.size();
   _E.push_back(e);
}

int Network::Dinic()
{
   int maxflow = 0;
   int u, v, e, ee, f;
   IntArray q;
   // insert a special edge for dfs
   _E.resize(_E.size() + 1);
   _E.back().v = _s;
   while (true)
   {
   // rebuild the level-network
   for (u = 0; u < _V.size(); u++)
      _V[u].l = -1;
   _V[_s].l = f = 0;
   _V[_s].o = _V[_s].e;
   q.clear();
   q.push_back(_s);
   while (f < (int)q.size())
   {
      u = q[f++];
      for (e = _V[u].e; e != -1; e = _E[e].n)
      {
      v = _E[e].v;
      if (_V[v].l == -1 && _E[e].c > 0) // not visited
      {
         _V[v].o = _V[v].e;
         _V[v].l = _V[u].l + 1;
         q.push_back(v);
      }
      }
   }
   // the sink is not in level-network
   if (_V[_t].l == -1)
      break;
   q.clear();                             //reserve the path
   q.push_back(_E.size() - 1); // push source into the queue
   while (!q.empty())
   {
      u = _E[q.back()].v;
      if (u == _t) // an augmenting path found
      {
      // calculate the flow
      for (f = INT_MAX, e = 1; e < (int)q.size(); e++)
         if (_E[q[e]].c < f)
         f = _E[q[e]].c, u = e;                   //notice this u !
      for (e = 1; e < q.size(); e++)
      {
         // we store one edge and a residual one adjacently
         // XOR ^ 1 is a smart method to find its neighbour
         _E[q[e]].c -= f;
         _E[q[e]^1].c += f;
      }
      // increase maxflow by flow
      maxflow += f;
      // adjust the queue size
      q.resize(u);
      }
      else
      {
      for (e = _V[u].o; e != -1; e = _E[e].n)
      {
         // the edge is full or marked as removed, remove it
         if (_V[_E[e].v].l < 0 || _E[e].c < 1)
         continue;
         if (_V[_E[e].v].l == _V[u].l + 1)
         break;
      }
      if ((_V[u].o = e) != -1)
         q.push_back(e);
      else
      {
         // remove u from augmenting queue
         q.pop_back();
         // we mark the vertex as removed
         _V[u].l = -1;
      }
      }
   }
   }
   return maxflow;
}

Network g;

int main()
{
    int t,ft,n,m,s,h;
    int c[200],i,a,b;
    scanf("%d",&t);
    for (ft = 1;ft <= t;ft++)
    {
        scanf("%d%d%d%d",&n,&m,&s,&h);
        g.Reset(2*n+2,0,2*n+1);
        g.InsertEdge(0,s,19921005);
        g.InsertEdge(h,2*n+1,19921005);
        for (i = 1;i <= n;i++)
        {
            scanf("%d",&c[i]);
            if ((i == s) || (i == h))
               c[i] = 19921005;
            g.InsertEdge(i,n+i,c[i]);
        }
        for (i = 1;i <= m;i++)
        {
            scanf("%d%d",&a,&b);
            g.InsertEdge(n+a,b,19921005);
            g.InsertEdge(n+b,a,19921005);
        }
        printf("%d\n",g.Dinic());
    }
    return 0;
}




