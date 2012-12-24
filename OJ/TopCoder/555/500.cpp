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

class XorBoard
{
public:
    int count(int, int, int, int, int);
};

const int mod = 555555555;

int c[3000][3000];

int XorBoard::count(int n, int m, int rc, int cc, int s)
{
    memset(c,0,sizeof(c));
    c[0][0] = 1;
    for (int i = 1; i < 2000; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
    }

    if (s == 0)
    {
        if (rc%2 != 0 || cc%2 != 0) return 0;
        else
            return (long long)c[n+rc/2-1][n-1]*c[m+cc/2-1][m-1]%mod;
    }

    int res = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            int tot = i*(m-j)+j*(n-i);
            if (tot != s)   continue;
            if ((rc-i)%2 != 0 || (cc-j)%2 != 0) continue;

            int row = (long long)c[n][i]*c[n+(rc-i)/2-1][n-1]%mod;
            int col = (long long)c[m][j]*c[m+(cc-j)/2-1][m-1]%mod;
            int tres = (long long)row*col%mod;
            res = (res+tres)%mod;
        }
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0()
{
    int p0 = 2;
    int p1 = 2;
    int p2 = 2;
    int p3 = 2;
    int p4 = 4;
    XorBoard * obj = new XorBoard();
    clock_t start = clock();
    int my_answer = obj->count(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p5 = 4;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p5 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p5 != my_answer)
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
    int p0 = 2;
    int p1 = 2;
    int p2 = 0;
    int p3 = 0;
    int p4 = 1;
    XorBoard * obj = new XorBoard();
    clock_t start = clock();
    int my_answer = obj->count(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p5 = 0;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p5 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p5 != my_answer)
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
    int p0 = 10;
    int p1 = 20;
    int p2 = 50;
    int p3 = 40;
    int p4 = 200;
    XorBoard * obj = new XorBoard();
    clock_t start = clock();
    int my_answer = obj->count(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p5 = 333759825;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p5 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p5 != my_answer)
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
    int p0 = 1200;
    int p1 = 1000;
    int p2 = 800;
    int p3 = 600;
    int p4 = 4000;
    XorBoard * obj = new XorBoard();
    clock_t start = clock();
    int my_answer = obj->count(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p5 = 96859710;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p5 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p5 != my_answer)
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
    int p0 = 555;
    int p1 = 555;
    int p2 = 555;
    int p3 = 555;
    int p4 = 5550;
    XorBoard * obj = new XorBoard();
    clock_t start = clock();
    int my_answer = obj->count(p0, p1, p2, p3, p4);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p5 = 549361755;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p5 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p5 != my_answer)
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
