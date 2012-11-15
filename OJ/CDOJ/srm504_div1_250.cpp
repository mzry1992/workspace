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

class MathContest {
public:
	int countBlack(string, int);
};

deque<char> Q;

int MathContest::countBlack(string ballSequence, int repetitions) {
    int n = ballSequence.size();
    bool rec = false;
    int fan = 1;
    Q.clear();
    for (int j = 1;j <= repetitions;j++)
    for (int i = 0;i < n;i++)
        Q.push_back(ballSequence[i]);
    int res = 0;
    while (!Q.empty())
    {
        char now;
        if (fan == 0)
        {
            now = Q.back();
            Q.pop_back();
        }
        else
        {
            now = Q.front();
            Q.pop_front();
        }
        if (rec == true)
        {
            if (now == 'W') now = 'B';
            else    now = 'W';
        }
        if (now == 'W')
        {
            if (fan == 0)   fan = 1;
            else    fan = 0;
        }
        else
        {
            res++;
            if (rec == false)   rec = true;
            else    rec = false;
        }
    }
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string p0 = "BBWWB";
	int p1 = 1;
	MathContest * obj = new MathContest();
	clock_t start = clock();
	int my_answer = obj->countBlack(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	string p0 = "BBB";
	int p1 = 10;
	MathContest * obj = new MathContest();
	clock_t start = clock();
	int my_answer = obj->countBlack(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1;
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
	string p0 = "BW";
	int p1 = 10;
	MathContest * obj = new MathContest();
	clock_t start = clock();
	int my_answer = obj->countBlack(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 20;
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
	string p0 = "WWWWWWWBWWWWWWWWWWWWWW";
	int p1 = 1;
	MathContest * obj = new MathContest();
	clock_t start = clock();
	int my_answer = obj->countBlack(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
