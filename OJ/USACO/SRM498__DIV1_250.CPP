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

class FoxSequence {
public:
	string isValid(vector <int>);
};

string FoxSequence::isValid(vector <int> seq) {
    int n = seq.size();
    int p[100];
    for (int i = 0;i < n;i++)
        p[i] = seq[i];
    bool flag = true;
    int cur = 0;
    while (true)
    {
        cur++;
        if (cur == n)   return "NO";
        if (p[cur+1] <= p[cur])  break;
        if (p[cur+1]-p[cur] != p[1]-p[0])
            return "NO";
    }
    int tmax = cur+1;
    while (true)
    {
        cur++;
        if (cur == n)   return "NO";
        if (p[cur+1] >= p[cur]) break;
        if (p[cur+1]-p[cur] != p[tmax+1]-p[tmax])
            return "NO";
    }
    while (p[cur+1] == p[cur])  cur++;
    int tmin = cur+1;
    while (true)
    {
        cur++;
        if (cur == n)   return "NO";
        if (p[cur+1] <= p[cur])  break;
        if (p[cur+1]-p[cur] != p[tmin+1]-p[tmin])
            return "NO";
    }
    tmax = cur+1;
    while (true)
    {
        cur++;
        if (cur == n)   return "NO";
        if (p[cur+1] >= p[cur]) break;
        if (p[cur+1]-p[cur] != p[tmax+1]-p[tmax])
            return "NO";
    }
    if (cur == n-1)
        return "YES";
    else
        return "NO";
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int t0[] = {1,3,5,7,5,3,1,1,1,3,5,7,5,3,1}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxSequence * obj = new FoxSequence();
	clock_t start = clock();
	string my_answer = obj->isValid(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {1,2,3,4,5,4,3,2,2,2,3,4,5,6,4}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxSequence * obj = new FoxSequence();
	clock_t start = clock();
	string my_answer = obj->isValid(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {3,6,9,1,9,5,1}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxSequence * obj = new FoxSequence();
	clock_t start = clock();
	string my_answer = obj->isValid(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {1,2,3,2,1,2,3,2,1,2,3,2,1}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxSequence * obj = new FoxSequence();
	clock_t start = clock();
	string my_answer = obj->isValid(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {1,3,4,3,1,1,1,1,3,4,3,1}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxSequence * obj = new FoxSequence();
	clock_t start = clock();
	string my_answer = obj->isValid(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {6,1,6}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxSequence * obj = new FoxSequence();
	clock_t start = clock();
	string my_answer = obj->isValid(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
