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

class BestApproximationDiv2 {
public:
	string findFraction(int, string);
};

string doubletostr(double a)
{
    string res = "";
    char ss[100];
    sprintf(ss,"%.18lf",a);
    res = res+ss;
    return res;
}

char s[1000];

bool bigthen(string a,string b)
{
    int l = min(a.size(),b.size());
    for (int i = 0;i < l;i++)
        if (a[i] < b[i])
            return false;
        else if (a[i] > b[i])
            return true;
    return true;
}

int getsim(string a,string b)
{
    //cout << a << ' ' << b << endl;
    int res = 0;
    int l = min(a.size(),b.size());
    for (int i = 0;a[i] == b[i];i++)
        res++;
    return res-1;
}

string BestApproximationDiv2::findFraction(int maxDen, string number) {
    string res;
    int fm,fz,sim;
    sim = 0;
    for (int tfm = 1;tfm <= maxDen;tfm++)
    {
        int l = 0;
        int r = tfm;
        while (l != r)
        {
            int mid = (l+r)/2;
            string fsim = doubletostr((double)mid/(double)tfm);
            if (bigthen(fsim,number))
                r = mid;
            else
                l = mid+1;
        }
        //cout << r << ' ' << fm << ' ' << doubletostr((double)r/(double)fm) << endl;
        string newnumber = doubletostr((double)r/(double)tfm);
        int tsim = getsim(newnumber,number);
        if (tfm == 50)
            cout << r << ' ' << tfm << ' ' << newnumber << ' ' << number << ' ' << tsim << endl;
        if (tsim > sim)
        {
            sim = tsim;
            fz = r;
            fm = tfm;
        }
        r = r-1;
        newnumber = doubletostr((double)r/(double)tfm);
        tsim = getsim(newnumber,number);
        if (tfm == 50)
            cout << r << ' ' << tfm << ' ' << newnumber << ' ' << number << ' ' << tsim << endl;
        if (tsim > sim)
        {
            sim = tsim;
            fz = r;
            fm = tfm;
        }
        r = r+2;
        newnumber = doubletostr((double)r/(double)tfm);
        tsim = getsim(newnumber,number);
        if (tfm == 50)
            cout << r << ' ' << tfm << ' ' << newnumber << ' ' << number << ' ' << tsim << endl;
        if (tsim > sim)
        {
            sim = tsim;
            fz = r;
            fm = tfm;
        }
    }
    res = "";
    sprintf(s,"%d/%d has %d exact digits",fz,fm,sim);
    res = res+s;
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int p0 = 42;
	string p1 = "0.141592658";
	BestApproximationDiv2 * obj = new BestApproximationDiv2();
	clock_t start = clock();
	string my_answer = obj->findFraction(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "1/7 has 3 exact digits";
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
	int p0 = 3;
	string p1 = "0.1337";
	BestApproximationDiv2 * obj = new BestApproximationDiv2();
	clock_t start = clock();
	string my_answer = obj->findFraction(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "0/1 has 1 exact digits";
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
	int p0 = 80000;
	string p1 = "0.1234567891011121314151617181920";
	BestApproximationDiv2 * obj = new BestApproximationDiv2();
	clock_t start = clock();
	string my_answer = obj->findFraction(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "10/81 has 8 exact digits";
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
double test3() {
	int p0 = 1000;
	string p1 = "0.42";
	BestApproximationDiv2 * obj = new BestApproximationDiv2();
	clock_t start = clock();
	string my_answer = obj->findFraction(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "3/7 has 3 exact digits";
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
double test4() {
	int p0 = 100;
	string p1 = "0.420";
	BestApproximationDiv2 * obj = new BestApproximationDiv2();
	clock_t start = clock();
	string my_answer = obj->findFraction(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "21/50 has 4 exact digits";
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
double test5() {
	int p0 = 115;
	string p1 = "0.141592658";
	BestApproximationDiv2 * obj = new BestApproximationDiv2();
	clock_t start = clock();
	string my_answer = obj->findFraction(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "16/113 has 7 exact digits";
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
