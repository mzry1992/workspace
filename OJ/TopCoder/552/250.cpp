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

using namespace std;

class FoxPaintingBalls
{
public:
    long long theMax(long long, long long, long long, int);
};

long long FoxPaintingBalls::theMax(long long R, long long G, long long B, int N)
{
    long long cr,cg,cb,tmp;

    long long xs = N/3;
    tmp = (xs-1)*xs/2*3;
    tmp += (N/3)*(N%3+1);

    cr = cg = cb = tmp;
    cr += N/3;
    if (N%3 == 1)   cr++;
    tmp = N/3;
    if (N%3 == 2)   tmp++;
    cg += tmp;
    cb += tmp;

    long long res = 0;
    if (cr == cg)
        return min(min(R,G),B)/cr;
    else
        return (R+G+B)/(1+3*cb);
}

//Powered by [KawigiEdit] 2.0!
double test0()
{
    long long p0 = 2LL;
    long long p1 = 2LL;
    long long p2 = 2LL;
    int p3 = 3;
    FoxPaintingBalls * obj = new FoxPaintingBalls();
    clock_t start = clock();
    long long my_answer = obj->theMax(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p4 = 1LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer)
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
    long long p0 = 1LL;
    long long p1 = 2LL;
    long long p2 = 3LL;
    int p3 = 3;
    FoxPaintingBalls * obj = new FoxPaintingBalls();
    clock_t start = clock();
    long long my_answer = obj->theMax(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p4 = 0LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer)
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
    long long p0 = 8LL;
    long long p1 = 6LL;
    long long p2 = 6LL;
    int p3 = 4;
    FoxPaintingBalls * obj = new FoxPaintingBalls();
    clock_t start = clock();
    long long my_answer = obj->theMax(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p4 = 2LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer)
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
    long long p0 = 7LL;
    long long p1 = 6LL;
    long long p2 = 7LL;
    int p3 = 4;
    FoxPaintingBalls * obj = new FoxPaintingBalls();
    clock_t start = clock();
    long long my_answer = obj->theMax(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p4 = 2LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer)
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
    long long p0 = 100LL;
    long long p1 = 100LL;
    long long p2 = 100LL;
    int p3 = 4;
    FoxPaintingBalls * obj = new FoxPaintingBalls();
    clock_t start = clock();
    long long my_answer = obj->theMax(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p4 = 30LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer)
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
double test5()
{
    long long p0 = 19330428391852493LL;
    long long p1 = 48815737582834113LL;
    long long p2 = 11451481019198930LL;
    int p3 = 3456;
    FoxPaintingBalls * obj = new FoxPaintingBalls();
    clock_t start = clock();
    long long my_answer = obj->theMax(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p4 = 5750952686LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer)
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
double test6()
{
    long long p0 = 1LL;
    long long p1 = 1LL;
    long long p2 = 1LL;
    int p3 = 1;
    FoxPaintingBalls * obj = new FoxPaintingBalls();
    clock_t start = clock();
    long long my_answer = obj->theMax(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    long long p4 = 3LL;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p4 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p4 != my_answer)
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

    time = test5();
    if (time < 0)
        errors = true;

    time = test6();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}
