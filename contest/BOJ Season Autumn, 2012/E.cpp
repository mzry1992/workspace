#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int mp[255][255];
int mic[255],mih[255];
bool vis[255][255];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    int i,j,k;
        memset(vis,false,sizeof(vis));
        for(i=0;i<n;i++)
        {
            mic[i]=n*n+1;
            mih[i]=n*n+1;
        }
        int now=n*n;
        while(now)
        {
            int p,l,mx=0;
            for(i=0;i<n;i++)
                if(mic[i]>mx)
                {
                    mx=mic[i];
                    p=i;
                }
            mx=0;
            for(i=0;i<n;i++)
                if(!vis[p][i] && mih[i]>mx)
                {
                    mx=mih[i];
                    l=i;
                }
            mp[p][l]=now--;
            mic[p]=mih[l]=now;
            vis[p][l]=true;
        }
        /*for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&mp[i][j]);
	    double mx=0;
	    for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                for(k=j+1;k<n;k++)
                    mx=max(mx,(double)min(mp[i][j],mp[i][k])/(double)max(mp[i][j],mp[i][k]));
        for(j=0;j<n;j++)
            for(i=0;i<n;i++)
                for(k=i+1;k<n;k++)
                    mx=max(mx,(double)min(mp[i][j],mp[k][j])/(double)max(mp[i][j],mp[k][j]));
        printf("%.4f\n",mx);*/
        bool first;
        for(i=0;i<n;i++)
        {
            first=true;
            for(j=0;j<n;j++)
            {
                if(!first)
                    printf(" ");
                first=false;
                printf("%d",mp[i][j]);
            }
            printf("\n");
        }
	}
    return 0;
}

