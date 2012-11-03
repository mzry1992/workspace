#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int inf = 100000000;
struct NODE{
    int to,next,cap,cost;
};
int n;
int vis[101],dis[101],pre[101];
int ehead[101];
NODE edge[4010];
int eL;
void add(int x,int y ,int cap,int cost){
    edge[eL].to = y;
    edge[eL].next = ehead[x];
    edge[eL].cap = cap;
    edge[eL].cost = cost;
    ehead[x] = eL++;
    //eL++;
    edge[eL].to = x;
    edge[eL].next = ehead[y];
    edge[eL].cap = 0;
    edge[eL].cost = -cost;
    ehead[y] = eL++;
    //eL++;
}
int spfa(int u){
    //printf("u = %d\n",u);
    vis[u] = true;
    for(int e = ehead[u] ; e != -1 ; e= edge[e].next){
        if(edge[e].cap == 0) continue;
        int v = edge[e].to;
        //printf("   v =%d cost = %d",v,edge[e].cost);
        if(dis[v] > dis[u] + edge[e].cost){
            dis[v] = dis[u] + edge[e].cost;
            pre[v] = e;
            if(vis[v]) return v;
            int ret = spfa(v);
            if(ret != -1) return ret;
        }
    }
    vis[u] = false;
    return -1;
}
int check(){
    for(int i = 0; i < n ; i++){
        dis[i] = 0;
        vis[i] = false;
    }
    for(int i = 0; i < n ;i++){
        int ret = spfa(i);
        //printf("ret = %d\n",ret);
        if(ret != -1) return ret;
    }
    return -1;
}
void dfs(int u){
    //printf("u = %d \n",u);
    vis[u] = true;
    for(int e = ehead[u] ; e!=-1;e= edge[e].next){
        int v = edge[e].to;
        //printf("   v = %d\n",v);
        if(edge[e].cap == 0) continue;
        if(vis[v] ==false)dfs(v);
    }
}
int ans = 0;
void Gao(int s,int t){
    memset(vis,0,sizeof(vis));
    dfs(s);
    if(vis[t] == false){
        puts("impossible");
        return;
    }
    while(1){
        int u = check();
        //printf("u = %d\n",u);
        if(u == -1)break;
        int v = u;
        while(1){
        //    printf("%d ",v);
            ans += edge[pre[v]].cost;
            edge[pre[v]].cap--;
            edge[pre[v]^1].cap++;
            v = edge[pre[v]^1].to;
            if(v == u) break;
        }
        //puts("");
    }
    printf("%d\n",ans+inf);
}
int main(){
    int T;scanf("%d",&T);
    for(int ii =1 ;ii<=T;ii++){
        memset(ehead,-1,sizeof(ehead));
        eL = 0;
        int m,s,t;
        scanf("%d%d%d%d",&n,&m,&s,&t);
        --s;--t;
        ans = 0;
        add(t,s,1,-inf);
        for(int i = 0; i < m ;i++){
            int u,v,a,b;
            scanf("%d%d%d%d",&u,&v,&a,&b);
            --u;--v;
            ans+= b;
            add(u,v,1,a-b);
        }
        printf("Case %d: ",ii);
        Gao(s,t);
    }
    return 0;
}
