#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;
int n,m;
int a[3300];
short dp[3300][3300],pre[3300][3300];

struct Hash {
static const int mask = 0x7fff;
int p[32768], q[32768];

void clear() {
for (int i = 0; i <= mask; ++i) {
q[i] = -1;
}
}

int& operator[](int k) {
int i = k & mask;
for (int j = 0; q[i] != -1 && p[i] != k; i = (i + 1) & mask) {
continue;
}
p[i] = k;
return q[i];
}
} hash;
void print(int x,int y)
{
     //cout<<x<<" "<<y<<endl;
     //cout<<pre[x][y]<<" "<<a[x]-c[y]<<endl;
     if (dp[x][y]>2) print(pre[x][y],hash[a[x]-a[y]]);
     else
         printf("%d ",a[pre[x][y]]);
     printf("%d ",a[x]);
}
int main()
{
    int x,y;
    freopen("我没有下限.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    while (scanf("%d",&n)>0)
    {
          hash.clear();
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            hash[a[i]]=i;
        }
        if (n==1) {printf("%d\n",a[1]);continue;}
        memset(dp,0,sizeof(dp));
        //dp[1][find(a[1])]=1;
        for (int i=2;i<=n;i++)
            for (int j=1;j<i;j++){
                dp[i][hash[a[j]]]=2;
                pre[i][hash[a[j]]]=j;
                }
        for (int i=3;i<=n;i++)
            for (int j=2;j<i;j++)
            {   //
                x=hash[a[i]-a[j]];
                //cout<<i<<" "<<j<<" "<<dp[j][x]<<endl;
                y=hash[a[j]];
                if (x==-1) continue;//cout<<i<<" "<<j<<" "<<dp[j][x]<<endl;
                if (dp[i][y]<dp[j][x]+1){
                   dp[i][y]=dp[j][x]+1;
                   pre[i][y]=j;
                   }
            }
        int ans=0;
        for (int i=1;i<=n;i++)
        for (int j=1;j<=i;j++)
            if (ans<dp[i][hash[a[j]]]) {
                              ans=dp[i][hash[a[j]]];
                              x=i;
                              y=hash[a[j]];
                              }
        cout<<ans<<endl;
        print(x,y);
        cout<<endl<<endl;
    }
}
