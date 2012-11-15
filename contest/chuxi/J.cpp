#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct hash_map
{
    const static int mod=40007;
    int head[mod];
    struct hash_tables
    {
        int key;
        int val;
        int next;
    } ele[1000000];
    int N;
    int getHash(int x)
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
    int fint(int x)
    {
        for (int i=head[getHash(x)]; i!=-1; i=ele[i].next)
            if (ele[i].key==x) return i;
        return -1;
    }
    void insert(int x)
    {
        int tmp=getHash(x);
        ele[N].key=x;
        ele[N].val=0;
        ele[N].next=head[tmp];
        head[tmp]=N++;
    }
    int& operator [](int x)
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

inline int getbit(int sta,int pos)
{
    return (sta>>(2*pos))&3;
}

inline int setbit(int sta,int pos,int val)
{
    return
        ((sta>>(2*pos+2))<<(2*pos+2))|(val<<(2*pos))|(sta&((1<<(pos*2))-1));
}

int n,m,k;
int key,val,nkey,col,cnt,ncol,ncnt,lcol,lcnt,ucol,ucnt;
hash_map dp[2];
bool flag;
const int mod = 1000000007;

void updata(int a,int b,int val)
{
    dp[a][b] = (dp[a][b]+val)%mod;
}

int main()
{
    int ft = 0;
    dp[0].init();
    dp[1].init();
    flag = 0;
    while (true)
    {
        scanf("%d%d%d",&n,&m,&k);
        if (n == 0 && m == 0 && k == 0) break;
        dp[flag].clear();
        dp[flag][0] = 1;
        for (int i = 0; i < n; i++,flag = !flag)
        {
            for (int j = 0; j < m; j++,flag = !flag)
            {
                dp[!flag].clear();
                for (int x = 0; x < dp[flag].N; x++)
                {
                    key = dp[flag].ele[x].key;
                    val = dp[flag].ele[x].val;
                    col = key&16383;
                    cnt = key>>14;
                    lcol = getbit(col,j);
                    lcnt = getbit(cnt,j);
                    ucol = getbit(col,j+1);
                    ucnt = getbit(cnt,j+1);
                    for (int y = 0; y < k; y++)
                    {
                        if (y == lcol && lcnt == 2) continue;
                        if (y == ucol && ucnt == 2) continue;
                        ncol = setbit(setbit(col,j,y),j+1,y);
                        ncnt = setbit(setbit(cnt,j,1),j+1,1);
                        if (y == lcol)
                            ncnt = setbit(ncnt,j+1,lcnt+1);
                        if (y == ucol)
                            ncnt = setbit(ncnt,j,ucnt+1);
                        nkey = (ncnt<<14)+ncol;
                        updata(!flag,nkey,val);
                    }
                }
            }
            dp[!flag].clear();
            for (int x = 0; x < dp[flag].N; x++)
            {
                key = dp[flag].ele[x].key;
                val = dp[flag].ele[x].val;
                col = key&16383;
                cnt = key>>14;
                ncol = setbit(col,m,0)<<2;
                ncnt = setbit(cnt,m,0)<<2;
                nkey = (ncnt<<14)+ncol;
                updata(!flag,nkey,val);
            }
        }
        int res = 0;
        for (int i = 0; i < dp[flag].N; i++)
            res = (res+dp[flag].ele[i].val)%mod;
        printf("Case %d: %d\n",++ft,res);
    }
    return 0;
}
