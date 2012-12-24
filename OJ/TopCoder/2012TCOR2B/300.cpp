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

class BlurredDartboard
{
public:
    int minThrows(vector <int>, int);
};

bool flag[51];
vector<int> unused;

int BlurredDartboard::minThrows(vector <int> points, int P)
{
    int n = points.size();

    sort(points.begin(),points.end());
    memset(flag,false,sizeof(flag));
    for (int i = 0; i < n; i++)
        flag[points[i]] = true;

    int sumu = 0,cntu = 0;
    unused.clear();
    for (int i = 1; i <= n; i++)
        if (flag[i] == false)
        {
            sumu += i;
            cntu ++;
            unused.push_back(i);
        }
    int tsum,step;
    if (points[n-1] == 0)
    {
        int k = P/sumu;
        tsum = k*sumu;
        step = k*cntu;
        for (int i = 1; i <= n; i++)
        {
            if (tsum >= P)  return step;
            tsum += i;
            step++;
        }
        return step;
    }
    else if (cntu == 0)
    {
        step = P/n;
        while (step*n < P)  step++;
        return step;
    }
    else
    {
        int maxnow = points[n-1];
        if (cntu*maxnow <= sumu)
        {
            int k = P/sumu;
            tsum = k*sumu;
            step = k*cntu;
        }
        else
        {
            int k = P/maxnow;
            tsum = k*maxnow;
            step = k;
        }
        int res = step+(P-tsum)/maxnow+1;
        for (int i = 0;tsum+maxnow*i <= P;i++)
        {
            int ttsum = tsum+maxnow*i;
            int tstep = step+i;

            int k = (P-ttsum)/sumu;
            ttsum += sumu*k;
            tstep += k*cntu;

            for (int j = 0;j < cntu;j++)
            {
                if (ttsum >= P) break;
                ttsum += unused[j];
                tstep++;
            }
            res = min(res,tstep);
        }
        return res;
    }
}

//Powered by [KawigiEdit] 2.0!
double test0()
{
    int t0[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 1274;
    BlurredDartboard * obj = new BlurredDartboard();
    clock_t start = clock();
    int my_answer = obj->minThrows(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 2;
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
    int t0[] = {0, 0, 0, 0, 0};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 15;
    BlurredDartboard * obj = new BlurredDartboard();
    clock_t start = clock();
    int my_answer = obj->minThrows(p0, p1);
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
double test2()
{
    int t0[] = {4, 7, 8, 1, 3, 2, 6, 5};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 2012;
    BlurredDartboard * obj = new BlurredDartboard();
    clock_t start = clock();
    int my_answer = obj->minThrows(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 252;
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
    int t0[] = {0, 0, 5, 0, 0, 0, 1, 3, 0, 0};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 2012;
    BlurredDartboard * obj = new BlurredDartboard();
    clock_t start = clock();
    int my_answer = obj->minThrows(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 307;
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
double test4()
{
    int t0[] = {0, 2, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 6, 0, 0, 0, 4, 0, 0, 0};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int p1 = 1000000000;
    BlurredDartboard * obj = new BlurredDartboard();
    clock_t start = clock();
    int my_answer = obj->minThrows(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 84656087;
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

    time = test4();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}
