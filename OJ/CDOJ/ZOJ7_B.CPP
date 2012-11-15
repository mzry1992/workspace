#include<cstdio>
#include<map>
#include<queue>
using namespace std;
map<int,int> mp[10000];
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=0;i<n;i++)
            mp[i].clear();
        for (int i=0;i<n-1;i++)
        {
            mp[i][i+1]=1;
            mp[i+1][i]=1;
        }
        mp[0][n-1]=1;
        mp[n-1][0]=1;
        for (int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            mp[--x][--y]=1;
            mp[y][x]=1;
        }
        queue<int> que;
        for (int i=0;i<n;i++)
            if (mp[i].size()==2)
                que.push(i);
        int ans=0;
        while (!que.empty())
        {
            int x=que.front();
            que.pop();
            if (mp[x].size()<2) continue;
            map<int,int> :: iterator i=mp[x].begin(),j=i++;
            bool flag=1;
            for (map<int,int> :: iterator it=mp[i->first].begin();flag && it!=mp[i->first].end();it++)
                if (it->first==j->first)
                    flag=0;
            if (flag)
            {
                mp[i->first][j->first]=i->second+j->second;
                mp[j->first][i->first]=i->second+j->second;
            }
            else
            {
                if (i->second+j->second+1>ans)
                    ans=i->second+j->second+1;
                if (mp[i->first].size()==3)
                    que.push(i->first);
                if (mp[j->first].size()==3)
                    que.push(j->first);
            }
            mp[i->first].erase(x);
            mp[j->first].erase(x);
        }
        printf("%d\n",ans);
    }
    return 0;
}
