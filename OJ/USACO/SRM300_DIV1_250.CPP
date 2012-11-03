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

class Dating {
public:
	string dates(string, int);
};

bool use[100];

int findnext(int cur,int n)
{
    int res = cur;
    while (true)
    {
        res++;
        res %= n;
        if (use[res] == false)  return res;
    }
}

string Dating::dates(string circle, int k) {
    int n = circle.size();
    for (int i = 0;i < n;i++)
        use[i] = false;
    int cur = -1;
    string res;
    res = "";
    bool first = true;
    int tot = 0;
    while (true)
    {
        for (int i = 1;i <= k;i++)
            cur = findnext(cur,n);
        use[cur] = true;
        char ta = circle[cur];
        int minp;
        char minc;
        if (circle[cur] >= 'A' && circle[cur] <= 'Z')
        {
            minp = 1000;
            minc = 'z'+1;
            for (int i = 0;i < n;i++)
            if (use[i] == false)
            if (circle[i] >= 'a' && circle[i] <= 'z')
            if (circle[i] < minc)
            {
                minc = circle[i];
                minp = i;
            }
        }
        else
        {
            minp = 1000;
            minc = 'Z'+1;
            for (int i = 0;i < n;i++)
            if (use[i] == false)
            if (circle[i] >= 'A' && circle[i] <= 'Z')
            if (circle[i] < minc)
            {
                minc = circle[i];
                minp = i;
            }
        }
        if (minp == 1000)   break;
        use[minp] = true;
        if (first == false)
            res += " ";
        first = false;
        res += ta;
        res += minc;
        tot++;
        if (tot*2+1 >= n)   break;
    }
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string p0 = "abXCd";
	int p1 = 2;
	Dating * obj = new Dating();
	clock_t start = clock();
	string my_answer = obj->dates(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "bC dX";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string p0 = "abXCd";
	int p1 = 8;
	Dating * obj = new Dating();
	clock_t start = clock();
	string my_answer = obj->dates(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Xa dC";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string p0 = "HGFhgfz";
	int p1 = 1;
	Dating * obj = new Dating();
	clock_t start = clock();
	string my_answer = obj->dates(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Hf Gg Fh";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

