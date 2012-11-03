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

class LuckyRemainder {
public:
	int getLuckyRemainder(string);
};

int c[51][51],v[51];

int LuckyRemainder::getLuckyRemainder(string X) {
    memset(c,0,sizeof(c));
    c[0][0] = 1;
    for (int i = 1;i <= 50;i++)
    {
        c[i][0] = 1;
        for (int j = 1;j <= i;j++)
            c[i][j] = (c[i-1][j-1]+c[i-1][j])%9;
    }
    v[0] = 1;
    for (int i = 1;i <= 50;i++) v[i] = (v[i-1]*10)%9;
    int n = X.size();
    int res = 0;
    for (int i = 0;i < n;i++)
        for (int k = 0;k < n-i;k++)
        {
            int tsum = 0;
            for (int q = 0;q <= i;q++)
                tsum = (tsum+c[i][q])%9;
            res = (res+(X[i]-'0')*v[k]*c[n-i-1][k]*tsum)%9;
        }
    return res;
}

//Powered by [KawigiEdit] 2.0!
double test0() {
	string p0 = "123";
	LuckyRemainder * obj = new LuckyRemainder();
	clock_t start = clock();
	int my_answer = obj->getLuckyRemainder(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 6;
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
	string p0 = "24816";
	LuckyRemainder * obj = new LuckyRemainder();
	clock_t start = clock();
	int my_answer = obj->getLuckyRemainder(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
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
	string p0 = "8";
	LuckyRemainder * obj = new LuckyRemainder();
	clock_t start = clock();
	int my_answer = obj->getLuckyRemainder(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 8;
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
double test3() {
	string p0 = "11235813213455";
	LuckyRemainder * obj = new LuckyRemainder();
	clock_t start = clock();
	int my_answer = obj->getLuckyRemainder(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 7;
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

	time = test3();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
