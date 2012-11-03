#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int n,m;
char mp[15][15];
map<long long,long long> dp[2];
map<long long,long long>::iterator it;
long long bit[15];
bool used[7];
int OGC[15];

inline int getbit(long long sta,int pos)
{
    return sta/bit[pos]%bit[1];
}

inline long long setbit(long long sta,int pos,int val)
{
    return sta/bit[pos+1]*bit[pos+1]+val*bit[pos]+sta%bit[pos];
}

void output(int b)
{
    for (int i = 0; i < m+1; i++)
        printf("%d",getbit(b,i));
}

void updata(int a,long long b,long long v)
{
    /*cout <<  "updata : " << a << ' ';
    output(b);
    cout << ' ' << v << endl;*/
    dp[a][b] += v;
}

int lasx,lasy;
int fisx,fisy;

int main()
{
    bit[0] = 1;
    for (int i = 1; i < 15; i++)
        bit[i] = bit[i-1]*7;
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%s",mp[i]);
        lasx = lasy = fisx = fisy = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (mp[i][j] != '*')
                    lasx = i,lasy = j;
        for (int i = n-1; i >= 0; i--)
            for (int j = m-1; j >= 0; j--)
                if (mp[i][j] != '*')
                    fisx = i,fisy = j;
        long long res = 0;
        bool flag = 0;
        dp[0].clear();
        dp[1].clear();
        for (int i = 0; i < n; i++,flag = !flag)
        {
            for (int j = 0; j < m; j++,flag = !flag)
            {
                cout << i << ' ' << j << ' ' << dp[flag].size() << endl;
                if (i == fisx && j == fisy)
                    dp[flag][0] = 1;
                dp[!flag].clear();
                for (it = dp[flag].begin(); it != dp[flag].end(); it++)
                {
                    long long k = it->first,upd;
                    long long val = it->second;
                    int l = getbit(k,j);
                    int u = getbit(k,j+1);
                    /*cout << "now : " << i << ' ' << j << ' ' << flag << ' ' << k << ' ';
                    output(k);
                    cout << ' ' << val << ' ' << l << ' ' << u << endl;*/
                    if (mp[i][j] == '*')
                    {
                        if (l == 0 && u == 0)
                            updata(!flag,k,dp[flag][k]);
                    }
                    else
                    {
                        if (l == 0 && u == 0)
                        {
                            //鏂板缓鎻掑ご
                            int id = 0;
                            for (int q = 0; q < m+1; q++)
                                id = max(getbit(k,q),id);
                            id++;
                            upd = setbit(setbit(k,j,id),j+1,id);
                            int now = 0;
                            memset(OGC,0,sizeof(OGC));
                            for (int q = 0;q < m+1;q++)
                                if (getbit(upd,q) > 0)
                                {
                                    if (OGC[getbit(upd,q)] == 0)
                                        OGC[getbit(upd,q)] = ++now;
                                    upd = setbit(upd,q,OGC[getbit(upd,q)]);
                                }
                            updata(!flag,upd,dp[flag][k]);
                        }
                        else if (l != 0 && u != 0)
                        {
                            //鍚堝苟鎻掑ご
                            upd = setbit(setbit(k,j,0),j+1,0);
                            if (l == u)
                            {
                                if (i == lasx && j == lasy && upd == 0)
                                    res += dp[flag][k];
                            }
                            else
                            {
                                for (int q = 0; q < m+1; q++)
                                    if (getbit(upd,q) == u)
                                        upd = setbit(upd,q,l);
                                memset(used,false,sizeof(used));
                                for (int q = 0; q < m+1; q++)
                                    used[getbit(upd,q)] = true;
                                for (int q = 1; q < 7; q++)
                                    if (used[q] == false)
                                    {
                                        for (int p = 0; p < m+1; p++)
                                            if (getbit(upd,p) > q)
                                                upd = setbit(upd,p,getbit(upd,p)-1);
                                        break;
                                    }
                                updata(!flag,upd,dp[flag][k]);
                            }
                        }
                        else
                        {
                            //淇濇寔鎻掑ご
                            updata(!flag,k,dp[flag][k]);
                            upd = setbit(setbit(k,j,u),j+1,l);
                            updata(!flag,upd,dp[flag][k]);
                        }
                    }
                }
            }
            if (i+1 == n)   break;
            dp[!flag].clear();
            for (it = dp[flag].begin(); it != dp[flag].end(); it++)
            {
                long long k = it->first,upd;
                long long val = it->second;
                int l = getbit(k,m);
                if (k != 0 && l == 0)
                    updata(!flag,k*7,dp[flag][k]);
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
