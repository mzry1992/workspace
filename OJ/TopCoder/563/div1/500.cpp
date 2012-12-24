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

class SpellCards {
public:
	int maxDamage(vector <int>, vector <int>);
};

int SpellCards::maxDamage(vector <int> tl, vector <int> td) {
	int n = tl.size();
	int ans = 0;
	for (int spos = 0;spos < n;spos++)
	{
		vector<int> l = tl;
		vector<int> d = td;
		rotate(&l[0],&l[spos],&l[n-1]);
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
double test0() {
	int t0[] = {1,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10,20,30};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	SpellCards * obj = new SpellCards();
	clock_t start = clock();
	int my_answer = obj->maxDamage(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 60;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {3,3,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10,20,30};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	SpellCards * obj = new SpellCards();
	clock_t start = clock();
	int my_answer = obj->maxDamage(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 30;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {4,4,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10,20,30};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	SpellCards * obj = new SpellCards();
	clock_t start = clock();
	int my_answer = obj->maxDamage(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {50,1,50,1,50};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10,20,30,40,50};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	SpellCards * obj = new SpellCards();
	clock_t start = clock();
	int my_answer = obj->maxDamage(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 60;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {2,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {40,40,10};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	SpellCards * obj = new SpellCards();
	clock_t start = clock();
	int my_answer = obj->maxDamage(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 80;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {1,2,1,1,3,2,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10,40,10,10,90,40,10};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	SpellCards * obj = new SpellCards();
	clock_t start = clock();
	int my_answer = obj->maxDamage(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 170;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test6() {
	int t0[] = {1,2,2,3,1,4,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {113,253,523,941,250,534,454};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	SpellCards * obj = new SpellCards();
	clock_t start = clock();
	int my_answer = obj->maxDamage(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1918;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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

	time = test6();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
