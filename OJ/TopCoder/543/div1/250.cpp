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

class EllysXors {
public:
	long long getXor(long long, long long);
};

long long EllysXors::getXor(long long L, long long R) {
    long long res = 0;
    long long mut = 1;
    long long r,l,dis,tot;
    for (int i = 0;i < 40;i++,mut *= 2)
    {
        r = R%(mut*2);
        l = L%(mut*2);
        tot = 0;

        if (mut*2-l+r+1 > R-L+1)
        {
            if (l >= mut)   tot -= l-mut;
            if (r >= mut)   tot += r-mut+1;
        }
        else
        {
            if (l >= mut)   tot += mut*2-l;
            else
                tot += mut;
            if (r >= mut)   tot += r-mut+1;
            dis = (R-L+1-(mut*2-l+r+1));
            tot += dis/2;
        }
        //cout << i << ' ' << mut << ' ' << l << ' ' << r << ' ' << dis << ' ' << tot << endl;
        if (tot%2 == 1)
            res += mut;
    }
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	long long p0 = 3LL;
	long long p1 = 10LL;
	EllysXors * obj = new EllysXors();
	clock_t start = clock();
	long long my_answer = obj->getXor(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 8LL;
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
	long long p0 = 5LL;
	long long p1 = 5LL;
	EllysXors * obj = new EllysXors();
	clock_t start = clock();
	long long my_answer = obj->getXor(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 5LL;
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
	long long p0 = 13LL;
	long long p1 = 42LL;
	EllysXors * obj = new EllysXors();
	clock_t start = clock();
	long long my_answer = obj->getXor(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 39LL;
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
	long long p0 = 666LL;
	long long p1 = 1337LL;
	EllysXors * obj = new EllysXors();
	clock_t start = clock();
	long long my_answer = obj->getXor(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 0LL;
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
	long long p0 = 1234567LL;
	long long p1 = 89101112LL;
	EllysXors * obj = new EllysXors();
	clock_t start = clock();
	long long my_answer = obj->getXor(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 89998783LL;
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
