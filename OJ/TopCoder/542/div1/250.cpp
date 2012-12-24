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

class PatrolRoute {
public:
	int countRoutes(int, int, int, int);
};

const int mod = 1000000007;

int totx[20001],toty[20001];

int PatrolRoute::countRoutes(int X, int Y, int minT, int maxT) {
    for (int i = 0;i < 20001;i++)
        totx[i] = toty[i] = 0;
    for (int a = 0;a < X;a++)
        for (int c = a+2;c < X;c++)
            if (2*(c-a) <= maxT)
                totx[2*(c-a)] += c-a-1;
    for (int a = 0;a < Y;a++)
        for (int c = a+2;c < Y;c++)
            if (2*(c-a) <= maxT)
                toty[2*(c-a)] += c-a-1;

    for (int i = 1;i <= maxT;i++)
        toty[i] = (toty[i]+toty[i-1])%mod;

    int res = 0;
    for (int x = 0;x <= maxT;x++)
    {
        int l,r;
        l = max(0,maxT-x);
        r = max(0,minT-x-1);
        long long sum = (toty[l]-toty[r]+mod)%mod;
        long long tmp = (long long)totx[x]*sum*6%mod;
        res = (res+tmp)%mod;
    }
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int p0 = 4000;
	int p1 = 4000;
	int p2 = 1;
	int p3 = 20000;
	PatrolRoute * obj = new PatrolRoute();
	clock_t start = clock();
	int my_answer = obj->countRoutes(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 6;
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
	int p0 = 3;
	int p1 = 3;
	int p2 = 4;
	int p3 = 7;
	PatrolRoute * obj = new PatrolRoute();
	clock_t start = clock();
	int my_answer = obj->countRoutes(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 0;
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
	int p0 = 4;
	int p1 = 6;
	int p2 = 9;
	int p3 = 12;
	PatrolRoute * obj = new PatrolRoute();
	clock_t start = clock();
	int my_answer = obj->countRoutes(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 264;
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
	int p0 = 7;
	int p1 = 5;
	int p2 = 13;
	int p3 = 18;
	PatrolRoute * obj = new PatrolRoute();
	clock_t start = clock();
	int my_answer = obj->countRoutes(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 1212;
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
	int p0 = 4000;
	int p1 = 4000;
	int p2 = 4000;
	int p3 = 14000;
	PatrolRoute * obj = new PatrolRoute();
	clock_t start = clock();
	int my_answer = obj->countRoutes(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 859690013;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
