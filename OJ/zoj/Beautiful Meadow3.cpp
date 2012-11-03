//独立插头
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
    return ((sta>>(2*pos+2))<<(2*pos+2))|(val<<(2*pos))|(sta&((1<<(pos*2))-1));
}

int n,m,mp[9][9];
hash_map dp[2];
bool flag;
int key,val,upd,l,u,res;
int w[15],s[15],top;

void update(int a,int b,int val)
{
    dp[a][b] = max(dp[a][b],val);
}

int count3(int sta)
{
    int res = 0;
    for (int i = 0;i < m+1;i++)
        if (getbit(sta,i) == 3)
            res++;
    return res;
}

void expand(int sta)
{
    top = 0;
    for (int i = 0; i < m+1; i++)
        if (getbit(sta,i) == 1)
            s[top++] = i;
        else if (getbit(sta,i) == 2)
        {
            w[s[top-1]] = i;
            w[i] = s[top-1];
            top--;
        }
}

int main()
{
    int t;
    scanf("%d",&t);
    dp[0].init();
    dp[1].init();
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d%d",&n,&m);
        res = 0;
        memset(mp,0,sizeof(mp));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d",&mp[i][j]);
        dp[0].clear();
        dp[1].clear();
        flag = 0;
        dp[flag][0] = 0;
        int res = 0;
        for (int i = 0;i < n;i++)
        {
            dp[!flag].clear();
            for (int k = 0;k < dp[flag].N;k++)
                update(!flag,dp[flag].ele[k].key<<2,dp[flag].ele[k].val);
            flag = !flag;
            for (int j = 0;j < m;j++)
            {
                if (mp[i][j] == 0)  continue;
                res = max(res,mp[i][j]);
                dp[!flag].clear();
                for (int k = 0;k < dp[flag].N;k++)
                {
                    key = dp[flag].ele[k].key;
                    val = dp[flag].ele[k].val;
                    upd = setbit(setbit(key,j,0),j+1,0);
                    l = getbit(key,j);
                    u = getbit(key,j+1);
                    if (l == 0 && u == 0)
                    {
                        update(!flag,key,val);//不要
                        if (mp[i][j+1] > 0 && mp[i+1][j] > 0)//可以新建插头
                            update(!flag,setbit(setbit(key,j,1),j+1,2),val+mp[i][j]);
                        if (count3(key) < 2)//可以新建独立插头
                        {
                            if (mp[i][j+1] > 0)
                                update(!flag,setbit(setbit(key,j,0),j+1,3),val+mp[i][j]);
                            if (mp[i+1][j] > 0)
                                update(!flag,setbit(setbit(key,j,3),j+1,0),val+mp[i][j]);
                        }
                    }
                    else if (l == 0 || u == 0)
                    {
                        if (mp[i][j+1] > 0)//可以延续插头
                            update(!flag,setbit(upd,j+1,l+u),val+mp[i][j]);
                        if (mp[i+1][j] > 0)//可以延续插头
                            update(!flag,setbit(upd,j,l+u),val+mp[i][j]);
                        if (l+u < 3 && count3(key) < 2)//可以用一个独立插头来结束这条路径
                        {
                            expand(key);
                            if (l > 0)
                                update(!flag,setbit(upd,w[j],3),val+mp[i][j]);
                            else
                                update(!flag,setbit(upd,w[j+1],3),val+mp[i][j]);
                        }
                        else if (l+u == 3 && upd == 0)//路径的一端
                            res = max(res,val+mp[i][j]);
                    }
                    else if (l == u)
                    {
                        if (l < 3) //合并两个相同的括号
                        {
                            expand(key);
                            if (l == 1)
                                update(!flag,setbit(upd,w[j+1],1),val+mp[i][j]);
                            else
                                update(!flag,setbit(upd,w[j],2),val+mp[i][j]);
                        }
                        else if (upd == 0)//合并两个独立插头
                            res = max(res,val+mp[i][j]);
                    }
                    else if (l == 3 || u == 3)//合并独立插头与括号
                    {
                        expand(key);
                        if (l == 3)
                            update(!flag,setbit(upd,w[j+1],3),val+mp[i][j]);
                        else
                            update(!flag,setbit(upd,w[j],3),val+mp[i][j]);
                    }
                    else if (l == 2 || u == 1) //合并)(
                        update(!flag,upd,val+mp[i][j]);
                }
                flag = !flag;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
