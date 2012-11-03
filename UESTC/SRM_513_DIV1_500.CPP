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

class PerfectMemory {
public:
	double getExpectation(int, int);
};

double dp[2600][1300];
bool use[2600][1300];

double DP(int sum,int no,int rea)
{
    if (use[no][rea])   return dp[no][rea];
    if (no == 0)    return sum/2-rea;
    dp[no][rea] = 0.0;
    if (sum-no-2*rea > 0)
        dp[no][rea] += DP(sum,no-1,rea+1)*(double)(sum-no-2*rea)/(double)no;
    if (no > 1 && sum-no-2*rea+2 <= no)
    {
        dp[no][rea] += DP(sum,no-2,rea+1)*((double)((no-(sum-no-2*rea))*(no-(sum-no-2*rea)-1))/(double)(no*(no-1)));
        dp[no][rea] += DP(sum,no-2,rea)*(1.0-(double)((no-(sum-no-2*rea))*(no-(sum-no-2*rea)-1))/(double)(no*(no-1)));
    }
    dp[no][rea] += 1.0;
    use[no][rea] = true;
    return dp[no][rea];
}

double PerfectMemory::getExpectation(int N, int M) {
    int sum = (N*M);
    memset(use,false,sizeof(use));
    return DP(sum,sum,0);
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int p0 = 1;
	int p1 = 2;
	PerfectMemory * obj = new PerfectMemory();
	clock_t start = clock();
	double my_answer = obj->getExpectation(p0, p1);
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
	int p0 = 2;
	int p1 = 2;
	PerfectMemory * obj = new PerfectMemory();
	clock_t start = clock();
	double my_answer = obj->getExpectation(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 2.6666666666666665;
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
	int p0 = 2;
	int p1 = 3;
	PerfectMemory * obj = new PerfectMemory();
	clock_t start = clock();
	double my_answer = obj->getExpectation(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 4.333333333333334;
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
	int p0 = 4;
	int p1 = 4;
	PerfectMemory * obj = new PerfectMemory();
	clock_t start = clock();
	double my_answer = obj->getExpectation(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 12.392984792984793;
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
