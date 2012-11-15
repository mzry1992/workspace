#include <stdio.h>
#define MAX 1000
#define MAXV 21005

int tcase,fcase;
int n,m,i,j,k,a,b,e,q;
int map[MAX][MAX];
int tasko[11000],taska[11000],taskb[11000];
int delnode[MAX],totd,node[MAX],tnode[MAX];
int newnodelist[MAX],tottemp,ys[MAX];
int newmap[MAX][MAX];
int ans[11000],totans,now;

int main()
{
    scanf("%d",&tcase);
    for (fcase = 1;fcase <= tcase;fcase++)
    {
        scanf("%d %d",&n,&m);
        for (i = 1;i <= n;i++)
        {
            for (j = 1;j <= n;j++)
                map[i][j] = MAXV;
            node[i] = true;
            map[i][i] = 0;
        }
        for (i = 1;i <= m;i++)
        {
            scanf("%d %d %d",&a,&b,&e);
            if (map[a][b] > e)
            {
               map[a][b] = e;
               map[b][a] = e;
            }
        }
        scanf("%d",&q);
        totd = 0;
        for (i = 1;i <= q;i++)
        {
            scanf("%d",&tasko[i]);
            if (tasko[i] == 0)
                      scanf("%d %d",&taska[i],&taskb[i]);
            if (tasko[i] == 1)
            {
                      scanf("%d",&taska[i]);
                      if (node[taska[i]] == true)
                      {
                         totd++;
                         delnode[totd] = taska[i];
                         node[taska[i]] = false;
                      }
            }
        }
        tottemp = 0;
        for (i = 1;i <= n;i++)
        if (node[i] == true)
        {
                    tottemp++;
                    newnodelist[tottemp] = i;
        }
        for (i = 1;i <= totd;i++)
            newnodelist[n+1-i] = delnode[i];
        for (i = 1;i <= n;i++)
            ys[newnodelist[i]] = i;        
        for (i = 1;i <= n;i++)   
            tnode[i] = false;   
        for (i = 1;i <= n;i++)
        for (j = 1;j <= n;j++)
            newmap[i][j] = map[newnodelist[i]][newnodelist[j]];
        totans = 0;
        for (k = 1;k <= tottemp;k++)
        {
            for (i = 1;i <= n;i++)
            for (j = 1;j <= n;j++)
            if (newmap[i][j] > newmap[i][k]+newmap[k][j])
                newmap[i][j] = newmap[i][k]+newmap[k][j];
            tnode[i] = true;
        }
        now = tottemp;
        /*for (i = 1;i <= n;i++)
        {
            for (j = 1;j <= n;j++)
                printf("%6d ",newmap[i][j]);
            printf("\n");
        }*/
        for (k = q;k >= 1;k--)
        {
            if (tasko[k] == 0)
            {
                           totans++;
                           ans[totans] = newmap[ys[taska[k]]][ys[taskb[k]]];
                           if (ans[totans] == MAXV) ans[totans] = -1;
                           if ((tnode[ys[taska[k]]] == false) || (tnode[ys[taskb[k]]] == false))   
                              ans[totans] = -1;   
            }
            else
            {
                           now++;
                           tnode[now] = true;  
                           for (i = 1;i <= n;i++)
                           for (j = 1;j <= n;j++)
                           if (newmap[i][j] > newmap[i][now]+newmap[now][j])
                              newmap[i][j] = newmap[i][now]+newmap[now][j];
            }
        }
        for (i = totans;i >= 1;i--)
            printf("%d\n",ans[i]);
        printf("\n");
    }
    return 0;
}
            
        
        
