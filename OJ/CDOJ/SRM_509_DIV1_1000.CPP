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
#include <cstring>
using namespace std;

class NumberLabyrinthDiv1 {
public:
	int getNumberOfPaths(vector <int>, vector <int>, vector <int>, int, int, int);
};

int NumberLabyrinthDiv1::getNumberOfPaths(vector <int> X, vector <int> Y, vector <int> val, int xFinish, int yFinish, int K) {

}

//Powered by [KawigiEdit] 2.0!

double test0() {
	vector <int> p0;
	vector <int> p1;
	vector <int> p2;
	int p3 = 3;
	int p4 = 3;
	int p5 = 2;
	NumberLabyrinthDiv1 * obj = new NumberLabyrinthDiv1();
	clock_t start = clock();
	int my_answer = obj->getNumberOfPaths(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	vector <int> p0;
	vector <int> p1;
	vector <int> p2;
	int p3 = 3;
	int p4 = 3;
	int p5 = 3;
	NumberLabyrinthDiv1 * obj = new NumberLabyrinthDiv1();
	clock_t start = clock();
	int my_answer = obj->getNumberOfPaths(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 14;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 3;
	int p4 = 3;
	int p5 = 3;
	NumberLabyrinthDiv1 * obj = new NumberLabyrinthDiv1();
	clock_t start = clock();
	int my_answer = obj->getNumberOfPaths(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 18;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {1, 3, 6};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 3, 6};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2, 2, 2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 5;
	int p4 = 5;
	int p5 = 4;
	NumberLabyrinthDiv1 * obj = new NumberLabyrinthDiv1();
	clock_t start = clock();
	int my_answer = obj->getNumberOfPaths(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 210;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {1, 19, 20, 21, 21, 21, 20, 19, 19};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 11, 11, 11, 10, 9, 9, 9, 10};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1, 2, 2, 2, 2, 2, 2, 2, 2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 20;
	int p4 = 10;
	int p5 = 4;
	NumberLabyrinthDiv1 * obj = new NumberLabyrinthDiv1();
	clock_t start = clock();
	int my_answer = obj->getNumberOfPaths(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 1778;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int t0[] = {13, 224, 77, 509, 1451, 43, 379, 142, 477};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1974, 375, 38, 783, 3, 1974, 1790, 1008, 2710};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {30, 1845, 360, 11, 837, 84, 210, 4, 6704};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 509;
	int p4 = 2011;
	int p5 = 10;
	NumberLabyrinthDiv1 * obj = new NumberLabyrinthDiv1();
	clock_t start = clock();
	int my_answer = obj->getNumberOfPaths(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 196052726;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
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
