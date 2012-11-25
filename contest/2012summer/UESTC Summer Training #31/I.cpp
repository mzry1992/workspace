#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int n,m;
char mp[1005][1005];
bool vis[1005*1005];
int tim[1005*1005];
int dir[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
class cmp
{
    public:
        bool operator()(const int a,const int b) const
            {
                return tim[a]<tim[b];
            }
};
priority_queue<int,vector<int>,cmp> q;
int main()
{
	while(scanf("%d%d",&n,&m)==2)
    {
        int i,j,k;
        for(i=0;i<n;i++)
            scanf("%s",mp[i]);
        memset(vis,false,sizeof(vis));
        memset(tim,0,sizeof(tim));
        int ans=0;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(mp[i][j]=='X')
                {
                    ans++;
                    vis[i*m+j]=true;
                    int dx,dy;
                    for(k=0;k<4;k++)
                    {
                        dx=i+dir[k][0];
                        dy=j+dir[k][1];
                        if(dx>=0&&dx<n&&dy>=0&&dy<m&&mp[dx][dy]=='.')
                            tim[dx*m+dy]++;
                    }
                }
        while(!q.empty())
            q.pop();
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(mp[i][j]=='.'&&tim[i*m+j]>=2)
                    q.push(i*m+j);
        while(!q.empty())
        {
            int now=q.top();
            q.pop();
            if(vis[now])
                continue;
            ans++;
            vis[now]=true;
            int dx,dy;
            for(i=0;i<4;i++)
            {
                dx=now/m+dir[i][0];
                dy=now%m+dir[i][1];
                if(dx>=0&&dx<n&&dy>=0&&dy<m&&mp[dx][dy]=='.')
                {
                    tim[dx*m+dy]++;
                    if(tim[dx*m+dy]>=2)
                        q.push(dx*m+dy);
                }
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}
