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

class AkariDaisukiDiv1 {
public:
	int countF(string, string, string, string, string, int);
};

string A,B,C,X,Y,T;
const int mod = 1000000007;

int Calc(int dep)
{
	int res = 0;
	return 0;
	res = ((res+Calc(dep-1))%mod+Calc(dep-1))%mod;
}

int AkariDaisukiDiv1::countF(string Waai, string Akari, string Daisuki, string S, string F, int k) {
	A = Waai;
	B = Akari;
	C = Daisuki;
	X = S;
	Y = F;
	T = X;
	while (T.length() <= Y.length())
		T = A+X+B+X+C;
	cout << T << endl;
	return Calc(k);
}


double test0() {
	string p0 = "a";
	string p1 = "b";
	string p2 = "c";
	string p3 = "x";
	string p4 = "axb";
	int p5 = 2;
	AkariDaisukiDiv1 * obj = new AkariDaisukiDiv1();
	clock_t start = clock();
	int my_answer = obj->countF(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 2;
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
	string p0 = "a";
	string p1 = "b";
	string p2 = "c";
	string p3 = "x";
	string p4 = "abcdefghij";
	int p5 = 1;
	AkariDaisukiDiv1 * obj = new AkariDaisukiDiv1();
	clock_t start = clock();
	int my_answer = obj->countF(p0, p1, p2, p3, p4, p5);
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
double test2() {
	string p0 = "a";
	string p1 = "a";
	string p2 = "a";
	string p3 = "b";
	string p4 = "aba";
	int p5 = 2;
	AkariDaisukiDiv1 * obj = new AkariDaisukiDiv1();
	clock_t start = clock();
	int my_answer = obj->countF(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 4;
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
	string p0 = "a";
	string p1 = "b";
	string p2 = "c";
	string p3 = "d";
	string p4 = "baadbdcbadbdccccbaaaadbdcbadbdccbaadbdcba";
	int p5 = 58;
	AkariDaisukiDiv1 * obj = new AkariDaisukiDiv1();
	clock_t start = clock();
	int my_answer = obj->countF(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 191690599;
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
	string p0 = "a";
	string p1 = "x";
	string p2 = "y";
	string p3 = "b";
	string p4 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	int p5 = 49;
	AkariDaisukiDiv1 * obj = new AkariDaisukiDiv1();
	clock_t start = clock();
	int my_answer = obj->countF(p0, p1, p2, p3, p4, p5);
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
double test5() {
	string p0 = "waai";
	string p1 = "akari";
	string p2 = "daisuki";
	string p3 = "usushio";
	string p4 = "id";
	int p5 = 10000000;
	AkariDaisukiDiv1 * obj = new AkariDaisukiDiv1();
	clock_t start = clock();
	int my_answer = obj->countF(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 127859200;
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
double test6() {
	string p0 = "vfsebgjfyfgerkqlr";
	string p1 = "ezbiwls";
	string p2 = "kjerx";
	string p3 = "jbmjvaawoxycfndukrjfg";
	string p4 = "bgjfyfgerkqlrvfsebgjfyfgerkqlrvfsebgjfyfgerkqlrvfs";
	int p5 = 1575724;
	AkariDaisukiDiv1 * obj = new AkariDaisukiDiv1();
	clock_t start = clock();
	int my_answer = obj->countF(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 483599313;
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
	
	time = test6();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
