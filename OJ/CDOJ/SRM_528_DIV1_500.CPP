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

class SPartition {
public:
	long long getCount(string);
};

map<string,int> ha,hb;

long long SPartition::getCount(string s) {
    int n = s.size(),hn;
    hn = n/2;
    ha.clear();
    int la,lb,ml;
    bool check;
    string a,b,c;
    for (int i = 0;i < (1<<hn);i++)
    {
        la = lb = 0;
        for (int j = 0;j < hn;j++)
            if (((i>>j)&1) == 0)
                la++;
            else
                lb++;
        a.resize(la);
        b.resize(lb);
        la = lb = 0;
        check = true;
        for (int j = 0;j < hn;j++)
        {
            if (((i>>j)&1) == 0)
                a[la++] = s[j];
            else
                b[lb++] = s[j];
            ml = min(la,lb);
            if (ml > 0 && a[ml-1] != b[ml-1])
                check = false;
            if (check == false) break;
        }
        if (check == true)
        {
            if (la > lb)
            {
                swap(a,b);
                swap(la,lb);
            }
            c.resize(lb-la);
            for (int j = 0;j < lb-la;j++)
                c[j] = b[la+j];
            ha[c]++;
        }
    }
    ha[""] = ha[""]*2;
    long long res = 0;
    for (int i = 0;i < (1<<(n-hn));i++)
    {
        la = lb = 0;
        for (int j = 0;j < n-hn;j++)
            if (((i>>j)&1) == 0)
                la++;
            else
                lb++;
        a.resize(la);
        b.resize(lb);
        la = lb = 0;
        check = true;
        for (int j = 0;j < n-hn;j++)
        {
            if (((i>>j)&1) == 0)
                a[la++] = s[n-1-j];
            else
                b[lb++] = s[n-1-j];
            ml = min(la,lb);
            if (ml > 0 && a[ml-1] != b[ml-1])
                check = false;
            if (check == false) break;
        }
        if (check == true)
        {
            if (la > lb)
            {
                swap(a,b);
                swap(la,lb);
            }
            c.resize(lb-la);
            for (int j = 0;j < lb-la;j++)
                c[lb-la-1-j] = b[la+j];
            res += ha[c];
        }
    }
    return res/2;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string p0 = "oxox";
	SPartition * obj = new SPartition();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 2LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string p0 = "oooxxx";
	SPartition * obj = new SPartition();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 0LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string p0 = "xoxxox";
	SPartition * obj = new SPartition();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 4LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string p0 = "xo";
	SPartition * obj = new SPartition();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 0LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string p0 = "ooooxoox";
	SPartition * obj = new SPartition();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 8LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	string p0 = "ooxxoxox";
	SPartition * obj = new SPartition();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 8LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
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
