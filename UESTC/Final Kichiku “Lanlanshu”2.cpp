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
const double pi=acos(-1.0);
const double eps=1e-5;
const long long MOD = 1000000000;
char seq[101];
char *top;
int slen , len;
//int dp[n][less][seq_i]
long long dp[201][2][101][11][3];
bool judge(int x, int pre, char c) {
    if(c == 0) return false;
    if(pre == 10) return true;
    if(c == '/') return x>pre;
    if(c == '-') return x==pre;
    if(c == '\\') return x<pre;
}
long long calc(int p,int less, int si,int pre,int zero) {
    if(p == -1) {
        if(zero != 2) return 0;
        if(si == slen-1) return 1;
        return 0;
    }
    if(dp[p][less][si][pre][zero] != -1) return dp[p][less][si][pre][zero];
    long long  &ans = dp[p][less][si][pre][zero];
    ans = 0;
    for(int c = 0 ; c <= 9 ; c++) {
        if(c > top[p] && less == false) break;
        if(zero == 0 && c== 0) {
            ans = calc(p- 1 ,c < top[p] || less, si , pre , zero);
            continue;
        }
        int nz = ((zero == 0) ? 1: 2);
        //if(c > pre && seq[si] == '/')
        bool f =false;
        if(zero==2 && judge(c , pre , seq[si+1])) {
            ans = (ans +calc(p-1,c < top[p] || less , si+1 , c,nz))%MOD;
            f = true;
        }
        if((f == false || seq[si+1] != seq[si]) && judge(c , pre , seq[si]))
            ans = (ans +calc(p-1,c < top[p] || less , si , c,nz))%MOD;

    }
    return ans;
}
long long  def(char *tc) {
    MEME(dp);
    len = strlen(tc);
    reverse(tc,tc+len);
    for(int i = 0 ; i <len; i++) tc[i] -='0';
    top = tc;
    return calc(len-1 , 0 , 0 , 10 , 0);
}
void minu(char *s) {
    int len = strlen(s);

    for(int i = len-1; i>=0; i--)
        if(s[i] != '0') {
            s[i]--;
            for(int j = len-1; j>i ; j--) s[j] = '9';
            break;
        }
}
char mn[200] ,mx[200];
int main() {
    freopen("in.txt","r",stdin);
    freopen("out_h.txt","w",stdout);
    while(scanf("%s",seq) == 1) {
        slen = strlen(seq);
        scanf("%s%s",mn,mx);
        minu(mn);
        //puts(mn);
        long long ca = def(mn) ;
        long long cb = def(mx) ;
        //printf("%d %d\n" ,ca,cb);
        printf("%08I64d\n",(cb-ca+MOD)%MOD);
    }
    return 0;
}

