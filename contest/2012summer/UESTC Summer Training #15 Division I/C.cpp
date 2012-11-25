#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;
const int mod=1234;
char com[100];
int n,m,cnt[4];
map<string,int> mp;
string tt;
bool calced[101][51][34];
int dp[101][51][35];
int fac[101];
int c[101][101];
int power(int x,int y)
{
    int ret=1;
    for (;y;y>>=1,x=x*x%mod)
        if (y&1)
            ret=ret*x%mod;
    return ret;
}
int calc(int len,int two,int three)
{
    if (calced[len][two][three])
        return dp[len][two][three];
    calced[len][two][three]=1;
    int &ret=dp[len][two][three]=0;
    if (len==n/m)
        return ret=1;
    for (int i=0;i<=two && i<=m;i++)
        for (int j=0;j<=three && j+i<=m;j++)
            if (n-m*len-two*2-three*3+i+j>=m)
            {
                ret+=calc(len+1,two-i+j,three-j)*power(2,i)%mod*power(3,j)%mod*c[i][two]%mod*c[j][three]%mod*fac[m]%mod*c[m-i-j][n-m*len-two*2-three*3]%mod;
                if (ret>=mod)
                    ret-=mod;
            }
    return ret;
}
int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int i=0;i<101;i++)
        c[i][i]=c[0][i]=1;
    for (int i=2;i<101;i++)
        for (int j=1;j<i;j++)
            c[j][i]=(c[j-1][i-1]+c[j][i-1])%mod;
    fac[0]=1;
    for (int i=1;i<101;i++)
        fac[i]=fac[i-1]*i%mod;
	for (int cas = 1;cas <= totcas;cas++)
	{
	    mp.clear();
	    memset(calced,0,sizeof(calced));
	    scanf("%d%d",&n,&m);
	    for (int i = 0;i < n;i++)
	    {
	        scanf("%s",com);
	        tt = "";
	        for (int j = 0;com[j] != 0;j++)
                if (com[j] == '-')
                {
                    for (int k = j+1;com[k] != 0;k++)
                        tt = tt+com[k];
                    break;
                }
            mp[tt]++;
	    }
	    memset(cnt,0,sizeof(cnt));
	    for (map<string,int>::iterator it = mp.begin();it != mp.end();it++)
            cnt[it->second]++;
        printf("Case %d: %d\n",cas,calc(0,cnt[2],cnt[3]));
	}
	return 0;
}
