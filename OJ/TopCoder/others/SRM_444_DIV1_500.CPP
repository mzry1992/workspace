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

class FourBlocks
{
public:
    int maxScore(vector <string>);
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

int n,m,bit[15];
char mp[25][10];
hash_map dp[2];
int flag,key,val,l,u;

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
    dp[a][b] = max(dp[a][b],val);
}

int FourBlocks::maxScore(vector <string> grid)
{
    bit[0] = 1;
    for (int i = 1; i < 15; i++)
        bit[i] = bit[i-1]*5;
    dp[0].init();
    dp[1].init();
    n = grid[0].size();
    m = grid.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mp[i][j] = grid[j][i];
    dp[0].clear();
    dp[1].clear();
    flag = 0;
    dp[0][0] = 0;
    int res = 0;
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
                if (mp[i][j] == '1')
                {
                    if (l == 0 && u == 0)
                        update(!flag,key,val+1);
                }
                else
                {
                    if (l == 0 && u == 0)
                    {
                        // 0
                        //00
                        update(!flag,key,val+1);
                        // 0
                        //01
                        update(!flag,setbit(setbit(key,j,1),j+1,1),val+4);
                    }
                    else if (l == 0)
                    {
                        // 1 |
                        //03 |
                        if (u == 1)
                            update(!flag,setbit(setbit(key,j,0),j+1,3),val+4);
                    }
                    else if (u == 0)
                    {
                        // 0
                        //12
                        if (l == 1)
                            update(!flag,setbit(setbit(key,j,2),j+1,0),val+4);
                    }
                    else
                    {
                        // 2
                        //34
                        if (l == 3 && u == 2)
                            update(!flag,setbit(setbit(key,j,0),j+1,0),val+4);
                    }
                }
            }
        }
        if (i+1 == n)
        {
            for (int k = 0; k < dp[flag].N; k++)
            {
                key = dp[flag].ele[k].key;
                val = dp[flag].ele[k].val;
                if (key == 0)
                    res = max(res,val);
            }
            break;
        }
        dp[!flag].clear();
        for (int k = 0; k < dp[flag].N; k++)
        {
            key = dp[flag].ele[k].key;
            val = dp[flag].ele[k].val;
            l = getbit(key,m);
            if (l != 0)   continue;
                /*cout << "next line = " << i << ' ';
                output(key);
                cout << ' ' << val << ' ' << l << endl;*/
            update(!flag,key*bit[1],val);
        }
    }
    return res;
}

//Powered by [KawigiEdit] 2.0!
double test0()
{
    string t0[] = {".....1..1..",
                   "..1.....1.."
                  };
    /*string t0[] = {"....",
                   "...."
                  };*/
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    FourBlocks * obj = new FourBlocks();
    clock_t start = clock();
    int my_answer = obj->maxScore(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 70;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    getchar();
    if (p1 != my_answer)
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
    string t0[] = {"...1.",
                   ".....",
                   ".1..1",
                   ".....",
                   "1...."
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    FourBlocks * obj = new FourBlocks();
    clock_t start = clock();
    int my_answer = obj->maxScore(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 73;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer)
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
    string t0[] = {"...1.",
                   ".1...",
                   "..1.1",
                   "1...."
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    FourBlocks * obj = new FourBlocks();
    clock_t start = clock();
    int my_answer = obj->maxScore(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 20;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer)
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
    string t0[] = {".....1...",
                   ".....1...",
                   "111111111",
                   ".....1...",
                   ".....1..."
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    FourBlocks * obj = new FourBlocks();
    clock_t start = clock();
    int my_answer = obj->maxScore(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 117;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p1 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p1 != my_answer)
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

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}
