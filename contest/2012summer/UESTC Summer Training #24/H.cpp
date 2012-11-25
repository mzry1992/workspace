#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
int mp[505][505];
struct N
{
    int high;
    char sex[3];
    char music[105];
    char sport[105];
    N () {}
    N (int h,char a[],char b[],char c[])
    {
        high=h;
        strcpy(sex,a);
        strcpy(music,b);
        strcpy(sport,c);
    }
    void init()
    {
        high=0;
        memset(sex,0,sizeof(sex));
        memset(music,0,sizeof(music));
        memset(sport,0,sizeof(sport));
    }
} male[505],female[505];
int pre[505];
bool vis[505];
int k1,k2;
bool dfs(int s)
{
    int i;
    for(i=0; i<k2; i++)
    {
        if(mp[s][i]&&!vis[i])
        {
            vis[i]=true;
            if(pre[i]==-1||dfs(pre[i]))
            {
                pre[i]=s;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int i;
        for(i=0; i<n; i++)
        {
            male[i].init();
            female[i].init();
        }
        k1=k2=0;
        for(i=0; i<n; i++)
        {
            int a;
            char b[3],c[105],d[105];
            scanf("%d %s %s %s",&a,b,c,d);
            if(b[0]=='M')
                male[k1++]=N(a,b,c,d);
            else
                female[k2++]=N(a,b,c,d);
        }
        int j;
        for(i=0; i<k1; i++)
            for(j=0; j<k2; j++)
            {
                mp[i][j]=1;
                if(abs(male[i].high-female[j].high)>40)
                    mp[i][j]=0;
                if(strcmp(male[i].music,female[j].music)!=0)
                    mp[i][j]=0;
                if(strcmp(male[i].sport,female[j].sport)==0)
                    mp[i][j]=0;
            }
        int ret=0;
        memset(pre,-1,sizeof(pre));
        for(i=0; i<k1; i++)
        {
            memset(vis,false,sizeof(vis));
            if(dfs(i))
                ret++;
        }
        printf("%d\n",max(n-ret,max(k1,k2)));
    }
    return 0;
}
