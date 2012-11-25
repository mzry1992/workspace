
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
char s[1005];
int R,Q;
bool vis[1005];
int rank[1005],pos[1005];
struct N
{
    int len;
    char num[1005];
    void init()
    {
        len=0;
        memset(num,0,sizeof(num));
    }
}dp[2][1005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    memset(s,0,sizeof(s));
	    scanf("%s%d%d",s,&R,&Q);
	    int len=strlen(s);
	    int i;
	    for(i=0;i<Q;i++)
	    {
            dp[0][i].init();
            rank[i]=-1;
            pos[i]=-1;
	    }
        rank[0]=0;
        pos[0]=0;
	    for(i=0;i<len;i++)
	    {
	        int j,now=i%2,ne=(i+1)%2;
            for(j=0;j<Q;j++)
            {
                dp[ne][i].len=dp[now][i].len;
                strcpy(dp[ne][i].num,dp[now][i].num);
            }
	        int nk=0;
	        memset(vis,false,sizeof(vis));
	        for(j=0;j<Q;j++)
                if(rank[j]!=-1)
                {
                    int nmod=(rank[j]*10+s[i]-'0')%Q;
                    if(vis[nmod])
                        continue;
                    if(pos[nmod]!=-1&&pos[nmod]<j)
                    {
                        if(dp[now][rank[j]].len+1>dp[ne][nmod].len)
                        {
                            strcpy(dp[ne][nmod].num,dp[now][rank[j]].num);
                            dp[ne][nmod].num[dp[now][rank[j]].len]=s[i];
                            dp[ne][nmod].len=dp[now][rank[j]].len+1;
                        }
                        else if(dp[now][rank[j]].len+1==dp[ne][nmod].len)
                        {
                            dp[now][rank[j]].num[dp[now][rank[j]].len]=s[i];
                            if(strcmp(dp[now][rank[j]].num,dp[ne][nmod].num)>0)
                                strcpy(dp[ne][nmod].num,dp[now][rank[j]].num);
                        }
                    }
                    else
                    {
                        if(dp[now][rank[j]].len!=0||s[i]!='0')
                        {
                            strcpy(dp[ne][nmod].num,dp[now][rank[j]].num);
                            dp[ne][nmod].num[dp[now][rank[j]].len]=s[i];
                            dp[ne][nmod].len=dp[now][rank[j]].len+1;
                        }
                    }
                    rank[nk]=nmod;
                    pos[nmod]=nk++;
                    vis[nmod]=true;
                }
	    }
	    if(dp[len%2][R].len==0)
            printf("Not found\n");
        else
            printf("%s\n",dp[len%2][R].num);
	}
	return 0;
}
