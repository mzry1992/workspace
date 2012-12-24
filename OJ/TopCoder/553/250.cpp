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

class Suminator {
public:
	int findMissing(vector <int>, int);
};

pair<long long,long long> s[100];
int top;

pair<long long,long long> gettop()
{
    if (top == 0)   return make_pair(0,0);
    return s[--top];
}

void push(pair<long long,long long> v)
{
    s[top++] = v;
}

int Suminator::findMissing(vector <int> p, int w) {
    int n = p.size();
    top = 0;
    for (int i = 0;i < n;i++)
        if (p[i] <= 0)
        {
            pair<long long,long long> a = gettop();
            pair<long long,long long> b = gettop();
            push(make_pair(a.first+b.first,a.second+b.second));
        }
        else if (p[i] > 0)
            push(make_pair(p[i],0));
    if (gettop().first == w)  return 0;
    top = 0;
    for (int i = 0;i < n;i++)
        if (p[i] == 0)
        {
            pair<long long,long long> a = gettop();
            pair<long long,long long> b = gettop();
            push(make_pair(a.first+b.first,a.second+b.second));
        }
        else if (p[i] > 0)
            push(make_pair(p[i],0));
        else if (p[i] == -1)
            push(make_pair(0,1));
    pair<long long,long long> a = gettop();
    if (a.second == 0)
    {
        if (a.first == w)   return 1;
        else
            return -1;
    }
    else
    {
        long long res = w-a.first;
        if (res <= 0 || res > 2147483647)   return -1;
        return res;
    }
    return -1;
}

//Powered by [KawigiEdit] 2.0!
double test0() {
	int t0[] = {7,-1,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 10;
	Suminator * obj = new Suminator();
	clock_t start = clock();
	int my_answer = obj->findMissing(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	int t0[] = {100, 200, 300, 0, 100, -1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 600;
	Suminator * obj = new Suminator();
	clock_t start = clock();
	int my_answer = obj->findMissing(p0, p1);
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
double test2() {
	int t0[] = {-1, 7, 3, 0, 1, 2, 0, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 13;
	Suminator * obj = new Suminator();
	clock_t start = clock();
	int my_answer = obj->findMissing(p0, p1);
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
	int t0[] = {-1, 8, 4, 0, 1, 2, 0, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 16;
	Suminator * obj = new Suminator();
	clock_t start = clock();
	int my_answer = obj->findMissing(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
	int t0[] = {1000000000, 1000000000, 1000000000,  1000000000, -1, 0, 0, 0, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1000000000;
	Suminator * obj = new Suminator();
	clock_t start = clock();
	int my_answer = obj->findMissing(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
	int t0[] = {7, -1, 3, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 3;
	Suminator * obj = new Suminator();
	clock_t start = clock();
	int my_answer = obj->findMissing(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
