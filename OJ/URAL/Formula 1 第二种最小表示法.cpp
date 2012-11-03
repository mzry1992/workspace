#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct hash_map
{
    const static int mod=25943;
    int head[mod];
    struct hash_tables
    {
        long long key,val;
        int next;
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
        for (int i = 0; i < N; i++)
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
        ele[N].val=0;
        ele[N].next=head[tmp];
        head[tmp]=N++;
    }
    long long& operator [](long long x)
    {
        int tmp=fint(x);
        if (tmp==-1)
        {
            insert(x);
            return ele[N-1].val;
        }
        else
            return ele[tmp].val;
    }
};

inline int getbit(long long sta,int pos)
{
    return (sta>>(3*pos))&7;
}

inline long long setbit(long long sta,int pos,int val)
{
    return ((sta>>(3*pos+3))<<(3*pos+3))|((long long)val<<(3*pos))|(sta&((1LL<<(pos*3))-1));
}

hash_map dp[2];
int n,m;
char mp[15][15];
int lasx,lasy;
int fisx,fisy;
bool flag;
long long key,val,upd,res;
int l,u;
int used[15],oth[15];

void expand(long long sta)
{
    for (int i = 0;i < 8;i++)
        used[i] = -1;
    for (int i = 0;i < 15;i++)
        oth[i] = -1;
    for (int i = 0;i < m+1;i++)
    {
        int tmp = getbit(sta,i);
        if (tmp == 0)   continue;
        if (used[tmp] != -1)
        {
            oth[used[tmp]] = i;
            oth[i] = used[tmp];
        }
        else
            used[tmp] = i;
    }
}

long long encode()
{
    long long res = 0;
    int now = 0;
    for (int i = 0;i < m+1;i++)
    {
        if (oth[i] == -1)   continue;
        now++;
        res = setbit(res,i,now);
        res = setbit(res,oth[i],now);
        oth[i] = oth[oth[i]] = -1;
    }
    return res;
}

void updata(int a,long long b,long long c)
{
    dp[a][b] += c;
}

int main()
{
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
        flag = 0;
        dp[0].clear();
        dp[1].clear();
        res = 0;
        for (int i = 0; i < n; i++,flag = !flag)
        {
            for (int j = 0; j < m; j++,flag = !flag)
            {
                if (i == fisx && j == fisy)
                    dp[flag][0] = 1;
                dp[!flag].clear();
                for (int k = 0; k < dp[flag].N; k++)
                {
                    key = dp[flag].ele[k].key;
                    val = dp[flag].ele[k].val;
                    l = getbit(key,j);
                    u = getbit(key,j+1);
                    if (mp[i][j] == '*')
                    {
                        if (l == 0 && u == 0)
                            updata(!flag,key,val);
                    }
                    else
                    {
                        if (l == 0 && u == 0)
                        {
                            //新建插头
                            expand(key);
                            oth[j] = j+1;
                            oth[j+1] = j;
                            upd = encode();
                            updata(!flag,upd,val);
                        }
                        else if (l != 0 && u != 0)
                        {
                            //合并插头
                            if (l != u)
                            {
                                expand(key);
                                int pa,pb;
                                pa = oth[j];
                                pb = oth[j+1];
                                oth[pa] = pb;
                                oth[pb] = pa;
                                oth[j] = oth[j+1] = -1;
                                upd = encode();
                                updata(!flag,upd,val);
                            }
                            else if (i == lasx && j == lasy)
                                {
                                    upd = setbit(setbit(key,j,0),j+1,0);
                                    if (upd == 0)
                                        res += val;
                                }
                        }
                        else
                        {
                            //保持插头
                            upd = setbit(setbit(key,j,u),j+1,l);
                            updata(!flag,upd,val);
                            updata(!flag,key,val);
                        }
                    }
                }
            }
            if (i+1 == n)   break;
            dp[!flag].clear();
            for (int k = 0; k < dp[flag].N; k++)
            {
                key = dp[flag].ele[k].key;
                val = dp[flag].ele[k].val;
                l = getbit(key,m);
                if (l == 0 && key != 0)
                    updata(!flag,key<<3,val);
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}


