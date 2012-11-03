#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;
#define SZ(x) (int(x.size()))
#define MP(X,Y) make_pair(X,Y)
#define PB(x)  push_back(x)
#define MEM(a)     (memset((a),0,sizeof(a)))
#define MEME(a)    (memset((a),-1,sizeof(a)))
#define MEMX(a)    (memset((a),0x7f,sizeof(a)))
#define For(i,a)   for((i)=0;i<(a);(i)++)
const int INF = 1000000000;
const double pi=acos(-1.0);
const double eps=1e-5;
int f[1001][1001][2];
int pnt[1001];
int sum[1001];
int n , L , M;
inline int c_sum(int a,int b){
    if(a == 0) return sum[b];
    return sum[b] - sum[a-1];
}

int calc(int p,int sp,int lis){
    if(p == n && sp == 0) return 0;
    if(p >= n || sp <0) return -INF;
    if(f[p][sp][lis] != -1) return f[p][sp][lis];
    int &ans = f[p][sp][lis]; ans = 0;
    if(lis){
        ans = max(calc(p+1,sp,1) + pnt[p] , calc(p+1,sp-1,0));
    }
    else
        ans = max(calc(p+L,sp,1) + c_sum(p,p+L-1) , calc(p+1,sp-1 , 0));
    //printf("%d %d %d = %d\n",p,sp,lis,ans);
    return ans;
}
int main() {
    while(scanf("%d%d%d",&n,&M,&L) == 3){
        memset(f, -1, sizeof(f));
        for(int i = 0 ; i < n ;i++) scanf("%d",&pnt[i]);
        sum [0] = pnt[0];
        for(int i = 1 ;i < n;i++ ) sum[i] = sum[i-1] + pnt[i];
        int ans = calc(0,M,0);
        printf("%d\n",ans);
    }
    return 0;
}
