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

class GogoXCake
{
public:
    string solve(vector <string>, vector <string>);
};

string GogoXCake::solve(vector <string> ca, vector <string> cu)
{
    for (int i = 0; i+cu.size()-1 < ca.size(); i++)
        for (int j = 0; j+cu[0].size()-1 < ca[0].size(); j++)
        {
            bool check = true;
            for (int x = 0; x < cu.size() && check; x++)
                for (int y = 0; y < cu[0].size() && check; y++)
                    if (cu[x][y] == '.' && ca[i+x][j+y] != '.')
                        check = false;
            if (check == true)
            {
                for (int x = 0; x < cu.size(); x++)
                    for (int y = 0; y < cu[0].size(); y++)
                        if (cu[x][y] == '.')
                            ca[i+x][j+y] = 'X';
            }
        }
    bool check = true;
    for (int i = 0;i < ca.size() && check;i++)
        for (int j = 0;j < ca[0].size() && check;j++)
            if (ca[i][j] != 'X')
                check = false;
    if (check == true)  return "YES";
    else    return "NO";
}

//Powered by [KawigiEdit] 2.0!

double test0()
{
    string t0[] = {"X.X"
                   ,"..."
                   ,"..."
                   ,"X.X"
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string t1[] = {".X"
                   ,".."
                   ,"X."
                  };
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    GogoXCake * obj = new GogoXCake();
    clock_t start = clock();
    string my_answer = obj->solve(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "YES";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p2 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    string t0[] = {"..XX"
                   ,"...X"
                   ,"X..."
                   ,"XX.."
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string t1[] = {".."
                   ,".."
                  };
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    GogoXCake * obj = new GogoXCake();
    clock_t start = clock();
    string my_answer = obj->solve(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "NO";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p2 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    string t0[] = {"...X..."};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string t1[] = {"..."};
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    GogoXCake * obj = new GogoXCake();
    clock_t start = clock();
    string my_answer = obj->solve(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "YES";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p2 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    string t0[] = {".X."
                   ,"X.X"
                   ,".X."
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string t1[] = {"."};
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    GogoXCake * obj = new GogoXCake();
    clock_t start = clock();
    string my_answer = obj->solve(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "YES";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p2 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    string t0[] = {"XXXXXXX"
                   ,"X.....X"
                   ,"X.....X"
                   ,"X.....X"
                   ,"XXXXXXX"
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string t1[] = {".X."
                   ,"XXX"
                   ,".X."
                  };
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    GogoXCake * obj = new GogoXCake();
    clock_t start = clock();
    string my_answer = obj->solve(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "NO";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p2 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
double test5()
{
    string t0[] = {".."
                   ,"X."
                   ,".X"
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string t1[] = {".."
                   ,".X"
                   ,"X."
                  };
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    GogoXCake * obj = new GogoXCake();
    clock_t start = clock();
    string my_answer = obj->solve(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "NO";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p2 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
double test6()
{
    string t0[] = {"X.."
                   ,".XX"
                   ,".XX"
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    string t1[] = {".XX"
                   ,".XX"
                   ,"X.."
                  };
    vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
    GogoXCake * obj = new GogoXCake();
    clock_t start = clock();
    string my_answer = obj->solve(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p2 = "NO";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p2 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
