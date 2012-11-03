#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<stack>
#include<iostream>
#include<vector>
using namespace std;

char st[5000][50];
char as[5000][50];
bool map[4000][4000];
int bel[4000],state[4000],low[4000],id[4000],cnt,in[4000],t,cnt1,n;
stack <int> s;

void dfs(int u,int t,int &clr)
{
    low[u]=id[u]=t++;
    state[u]=1;
    s.push(u);
    for (int i=0;i<cnt;i++)
    {
        if (map[u][i] && state[i]==0)
        {
            dfs(i,t,clr);
            low[u]=min(low[i],low[u]);
        }
        else if (map[u][i] && state[i]==1)
            low[u]=min(low[i],low[u]);
    }
    if (low[u]==id[u])
    {
        int v;
        clr++;
        do
        {
            v=s.top();s.pop();
            state[v]=2;
            bel[v]=clr;
        }while (v!=u);
    }
}
int tarjan()
{
    memset(state,0,sizeof(state));
    memset(low,0,sizeof(low));
    memset(id,0,sizeof(id));
    memset(bel,0,sizeof(bel));
    t=1;cnt1=0;
    for (int i=0;i<cnt;i++)
        if (!state[i]) dfs(i,t,cnt1);
    return cnt1;
}
int main()
{
    while (scanf("%d",&n)>0,n!=0)
    {
        memset(map,0,sizeof(map));
        char tmp[1000];
        gets(tmp);
        cnt=0;
        bool flag;
        for (int i=1;i<=n;i++)
        {
            gets(tmp);
            int len=strlen(tmp);
            flag=false;
            int first=-1;
            for (int j=0;j<len;j++)
            {
                if (tmp[j]>='a' && tmp[j]<='z')
                {
                    char t1[100],po=0;
                    while (tmp[j]>='a' && tmp[j]<='z')
                    {
                        t1[po++]=tmp[j++];
                    }
                    t1[po]='\0';
                    int key=-1;
                    for (int k=0;k<cnt;k++)
                    {
                        if (strcmp(t1,st[k])==0)
                        {
                            key=k;break;
                        }
                    }
                    if (key==-1)
                    {
                        key=cnt;
                        strcpy(st[cnt++],t1);
                    }
                    if (!flag)
                    {
                        flag=true;first=key;
                    }
                    else map[first][key]=1;
                }
            }
        }
        //for (int j=0;j<cnt;j++) puts(st[j]);
        int cont=tarjan();
        memset(in,0,sizeof(in));
        for (int i=0;i<cnt;i++)
            for (int j=0;j<cnt;j++)
            {
                if (map[i][j] && bel[i]!=bel[j])
                    in[bel[i]]++;
            }
        int ans=0;
        for (int i=1;i<=cont;i++)

        for (int j=0;j<cnt;j++)
        {
            if (bel[j]==minp)
            {
                strcpy(as[ans],st[j]);
                ans++;
            }
        }
        printf("%d\n",ans);
        char ttt[1000];
        for (int i=0;i<ans-1;i++)
            for (int j=i+1;j<ans;j++)
                if (strcmp(as[i],as[j])>0)
                {
                    strcpy(ttt,as[i]);strcpy(as[i],as[j]);strcpy(as[j],ttt);
                }
        for (int i=0;i<ans;i++) printf("%s ",as[i]);
        puts("");
    }
}
