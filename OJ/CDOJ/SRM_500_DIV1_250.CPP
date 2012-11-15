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

class MafiaGame {
public:
	double probabilityToLose(int, vector <int>);
};

int a[600];

double MafiaGame::probabilityToLose(int N, vector <int> decisions) {
    double res = 1.0;
    memset(a,0,sizeof(a));
    for (int i = 0;i < decisions.size();i++)
        a[decisions[i]]++;
    int maxa,maxt;
    maxa = maxt = 0;
    for (int i = 0;i < N;i++)
    if (a[i] == maxa)
        maxt++;
    else if (a[i] > maxa)
    {
        maxa = a[i];
        maxt = 1;
    }
    int dif = 0;
    for (int i = 0;i < N;i++)
    if (a[i] < maxa)
        dif += maxa-1-a[i];
    int leav = N-decisions.size();
    int nextt,nexta;
    if (dif < leav)
    {
        dif = 0;
        int temp1 = leav-dif;
        for (int i = 0;i < N;i++)
            dif += maxa-a[i];
        if (dif < leav)
        {
            nexta = maxa;
            nextt = (leav-dif)%N;
            if (nextt == 0) nextt = N;
            res = res*((double)nextt/(double)N);
        }
        else
        {
            nexta = maxa;
            nextt = maxt+temp1;
        }
    }
    else
    {
        nexta = maxa;
        nextt = maxt;
    }
    //cout << nextt << ' ' << nexta << endl;
    while (true)
    {
        if (nextt == 1) return res;
        leav = N-nexta*nextt;
        if (leav%nextt == 0)    return 0.0;
        nexta = nexta;
        int temp2 = nextt;
        nextt = leav%nextt;
        res = res*((double)nextt/(double)temp2);
    }
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int p0 = 1;
	int t1[] = {1, 1, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	MafiaGame * obj = new MafiaGame();
	clock_t start = clock();
	double my_answer = obj->probabilityToLose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 1.0;
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
	int p0 = 5;
	int t1[] = {1, 2, 3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	MafiaGame * obj = new MafiaGame();
	clock_t start = clock();
	double my_answer = obj->probabilityToLose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.0;
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
	int p0 = 20;
	int t1[] = {1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 18, 19, 0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	MafiaGame * obj = new MafiaGame();
	clock_t start = clock();
	double my_answer = obj->probabilityToLose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.0;
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
	int p0 = 23;
	int t1[] = {17, 10, 3, 14, 22, 5, 11, 10, 22, 3, 14, 5, 11, 17};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	MafiaGame * obj = new MafiaGame();
	clock_t start = clock();
	double my_answer = obj->probabilityToLose(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.14285714285714285;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
