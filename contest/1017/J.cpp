#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int NSIZE = 10010 ,ESIZE = 100010*2;
int ehead[NSIZE];
int col[NSIZE];
int eto[ESIZE] , enext[ESIZE];
int eL;
int du[NSIZE];
void add_edge(int x,int y){
    eto[eL] = y;
    enext[eL] = ehead[x];
    ehead[x] = eL++;
}

queue<int> que;
void Gao(){
    int use[] = {0,0,0,0,0,0};
    que.push(0);
    while(que.empty() == false){
        use[1] = use[2] = use[3] = use[4] = use[5] = 0;
        int id = que.front();
        que.pop();
        for(int e = ehead[id] ; e!= -1; e= enext[e]){
            int nid = eto[e];
            if(col[nid] == 0) {que.push(nid); continue;}
            use[col[nid]] = 1;
        }
        for(int c = 1; c<=5;c++)
            if(use[c] == 0)
                {col[id] = c;break;}
    }
}
int main(){
    int n , m;
    while(scanf("%d%d",&n,&m) == 2){
        eL = 0;
        memset(ehead,-1,sizeof(ehead));
        int kk = 0;
        memset(du,0,sizeof(du));
        for(int i = 0 ;i < m; i++){
            int x,y;scanf("%d%d",&x,&y);
            --x;--y;
            add_edge(x,y);
            add_edge(y,x);
            du[x]++;du[y]++;
            kk = max(kk , du[x]);
            kk = max(kk , du[y]);
        }
        memset(col,0,sizeof(col));
        Gao();
        if(!(kk&1)) kk++;
        printf("%d\n",kk);
        for(int i = 0 ; i< n ;i++)
            printf("%d\n", col[i]);
    }
    return 0;
}
