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
        long long key;
        int val;
        int next;
    } ele[100000];
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
    int& operator [](long long x)
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

long long bit[12];

inline int getbit(long long sta,int pos)
{
    return sta/bit[pos]%bit[1];
}

inline long long setbit(long long sta,int pos,int val)
{
    return sta/bit[pos+1]*bit[pos+1]+val*bit[pos]+sta%bit[pos];
}

inline int getbit2(int sta,int pos)
{
    return (sta>>pos)&1;
}

inline int setbit2(int sta,int pos,int val)
{
    if (val == 0)
        return sta&~(1<<pos);
    else
        return sta|(1<<pos);
}

int spos;
char mp[9][7];
hash_map dp[2];
bool flag;
long long msk,key,epkey,upkey;
int fired,epfired,upfired;
int l,u,lf,uf,uid;
int wkey[10],wfired[10],maxid;
int ukey[10],ufired[10];
int newid[12];

void expand(long long key,int fired)
{
    for (int i = 0; i < 10; i++)
    {
        wkey[i] = getbit(key,i);
        wfired[i] = getbit2(fired,i);
    }
}

void rebuild(long long& key,int& fired)
{
    memset(newid,0,sizeof(newid));
    maxid = 1;
    for (int i = 0; i < 10; i++)
        if (ukey[i] > 0 && newid[ukey[i]] == 0)
            newid[ukey[i]] = maxid++;
    key = 0;
    fired = 0;
    for (int i = 0; i < 10; i++)
    {
        key = setbit(key,i,newid[ukey[i]]);
        fired = setbit2(fired,i,ufired[i]);
    }
}

void output(int key)
{
    for (int i = 0; i < 10; i++)
        printf("%d",getbit2(key,i));
}

void output2(long long key)
{
    for (int i = 0; i < 10; i++)
        printf("%d",getbit(key,i));
}

//#define debug

bool check(long long key)
{
    int curmax = 0;
    for (int i = 0;i < 10;i++)
        if (getbit(key,i)-1 > curmax)
            return false;
        else curmax = max(curmax,getbit(key,i));
    return true;
}

void update(int a,long long key,int fired)
{
#ifdef debug
    printf("update: ");
    output2(key);
    printf(" ");
    output(fired);
    printf("\n");
#endif
    for (int i = 0;i < 10;i++)
    {
        ukey[i] = getbit(key,i);
        ufired[i] = getbit2(fired,i);
    }
    rebuild(key,fired);
    if ((fired&dp[a][key]) == dp[a][key])
        dp[a][key] = fired;
}

int tmp[10];
int count(long long key)
{
    memset(tmp,0,sizeof(tmp));
    for (int i = 0; i < 10; i++)
        tmp[getbit(key,i)]++;
    for (int i = 1; i < 10; i++)
        if (tmp[i] == 3)    return 3;
}
/*
int count(int fired)
{
    int res = 0;
    for (int i = 0;i < 10;i++)
        if (getbit2(upfired,i) == 1)
            res++;
    return res;
}*/

int main()
{
    bit[0] = 1;
    for (int i = 1; i < 12; i++)
        bit[i] = bit[i-1]*10;
    dp[0].init();
    dp[1].init();
    while (scanf("%d",&spos) != EOF)
    {
        for (int i = 0; i < 9; i++)
            scanf("%s",mp[i]);
        dp[0].clear();
        dp[1].clear();
        flag = 0;
        dp[0][setbit(0,spos,1)] = setbit2(0,spos,1);
        for (int i = 0; i < 6; i++,flag = !flag)
        {
            for (int j = 0; j < 9; j++,flag = !flag)
            {
                cout << i << ' ' << j << ' ' << dp[flag].N << endl;
                dp[!flag].clear();
                for (int k = 0; k < dp[flag].N; k++)
                {
                    key = dp[flag].ele[k].key;
                    fired = dp[flag].ele[k].val;
                    if (key == 0)   continue;
                    if (fired == 0) continue;
                    epkey = setbit(setbit(key,j,0),j+1,0);
                    epfired = setbit2(setbit2(fired,j,0),j+1,0);
                    l = getbit(key,j);
                    u = getbit(key,j+1);
                    lf = getbit2(fired,j);
                    uf = getbit2(fired,j+1);
#ifdef debug
                    printf("now : %d %d ",i,j);
                    output2(key);
                    printf(" ");
                    output(fired);
                    printf(" %d %d %d %d\n",l,u,lf,uf);
#endif
                    if (mp[j][i] == '.') //空格子
                    {
                        //接下来只能是空了
                        update(!flag,epkey,epfired);
                        continue;
                    }
                    if (mp[j][i] == '-') //一字
                    {
                        //延伸l或者u
                        if (l > 0)
                            update(!flag,setbit(epkey,j+1,l),setbit2(epfired,j+1,lf));
                        if (u > 0)
                            update(!flag,setbit(epkey,j,u),setbit2(epfired,j,uf));
                        if (l == 0 || u == 0)
                            update(!flag,epkey,epfired);
                        continue;
                    }
                    expand(key,fired);
                    if (mp[j][i] == 'L')
                    {
                        //延伸l到j或者u到j+1
                        if (l > 0)
                            update(!flag,setbit(epkey,j,l),setbit2(epfired,j,lf));
                        if (u > 0)
                            update(!flag,setbit(epkey,j+1,u),setbit2(epfired,j+1,uf));
                        if (l == 0 || u == 0)
                            update(!flag,epkey,epfired);
                        if (l > 0 && u > 0) //连接l和u
                        {
                            for (int q = 0; q < 10; q++)
                            {
                                ukey[q] = wkey[q];
                                if (wkey[q] == u)
                                    ukey[q] = l;
                                ufired[q] = wfired[q];
                            }
                            ukey[j] = ukey[j+1] = 0;
                            ufired[j] = ufired[j+1] = 0;
                            for (int q = 0; q < 10; q++)
                                if (ukey[q] == l)
                                    ufired[q] = lf|uf;
                            rebuild(upkey,upfired);
                            update(!flag,upkey,upfired);
                        }
                        //新建一个连通分量
                        for (int q = 0; q < 10; q++)
                        {
                            ukey[q] = wkey[q];
                            ufired[q] = wfired[q];
                        }
                        ukey[j] = ukey[j+1] = 10;
                        ufired[j] = ufired[j+1] = 0;
                        rebuild(upkey,upfired);/*
                            if (count(upkey) == 3)
                            {
                                cout << j << ' ';
                                output(fired);
                                cout << ' ';
                                output2(key);
                                cout << "-->";
                                output(upfired);
                                cout << ' ' ;
                                output2(upkey);
                                cout << endl;
                            }*/
                        update(!flag,upkey,upfired);
                        continue;
                    }
                    if (mp[j][i] == 'T')
                    {
                        //新建插头
                        if (l == 0 || u == 0)
                        {
                            for (int q = 0; q < 10; q++)
                            {
                                ukey[q] = wkey[q];
                                ufired[q] = wfired[q];
                            }
                            ukey[j] = ukey[j+1] = 10;
                            ufired[j] = ufired[j+1] = 0;
                            rebuild(upkey,upfired);
                            update(!flag,upkey,upfired);
                        }
                        //延伸l或u到j和j+1
                        if (l > 0)
                            update(!flag,setbit(setbit(epkey,j,l),j+1,l),setbit2(setbit2(epfired,j,lf),j+1,lf));
                        if (u > 0)
                            update(!flag,setbit(setbit(epkey,j,u),j+1,u),setbit2(setbit2(epfired,j,uf),j+1,uf));
                        if (l == 0 || u == 0)
                            update(!flag,epkey,epfired);
                        //连接l和u，延伸到j或者j+1上
                        if (l > 0 && u > 0)
                        {
                            for (int q = 0; q < 10; q++)
                            {
                                if (wkey[q] == u)
                                    ukey[q] = l;
                                else
                                    ukey[q] = wkey[q];
                                ufired[q] = wfired[q];
                            }
                            ukey[j] = l;
                            ukey[j+1] = 0;
                            ufired[j] = ufired[j+1] = 0;
                            for (int q = 0; q < 10; q++)
                                if (ukey[q] == l)
                                    ufired[q] = lf|uf;
                            rebuild(upkey,upfired);
                            update(!flag,upkey,upfired);

                            for (int q = 0; q < 10; q++)
                            {
                                if (wkey[q] == u)
                                    ukey[q] = l;
                                else
                                    ukey[q] = wkey[q];
                                ufired[q] = wfired[q];
                            }
                            ukey[j] = 0;
                            ukey[j+1] = l;
                            ufired[j] = ufired[j+1] = 0;
                            for (int q = 0; q < 10; q++)
                                if (ukey[q] == l)
                                    ufired[q] = lf|uf;
                            rebuild(upkey,upfired);
                            update(!flag,upkey,upfired);
                        }
                        continue;
                    }
                    if (mp[j][i] == '+') //十字
                    {
                        //新建插头
                        if (l == 0 && u == 0)
                        {
                            for (int q = 0; q < 10; q++)
                            {
                                ukey[q] = wkey[q];
                                ufired[q] = wfired[q];
                            }
                            ukey[j] = ukey[j+1] = 10;
                            ufired[j] = ufired[j+1] = 0;
                            rebuild(upkey,upfired);
                            update(!flag,upkey,upfired);
                        }
                        if (l == 0 && u == 0)
                            update(!flag,epkey,epfired);
                        //延伸l或u到j和j+1
                        if (l > 0 && u == 0)
                            update(!flag,setbit(setbit(epkey,j,l),j+1,l),setbit2(setbit2(epfired,j,lf),j+1,lf));
                        if (u > 0 && l == 0)
                            update(!flag,setbit(setbit(epkey,j,u),j+1,u),setbit2(setbit2(epfired,j,uf),j+1,uf));
                        //连接l和u，延伸到j和j+1上
                        if (l > 0 && u > 0)
                        {
                            for (int q = 0; q < 10; q++)
                            {
                                if (wkey[q] == u)
                                    ukey[q] = l;
                                else
                                    ukey[q] = wkey[q];
                                ufired[q] = wfired[q];
                            }
                            ukey[j] = ukey[j+1] = l;
                            ufired[j] = ufired[j+1] = 0;
                            for (int q = 0; q < 10; q++)
                                if (ukey[q] == l)
                                    ufired[q] = lf|uf;
                            rebuild(upkey,upfired);
                            update(!flag,upkey,upfired);
                        }
                        continue;
                    }
                }
            }
            dp[!flag].clear();
            for (int k = 0; k < dp[flag].N; k++)
            {
                key = dp[flag].ele[k].key;
                fired = dp[flag].ele[k].val;
                upkey = setbit(key,9,0)*bit[1];
                upfired = setbit2(fired,9,0)<<1;
                if (upfired == 0)   continue;
                if (upkey == 0) continue;
#ifdef debug
                printf("nextline : ");
                output2(key);
                printf(" ");
                output(fired);
                printf("\n");
#endif
                update(!flag,upkey,upfired);
            }
        }
        int res = 0,tres;
        for (int k = 0; k < dp[flag].N; k++)
        {
            key = dp[flag].ele[k].key;
            fired = dp[flag].ele[k].val;
#ifdef debug
            output2(key);
            cout << ' ';
            output(fired);
            cout << endl;
#endif
            tres = 0;
            for (int i = 0; i < 10; i++)
                if (getbit2(fired,i) == 1)
                    tres++;
            /*if (tres == 2)
            {
                output(fired);
                cout << ' ';
                output2(key);
                cout << endl;
            }*/
            res = max(res,tres);
        }
        printf("%d\n",res);
    }
    return 0;
}

