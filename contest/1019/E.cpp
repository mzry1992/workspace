#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct Peo
{
    int x,y,t,w;
} peo[510];
vector<int> g[510];
vector< pair<int,int> >  goods[510];
bool conf(int i ,int j)
{
    long long xi = (peo[i].x - peo[0].x) , yi = (peo[i].y-peo[0].y);
    long long xj = (peo[j].x - peo[0].x) , yj = (peo[j].y-peo[0].y);
    return xi*yj-xj*yi == 0 && xi*xj+yi*yj >= 0;
}
bool cmp(const Peo &a,const Peo &b)
{
    long long da = (long long)(a.x-peo[0].x)*(a.x-peo[0].x) + (long long)(a.y - peo[0].y)*(a.y - peo[0].y);
    long long db = (long long)(b.x-peo[0].x)*(b.x-peo[0].x) + (long long)(b.y - peo[0].y)*(b.y - peo[0].y);
    return da<db;
}
int deg[510];
int dp[510][10001];
int main()
{

    int X0,Y0,N,T0;
    while(scanf("%d%d%d%d",&X0,&Y0,&N,&T0) == 4)
    {
        memset(deg,0,sizeof(deg));
        peo[0].x = X0; peo[0].y = Y0;
        N++;
        for(int i = 1 ; i<N; i++)
        {
            scanf("%d%d%d%d",&peo[i].x,&peo[i].y,&peo[i].t,&peo[i].w);
            g[i].clear();
        }
        sort(peo+1,peo+N,cmp);
        int beg = 1;
        int ans = 0;
        /*bool fail = false;
        for(beg = 1; beg < N ; beg++){
            if(peo[beg].x == peo[0].x && peo[beg].y == peo[0].y)
                {
                    if(T0 >= peo[beg].t)
                        {
                            ans+=peo[beg].w;
                            T0 -= peo[beg].t;
                        }
                    else {fail = true;break;}
                }
            else break;
        }
        if(fail){
            puts("0");
            continue;
        }*/
        //printf("ans =%d\n",ans);
        for(int i = beg ; i < N ; i++)
        {
            for(int j = i+1 ; j < N; j++)
            {
                if(conf(i,j))
                {
                    g[i].push_back(j);
                    deg[j]++;
                }
            }
        }
        int wcnt = 1;
        for(int i =beg; i< N; i++)
            if(deg[i] == 0)
            {
                goods[wcnt].clear();
                int sumt = peo[i].t;
                int sumw = peo[i].w;
                goods[wcnt].push_back(make_pair(peo[i].t,peo[i].w));
                for(int j = 0  ; j < g[i].size() ; j++)
                {
                    sumt+= peo[g[i][j]].t;
                    sumw+= peo[g[i][j]].w;
                    goods[wcnt].push_back(make_pair(sumt,sumw));
                }
                wcnt++;
            }
        /*printf("wcnt = %d\n",wcnt);
        for(int i = 0; i <wcnt;i++,puts("")){
            for(int j = 0 ;j < goods[i].size();j++)
                printf("(%d %d) ",goods[i][j].first,goods[i][j].second);

        }*/
        memset(dp,0,sizeof(dp));
        for (int i=1;i<wcnt;i++)
            for (int j=T0;j>=0;j--)
            {
                dp[i][j] = dp[i-1][j];
                for (int k=0;k<goods[i].size();k++)
                    if (j>=goods[i][k].first)
                        dp[i][j]=max(dp[i][j],dp[i-1][j-goods[i][k].first]+goods[i][k].second);
            }
        printf("%d\n",dp[wcnt-1][T0] +ans);
    }
    return 0;
}
