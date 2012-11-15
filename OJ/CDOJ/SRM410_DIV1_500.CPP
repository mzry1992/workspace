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

class ContiguousCache {
public:
	long long minimumReads(int, int, vector <int>);
};

long long dp[50];

long long ContiguousCache::minimumReads(int n, int k, vector <int> a) {
    int m = a.size();
    sort(a.begin(),a.end());
    for (int i = 0;i < m;i++)

}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int p0 = 100;
	int p1 = 3;
	int t2[] = {0, 2, 16, 13};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ContiguousCache * obj = new ContiguousCache();
	clock_t start = clock();
	long long my_answer = obj->minimumReads(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 7LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 100;
	int p1 = 10;
	int t2[] = {1,10,19,28,30,37};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ContiguousCache * obj = new ContiguousCache();
	clock_t start = clock();
	long long my_answer = obj->minimumReads(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 29LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 1000000000;
	int p1 = 500000000;
	int t2[] = {0, 999999999, 1, 500000000, 500000001, 987654321};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ContiguousCache * obj = new ContiguousCache();
	clock_t start = clock();
	long long my_answer = obj->minimumReads(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 1987654320LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 8;
	int p1 = 2;
	int t2[] = {7};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ContiguousCache * obj = new ContiguousCache();
	clock_t start = clock();
	long long my_answer = obj->minimumReads(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 2LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
