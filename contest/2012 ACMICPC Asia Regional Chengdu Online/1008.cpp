#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
const int inf=0x3f3f3f3f;
char s[4097],t[4][65];
int dp[4097][16][2];
bool ck[4097][4];
int l;
bool check(int pos,int x)
{
    if (pos+strlen(t[x])>l)
        return 0;
    for (int i = 0; t[x][i] != 0;i++)
        if (s[pos+i] != t[x][i])
            return false;
    return true;
}
set<int> st[4097][16];
int main()
{
    //while (gets(s))
    {
        for (int i = 0;i < 4096;i++)
            s[i] = 'a';
        s[4096] = 0;
        for (int i = 0;i < 4;i++)
        {
            for (int j = 0;j < 64;j++)
                t[i][j] = 'a';
            t[i][64] = 0;
        }
        //for (int i=0;i<4;i++)
        //    gets(t[i]);
        l=strlen(s);
        for (int i=0;i<4;i++)
            for (int j=0;j<l;j++)
            {
                ck[j][i] = check(j,i);
                if (ck[j][i])
                    st[j][1<<i].insert(strlen(t[i]));
            }
        st[l][0].insert(0);
        for (int i=1;i<16;i++)
            for (int j=0;j<l;j++)
            {
                //printf("%d %d\n",j,i);
                //printf("%d\n",st[j][i].size());
                for (int k=0;k<4;k++)
                    if ((i>>k&1)==0 && ck[j][k])
                    {
                        int len=strlen(t[k]);
                        for (int p=j;p<=j+len && p<=l;p++)
                            for (set<int> ::iterator it=st[p][i].begin();it!=st[p][i].end();it++)
                                st[j][i^(1<<k)].insert(max(*it+p-j,len));
                    }
            }
        puts("b");
        for (int i=0;i<=l;i++)
            for (int j=0;j<16;j++)
            {
                dp[i][j][0]=inf;
                dp[i][j][1]=-1;
            }
        dp[0][0][0]=dp[0][0][1]=0;
        for (int i=0;i<l;i++)
            for (int j=0;j<16;j++)
            {
                if (dp[i][j][0]!=inf)
                {
                    dp[i+1][j][0]=min(dp[i+1][j][0],dp[i][j][0]);
                    for (int k=1;k<16;k++)
                        if ((j&k)==0)
                            for (set<int> ::iterator it=st[i][k].begin();it!=st[i][k].end();it++)
                                dp[i+*it][j|k][0]=min(dp[i+*it][j|k][0],dp[i][j][0]+*it);
                }
                if (dp[i][j][1]!=-1)
                {
                    dp[i+1][j][1]=max(dp[i+1][j][1],dp[i][j][1]);
                    for (int k=1;k<16;k++)
                        if ((j&k)==0)
                            for (set<int> ::iterator it=st[i][k].begin();it!=st[i][k].end();it++)
                                dp[i+*it][j|k][1]=max(dp[i+*it][j|k][1],dp[i][j][1]+*it);
                }
            }
        printf("%d %d\n",dp[l][15][0],dp[l][15][1]);
    }
    return 0;
}
