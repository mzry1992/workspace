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

class Survived {
public:
	double minTime(int, int, int, int);
};

double Survived::minTime(int x, int y, int V, int U) {
    if (x == 0 && y == 0)   return 0.0;
    if (x == 0)
    {
        if (V < U)
            return -1.0;
        double speed = sqrt(V*V-U*U);
        return (double)y/speed;
    }
    double a,b,c,d;
    a = 1.0+(double)(y*y)/(double)(x*x);
    b = 2.0*(double)U*(double)(y*y)/(double)(x*x);
    c = (double)(U*U)*(double)(y*y)/(double)(x*x)-(double)(V*V);
    d = b*b-4*a*c;
    if (d < -1e-8)   return -1.0;
    if (d < 1e-8)   d = 0.0;
    double a1;
    a1 = (-b+sqrt(d))/(2.0*a)+U;
    double a2;
    a2 = (-b-sqrt(d))/(2.0*a)+U;
    double t1,t2;
    t1 = (double)x/a1;
    t2 = (double)x/a2;
    if (t1 < 0)
        t1 = 1e100;
    if (t2 > 0)
        if (t2 < t1)
            t1 = t2;
    if (t1 == 1e100) return -1.0;
    return t1;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int p0 = -23;
	int p1 = 13;
	int p2 = 32;
	int p3 = 32;
	Survived * obj = new Survived();
	clock_t start = clock();
	double my_answer = obj->minTime(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 1.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 1;
	int p1 = 1;
	int p2 = 1;
	int p3 = 0;
	Survived * obj = new Survived();
	clock_t start = clock();
	double my_answer = obj->minTime(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 1.4142135623730951;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 1;
	int p1 = 1;
	int p2 = 0;
	int p3 = 1;
	Survived * obj = new Survived();
	clock_t start = clock();
	double my_answer = obj->minTime(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = -1.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 9;
	int p1 = 3;
	int p2 = 2;
	int p3 = 3;
	Survived * obj = new Survived();
	clock_t start = clock();
	double my_answer = obj->minTime(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 2.0593413823019864;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 0;
	int p1 = 0;
	int p2 = 0;
	int p3 = 0;
	Survived * obj = new Survived();
	clock_t start = clock();
	double my_answer = obj->minTime(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 0.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int p0 = 5;
	int p1 = 12;
	int p2 = 24;
	int p3 = 26;
	Survived * obj = new Survived();
	clock_t start = clock();
	double my_answer = obj->minTime(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 1.3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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
