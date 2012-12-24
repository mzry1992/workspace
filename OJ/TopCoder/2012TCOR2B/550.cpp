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

class HeavyBooks
{
public:
    vector <int> findWeight(vector <int>, vector <int>);
};

vector<int> a,b;

vector <int> HeavyBooks::findWeight(vector <int> books, vector <int> moves)
{
    int n = books.size();
    int m = moves.size();
    int fc = moves[0];
    sort(books.begin(),books.end());
    int resa,resb;
    bool first = false;
    for (int i = 0; i+fc <= n; i++)
    {
        a.clear();
        b.clear();
        for (int j = 0; j < fc; j++)
            a.push_back(books[i+j]);
        for (int j = 0; j < m; j++)
        {
            if (j%2 == 0)
            {
                moves[j] = min(moves[j],(int)a.size());
                for (int k = 0; k < moves[j]; k++)
                {
                    b.push_back(a.back());
                    a.pop_back();
                }
                sort(b.begin(),b.end());
            }
            else
            {
                moves[j] = min(moves[j],(int)b.size());
                for (int k = 0; k < moves[j]; k++)
                {
                    a.push_back(b.back());
                    b.pop_back();
                }
                sort(a.begin(),a.end());
            }
        }
        int wa,wb;
        wa = wb = 0;
        for (int j = 0; j < a.size(); j++)
            wa += a[j];
        for (int j = 0; j < b.size(); j++)
            wb += b[j];
        if (first == false || wb-wa > resb-resa)
        {
            resa = wa;
            resb = wb;
            first = true;
        }
        else if (wb-wa == resb-resa)
        {
            if (wa+wb > resa+resb)
            {
                resa = wa;
                resb = wb;
            }
        }
    }
    vector<int> res(2);
    res[0] = resa;
    res[1] = resb;
    return res;
}

//Powered by [KawigiEdit] 2.0!
double test0()
{
    int t0[] = {5,2,3,1};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {3,2,1,1,1};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    HeavyBooks * obj = new HeavyBooks();
    clock_t start = clock();
    vector <int> my_answer = obj->findWeight(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int t2[] = {3, 7 };
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0)
    {
        cout <<p2[0];
        for (int i=1; i<p2.size(); i++)
            cout <<", " <<p2[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    cout <<endl <<"Your answer: " <<endl;
    cout <<"\t{ ";
    if (my_answer.size() > 0)
    {
        cout <<my_answer[0];
        for (int i=1; i<my_answer.size(); i++)
            cout <<", " <<my_answer[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    if (my_answer != p2)
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
    int t0[] = {10, 100, 1000};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {2, 3};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    HeavyBooks * obj = new HeavyBooks();
    clock_t start = clock();
    vector <int> my_answer = obj->findWeight(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int t2[] = {110, 0 };
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0)
    {
        cout <<p2[0];
        for (int i=1; i<p2.size(); i++)
            cout <<", " <<p2[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    cout <<endl <<"Your answer: " <<endl;
    cout <<"\t{ ";
    if (my_answer.size() > 0)
    {
        cout <<my_answer[0];
        for (int i=1; i<my_answer.size(); i++)
            cout <<", " <<my_answer[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    if (my_answer != p2)
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
    int t0[] = {155870,565381};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {1,1,1};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    HeavyBooks * obj = new HeavyBooks();
    clock_t start = clock();
    vector <int> my_answer = obj->findWeight(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int t2[] = {0, 565381 };
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0)
    {
        cout <<p2[0];
        for (int i=1; i<p2.size(); i++)
            cout <<", " <<p2[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    cout <<endl <<"Your answer: " <<endl;
    cout <<"\t{ ";
    if (my_answer.size() > 0)
    {
        cout <<my_answer[0];
        for (int i=1; i<my_answer.size(); i++)
            cout <<", " <<my_answer[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    if (my_answer != p2)
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
    int t0[] = {500,500,500,500};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {4,1,1,3,2};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    HeavyBooks * obj = new HeavyBooks();
    clock_t start = clock();
    vector <int> my_answer = obj->findWeight(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int t2[] = {500, 1500 };
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0)
    {
        cout <<p2[0];
        for (int i=1; i<p2.size(); i++)
            cout <<", " <<p2[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    cout <<endl <<"Your answer: " <<endl;
    cout <<"\t{ ";
    if (my_answer.size() > 0)
    {
        cout <<my_answer[0];
        for (int i=1; i<my_answer.size(); i++)
            cout <<", " <<my_answer[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    if (my_answer != p2)
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
    int t0[] = {1,1,1,1,1000000};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {1};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    HeavyBooks * obj = new HeavyBooks();
    clock_t start = clock();
    vector <int> my_answer = obj->findWeight(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int t2[] = {0, 1000000 };
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0)
    {
        cout <<p2[0];
        for (int i=1; i<p2.size(); i++)
            cout <<", " <<p2[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    cout <<endl <<"Your answer: " <<endl;
    cout <<"\t{ ";
    if (my_answer.size() > 0)
    {
        cout <<my_answer[0];
        for (int i=1; i<my_answer.size(); i++)
            cout <<", " <<my_answer[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    if (my_answer != p2)
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
    int t0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
    int t1[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
    HeavyBooks * obj = new HeavyBooks();
    clock_t start = clock();
    vector <int> my_answer = obj->findWeight(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int t2[] = {110, 100 };
    vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
    cout <<"Desired answer: " <<endl;
    cout <<"\t{ ";
    if (p2.size() > 0)
    {
        cout <<p2[0];
        for (int i=1; i<p2.size(); i++)
            cout <<", " <<p2[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    cout <<endl <<"Your answer: " <<endl;
    cout <<"\t{ ";
    if (my_answer.size() > 0)
    {
        cout <<my_answer[0];
        for (int i=1; i<my_answer.size(); i++)
            cout <<", " <<my_answer[i];
        cout <<" }" <<endl;
    }
    else
        cout <<"}" <<endl;
    if (my_answer != p2)
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
