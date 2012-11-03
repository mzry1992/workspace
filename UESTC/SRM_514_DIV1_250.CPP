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

class MagicalGirlLevelOneDivOne {
public:
	string isReachable(vector <int>, int, int);
};

long long dx[4*50],dy[4*50];

string MagicalGirlLevelOneDivOne::isReachable(vector <int> jump, int x, int y) {
    int n = jump.size();
    for (int i = 0;i < n;i++)
    {
        dx[i*4+0] = dx[i*4+1] = jump[i];
        dx[i*4+2] = dx[i*4+3] = 1;
        dy[i*4+0] = 1;
        dy[i*4+1] = -1;
        dy[i*4+2] = jump[i];
        dy[i*4+3] = -jump[i];
    }
    for (int i = 0;i < 4*n;i++)
        dx[i] %= 2;
    for (int i = 0;i < 4*n;i++)
        dy[i] %= 2;
    x %= 2;
    y %= 2;
    for (int i = 0;i < 4*n;i++)
        dy[i] = (dy[i]+dx[i]+2)%2;
    y = (y+x+2)%2;
    if (y == 0) return "YES";
    for (int i = 0;i < 4*n;i++)
        if (dy[i] != 0) return "YES";
    return "NO";
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int t0[] = {2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 5;
	int p2 = 4;
	MagicalGirlLevelOneDivOne * obj = new MagicalGirlLevelOneDivOne();
	clock_t start = clock();
	string my_answer = obj->isReachable(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 5;
	int p2 = 4;
	MagicalGirlLevelOneDivOne * obj = new MagicalGirlLevelOneDivOne();
	clock_t start = clock();
	string my_answer = obj->isReachable(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1000000000;
	int p2 = -999999999;
	MagicalGirlLevelOneDivOne * obj = new MagicalGirlLevelOneDivOne();
	clock_t start = clock();
	string my_answer = obj->isReachable(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {999999999};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 999999999;
	int p2 = 0;
	MagicalGirlLevelOneDivOne * obj = new MagicalGirlLevelOneDivOne();
	clock_t start = clock();
	string my_answer = obj->isReachable(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
