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

int n,m,mp[9][9];
hash_map dp[2];
bool flag;
int key,val,upd,l,u,res;
int fisx,fisy;
int w[15],s[15],top;

inline int getbit(int sta,int pos)
{
    return (sta>>(2*pos))&3;
}

inline int setbit(int sta,int pos,int val)
{
    return ((sta>>(2*pos+2))<<(2*pos+2))|(val<<(2*pos))|(sta&((1<<(pos*2))-1));
}

void output(int sta)
{
    for (int i = 0; i < m+1; i++)
        printf("%d",getbit(sta,i));
}

void update(int a,int b,int val)
{
    /*cout << "update : " << a << ' ' ;
    output(b);
    cout << ' ' << val << endl;*/
    dp[a][b] = max(dp[a][b],val);
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

int count3(int sta)
{
    int res = 0;
    for (int i = 0; i < m+1; i++)
        if (getbit(sta,i) == 3)
            res++;
    return res;
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
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                scanf("%d",&mp[i][j]);
                res = max(res,mp[i][j]);
            }
        fisx = fisy = 0;
        for (int i = n-1; i >= 0; i--)
            for (int j = m-1; j >= 0; j--)
                if (mp[i][j] != 0)
                    fisx = i,fisy = j;
        dp[0].clear();
        dp[1].clear();
        flag = 0;
        for (int i = 0; i < n; i++,flag = !flag)
        {
            for (int j = 0; j < m; j++,flag = !flag)
            {
                if (i == fisx && j == fisy)
                    dp[flag][0] = 0;
                dp[!flag].clear();
                for (int k = 0; k < dp[flag].N; k++)
                {
                    key = dp[flag].ele[k].key;
                    val = dp[flag].ele[k].val;
                    l = getbit(key,j);
                    u = getbit(key,j+1);
                    /*cout << "now = " << i << ' ' << j << ' ';
                    output(key);
                    cout << ' ' << val << ' ' << l << ' ' << u << endl;*/
                    if (l == 0 && u == 0)
                        update(!flag,key,val);
                    if (mp[i][j] > 0)
                    {
                        if (l == 0 && u == 0)
                        {
                            //新建普通插头
                            upd = setbit(setbit(key,j,1),j+1,2);
                            update(!flag,upd,val+mp[i][j]);
                            //新建独立插头
                            if (count3(key) < 2)
                            {
                                upd = setbit(setbit(key,j,0),j+1,3);
                                update(!flag,upd,val+mp[i][j]);
                                upd = setbit(setbit(key,j,3),j+1,0);
                                update(!flag,upd,val+mp[i][j]);
                            }
                        }
                        else if (l != 0 && u != 0)
                        {
                            //合并插头
                            upd = setbit(setbit(key,j,0),j+1,0);
                            if (l < 3 && u < 3)
                            {
                                if (l == u)
                                {
                                    expand(key);
                                    if (l == 1)
                                        upd = setbit(upd,w[j+1],1);
                                    else
                                        upd = setbit(upd,w[j],2);
                                    update(!flag,upd,val+mp[i][j]);
                                }
                                else if (l == 2)
                                    update(!flag,upd,val+mp[i][j]);
                            }
                            else
                            {
                                if (l == u)
                                {
                                    //合并两个独立插头
                                        if (upd == 0)
                                            res = max(res,val+mp[i][j]);
                                }
                                else
                                {
                                    if (l < 3)
                                        upd = setbit(upd,w[j],3);
                                    else
                                        upd = setbit(upd,w[j+1],3);
                                    update(!flag,upd,val+mp[i][j]);
                                }
                            }
                        }
                        else
                        {
                            //保持插头
                            upd = setbit(setbit(key,j,0),j+1,l+u);
                            update(!flag,upd,val+mp[i][j]);
                            upd = setbit(setbit(key,j+1,0),j,l+u);
                            update(!flag,upd,val+mp[i][j]);

                            upd = setbit(setbit(key,j,0),j+1,0);
                            if (l == 3 || u == 3)
                            {
                                //如果是独立插头而且在最后一个非障碍格子那么就可以作为路径的一端
                                    if (upd == 0)
                                        res = max(res,val+mp[i][j]);
                            }
                            else
                            {
                                //用独立插头封住，修改另外一端
                                if (count3(key) < 2)
                                {
                                    expand(key);
                                    if (l == 0)
                                        upd = setbit(upd,w[j+1],3);
                                    else
                                        upd = setbit(upd,w[j],3);
                                    update(!flag,upd,val+mp[i][j]);
                                }
                            }
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
                if (l != 0) continue;
                if (key == 0)   val = 0;
                /*cout << "next line = ";
                output(key);
                cout << ' ' << val << ' ' << l << endl;*/
                update(!flag,key<<2,val);
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
