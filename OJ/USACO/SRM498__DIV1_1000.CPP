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
#define MAX(X,Y) (((X)>(Y))?(X):(Y))
using namespace std;

class FoxJumping {
public:
	int getCount(int, int, int, int, int, vector <int>);
};

long long dp[2][1000][1000];
const int MOD = 10007;
bool b[1000];

int FoxJumping::getCount(int Tx, int Ty, int Mx, int My, int R, vector <int> bad) {
    memset(dp,0,sizeof(dp));
    memset(b,false,sizeof(b));
    for (int i = 0;i < bad.size();i++)
        b[bad[i]] = true;
    dp[0][0][0] = 1;
    for (int k = 1;k <= R;k++)
    for (int i = 0;i <= Tx;i++)
    for (int j = 0;j <= Ty;j++)
    {
        dp[k%2][i][j] = 0;
        if (i == j && b[i] == true)
            continue;
        for (int x = MAX(i-Mx,0);x <= i;x++)
        for (int y = MAX(j-My,0);y <= j;y++)
        if (!(x == i && y == j))
            dp[k%2][i][j] = (dp[k%2][i][j]+dp[(k+1)%2][x][y])%MOD;
    }
    return dp[R%2][Tx][Ty];
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int p0 = 2;
	int p1 = 2;
	int p2 = 1;
	int p3 = 1;
	int p4 = 2;
	vector <int> p5;
	FoxJumping * obj = new FoxJumping();
	clock_t start = clock();
	int my_answer = obj->getCount(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 1;
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
	int p0 = 2;
	int p1 = 2;
	int p2 = 1;
	int p3 = 1;
	int p4 = 3;
	vector <int> p5;
	FoxJumping * obj = new FoxJumping();
	clock_t start = clock();
	int my_answer = obj->getCount(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 6;
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
	int p0 = 10;
	int p1 = 10;
	int p2 = 10;
	int p3 = 10;
	int p4 = 1;
	vector <int> p5;
	FoxJumping * obj = new FoxJumping();
	clock_t start = clock();
	int my_answer = obj->getCount(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 1;
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
	int p0 = 10;
	int p1 = 10;
	int p2 = 10;
	int p3 = 10;
	int p4 = 1;
	int t5[] = {10};
	vector <int> p5(t5, t5+sizeof(t5)/sizeof(int));
	FoxJumping * obj = new FoxJumping();
	clock_t start = clock();
	int my_answer = obj->getCount(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 0;
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
	int p0 = 11;
	int p1 = 11;
	int p2 = 11;
	int p3 = 11;
	int p4 = 2;
	int t5[] = {10};
	vector <int> p5(t5, t5+sizeof(t5)/sizeof(int));
	FoxJumping * obj = new FoxJumping();
	clock_t start = clock();
	int my_answer = obj->getCount(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 140;
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
	int p0 = 123;
	int p1 = 456;
	int p2 = 70;
	int p3 = 80;
	int p4 = 90;
	int t5[] = {30, 40, 20, 10, 50};
	vector <int> p5(t5, t5+sizeof(t5)/sizeof(int));
	FoxJumping * obj = new FoxJumping();
	clock_t start = clock();
	int my_answer = obj->getCount(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 6723;
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
