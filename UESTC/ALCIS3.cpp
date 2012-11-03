#include<cstdio>
#include<algorithm>
using namespace std;
int f[100005],t,n,m,mt=1,i,p,q,z,ans,tans;
char s[10];
int main()
{
	freopen("ain.txt","r",stdin);
	freopen("aout.txt","w",stdout);
	scanf("%d",&t);
	while(mt<=t)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&f[i]);
		}
		printf("Case #%d:\n",mt++);
		while(m--)
		{
			scanf("%s",s);
			if (s[0]=='q')
			{
				scanf("%d%d",&p,&q);
				tans=ans=1;
				for(i=p+1;i<=q;i++)
				{
					if (f[i]>f[i-1]) tans++;
					else
					{
						ans=max(ans,tans);
						tans=1;
					}
				}
				ans=max(tans,ans);
				printf("%d\n",ans);
			}
			if (s[0]=='a')
			{
				scanf("%d%d%d",&p,&q,&z);
				for(i=p;i<=q;i++)
				{
					f[i]+=z;
				}
			}
		}
	}
}
