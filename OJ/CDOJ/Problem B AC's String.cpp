#include<cstdio>
#include<set>
#include<cstring>
using namespace std;
int mod[2] = {100000007 ,100000399};
int pk[2] = {47 , 89};
int ten[100010][2];
int tree[100010*4][2];
int A[100010][2];
void build(int x,int l,int r) {
    if (l==r) {
        tree[x][0]=A[l][0];
        tree[x][1]=A[l][1];
        return ;
    }
    tree[x][0]=tree[x][1]=0;
    int mid=l+r>>1;
    build(x*2,l,mid);
    build(x*2+1,mid+1,r);
}

void update(int x,int l,int r,int s,int t,int v1,int v2) {
    if (l<=s && t<=r) {
        tree[x][0]+=v1;
        tree[x][0]%= mod[0];
        tree[x][1]+=v2;
        tree[x][1]%= mod[1];
        return ;
    }
    int mid=l+r>>1;
    if (s<=mid)
        update(x*2,l,mid,s,t,v1,v2);
    if (t>mid)
        update(x*2+1,mid+1,r,s,t,v1,v2);
}
int read(int x,int l,int r,int p,bool w) {
    if (p<0) return 0;
    if (l==r)
        return tree[x][w];
    int mid=l+r>>1;
    if (p>mid)
        return tree[x][w]+read(x*2+1,mid+1,r,p,w);
    else
        return tree[x][w]+read(x*2,l,mid,p,w);
}
int power(int x,int y,int mod) {
    long long ret=1;
    for (long long a=x%mod; y; y>>=1,a=a*a%mod)
        if (y&1)
            ret=ret*a%mod;
    return ret;
}
int getInv(int x,int mod) { //modÎªËØÊı
    return power(x,mod-2,mod);
}

set< pair<int ,int > > st;
char ts[2000010];
int main() {
    ten[0][0] = ten[0][1] = 1;
    for(int i = 1 ; i <=100000 ; i++) {
        ten[i][0] = ten[i-1][0]*pk[0];
        ten[i][1] = ten[i-1][1]*pk[1];
    }
    int T;
    scanf("%d",&T);
    for(int ii = 1; ii<=T; ii++) {
        printf("Case #%d:\n",ii);
        st.clear();
        int n ;
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++) {
            scanf("%s",ts);
            int len = strlen(ts);
            if(len > 100000) continue;
            int p0 = 0;
            int p1 = 0;
            for(int l = 0 ; l <len ; l++) {
                {
                    p0 = (p0+(long long)ts[l]*ten[l][0])%mod[0];
                    p1 = (p1+(long long)ts[l]*ten[l][1])%mod[1];
                    printf("i = %d p0 = %d p1 = %d\n",i,p0,p1);
                }
            }
            st.insert(make_pair(p0,p1));
        }
        scanf("%s",ts);
        int s_len = strlen(ts);
        for(int l = 0 ; l < s_len ; l++) {
            if(l == 0) {
                A[l][0] = (0+ (long long)ts[l]*ten[l][0])%mod[0];
                A[l][1] = (0+ (long long)ts[l]*ten[l][1])%mod[1];
            } else {
                A[l][0] = (A[l-1][0] + (long long)ts[l]*ten[l][0])%mod[0];
                A[l][1] = (A[l-1][1] + (long long)ts[l]*ten[l][1])%mod[1];
            }
            printf("%d %d\n",A[l][0] , A[l][1]);
        }
        build(1,0,s_len-1);
        int Qn;
        scanf("%d",&Qn);
        for(int i = 0 ; i < Qn; i++) {
            char cmd;
            scanf(" %c",&cmd);
            if(cmd == 'Q') {
                int l , r;
                scanf("%d%d",&l,&r);
                int ask_l0 = read(1,0,s_len-1,l-1,0);
                int ask_l1 = read(1,0,s_len-1,l-1,1);
                int ask_r0 = read(1,0,s_len-1,r,0);
                int ask_r1 = read(1,0,s_len-1,r,1);

                int val0 = ((long long)(ask_r0 - ask_l0+mod[0])%mod[0]
                            *getInv(l == 0 ? 1 :ten[l-1][0],mod[0]))%mod[0];
                int val1 = ((long long)(ask_r1 - ask_l1+mod[1])%mod[1]
                            *getInv(l == 0 ? 1 :ten[l-1][1],mod[1]))%mod[1];


                printf("ask_l0 = %d ask_r0 = %d %d %d" , ask_l0 ,ask_r0 , val0, val1);
                if(st.find(make_pair(val0,val1)) != st.end()) {
                    puts("Yes");
                } else puts("No");
            } else {
                int pos ;
                char nc;
                scanf("%d %c",&pos,&nc);
                update(1,0,s_len-1,pos,s_len-1,((long long)(nc-ts[pos]+mod[0])*ten[pos][0])%mod[0],
                       ((long long)(nc-ts[pos]+mod[1])*ten[pos][1])%mod[1]);
            }
        }
    }
    return 0;
}
