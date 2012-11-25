#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
struct Edge{
    int x ,y;
    int val;
};
Edge e[70010];
bool operator<(const Edge &a,const Edge &b){
    return a.val < b.val;
}
int fat[20010];
int fint(int x){
    if(fat[x] == -1) return fat[x] = x;
    if(fat[x] == x) return x;
    return fat[x] = fint(fat[x]);
}
int main(){
    int T;scanf("%d",&T);
    for(int ii = 1;ii<=T;ii++){
        memset(fat,-1,sizeof(fat));
        int ecnt = 0;
        int n,m,r;
        scanf("%d%d%d",&n,&m,&r);
        for(int i = 0 ; i < n ; i++){
            e[ecnt].x = 0;
            e[ecnt].y = i+1;
            e[ecnt].val = 10000;
            ecnt++;
        }
        for(int i = 0 ; i < m ; i++){
            e[ecnt].x = 0;
            e[ecnt].y = n+i+1;
            e[ecnt].val = 10000;
            ecnt++;
        }
        for(int i = 0 ; i <r ; i++){
            int x,y,val;
            scanf("%d%d%d",&x,&y,&val);
            x++;y++;
            y+=n;
            e[ecnt].x = x;
            e[ecnt].y = y;
            e[ecnt].val = 10000-val;
            ecnt++;
        }
        sort(e, e+ecnt);
        int ans = 0;
        for(int ei = 0 ; ei < ecnt;ei++){
            int x = e[ei].x;
            int y = e[ei].y;
            int fx = fint(x);
            int fy = fint(y);
            if(fx == fy) continue;
            ans += e[ei].val;
            fat[fx] = fy;
        }
        printf("%d\n",ans);
    }
    return 0;
}
