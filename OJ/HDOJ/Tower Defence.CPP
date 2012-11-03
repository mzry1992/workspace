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

int n,m;
char mp[20][10];
bool flag;
hash_map dp[2];
int val;
int key,l,u,upd,res;
int bit[15],w[15],s[15],top;

inline int getbit(int sta,int pos)
{
    return sta/bit[pos]%bit[1];
}

inline int setbit(int sta,int pos,int val)
{
    return sta/bit[pos+1]*bit[pos+1]+val*bit[pos]+sta%bit[pos];
}

void output(int sta)
{
    for (int i = 0;i < m+1;i++)
        printf("%d",getbit(sta,i));
}

void update(int a,int b,int val)
{
    /*cout << "update : " << a << ' ' ;
    output(b);
    cout << ' ' << val << endl;*/
    if (dp[a][b] < val)
        dp[a][b] = val;
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
    bit[0] = 1;
    for (int i = 1; i < 15; i++)
        bit[i] = bit[i-1]*5;
    int t;
    scanf("%d",&t);
    dp[0].init();
    dp[1].init();
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0; i < n; i++)
            scanf("%s",mp[i]);
        flag = 0;
        dp[0].clear();
        dp[1].clear();
        dp[0][0] = 0;
        res = 0;
        for (int i = 0; i < n; i++,flag = !flag)
        {
            for (int j = 0; j < m; j++,flag = !flag)
            {
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
                    //0墙 1无插头 2( 3) 4独立
                    if (mp[i][j] == 'B')
                    {
                        // 0 | 1 | 1 | 0
                        //00 |10 |00 |10
                        if (l < 2 && u < 2)
                        {
                            upd = setbit(setbit(key,j,0),j+1,0);
                            update(!flag,upd,val);
                        }
                    }
                    else if (mp[i][j] == '.')
                    {
                        if (l < 2 && u < 2)
                        {
                            //可以在这里安置墙
                            upd = setbit(setbit(key,j,0),j+1,0);
                            update(!flag,upd,val);
                        }
                        if (l == 0 && u == 0)
                        {
                            //可以新建一个插头
                            upd = setbit(setbit(key,j,2),j+1,3);
                            update(!flag,upd,val+1);
                            continue;
                        }
                        if ((l > 1 && u == 0) || (u > 1 && l == 0))
                        {
                            //可以延续一个插头
                            upd = setbit(setbit(key,j,l+u),j+1,1);
                            update(!flag,upd,val+1);
                            upd = setbit(setbit(key,j,1),j+1,l+u);
                            update(!flag,upd,val+1);
                            continue;
                        }
                        if (l == 4 && u == 4)
                        {
                            //合并两个独立插头
                            upd = setbit(setbit(key,j,1),j+1,1);
                            update(!flag,upd,val+1);
                            continue;
                        }
                        if (l == u)
                        {
                            //合并两个同样的括号
                            expand(key);
                            upd = setbit(setbit(key,j,1),j+1,1);
                            if (l == 2)
                                upd = setbit(upd,w[u],2);
                            else
                                upd = setbit(upd,w[l],3);
                            update(!flag,upd,val+1);
                            continue;
                        }
                        if (l == 3 && u == 2)
                        {
                            //合并)(
                            upd = setbit(setbit(key,j,1),j+1,1);
                            update(!flag,upd,val+1);
                        }
                        if ((l == 4 && u > 1) || (u == 4 && l > 1))
                        {
                            //合并一个独立插头和一个一般插头
                            expand(key);
                            upd = setbit(setbit(key,j,1),j+1,1);
                            if (l == 4)
                                upd = setbit(upd,w[u],4);
                            else
                                upd = setbit(upd,w[l],4);
                            update(!flag,upd,val+1);
                            continue;
                        }
                    }
                    else
                    {
                        if (l == 0 && u == 0)
                        {
                            //新建一个独立插头
                            upd = setbit(setbit(key,j,4),j+1,1);
                            update(!flag,upd,val+1);
                            upd = setbit(setbit(key,j,1),j+1,4);
                            update(!flag,upd,val+1);
                            continue;
                        }
                        if ((l == 0 && u == 4) || (l == 4 && u == 0))
                        {
                            //合并两个独立插头
                            upd = setbit(setbit(key,j,1),j+1,1);
                            update(!flag,upd,val+1);
                            continue;
                        }
                        if ((l == 0 && u > 1) || (l > 1 && u == 0))
                        {
                            //合并独立插头与一个普通插头
                            expand(key);
                            upd = setbit(setbit(key,j,1),j+1,1);
                            if (l == 0)
                                upd = setbit(upd,w[u],4);
                            else
                                upd = setbit(upd,w[l],4);
                            update(!flag,upd,val+1);
                            continue;
                        }
                    }
                }
            }
            if (i+1 == n)   continue;
            dp[!flag].clear();
            /*cout << endl;
            cout << "Update nextline : " << i << endl;*/
            for (int k = 0; k < dp[flag].N; k++)
            {
                key = dp[flag].ele[k].key;
                val = dp[flag].ele[k].val;
                l = getbit(key,m);
                /*cout << "next line = ";
                output(key);
                cout << ' ' << val << ' ' << l << endl;*/
                if (l > 1)  continue;
                if (key == 0)   continue;
                upd = setbit(key,m,0)*5;
                update(!flag,upd,val);
            }
            /*cout << endl;*/
        }
        printf("%d\n",res);
    }
    return 0;
}
