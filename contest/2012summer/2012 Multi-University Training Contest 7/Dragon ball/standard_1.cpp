#include<stdio.h>
#include<algorithm>
#include<memory.h>
#include<time.h>
#include<iostream>
#define LL long long
using namespace std;
struct node{
    int pos,cost;
}p[55][1005];
int dp[55][1005],pos[55][1005],n,m,x,i,j,t,k,mink,res;
int cmp(node a,node b){
    return a.pos<b.pos;
}
int abs(int a){
    return a>=0?a:-a;
}
int min(int a,int b){
    if(a==-1)return b;
    return a<b?a:b;
}
int main(){
    int tt = clock();
    //freopen("data.in", "r", stdin);
    //freopen("data_1.out", "w", stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&m,&n,&x);
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)scanf("%d",&p[i][j].pos);
        for(i=0;i<m;i++){
            for(j=0;j<n;j++)scanf("%d",&p[i][j].cost);
            sort(p[i],p[i]+n,cmp);
        }
        memset(dp,-1,sizeof(dp));
        for(i=0;i<n;i++)dp[0][i] = p[0][i].cost + abs(x - p[0][i].pos);
        res = -1;
        for(i=1;i<m;i++){
            for(j=0,k=0,mink=-1;j<n;j++){                
                while(k<n&&p[i-1][k].pos<=p[i][j].pos){
                    if(mink==-1||dp[i-1][mink]-p[i-1][mink].pos >= dp[i-1][k]-p[i-1][k].pos){
                        mink = k;
                    }
                    k++;
                }
                if(mink>=0)dp[i][j] = dp[i-1][mink] + p[i][j].pos - p[i-1][mink].pos + p[i][j].cost;
            }
            for(j=n-1,k=n-1,mink=-1;j>=0;j--){
                while(k>=0 && p[i-1][k].pos>=p[i][j].pos){ 
                    if(mink==-1||dp[i-1][mink]+p[i-1][mink].pos >= dp[i-1][k]+p[i-1][k].pos){
                        mink = k;
                    }
                    k--;
                }
                if(mink>=0)dp[i][j] = min(dp[i][j],dp[i-1][mink] + p[i-1][mink].pos - p[i][j].pos + p[i][j].cost);
            }
        }
        res = dp[m-1][0];
        for(j=1;j<n;j++)
            if(res>dp[m-1][j])res = dp[m-1][j];
        printf("%d\n",res);
    }
    //cerr<<"time:"<<clock()-tt<<endl;
} 
