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

class SRMCodingPhase {
public:
	int countScore(vector <int>, vector <int>, int);
};

int SRMCodingPhase::countScore(vector <int> points, vector <int> skills, int luck) {
    int res = 0,tres;
    for (int wdo = 0;wdo < (1<<3);wdo++)
        for (int i = 0;i <= luck;i++)
            for (int j = 0;i+j <= luck;j++)
                for (int k = 0;i+j+k <= luck;k++)
                {
                    if (skills[0]-i <= 0)   continue;
                    if (skills[1]-j <= 0)   continue;
                    if (skills[2]-k <= 0)   continue;
                    int ct = 0;
                    if (((wdo>>0)&1) == 1)  ct += skills[0]-i;
                    if (((wdo>>1)&1) == 1)  ct += skills[1]-j;
                    if (((wdo>>2)&1) == 1)  ct += skills[2]-k;
                    if (ct > 75)    continue;
                    tres = 0;
                    if (((wdo>>0)&1) == 1)  tres += points[0]-2*(skills[0]-i);
                    if (((wdo>>1)&1) == 1)  tres += points[1]-4*(skills[1]-j);
                    if (((wdo>>2)&1) == 1)  tres += points[2]-8*(skills[2]-k);
                    res = max(res,tres);
                }
    return res;
}

//Powered by [KawigiEdit] 2.0!
double test0() {
	int t0[] = {250, 500, 1000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10, 25, 40};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 0;
	SRMCodingPhase * obj = new SRMCodingPhase();
	clock_t start = clock();
	int my_answer = obj->countScore(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1310;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {300, 600, 900};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {30, 65, 90};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 25;
	SRMCodingPhase * obj = new SRMCodingPhase();
	clock_t start = clock();
	int my_answer = obj->countScore(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 680;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {250, 550, 950};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10, 25, 40};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 75;
	SRMCodingPhase * obj = new SRMCodingPhase();
	clock_t start = clock();
	int my_answer = obj->countScore(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1736;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {256, 512, 1024};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {35, 30, 25};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 0;
	SRMCodingPhase * obj = new SRMCodingPhase();
	clock_t start = clock();
	int my_answer = obj->countScore(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1216;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {300, 600, 1100};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {80, 90, 100};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 4;
	SRMCodingPhase * obj = new SRMCodingPhase();
	clock_t start = clock();
	int my_answer = obj->countScore(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
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
