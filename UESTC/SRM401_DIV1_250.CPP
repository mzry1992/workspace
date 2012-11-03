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

class FIELDDiagrams {
public:
	long long countDiagrams(int);
};

long long dp[50][50];

long long FIELDDiagrams::countDiagrams(int fieldOrder) {
    memset(dp,0,sizeof(dp));
    for (int i = 1;i <= fieldOrder;i++)
        dp[1][i] = 1;
    for (int i = 2;i <= fieldOrder;i++)
        for (int j = 1;j <= fieldOrder-i+1;j++)
            for (int k = j;k <= fieldOrder-i+2;k++)
                dp[i][j] = dp[i][j]+dp[i-1][k];
    long long res = 0;
    for (int i = 1;i <= fieldOrder;i++)
        for (int j = 1;j <= fieldOrder-i+1;j++)
            res = res+dp[i][j];
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int p0 = 2;
	FIELDDiagrams * obj = new FIELDDiagrams();
	clock_t start = clock();
	long long my_answer = obj->countDiagrams(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 4LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int p0 = 3;
	FIELDDiagrams * obj = new FIELDDiagrams();
	clock_t start = clock();
	long long my_answer = obj->countDiagrams(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 13LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int p0 = 5;
	FIELDDiagrams * obj = new FIELDDiagrams();
	clock_t start = clock();
	long long my_answer = obj->countDiagrams(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 131LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
