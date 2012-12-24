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

class ConversionMachine {
public:
	int countAll(string, string, vector <int>, int);
};

string a,b;
int n;
long long c[3],totaa,mc,cost[3][3],op[3][3],totop[12];
const long long mod = 1000000007;

int ConversionMachine::countAll(string _a, string _b, vector <int> _c, int _mc) {
    a = _a,b = _b;
    n = a.size();
    for (int i = 0;i < 3;i++)
        c[i] = _c[i];
    mc = _mc;
    totaa = c[0]+c[1]+c[2];

    cost[0][0] = 0;op[0][0] = 0;
    cost[0][1] = c[0];op[0][1] = 1;
    cost[0][2] = c[0]+c[1];op[0][2] = 2;

    cost[1][0] = c[1]+c[2];op[1][0] = 2;
    cost[1][1] = 0;op[1][1] = 0;
    cost[1][2] = c[1];op[1][2] = 1;

    cost[2][0] = c[2];op[2][0] = 1;
    cost[2][1] = c[2]+c[0];op[2][1] = 2;
    cost[2][2] = 0;op[2][2] = 0;

    for (int i = 0;i < n;i++)
    {
        totop[i] = op[a[i]-'a'][b[i]-'a'];
        mc -= cost[a[i]-'a'][b[i]-'a'];
    }
    if (mc < 0) return 0;
    totaa = mc/totaa;

    long long res = 1;

    for (int i = 0;i < n;i++)
        printf("%lld ",totop[i]);
    printf("\n");
    cout << res << ' ' << totaa << ' ' << n << endl;

    return (int)res;
}

//Powered by [KawigiEdit] 2.0!
double test0() {
	string p0 = "a";
	string p1 = "b";
	int t2[] = {100,2,3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 205;
	ConversionMachine * obj = new ConversionMachine();
	clock_t start = clock();
	int my_answer = obj->countAll(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string p0 = "abcba";
	string p1 = "abcba";
	int t2[] = {67,23,43};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 0;
	ConversionMachine * obj = new ConversionMachine();
	clock_t start = clock();
	int my_answer = obj->countAll(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string p0 = "cccccccc";
	string p1 = "aaaaaaaa";
	int t2[] = {10000000,1,1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 100;
	ConversionMachine * obj = new ConversionMachine();
	clock_t start = clock();
	int my_answer = obj->countAll(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 40320;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string p0 = "aa";
	string p1 = "cc";
	int t2[] = {1,10,100};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 1787;
	ConversionMachine * obj = new ConversionMachine();
	clock_t start = clock();
	int my_answer = obj->countAll(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 123611681;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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
