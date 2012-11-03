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

class Cut
{
public:
    int getMaximum(vector <int>, int);
};

int Cut::getMaximum(vector <int> eel, int maxCuts)
{
    sort(eel.begin(),eel.end());
    int n = eel.size(),now;
    int res = 0;
    for (int i = 0; i < n; i++)
        if (eel[i]%10 == 0)
        {
            if (eel[i]/10-1 <= maxCuts)
            {
                res += eel[i]/10;
                maxCuts -= eel[i]/10-1;
            }
            else
            {
                res += maxCuts;
                maxCuts = 0;
            }
        }
    for (int i = 0; i < n; i++)
        if (eel[i]%10 != 0)
        {
            now = min(eel[i]/10,maxCuts);
            res += now;
            maxCuts -= now;
        }
    return res;
}

//Powered by [KawigiEdit] 2.0!
double test0()
{
    int t0[] = {13, 20, 13};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 2;
    Cut * obj = new Cut();
    clock_t start = clock();
    int my_answer = obj->getMaximum(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 3;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer)
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
    int t0[] = {5, 5, 5, 5};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 2;
    Cut * obj = new Cut();
    clock_t start = clock();
    int my_answer = obj->getMaximum(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 0;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer)
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
    int t0[] = {34, 10, 48};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 4;
    Cut * obj = new Cut();
    clock_t start = clock();
    int my_answer = obj->getMaximum(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 5;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer)
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
    int t0[] = {30, 50, 30, 50};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 350;
    Cut * obj = new Cut();
    clock_t start = clock();
    int my_answer = obj->getMaximum(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 16;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer)
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
