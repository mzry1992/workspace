#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct trees
{
    int to,next;
}tree[110000];
int head[110000];
int l=0;
int dp[110000][2];
void add_edge(int x,int y)
{
    l++;
    tree[l].to=y;
    tree[l].next=head[x];
    head[x]=l;
    l++;
    tree[l].to=x;
    tree[l].next=head[y];
    head[y]=l;
}
void dfs(int x,int y)
{
    //cout<<x<<" "<<y<<endl;
    //getchar();
    int i,flag=false,tmp=0,j=0,max1=0,max2=0;
    for (i=head[x];i!=-1;i=tree[i].next)
    {
        if (tree[i].to==y) continue;
        j++;
        flag=true;
        dfs(tree[i].to,x);
    }
    if (!flag) dp[x][0]=dp[x][1]=0;
    else
    {
        for (i=head[x];i!=-1;i=tree[i].next)
        {
            if (tree[i].to==y) continue;
            tmp+=dp[tree[i].to][0];
            if (dp[tree[i].to][1]-dp[tree[i].to][0]>max1)
            {
                max2=max1;
                max1=dp[tree[i].to][1]-dp[tree[i].to][0];
            }
            if (dp[tree[i].to][1]-dp[tree[i].to][0]>max2)
            {
                max2=dp[tree[i].to][1]-dp[tree[i].to][0];
            }
        }
        if (j==1)
        {
            dp[x][1]=tmp-max1;
            dp[x][0]=tmp-max2;
        }
        dp[x][0]=tmp+j-1;
        //cout<<dp[x][0]<<endl;
        dp[x][1]=dp[x][0]+1;
        dp[x][1]-=max1;
        dp[x][0]-=max1+max2;
        cout<<x<<" "<<dp[x][0]<<" "<<dp[x][1]<<" "<<tmp<<endl;
    }
    return ;
}
int main()
{
    int n,i,x,y;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        head[i]=-1;
    for (i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        add_edge(x,y);
    }
    dfs(1,0);
    cout<<dp[n][0]<<endl;
}
