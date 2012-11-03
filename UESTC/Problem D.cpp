#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
const int LEN = 100000;
const double eps = 0.000001;
int char_cnt;
int edge[200][30];
int pre[200];
bool mask[200];
double dp[LEN][200];
int pcnt;
void clr(){
    pcnt = 0;
    memset(edge,-1,sizeof(edge));
    memset(mask,0,sizeof(mask));
}
void add(string str){
    int pos = 0;
    for(int p = 0 ;  p < str.size();p++){
        if(edge[pos][str[p]-'A'] == -1){
            pcnt++;
            edge[pos][str[p]-'A'] = pcnt;
        }
        pos = edge[pos][str[p]-'A'];
        if(mask[pos])break;
    }
    mask[pos] = 1;
}
queue<int>que;
void build(){
    while(!que.empty()) que.pop();
    pre[0] = 0;
    for(int c = 0 ; c<char_cnt;c++){
        if(edge[0][c] != -1){
            pre[edge[0][c]] = 0;
            que.push(edge[0][c]);
        }
        else edge[0][c] = 0;
    }
    while(!que.empty()){
        int ipos = que.front();
        que.pop();
        for(int c = 0 ;c <char_cnt;c++){
            if(edge[ipos][c] == -1){
                edge[ipos][c] = edge[pre[ipos]][c];
            }
            else{
                pre[edge[ipos][c]] =edge[pre[ipos]][c];
                mask[edge[ipos][c]] |= mask[edge[pre[ipos]][c]];
                que.push(edge[ipos][c]);
            }
        }
    }
}
char ts[20];
int main(){
    int T;
    scanf("%d",&T);
    for(int ii =1;ii<=T;ii++){
        clr();
        int n = 0;
        scanf("%d%d",&char_cnt ,&n);
        for(int i =0;i<n;i++){
            scanf("%s",ts);
            add(ts);
        }
        build();
        pcnt++;
        for(int l = 0 ; l <LEN;l++)
            for(int p = 0 ; p <pcnt;p++)
                dp[l][p] = 0.0;
        dp[0][0] = 1.0;

        double ans = 0.0;

        for(int l = 0 ; l <LEN-1;l++){
            for(int p = 0 ; p <pcnt;p++)
                if(fabs(dp[l][p]*(l+1)) > eps){
                    if(mask[p]) {ans += l*dp[l][p];continue;}
                    for(int c = 0 ;c<char_cnt;c++)
                        dp[l+1][edge[p][c]] += dp[l][p]*1.0/char_cnt;
                }
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
