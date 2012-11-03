#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

char s[110],dp[110][110][2][110],ans[110],c[110];
char *change(char s[],int x){
	c=s;
	int i;
	for (i=0;i<=x;i++)
		c[i]=s[x-i];
	return c;
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out2.txt","w",stdout);
	int T,cas,n,m,i,j,k;
	scanf("%d",&T);
	for (cas=1;cas<=T;cas++){
		scanf("%d%d",&n,&m);
		//cout<<cas<<endl;
		scanf("%s",&s);
		for (i=0;i<n;i++)
			for (j=0;j<=m;j++)
                for (k=0;k<=105;k++)
				 dp[i][j][0][k]=dp[i][j][1][k]='Z';
		ans=s;
		for (i=0;i<n;i++){
			dp[i][0][0]=s;
			dp[i][0][1]=s;
		}
		for (j=1;j<=m;j++)
			dp[0][j][0]=dp[0][j][1]=s;
		for (i=1;i<n;i++)
			for (j=1;j<=m;j++){
				k=i-1;
				dp[i][j][0]=dp[i-1][j][0];if (dp[i][j][0]>dp[i-1][j-1][0]) dp[i][j][0]=dp[i-1][j-1][0];
				dp[i][j][1]=dp[i-1][j][1];if (change(dp[i][j][1],i)>change(dp[i-1][j-1][1],i)) dp[i][j][1]=dp[i-1][j-1][1];
				//for (k=0;k<i;k++){
					//cout<<k<<" "<<j<<' '<<change(dp[k][j-1][1],i)<<endl;
					if (dp[i][j][0]>change(dp[k][j-1][1],i)) {
						dp[i][j][0]=change(dp[k][j-1][1],i);
						if (ans>dp[i][j][0]) ans=dp[i][j][0];
					}
					if (change(dp[i][j][1],i)>dp[k][j-1][0])
					      dp[i][j][1]=change(dp[k][j-1][0],i);
				}
		cout<<"Case "<<cas<<": " <<ans<<endl;
	}
}
