#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct recipes
{
    char a[2],b[2],c[2];
    int cost;
};

vector<recipes> rr[26];
recipes tmp;
int n,q;
char buf[110];
int len;

bool vis[110][110][26];
int dp[110][110][26];

int DP(int l,int r,char ch)
{
    if (vis[l][r][ch-'A'] == true)  return dp[l][r][ch-'A'];
    if (l == r)
    {
        if (buf[l]-'a' == ch-'A')   return 0;
        else    return -1;
    }
    int best = -1,dpl,dpr;
    for (int i = l;i < r;i++)
        for (int fr = 0;fr < rr[ch-'A'].size();fr++)
        {
            dpl = DP(l,i,rr[ch-'A'][fr].b[0]);
            dpr = DP(i+1,r,rr[ch-'A'][fr].c[0]);
            if (dpl == -1 || dpr == -1) continue;
            if (best == -1)
                best = dpl+dpr+rr[ch-'A'][fr].cost;
            else
                best = min(best,dpl+dpr+rr[ch-'A'][fr].cost);
        }
    vis[l][r][ch-'A'] = true;
    dp[l][r][ch-'A'] = best;
    return dp[l][r][ch-'A'];
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&q);
        for (int i = 0;i < 26;i++)
            rr[i].clear();
        for (int i = 0;i < n;i++)
        {
            scanf("%s%s%s%d",tmp.a,tmp.b,tmp.c,&tmp.cost);
            rr[tmp.a[0]-'A'].push_back(tmp);
        }
        printf("CASE #%d\n",ft);
        for (int i = 0;i < q;i++)
        {
            scanf("%d%s",&len,buf);
            memset(vis,false,sizeof(vis));
            int res = DP(0,len-1,'A');
            if (res == -1)
                printf("IMPOSSIBLE\n");
            else
                printf("POSSIBLE WITH %d DIAMONDS\n",res+len);
        }
    }
    return 0;
}
