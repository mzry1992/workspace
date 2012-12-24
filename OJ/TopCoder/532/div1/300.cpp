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

class DengklekMakingChains
{
public:
    int maxBeauty(vector <string>);
};

int n,type[50],val[50];

int g(char ch)
{
    if (ch == '.')  return 0;
    return ch-'0';
}

int DengklekMakingChains::maxBeauty(vector <string> ch)
{
    n = ch.size();
    for (int i = 0; i < n; i++)
    {
        if (ch[i][0] != '.' && ch[i][1] != '.' && ch[i][2] != '.')
        {
            type[i] = 0;
            val[i] = g(ch[i][0])+g(ch[i][1])+g(ch[i][2]);
        }
        else if (ch[i][0] == '.' && ch[i][2] != '.')
        {
            type[i] = 1;
            val[i] = g(ch[i][0])+g(ch[i][1])+g(ch[i][2]);
        }
        else if (ch[i][0] != '.' && ch[i][2] == '.')
        {
            type[i] = 2;
            val[i] = g(ch[i][0])+g(ch[i][1])+g(ch[i][2]);
        }
        else if (ch[i][0] != '.' && ch[i][1] == '.' && ch[i][2] != '.')
        {
            type[i] = 3;
        }
        else
            type[i] = 4;
    }
    int res = 0,mid = 0;
    int vh,vt;
    for (int i = 0; i < n; i++)
        if (type[i] == 0)
            mid += val[i];
    for (int i = 0; i < n; i++)
        if (type[i] == 1 || type[i] == 3)
        {
            int vh,vt;
            if (type[i] == 1)   vh = val[i];
            else vh = g(ch[i][2]);
            res = max(res,vh);
        }
    for (int j = 0; j < n; j++)
        if (type[j] == 2 || type[j] == 3)
        {
            if (type[j] == 1)   vt = val[j];
            else vt = g(ch[j][0]);
            res = max(res,vt);
        }
    for (int i = 0; i < n; i++)
        if (type[i] == 1 || type[i] == 3)
        {
            if (type[i] == 1)   vh = val[i];
            else vh = g(ch[i][2]);
            for (int j = 0; j < n; j++)
                if (type[j] == 2 || type[j] == 3)
                    if (i != j)
                    {
                        if (type[j] == 1)   vt = val[j];
                        else vt = g(ch[j][0]);
                        res = max(res,vh+vt);
                    }
        }
    if (mid == 0)
    {
        for (int i = 0; i < n; i++)
            if (type[i] == 4)
                res = max(res,g(ch[i][1]));
    }
    return res+mid;
}

//Powered by [KawigiEdit] 2.0!

double test0()
{
    string t0[] = {".15", "7..", "402", "..3"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    DengklekMakingChains * obj = new DengklekMakingChains();
    clock_t start = clock();
    int my_answer = obj->maxBeauty(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 19;
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
double test1()
{
    string t0[] = {"..1", "7..", "567", "24.", "8..", "234"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    DengklekMakingChains * obj = new DengklekMakingChains();
    clock_t start = clock();
    int my_answer = obj->maxBeauty(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 36;
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
    string t0[] = {"...", "..."};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    DengklekMakingChains * obj = new DengklekMakingChains();
    clock_t start = clock();
    int my_answer = obj->maxBeauty(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 0;
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
    string t0[] = {"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    DengklekMakingChains * obj = new DengklekMakingChains();
    clock_t start = clock();
    int my_answer = obj->maxBeauty(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 28;
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
double test4()
{
    string t0[] = {"..1", "3..", "2..", ".7."};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    DengklekMakingChains * obj = new DengklekMakingChains();
    clock_t start = clock();
    int my_answer = obj->maxBeauty(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 7;
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
double test5()
{
    string t0[] = {"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    DengklekMakingChains * obj = new DengklekMakingChains();
    clock_t start = clock();
    int my_answer = obj->maxBeauty(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p1 = 58;
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

    time = test4();
    if (time < 0)
        errors = true;

    time = test5();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}
