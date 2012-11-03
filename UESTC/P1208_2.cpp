#include <iostream>
#define MAX_VERTICES 20000
#define MAXM 150000
#define MIN(x,y) ((x) < (y) ? (x) : (y))
using namespace std;

typedef struct node *node_pointer;
struct node 
{
      int vertex;
      struct node *link;        
};
node_pointer graph[MAX_VERTICES];
int n,m;
int dfn[MAX_VERTICES];
int low[MAX_VERTICES];
int flg[MAX_VERTICES];
typedef struct 
{
    int v;
    int w;   
}edge;
edge edges[MAXM];
int top = 0;
int node,path;
int visit[MAX_VERTICES];
int bicnt;
int ans1,ans2;
int num;

void addEdge(int v, int w) 
{
      node_pointer e = (node_pointer)malloc(sizeof(struct node));
      e->vertex = w;
      e->link = graph[v];
      graph[v] = e;
}

void addREdge(int v,int w)
{
      addEdge(v,w);
      addEdge(w,v);     
}
 
void init() 
{
    int i,u,v;
    for (i = 0;i < n;i++)
    {
        graph[i] = 0;
        dfn[i] = low[i] = -1;
        flg[i] = false;
    }
    for (i = 1;i <= m;i++)
    {
        scanf("%d %d",&u,&v);
        addREdge(u,v);
    }
}
 
void bicon(int u, int v) 
{
      node_pointer ptr;
      int w;
      edge e;
      flg[u] = true;
      dfn[u] = low[u] = num++;
      for (ptr = graph[u];ptr;ptr = ptr->link) 
      {
          w = ptr->vertex;
          if ((v != w) && (dfn[w] < dfn[u])) 
          {
                  edges[top].v = u;
                  edges[top].w = w;
                  ++top;
                  if (dfn[w] < 0) 
                  {
                      bicon(w,u);       
                      low[u] = MIN(low[u], low[w]);
                      if (low[w] >= dfn[u]) 
                      {
                          bicnt++;      
                          path = node = 0;
                          memset(visit,false,sizeof(visit));
                          do
                          {
                              e = edges[--top]; 
                              path++;
                              if (visit[e.v] == false)
                              {
                                             node++;
                                             visit[e.v] = true;
                              }
                              if (visit[e.w] == false)
                              {
                                             node++;
                                             visit[e.w] = true;
                              }
                          }
                          while( !(e.v == u && e.w == w));
                          if (node == 2)  ans1++;
                          else
                          if (path > node)       ans2 += path;
                      }         
                 } 
                 else if (w != v)
                        low[u] = MIN(low[u], dfn[w]);
          }
     }     
}
 
int main()
{
    int i;
    scanf("%d %d",&n,&m);
    while (!((n == 0) && (m == 0)))
    {
          init();
          ans1 = ans2 = num = bicnt = 0;
          for (i = 0;i < n;i++)
          if (flg[i] == false)
             bicon(i,-1);
          printf("%d %d\n",ans1,ans2);
          scanf("%d %d",&n,&m);
    }
    return 0;
}

