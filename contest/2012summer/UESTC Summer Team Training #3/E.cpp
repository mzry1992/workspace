#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <cstdlib>
using namespace std;
const long long inf = 1ll<<60;
int n,m;
int head[505],e,S,T;
char ss[10050];
int next[10050];
int pre[505];
long long dist[505];
bool vis[505];
struct N
{
    char name[25];
    char stc[10005];
}boy[205],girl[205];
struct M
{
    int u,v,next;
    long long cap,val;
}edge[100005];
void addedge(int u,int v,long long c,long long l)
{
    edge[e].u=u;edge[e].v=v;edge[e].cap=c;
    edge[e].val=l;edge[e].next=head[u];head[u]=e++;

    edge[e].u=v;edge[e].v=u;edge[e].cap=0;
    edge[e].val=-l;edge[e].next=head[v];head[v]=e++;
}
bool SPFA()
{
    int i,j,k;
    queue<int> que;
    while(!que.empty()) que.pop();
    for(i=S;i<=T;i++) dist[i]=inf;
    memset(vis,false,sizeof(vis));
    memset(pre,-1,sizeof(pre));
    dist[S]=0;que.push(S);vis[S]=true;
    while(!que.empty())
    {
        i=que.front();que.pop();vis[i]=false;
        for(j=head[i];j!=-1;j=edge[j].next)
        {
            k=edge[j].v;
            if(edge[j].cap>0&&dist[i]+edge[j].val<dist[k])
            {
                dist[k]=dist[i]+edge[j].val;
                pre[k]=j;
                if(!vis[k])
				{vis[k]=true;que.push(k);}
            }
        }
    }
    if(pre[T]==-1) return false;
    return true;
}
void fee_maxflow()
{
    int i,j,k,l;
    long long ans=0,min;
    while(1)
    {
        if(!SPFA()) break;
        min=inf;i=T;
        while(pre[i]!=-1)
        {
            if(edge[pre[i]].cap<min)
                min=edge[pre[i]].cap;
            i=edge[pre[i]].u;
        }
        ans+=dist[T]*min;
        i=T;
        while(pre[i]!=-1)
        {
            j=pre[i];
            edge[j].cap-=min;
            edge[j^1].cap+=min;
            i=edge[pre[i]].u;
        }
    }
    printf("%lld\n",-ans);
}
long long KMP(char s[],char r[])
{
    int i,j,len2,len1;
    long long ti=0,pos=inf;
    len1=strlen(r);
    len2=strlen(s);
    i=0;
    next[1]=0;
    for(j=2; j<=len2; j++)
    {
        while(i>0&&s[i]!=s[j-1])
            i=next[i];
        if(s[i]==s[j-1])
            i++;
        next[j]=i;
    }
    j=0;
    for(i=1; i<=len1; i++)
    {
        while(j>0&&s[j]!=r[i-1])
            j=next[j];
        if(s[j]==r[i-1])
            j++;
        if(j==len2)
        {
            pos=min(pos,(long long)i-len2+1);
            ti++;
        }
    }
   // printf("%s %s %d %d\n",s,r,pos,ti);
    return ti*pos;
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        gets(ss);
        int i,j,k,len;
        for(i=1;i<=n;i++)
        {
            gets(ss);
            len=strlen(ss);
            for(j=0;j<len;j++)
                if(ss[j]!=':')
                    boy[i].name[j]=ss[j];
                else
                    break;
            boy[i].name[j]='\0';
            for(k=j+2;k<len;k++)
                boy[i].stc[k-j-2]=ss[k];
            boy[i].stc[k-j-2]='\0';
        }
        for(i=1;i<=m;i++)
        {
            gets(ss);
            len=strlen(ss);
            for(j=0;j<len;j++)
                if(ss[j]!=':')
                    girl[i].name[j]=ss[j];
                else
                    break;
            girl[i].name[j]='\0';
            for(k=j+2;k<len;k++)
                girl[i].stc[k-j-2]=ss[k];
            girl[i].stc[k-j-2]='\0';
        }
        memset(head,-1,sizeof(head));
        e=0;S=0;T=n+m+1;
        for(i=1;i<=n;i++)
        {
            addedge(S,i,1,0);
            for(j=1;j<=m;j++)
            {
                long long c=0;
                c+=KMP(boy[i].name,girl[j].stc);
                c+=KMP(girl[j].name,boy[i].stc);
                addedge(i,j+n,1,-c);
            }
        }
        for(j=1;j<=m;j++)
            addedge(j+n,T,1,0);
        fee_maxflow();
    }
    return 0;
}
