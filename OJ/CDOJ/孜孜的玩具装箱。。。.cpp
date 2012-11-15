#include<string.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int a[55000],sum[55000],m;
long long dp[55000];
struct stack{
	int s,key;
}st[55000];
long long calc(long long x,long long y){
	return dp[x]+(y-x-1+sum[y]-sum[x]-m)*(y-x-1+sum[y]-sum[x]-m);
}
int main(){
    freopen("zizinihao.txt","r",stdin);
    freopen("out2.txt","w",stdout);
	int n,i,j,t,r,l,mid;
	while (scanf("%d%d",&n,&m)!=EOF){
	sum[0]=0;
	for (i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	j=1;
	st[1].s=1;
	st[1].key=0;
	st[2].s=n+1;
	t=2;
	dp[0]=0;
	//dp[1]=(a[1]-m)*(a[1]-m);
	for (i=1;i<=n;i++){
		if (st[j+1].s<=i) j++;
		dp[i]=calc(st[j].key,i);
		while (t>j && calc(st[t-1].key,st[t-1].s)>=calc(i,st[t-1].s)) t--;
		if (t==j) {
			t=j+1;
			st[j].s=i+1;
			st[j].key=i;
			st[j+1].s=n+1;
			continue;
		}
		if (calc(st[t-1].key,st[t].s-1)<calc(i,st[t].s-1))
        {
           st[t].key=i;
           if (st[t].s==n+1) continue;
           t++;
           st[t].s=n+1;
           continue;
        }

		l=st[t-1].s;
		r=n;
		while (l+1<r){
			mid=(l+r)/2;
			if (calc(st[t-1].key,mid)>calc(i,mid)) r=mid;
			else l=mid;
		}
		t--;
		st[t+1].s=l+1;
		st[t+1].key=i;
		st[t+2].s=n+1;
		t+=2;
	}
	printf("%I64d\n",dp[n]);
	}
}
