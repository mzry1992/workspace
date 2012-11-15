#include <stdio.h>

using namespace std;

struct node
{int x , y , z;};

const int dx[4] = {1 , -1 , 0 , 0};
const int dy[4] = {0 , 0 , 1 , -1};

const int nx = 80010;
const int mx = 20010;

bool visited[nx];
node E[nx] , Q[mx];
int Fa[nx] , tmp[nx] , ans[mx] , start[nx] , begin[nx] , dis[nx];
int n , m , L , len;

bool cmp_1(const node &i , const node &j)
{
  return (i.x < j.x);
}

void init()
{
  char c;

  scanf("%d %d" , &n , &L);
  for (int i = 0 ; i < L ; ++i)
    {
      scanf("%d %d %d %c" , &E[i].x, &E[i].y , &E[i].z , &c);
      E[i + L] = E[i];
      swap(E[i + L].x , E[i + L].y);
    }
  scanf("%d" , &m);
  for (int i = 0 ; i < m ; ++i)
    {
      scanf("%d %d" , &Q[i].x , &Q[i].y);
      Q[i].z = i;
      Q[i + m] = Q[i];
      swap(Q[i + m].x , Q[i + m].y);
    }
  L *= 2 ; m *= 2;
}

int find(int t)
{
  len = 0;
  while (Fa[t] != t)
    {
      tmp[len++] = t;
      t = Fa[t];
    }
  for (int i = len - 2 ; i >= 0 ; --i)
    Fa[tmp[i]] = t;
  return t;
}

void DFS(int k)
{
  int t;

  Fa[k] = k;
  for (int i = start[k] ; i < start[k + 1] ; ++i)
    if (visited[Q[i].y])
      {
 t = find(Q[i].y);
 ans[Q[i].z] = dis[Q[i].x] + dis[Q[i].y] - 2 * dis[t];
      }
  visited[k] = 1;
  for (int i = begin[k] ; i < begin[k + 1] ; ++i)
    if (!visited[E[i].y])
      {
 dis[E[i].y] = dis[k] + E[i].z; 
 DFS(E[i].y);
 Fa[E[i].y] = k;
      }
}

void work()
{
  int down;

  down = 1;
  Q[m].x = n + 1;
  sort(Q , Q + m , cmp_1);
  for (int i = 0 ; i <= 2 * n ; ++i)
    if (!i || Q[i].x != Q[i - 1].x)
      {
 if (i) down = Q[i - 1].x + 1;
 for (int j = down ; j <= Q[i].x ; ++j)
   start[j] = i;
      }
  down = 1;
  E[L].x = n + 1;
  sort(E , E + L , cmp_1);
  for (int i = 1 ; i <= L ; ++i)
    if (!i || E[i].x != E[i - 1].x)
      {
 if (i) down = E[i - 1].x + 1;
 for (int j = down ; j <= E[i].x ; ++j)
   begin[j] = i;
      }
  memset(visited , 0 , sizeof(visited));
  dis[1] = 0;
  DFS(1);
}

void show()
{
  for (int i = 0 ; i < m / 2 ; ++i)
    printf("%d\n" , ans[i]);
}

int main()
{
  init();
  work();
  show();
}
