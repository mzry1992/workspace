#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int a[25][25],op[110000][6],opt[110000];
int main(){
	int n,m,j,i,t,x,y;
	freopen("out.txt","r",stdin);
	while (scanf("%d%d",&n,&m)!=EOF){
		for (i=0;i<m;i++)
			for (j=0;j<n;j++)
				scanf("%d",&a[j][i]);
		scanf("%d",&t);
		for (i=1;i<=t;i++)
			for (j=1;j<=5;j++)
				scanf("%d",&op[i][j]);
		scanf("%d%d",&x,&y);
		for (i=n;i>0;i--){
			opt[i]=0;
			if (op[i][1]<=x && op[i][2]<=y && op[i][3]>=x && op[i][4]>=y){
				//cout<<'a'<<i<<endl;
				if (op[i][5]>=1 && op[i][5]<=3)
					opt[i]=1;
				else
					if (op[i][5]==4) x=op[i][1]+op[i][3]-x;
					else y=op[i][2]+op[i][4]-y;
			}
		}
		int ans=a[x][y];
		//cout<<'b'<<x<<" "<<y<<endl;
		for (i=1;i<=n;i++)
			if (opt[i]){
				if (op[i][5]==1) ans=-ans;
				if (op[i][5]==2) ans+=1;
				if (op[i][5]==3) ans-=1;
			}
		printf("%d\n",ans);
	}
}
