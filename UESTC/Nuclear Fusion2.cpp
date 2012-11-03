#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#define M 230
#define INF 1<<30
using namespace std;

int c[M][M];/*容量*/
int flow[M][M];/*流量*/
int up[M][M];/*上界*/
int low[M][M];/*下界*/
int pre[M];/*路径标号*/
int d[M];/*距离标号*/
int num[M];/*同距离标号个数，用于间隙优化*/
int row[M],col[M];/*行和，列和*/
int in[M],out[M];/*入边下界和，出边下界和*/
int sap(int begin,int end,int n)/*sap求网络最大流*/
{
    int Queue[M],front=0,rear=0;
    int i,j,k,dd,mflow=0;
    for(i=0;i<n;i++)
      num[d[i]=n]=1;
    d[end]=0;
    Queue[rear++]=end;
    while(front<rear)
    {
        j=Queue[front++];
        for(i=0;i<n;i++)
         if(d[i]>=n&&c[i][j]>0)
          {
              d[i]=d[j]+1;
              ++num[d[i]];
              Queue[rear++]=i;
          }
    }
    i=begin;
    while(d[begin]<n)
    {
        for(j=0;j<n;j++)
          if(c[i][j]>0&&d[i]==d[j]+1)
             break;
        if(j<n)
        {
           pre[j]=i;
           i=j;
           if(i==end)
           {
              dd=INF;
              while(i!=begin)
              {
                  dd=min(dd,c[pre[i]][i]);
                  i=pre[i];
              }
              i=end;
              while(i!=begin)
              {
                  c[pre[i]][i]-=dd;
                  c[i][pre[i]]+=dd;
                  flow[pre[i]][i]+=dd;
      flow[i][pre[i]]-=dd;
                  i=pre[i];
              }
              mflow+=dd;
           }
        }
        else
        {   dd=INF;
            for(j=0;j<n;j++)
               if(c[i][j]>0)
                 dd=min(dd,d[j]+1);
            if(dd!=INF)
              j=dd;
            ++num[j];
            --num[d[i]];
            if(num[d[i]]==0)
                return mflow;
            d[i]=j;
            if(i!=begin)
              i=pre[i];
        }
    }
    return mflow;
}
void work(int s,int t,int n)
{
    int vs=n, vt=n+1;/*新拟源汇点*/
    int tflow=0;/*判断是否存在可行流*/
    int i,j;
    for(i=0;i<n;++i)
    for(j=0;j<n;++j)
    {
        c[i][j]=up[i][j]-low[i][j];/*所有点间建边，容量为该行该列元素的上下界差*/
        in[i]+=low[i][j];/*记入边下界和*/
        out[j]+=low[i][j];/*记出边下界和*/
        tflow+=low[i][j];/*记可行流大小*/
    }
    for(int i=0;i<n;++i)
        c[vs][i]=out[i],c[i][vt]=in[i];/*新拟源汇建边*/
    c[t][s]=INF;/*注意这里，使原图成为无源汇的上下界图*/
    int mflow=sap(vs,vt,n+2);
    if(mflow!=tflow)/*如果最大流不是可行流*/
    {
        printf("IMPOSSIBLE\n");
        return;
    }
    c[t][s]=c[s][t]=0;/*去掉源汇间的连接*/
    sap(s,t,n);
    /*for(int i=1;i<=nn;++i)
    {
        for(int j=1;j<=mm;++j)
            printf("%d ",flow[i][j+nn]+low[i][j+nn]);/*由于上述判断时下界流量丢失,所以实际流量为最大流加下界*/
    //    printf("\n");
    //}
}

const char g[100][5] =
{"H","He","Li","Be","B","C","N","O","F","Ne",
"Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca",
"Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu",
"Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr",
"Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag",
"Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba",
"La","Ce","Pr","Nd","Pm","Sm","Eu","Gd",
"Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta",
"W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb",
"Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa",
"U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm" };
int n,m;
char a[20][5],b[20][5];
int na[20],nb[20];

int getid(char *s)
{
    for (int i = 0;i < 100;i++)
    if (strcmp(s,g[i]) == 0)    return i+1;
    return -1;
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        memset(c,0,sizeof(c));/*初始化*/
        memset(up,0,sizeof(up));
        memset(low,0,sizeof(low));
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        memset(flow,0,sizeof(flow));
        int suma = 0,sumb = 0;
        for (int i = 1;i <= n;i++)  {scanf("%s",a[i]);na[i] = getid(a[i]);suma += na[i];}
        for (int i = 1;i <= m;i++)  {scanf("%s",b[i]);nb[i] = getid(b[i]);sumb += nb[i];}
        sort(na+1,na+1+n);
        sort(nb+1,nb+1+m);
        for (int i = 1;i <= n;i++)
            low[0][i] = up[0][i] = na[i];
        for (int i = 1;i <= m;i++)
            low[n+i][n+m+1] = up[n+i][n+m+1] = nb[i];
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
                low[i][n+j] = up[i][n+j] = na[i];
        work(0,n+m+1,n+m+2);
    }
    return 0;
}
