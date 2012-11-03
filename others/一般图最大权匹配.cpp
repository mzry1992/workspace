#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
#include<iostream>
using namespace std;
const int NSIZE = 100;
int M[NSIZE] ;
double conn[NSIZE][NSIZE] , new_conn[NSIZE][NSIZE];
int M2[NSIZE];
int pre[NSIZE];
double dis[NSIZE];
bool vis[NSIZE],old_vis[NSIZE];
int N;
int list[NSIZE];
int spfa(int u)
{
    vis[u] = true;
    old_vis[u] = old_vis[M[u]] = true;
    for(int v = 0 ; v< N; v++)
    {
        if(dis[v] > dis[u] + new_conn[u][v])
        {

            dis[v] = dis[u] + new_conn[u][v];
            pre[v] = u;
            if(vis[v]) return v;
            if(old_vis[v])
            {
                continue;
            }
            int ret = spfa(v);
            if(ret != -1)
                return ret;
        }
    }
    old_vis[u] = old_vis[M[u]] = false;
    vis[u] =false;
    return -1;
}
int find_cir()
{
    memset(vis,0,sizeof(vis));
    memset(old_vis,0,sizeof(old_vis));
    for(int i =0 ; i< N; i++)
        dis[i] = 0;
    random_shuffle(list,list+N);
    for(int i = 0 ; i < N ; i++)
    {
        int u = list[i];
        int ret = spfa(u);
        if(ret != -1)
            return ret;
    }
    return -1;
}
void augment(int u,double &ans)
{
    int x= u;
    int y = pre[x];
    for(int i = 0 ; i < N ; i++)
        M2[i]= M[i];
    do
    {
//printf(" %d %d\n",x,y);
        int a1 = x, a2 =M[y] ,a3=y;
        ans += conn[a1][a2] - conn[a2][a3];
        M2[a1] = a2;
        M2[a2] = a1;
        x = y;
        y = pre[y];
    }
    while(x!=u);
    for(int i = 0; i < N; i++)
        M[i] = M2[i];
    /*puts("");
    for(int i = 0; i < N ;i++)
    printf("%d - %d\n",i, M[i]);*/
}
void build()
{
    for(int i = 0; i < N ; i++)
        for(int j = 0 ; j < N; j++)
            new_conn[i][j] = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0 ; j < N; j++)
        {
            if(M[i]!=j && i != j)
            {
                new_conn[i][M[j]] = conn[j][M[j]] - conn[i][j];
                new_conn[j][M[i]] = conn[i][M[i]] - conn[i][j];
            }
        }
}
double Gao()
{
    if(N&1)
        N++;
    for(int i = 0 ; i< N ; i++)
        list[i] = i;
    double ret = 0;
    for(int i = 0; i < N; i+=2)
    {
        M[i] = i+1;
        M[i+1] = i;
        ret += conn[i][i+1];
    }
    int not_found = 0;

    while(not_found<=2)
    {
        build();
        int p = find_cir();
//printf("p = %d\n",p);
        if(p != -1)
        {
            not_found = 0;
            augment(p , ret);
        }
        else not_found++;
    }
    return ret;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int ii =1 ; ii<=T; ii++)
    {
        scanf("%d",&N);
        for(int i = 0; i < N; i++)
        {
            for(int j =0 ; j<N; j++)
                scanf("%lf",&conn[i][j]);
        }
        printf("%.2f\n",Gao());
    }
    return 0;
}
/*
4
0 2 2 3
2 0 4 3
2 4 0 2
3 3 2 0

*/
