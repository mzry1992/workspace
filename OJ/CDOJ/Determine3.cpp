#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int a[1200];
bool use[1200];
int dp[1200];
int pre[1200];
int ndp[1200];
int npre[1200];
int ppre[1200];
int bpre[1200];
int res[1200];
int tot;
int mpre[1200],mbac[1200];

int main()
{
    int t;
    freopen("din.txt","r",stdin);
    freopen("dout1.txt","w",stdout);
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        memset(ndp,0,sizeof(dp));
        memset(npre,0,sizeof(pre));
        memset(mpre,0,sizeof(mpre));
        memset(mbac,0,sizeof(mbac));
        a[0] = 0;
        ndp[0] = 0;
        npre[0] = 0;
        for (int i = 1;i <= n;i++)
        {
            int tmax = 0;
            int tpre = 0;
            for (int j = 0;j < i;j++)
            if (a[j] < a[i])
            if (ndp[j]+1 > tmax)
            {
                tmax = ndp[j]+1;
                tpre = j;
            }
            ndp[i] = tmax;
            npre[i] = tpre;
        }
        int tres = 0;
        int tmax = 0;
        for (int i = n;i >= 1;i--)
        if (ndp[i] >= tmax)
        {
            tres = i;
            tmax = ndp[i];
        }
        int ans = 0;
        for (int jj = 1;jj <= n;jj++)
        if (ndp[jj] == tmax)
        {
            tres = jj;
            cout << tres << endl;
            memset(use,false,sizeof(use));
            for (int cur = tres;cur > 0;cur = npre[cur])
                use[cur] = true;
            tot = 0;
            for (int i = 1;i <= n;i++)
            if (use[i] == true)
            {
                tot++;
                res[tot] = i;
                cout << a[i] << ' ';
            }
            cout << endl;
            dp[0] = 0;
            ppre[0] = 0;
            for (int i = 1;i <= n;i++)
            {
                int tmax = 0;
                int tpre = 0;
                for (int j = 0;j < i;j++)
                if (use[j] == false)
                if (a[j] < a[i])
                if (dp[j]+1 > tmax)
                {
                    tmax = dp[j]+1;
                    tpre = 0;
                }
                dp[i] = tmax;
                ppre[i] = tpre;
            }
            for (int i = 1;i <= n;i++)
            if (use[i] == false)
                mpre[i] = dp[i];
            dp[n+1] = 0;
            a[n+1] = 2000000000;
            bpre[n+1] = 0;
            for (int i = n;i >= 1;i--)
            {
                int tmax = 0;
                int tpre = 0;
                for (int j = n+1;j > i;j--)
                if (use[j] == false)
                if (a[j] > a[i])
                if (dp[j]+1 > tmax)
                {
                    tmax = dp[j]+1;
                    tpre = 0;
                }
                dp[i] = tmax;
                bpre[i] = tpre;
            }
            for (int i = 1;i <= n;i++)
            if (use[i] == false)
                mbac[i] = dp[i];
            for (int i = 1;i <= n;i++)
            if (use[i] == false)
            {
                if (mpre[i] > ans)  ans = mpre[i];
                if (mbac[i] > ans)  ans = mbac[i];
            }
            for (int i = 1;i <= tot-1;i++)
            {
                for (int j = res[i];j <= res[i+1];j++)
                if (a[j] > a[res[i]])
                for (int k = res[i];k <= res[i+1];k++)
                if (a[k] < a[res[i+1]])
                {
                    int len = mbac[j]+mpre[k];
                    int com = 0;
                    int sa,sb;
                    sa = j;
                    sb = k;
                    while (true)
                    {
                        if (sa == sb) com++;
                        sa = bpre[sa];
                        sb = ppre[sb];
                        if (sa > sb)    break;
                        if (sa == 0)    break;
                        if (sb == 0)    break;
                    }
                    if (ans < len-com)
                        ans = len-com;
                    //cout << i << ' ' << j << ' ' << k << ' ' << ans << endl;
                }
                /*int maxpre,maxbac;
                maxpre = maxbac = 0;
                for (int j = res[i];j <= res[i+1];j++)
                {
                    if (a[j] > a[res[i]])
                    if (maxbac < mbac[j])   maxbac = mbac[j];
                    if (a[j] < a[res[i+1]])
                    if (maxpre < mpre[j])   maxpre = mpre[j];
                }
                if (ans < maxpre+maxbac)
                    ans = maxpre+maxbac;*/
            }
        }
        for (int i = 1;i <= n;i++)
        if (use[i] == true) ans++;
        printf("Case #%d: %d\n",ft,ans);
    }
}
