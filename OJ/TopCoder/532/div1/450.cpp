#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

class DengklekBuildingRoads
{
public:
    int numWays(int, int, int);
};

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

int n,m,k;
bool flag;
int key,val,sta,cnt,nsta,ncnt,nval,mcnt;
hash_map dp[2];
int f[9][16];

bool check(int i,int sta)
{
    for (int j = 0; j < (k-i); j++)
        if (((sta>>j)&1) == 1)
            return false;
    return true;
}

const int mod = 1000000007;

void output(int sta)
{
    for (int i = 0; i < k; i++)
        cout << ((sta>>i)&1);
    cout << ' ';
}

void updata(int flag,int sta,int mcnt,int cnt,int val)
{
    if (((sta>>0)&1) == 1)  return;
    sta >>= 1;
    mcnt %= 2;
    sta |= mcnt<<(k-1);
    sta <<= 5;
    sta += cnt;
    dp[flag][sta] = (dp[flag][sta]+val)%mod;
}

int DengklekBuildingRoads::numWays(int N, int M, int K)
{
    memset(f,0,sizeof(f));
    f[0][0] = 1;
    for (int i = 1; i <= 8; i++)
        for (int j = 0; j <= 15; j++)
            for (int q = 0; q <= j; q++)
                f[i][j] = (f[i][j]+f[i-1][q])%mod;
    dp[0].init();
    dp[1].init();
    flag = 0;
    dp[flag][0] = 1;
    n = N;
    m = M;
    k = K;
    for (int i = 1; i < n; i++,flag = !flag)
    {
        dp[!flag].clear();
        for (int x = 0; x < dp[flag].N; x++)
        {
            key = dp[flag].ele[x].key;
            val = dp[flag].ele[x].val;
            cnt = key&31;
            sta = key>>5;
            for (int y = 0; y < (1<<k); y++)
                if (check(i,y) == true)
                {
                    nsta = sta^y;
                    mcnt = 0;
                    for (int j = 0; j < k; j++)
                        if (((y>>j)&1) == 1)
                            mcnt++;
                    ncnt = cnt+mcnt;
                    if (ncnt > m)   continue;
                    for (int z = 0; ncnt+2*z <= m; z++)
                    {
                        nval = ((long long)val*(long long)f[k][z])%mod;
                        updata(!flag,nsta,mcnt,ncnt+2*z,nval);
                    }
                }
        }
    }
    int res = 0;
    for (int i = 0; i < dp[flag].N; i++)
    {
        key = dp[flag].ele[i].key;
        val = dp[flag].ele[i].val;
        cnt = key&31;
        sta = key>>5;
        bool check = true;
        if (cnt != m)   check = false;
        for (int j = 0; j < k; j++)
            if (((sta>>j)&1) == 1)
                check = false;
        if (check == true)
            res = (res+val)%mod;
    }
    return res;
}

//Powered by [KawigiEdit] 2.0!
double test0()
{
    int p0 = 3;
    int p1 = 4;
    int p2 = 1;
    DengklekBuildingRoads * obj = new DengklekBuildingRoads();
    clock_t start = clock();
    int my_answer = obj->numWays(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 3;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1()
{
    int p0 = 4;
    int p1 = 3;
    int p2 = 3;
    DengklekBuildingRoads * obj = new DengklekBuildingRoads();
    clock_t start = clock();
    int my_answer = obj->numWays(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 4;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2()
{
    int p0 = 2;
    int p1 = 1;
    int p2 = 1;
    DengklekBuildingRoads * obj = new DengklekBuildingRoads();
    clock_t start = clock();
    int my_answer = obj->numWays(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 0;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test3()
{
    int p0 = 5;
    int p1 = 0;
    int p2 = 3;
    DengklekBuildingRoads * obj = new DengklekBuildingRoads();
    clock_t start = clock();
    int my_answer = obj->numWays(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 1;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test4()
{
    int p0 = 10;
    int p1 = 20;
    int p2 = 5;
    DengklekBuildingRoads * obj = new DengklekBuildingRoads();
    clock_t start = clock();
    int my_answer = obj->numWays(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 26964424;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
int main()
{
    int time;
    bool errors = false;

    time = test0();
    if (time < 0)
        errors = true;

    time = test1();
    if (time < 0)
        errors = true;

    time = test2();
    if (time < 0)
        errors = true;

    time = test3();
    if (time < 0)
        errors = true;

    time = test4();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}
