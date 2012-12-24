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

class PointyWizardHats
{
public:
    int getNumHats(vector <int>, vector <int>, vector <int>, vector <int>);
};

int n,m;
bool mp[50][50],use[50];
int pre[50];

bool check(int u)
{
    for (int v=0; v<m; v++)
        if (mp[u][v] && !use[v])
        {
            use[v]=1;
            if (pre[v]==-1 || check(pre[v]))
            {
                pre[v]=u;
                return 1;
            }
        }
    return 0;
}
int match()
{
    int ret=0;
    memset(pre,-1,sizeof(pre));
    for (int u=0; u<n; u++)
    {
        memset(use,0,sizeof(use));
        if (check(u))
            ret++;
    }
    return ret;
}

int PointyWizardHats::getNumHats(vector <int> ht, vector <int> rt, vector <int> hl, vector <int> rl)
{
    n = ht.size();
    m = hl.size();
    memset(mp,false,sizeof(mp));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (rt[i] < rl[j])
                if (rt[i]*hl[j] < rl[j]*ht[i])
                    mp[i][j] = true;
    return match();
}

//Powered by [KawigiEdit] 2.0!

double test0()
{
    int t0[] = {30};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {3};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int t2[] = {3};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    int t3[] = {30};
    vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
    PointyWizardHats * obj = new PointyWizardHats();
    clock_t start = clock();
    int my_answer = obj->getNumHats(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 1;
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
    int t0[] = {4,4};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {4,3};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int t2[] = {5,12};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    int t3[] = {5,4};
    vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
    PointyWizardHats * obj = new PointyWizardHats();
    clock_t start = clock();
    int my_answer = obj->getNumHats(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 1;
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
    int t0[] = {3};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {3};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int t2[] = {1,1};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    int t3[] = {2,4};
    vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
    PointyWizardHats * obj = new PointyWizardHats();
    clock_t start = clock();
    int my_answer = obj->getNumHats(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 1;
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
    int t0[] = {10,10};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {2,5};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int t2[] = {2,9};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    int t3[] = {3,6};
    vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
    PointyWizardHats * obj = new PointyWizardHats();
    clock_t start = clock();
    int my_answer = obj->getNumHats(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 2;
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
    int t0[] = {3,4,5};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {5,4,3};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int t2[] = {3,4,5};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    int t3[] = {3,8,5};
    vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
    PointyWizardHats * obj = new PointyWizardHats();
    clock_t start = clock();
    int my_answer = obj->getNumHats(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 2;
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
    int t0[] = {1,2,3,4,5};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {2,3,4,5,6};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int t2[] = {2,3,4,5,6};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    int t3[] = {1,2,3,4,5};
    vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
    PointyWizardHats * obj = new PointyWizardHats();
    clock_t start = clock();
    int my_answer = obj->getNumHats(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 0;
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
    int t0[] = {123,214,232,323,342,343};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {123,123,232,123,323,434};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int t2[] = {545,322,123,545,777,999};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    int t3[] = {323,443,123,656,767,888};
    vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
    PointyWizardHats * obj = new PointyWizardHats();
    clock_t start = clock();
    int my_answer = obj->getNumHats(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 5;
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
double test7()
{
    int t0[] = {999,999,999,10000,10000,10000};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {10000,10000,10000,1,2,3};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    int t2[] = {2324,2323,234,5454,323,232};
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    int t3[] = {1,2,3222,434,5454,23};
    vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
    PointyWizardHats * obj = new PointyWizardHats();
    clock_t start = clock();
    int my_answer = obj->getNumHats(p0, p1, p2, p3);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p4 = 3;
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

    time = test7();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}
