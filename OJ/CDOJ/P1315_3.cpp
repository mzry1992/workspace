const int MAXV = 1<<30;
int tcase,fcase;
int n,m,i,j,a,b;
int map[50][50],val[50][50],val2[10000];
int tu[50][50],sa[3000],sb[3000],tots;
char st[100];
struct graphtype
{
       int next;
       int to;
}g[10000],g2[10000],newg[10000];
int totg,totg2,totn,totnewg;
int visit[10000],dfsorder[50],totdfs;
int totsc,nodein[10000],value[10000];
int ans,tans;

void addpath(int u,int v)
{
     totg++;                      totg2++;   
     g[totg].to = v;              g2[totg2].to = u;
     g[totg].next = g[u].next;    g2[totg2].next = g2[v].next;
     g[u].next = totg;            g2[v].next = totg2;
}

void addnewpath(int u,int v)
{
     totnewg++;
     newg[totnewg].to = v;
     newg[totnewg].next = newg[u].next;
     newg[u].next = totnewg;
}

void DFS1(int i)
{
     int j;
     visit[i] = true;
     for (j = g[i].next;j != -1;j = g[j].next)
     if (visit[g[j].to] == false)
        DFS1(g[j].to);
     totdfs++;
     dfsorder[totdfs] = i;
}

void DFS2(int i)
{
     int j;
     visit[i] = true;
     nodein[i] = totsc;
     for (j = g2[i].next;j != -1;j = g2[j].next)
     if (visit[g2[j].to] == false)
        DFS2(g2[j].to);
}

void Kosaraju()
{
     int i,j;
     for (i = 1;i <= totn;i++)
         visit[i] = false;
     totdfs = 0;
     for (i = 1;i <= totn;i++)
     if (visit[i] == false)   DFS1(i);
     for (i = 1;i <= totn;i++)
         visit[i] = false;
     totsc = 0;
     for (i = totn;i >= 1;i--)
     if (visit[dfsorder[i]] == false)
     {
                  totsc++;
                  DFS2(dfsorder[i]);
     }
     for (i = 1;i <= totsc;i++)
         value[i] = 0;
     for (i = 1;i <= totn;i++)
         if (val2[i] >= 0) value[nodein[i]] += val2[i];
     totnewg = 0;
     for (i = 1;i <= totsc;i++)
     {
         totnewg++;
         newg[totnewg].next = -1;
     }
     for (i = 1;i <= totn;i++)
     for (j = g[i].next;j != -1;j = g[j].next)
     if (nodein[i] != nodein[g[j].to])
        addnewpath(nodein[i],nodein[g[j].to]);
}

void DFS(int now)
{
     int i,j;
     visit[now] = true;
     tans += value[now];
     if (tans > ans)
        ans = tans;
     for (i = newg[now].next;i != -1;i = newg[i].next)
     {
         j = newg[i].to;
         if (visit[j] == false) DFS(j);
     }
     tans -= value[now];
     visit[now] = false;
}

int main()
{
    scanf("%d",&tcase);
    for (fcase = 1;fcase <= tcase;fcase++)
    {
        scanf("%d %d",&n,&m);
        tots = totg = totg2 = 0;
        for (i = 1;i <= n;i++)
        {
            scanf("%s",&st);
            for (j = 1;j <= m;j++)
            {
                map[i][j] = st[j-1];
                if (map[i][j] == '*')
                {
                          tots++;
                          sa[tots] = i;   sb[tots] = j;
                }
                if ((map[i][j] == '#') || (map[i][j] == '*')) val[i][j] = 0;
                else
                    val[i][j] = map[i][j]-'0';
                totg++;
                totg2++;
                val2[totg] = val[i][j];
                g[totg].next = g2[totg2].next = -1;
                tu[i][j] = totg;
            }
        }
        totn = totg;
        for (i = 1;i <= n;i++)
        for (j = 1;j <= m;j++)
        if (map[i][j] != '#')
        {
                      if (j+1 <= m)
                      if (map[i][j+1] != '#')
                         addpath(tu[i][j],tu[i][j+1]);
                      if (i+1 <= n)
                      if (map[i+1][j] != '#')
                         addpath(tu[i][j],tu[i+1][j]);
        }
        for (i = 1;i <= tots;i++)
        {
            scanf("%d %d",&a,&b);
            addpath(tu[sa[i]][sb[i]],tu[a+1][b+1]);
        }
        Kosaraju();
        ans = -1;
        tans = 0;
        for (i = 1;i <= totsc;i++)
            visit[i] = false;
        DFS(nodein[tu[1][1]]);
        printf("%d\n",ans);
    }
}
