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

class FoxAndHandle
{
public:
    string lexSmallestName(string);
};

bool mark[100],use[100];
int r[100];
string FoxAndHandle::lexSmallestName(string s)
{
    for (int i = 0; i < s.length(); i++)
        mark[i] = use[i] = false;
    for (int i = 0; i < s.length(); i++)
        if (mark[i] == false)
        {
            for (int j = s.length()-1; j > i; j--)
                if (mark[j] == false && s[i] == s[j])
                {
                    mark[j] = true;
                    r[i] = j;
                    break;
                }
        }

    string ans;
    ans.resize(s.length()/2);

    int pos = 0;
    for (int i = 0; i < ans.length(); i++)
    {
		char minch = 'z';
        int nxtpos = pos;
        for (int j = pos; j < s.length(); j++)
            if (use[j] == false)
            {
                if (s[j] < minch)
				{
					minch = s[j];
                    nxtpos = j;
				}
                if (mark[j] == true)
                    break;
            }
        ans[i] = s[nxtpos];
		if (mark[nxtpos] == false)
			use[r[nxtpos]] = true;
		use[nxtpos] = true;
		pos = nxtpos;
    }

	return ans;
}

//Powered by [KawigiEdit] 2.0!
double test0()
{
    string p0 = "foxfox";
    FoxAndHandle * obj = new FoxAndHandle();
    clock_t start = clock();
    string my_answer = obj->lexSmallestName(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "fox";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    string p0 = "ccieliel";
    FoxAndHandle * obj = new FoxAndHandle();
    clock_t start = clock();
    string my_answer = obj->lexSmallestName(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "ceil";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    string p0 = "abaabbab";
    FoxAndHandle * obj = new FoxAndHandle();
    clock_t start = clock();
    string my_answer = obj->lexSmallestName(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "aabb";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    string p0 = "bbbbaaaa";
    FoxAndHandle * obj = new FoxAndHandle();
    clock_t start = clock();
    string my_answer = obj->lexSmallestName(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "bbaa";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    string p0 = "fedcbafedcba";
    FoxAndHandle * obj = new FoxAndHandle();
    clock_t start = clock();
    string my_answer = obj->lexSmallestName(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "afedcb";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
    string p0 = "nodevillivedon";
    FoxAndHandle * obj = new FoxAndHandle();
    clock_t start = clock();
    string my_answer = obj->lexSmallestName(p0);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    string p1 = "deilvon";
    cout <<"Desired answer: " <<endl;
    cout <<"\t\"" << p1 <<"\"" <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t\"" << my_answer<<"\"" <<endl;
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
