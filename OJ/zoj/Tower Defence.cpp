//独立插头
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

struct hash_map
{
    const static int mod=10007;
    int head[mod];
    struct hash_tables
    {
        int key;
        int val;
        int next;
    } ele[10007];
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

int bit[12];

inline int getbit(long long sta,int pos)
{
    return sta/bit[pos]%bit[1];
}

inline long long setbit(long long sta,int pos,int val)
{
    return sta/bit[pos+1]*bit[pos+1]+val*bit[pos]+sta%bit[pos];
}

int n,m,mp[30][10];
char buf[30][10];
hash_map dp[2];
bool flag;
int key,val,upd,l,u,res,msk,cov,now,pr,resnow,resmsk,pru;
int w[15],s[15],top;
int pre[210][10007],preuse[210][10007];

void decode(int msk,int& key,int& cov)
{
    int tmp;
    key = cov = 0;
    for (int i = 0; i < m+1; i++)
    {
        tmp = getbit(msk,i);
        if (tmp > 0)
        {
            key = setbit(key,i,tmp-1);
            cov = setbit(cov,i,1);
        }
    }
}

int encode(int key,int cov)
{
    int res = 0,tmp;
    for (int i = 0; i < m+1; i++)
    {
        tmp = getbit(cov,i);
        if (tmp > 0)
        {
            tmp = getbit(key,i);
            res = setbit(res,i,tmp+1);
        }
    }
    return res;
}

void update(int a,int key,int cov,int val)
{
    int msk = encode(key,cov);
    int pos;
    if (dp[a][msk] < val)
    {
        dp[a][msk] = val;
        pos = dp[a].fint(msk);
        pre[now][pos] = pr;
        preuse[now][pos] = pru;
    }
}

int count3(int sta)
{
    int res = 0;
    for (int i = 0; i < m+1; i++)
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
    //freopen("TD.in","r",stdin);
    //freopen("TDM.out","w",stdout);
    bit[0] = 1;
    for (int i = 1; i < 12; i++)  bit[i] = bit[i-1]*5;
    int t;
    scanf("%d",&t);
    dp[0].init();
    dp[1].init();
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d%d",&n,&m);
        res = 0;
        memset(mp,0,sizeof(mp));
        memset(pre,0,sizeof(pre));
        memset(preuse,0,sizeof(preuse));
        for (int i = 0; i < n; i++)
        {
            scanf("%s",buf[i]);
            for (int j = 0; j < m; j++)
                if (buf[i][j] == '.')
                    mp[i][j] = 1;
                else if (buf[i][j] != 'B')
                    mp[i][j] = 2;
        }
        dp[0].clear();
        dp[1].clear();
        flag = 0;
        dp[flag][0] = 0;
        int res = 0;
        now = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dp[!flag].clear();
                for (int k = 0; k < dp[flag].N; k++)
                {
                    msk = dp[flag].ele[k].key;
                    pr = k;
                    val = dp[flag].ele[k].val;
                    decode(msk,key,cov);
                    l = getbit(key,j);
                    u = getbit(key,j+1);
                    if (mp[i][j] == 0)//是障碍
                    {
                        if (l == 0 && u == 0)
                        {
                            pru = 0;
                            update(!flag,key,setbit(setbit(cov,j,0),j+1,0),val);
                        }
                    }
                    else
                    {
                        if (mp[i][j] == 1 && l == 0 && u == 0)//不要插头
                        {
                            pru = 1;
                            update(!flag,key,setbit(setbit(cov,j,0),j+1,0),val);
                        }
                        if (getbit(cov,j) == 1 && l == 0)   continue;//不可以在这里搞插头
                        if (getbit(cov,j+1) == 1 && u == 0) continue;
                        cov = setbit(setbit(cov,j,1),j+1,1);//更新覆盖情况
                        upd = setbit(setbit(key,j,0),j+1,0);
                        pru = 2;
                        if (mp[i][j] == 2)
                        {
                            if (l == 0 && u == 0)
                            {
                                if (count3(key) < 2)//可以新建独立插头
                                {
                                    if (mp[i][j+1] != 0)
                                        update(!flag,setbit(setbit(key,j,0),j+1,3),cov,val+1);
                                    if (mp[i+1][j] != 0)
                                        update(!flag,setbit(setbit(key,j,3),j+1,0),cov,val+1);
                                }
                            }
                            else if (l == 0 || u == 0)
                            {
                                if (l+u < 3 && count3(key) < 2)//可以用一个独立插头来结束这条路径
                                {
                                    expand(key);
                                    if (l > 0)
                                        update(!flag,setbit(upd,w[j],3),cov,val+1);
                                    else
                                        update(!flag,setbit(upd,w[j+1],3),cov,val+1);
                                }
                                else if (l+u == 3 && upd == 0)//路径的一端
                                {
                                    if (res < val+1)
                                    {
                                        res = val+1;
                                        resnow = now-1;
                                        resmsk = k;
                                    }
                                }
                            }
                        }
                        else if (l == 0 && u == 0)
                        {
                            if (mp[i][j+1] != 0 && mp[i+1][j] != 0)//可以新建插头
                                update(!flag,setbit(setbit(key,j,1),j+1,2),cov,val+1);
                        }
                        else if (l == 0 || u == 0)
                        {
                            if (mp[i][j+1] != 0)//可以延续插头
                                update(!flag,setbit(upd,j+1,l+u),cov,val+1);
                            if (mp[i+1][j] != 0)//可以延续插头
                                update(!flag,setbit(upd,j,l+u),cov,val+1);
                        }
                        else if (l == u)
                        {
                            if (l < 3) //合并两个相同的括号
                            {
                                expand(key);
                                if (l == 1)
                                    update(!flag,setbit(upd,w[j+1],1),cov,val+1);
                                else
                                    update(!flag,setbit(upd,w[j],2),cov,val+1);
                            }
                            else if (upd == 0)//合并两个独立插头
                            {
                                if (res < val+1)
                                {
                                    res = val+1;
                                    resnow = now-1;
                                    resmsk = k;
                                }
                            }
                        }
                        else if (l == 3 || u == 3)//合并独立插头与括号
                        {
                            expand(key);
                            if (l == 3)
                                update(!flag,setbit(upd,w[j+1],3),cov,val+1);
                            else
                                update(!flag,setbit(upd,w[j],3),cov,val+1);
                        }
                        else if (l == 2 || u == 1) //合并)(
                            update(!flag,upd,cov,val+1);
                    }
                }
                flag = !flag;
                now++;
            }
            if (i+1 == n)   break;

            dp[!flag].clear();
            for (int k = 0; k < dp[flag].N; k++)
            {
                msk = dp[flag].ele[k].key;
                pr = k;
                val = dp[flag].ele[k].val;
                pru = 0;
                decode(msk,key,cov);
                update(!flag,key*bit[1],cov*bit[1],val);
            }
            now++;
            flag = !flag;
        }

        printf("Case %d: %d\n",ft,res);
        for (int i = resnow; i >= 0; i--)
        {
            if (preuse[i][resmsk] == 1)
                buf[i/(m+1)][i%(m+1)] = 'W';
            resmsk = pre[i][resmsk];
        }
        for (int i = 0; i < n; i++)
            printf("%s\n",buf[i]);
        printf("\n");
    }
    return 0;
}
