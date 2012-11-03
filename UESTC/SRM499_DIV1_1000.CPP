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

class ImpossibleGame {
public:
	long long getMinimum(int, vector <string>, vector <string>);
};

long long ImpossibleGame::getMinimum(int k, vector <string> before, vector <string> after) {

}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int p0 = 1;
	string t1[] = { "A" }
;
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = { "B" }
;
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ImpossibleGame * obj = new ImpossibleGame();
	clock_t start = clock();
	long long my_answer = obj->getMinimum(p0, p1, p2);
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
double test1() {
	int p0 = 2;
	string t1[] = { "A", "A", "D" }
;
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = { "B", "C", "D" }
;
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ImpossibleGame * obj = new ImpossibleGame();
	clock_t start = clock();
	long long my_answer = obj->getMinimum(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 5LL;
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
	int p0 = 2;
	string t1[] = { "B", "C", "D" }
;
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = { "C", "D", "B" }
;
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ImpossibleGame * obj = new ImpossibleGame();
	clock_t start = clock();
	long long my_answer = obj->getMinimum(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 9LL;
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
	int p0 = 6;
	string t1[] = { "AABBC", "AAAADA", "AAACA", "CABAA", "AAAAAA", "BAAAA" }
;
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = { "AACCB", "DAAABC", "AAAAD", "ABCBA", "AABAAA", "AACAA" }
;
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ImpossibleGame * obj = new ImpossibleGame();
	clock_t start = clock();
	long long my_answer = obj->getMinimum(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 499LL;
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
