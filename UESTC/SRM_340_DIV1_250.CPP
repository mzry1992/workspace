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

class ProblemsToSolve {
public:
	int minNumber(vector <int>, int);
};

int dp[100][3];

int ProblemsToSolve::minNumber(vector <int> pleasantness, int variety) {
    int n = pleasantness.size();
    int res = 19921005;
    dp[0][0] = dp[0][1] = pleasantness[0];
    dp[0][2] = 1;
    bool tt = true;
    for (int i = 1;i < n;i++)
    {
        dp[i][2] = dp[i-1][2]+1;
        dp[i][0] = min(dp[i-1][0],pleasantness[i]);
        dp[i][1] = max(dp[i-1][1],pleasantness[i]);
        if (dp[i][1]-dp[i][0] >= variety)
        {
            if (res > dp[i][2])
                res = dp[i][2];
            tt = false;
        }
        if (i > 1)
        {
            dp[i][2] = dp[i-2][2]+1;
            dp[i][0] = min(dp[i-2][0],pleasantness[i]);
            dp[i][1] = max(dp[i-2][1],pleasantness[i]);
            if (dp[i][1]-dp[i][0] >= variety)
            {
                if (res > dp[i][2])
                    res = dp[i][2];
                tt = false;
            }
        }
    }
    if (res > dp[n-1][2])
        res = dp[n-1][2];
    if (tt == true)
        res = n;
    for (int i = 0;i < n;i++)
        cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << endl;
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int t0[] = {3, 3, 3, 1, 3, 3, 5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 4;
	ProblemsToSolve * obj = new ProblemsToSolve();
	clock_t start = clock();
	int my_answer = obj->minNumber(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 5;
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
	int t0[] = {1, 2, 3, 4, 5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 4;
	ProblemsToSolve * obj = new ProblemsToSolve();
	clock_t start = clock();
	int my_answer = obj->minNumber(p0, p1);
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
double test2() {
	int t0[] = {10, 1, 12, 101};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 100;
	ProblemsToSolve * obj = new ProblemsToSolve();
	clock_t start = clock();
	int my_answer = obj->minNumber(p0, p1);
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
double test3() {
	int t0[] = {10, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 9;
	ProblemsToSolve * obj = new ProblemsToSolve();
	clock_t start = clock();
	int my_answer = obj->minNumber(p0, p1);
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
double test4() {
	int t0[] = {6, 2, 6, 2, 6, 3, 3, 3, 7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 4;
	ProblemsToSolve * obj = new ProblemsToSolve();
	clock_t start = clock();
	int my_answer = obj->minNumber(p0, p1);
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

	time = test4();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
