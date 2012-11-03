#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

struct hash_map
{
    const static int mod=1000007;
    int head[mod];
    struct hash_tables
    {
        long long key;
        int next;
        long long dp;
    } ele[1000000];
    int N;
    int getHash(long long x)
    {
        return x%mod;
    }
    void init()
    {
        memset(head,255,sizeof(head));
        N=0;
    }
    void clear()
    {
        for (int i = 0;i < N;i++)
            head[getHash(ele[i].key)] = -1;
        N = 0;
    }
    int fint(long long x)
    {
        for (int i=head[getHash(x)]; i!=-1; i=ele[i].next)
            if (ele[i].key==x) return i;
        return -1;
    }
    void insert(long long x)
    {
        int tmp=getHash(x);
        ele[N].key=x;
        ele[N].dp=0;
        ele[N].next=head[tmp];
        head[tmp]=N++;
    }
    long long& operator [](long long x)
    {
        int tmp=fint(x);
        if (tmp==-1)
        {
            insert(x);
            return ele[N-1].dp;
        }
        else
            return ele[tmp].dp;
    }
    int begin()
    {
        return 0;
    }
    int end()
    {
        return N;
    }
};

int n,m;
char mp[15][15];
hash_map dp[2];
int it;
long long bit[15];
bool used[7];

inline int getbit(long long sta,int pos)
{
    return sta/bit[pos]%bit[1];
}

inline long long setbit(long long sta,int pos,int val)
{
    return sta/bit[pos+1]*bit[pos+1]+val*bit[pos]+sta%bit[pos];
}

void updata(int a,long long b,long long v)
{
    dp[a][b] += v;
}

int lasx,lasy;
int fisx,fisy;
int OGC[15];

int main()
{
    freopen("in.txt","r",stdin);
    bit[0] = 1;
    for (int i = 1; i < 15; i++)
        bit[i] = bit[i-1]*7;
    dp[0].init();
    dp[1].init();
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
                //cout << i << ' ' << j << ' ' << dp[flag].N << endl;
                if (i == fisx && j == fisy)
                {
                    dp[flag].clear();
                    dp[flag][0] = 1;
                }
                dp[!flag].clear();
                for (it = dp[flag].begin(); it < dp[flag].end(); it++)
                {
                    long long k = dp[flag].ele[it].key,upd;
                    long long val = dp[flag].ele[it].dp;
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
            for (it = dp[flag].begin(); it < dp[flag].end(); it++)
            {
                long long k = dp[flag].ele[it].key,upd;
                long long val = dp[flag].ele[it].dp;
                int l = getbit(k,m);
                if (k != 0 && l == 0)
                    updata(!flag,k*7,dp[flag][k]);
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
