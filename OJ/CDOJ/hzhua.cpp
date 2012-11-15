#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
const int LEN = 1200;
const double eps = 0.00001;
int char_cnt;
int edge[101][30];
int pre[101];
bool mask[101];
double dp[LEN][101];
double mtx[200][200];
double mtx_b[200];
double ans[200];
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
int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}
void Gao()
{
    for (int i = 0;i < pcnt;i++)
    {
        if (cmp(mtx[i][i],0.0) == 0)
            for (int j = i;j < pcnt;j++)
                if (cmp(mtx[j][i],0.0) != 0)
                {
                    for (int k = i;k < pcnt;k++)
                        swap(mtx[j][k],mtx[i][k]);
                    swap(mtx_b[j],mtx_b[i]);
                }
        for (int j = 0;j < pcnt;j++)
            if (i != j && cmp(mtx[j][i],0.0) != 0)
            {
                double tmp = mtx[j][i]/mtx[i][i];
                for (int k = i;k < pcnt;k++)
                    mtx[j][k] -= mtx[i][k]*tmp;
                mtx_b[j] -= mtx_b[i]*tmp;
            }
    }
    ans[0] = mtx_b[0]/mtx[0][0];
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
        for(int i = 0 ; i <pcnt ;i++){
            if(mask[i]) {
                mtx[i][i] = 1.0;
                mtx_b[i] = 0.0;
                continue;
            }
            mtx_b[i] = -1.0;
            for(int c = 0 ;c<char_cnt ;c++){
                mtx[i][edge[i][c]] += 1.0/(char_cnt);
            }
            mtx[i][i] += -1.0;
        }
        for(int i = 0 ; i <pcnt;i++,puts(""))
            for(int j = 0 ; j<pcnt;j++)
                printf("%.10f ",mtx[i][j]);
        for(int i = 0 ; i <pcnt;i++,puts(""))
            printf("%.10f\n",mtx_b[i]);
        //Gao();
        printf("%.2f\n",ans[0]);
    }
    return 0;
}
