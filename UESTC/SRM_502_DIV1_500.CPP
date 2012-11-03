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

class TheProgrammingContestDivOne {
public:
	int find(int, vector <int>, vector <int>, vector <int>);
};

struct problem
{
    long long a;
    long long b;
    long long c;
}p[100];

bool cmp(problem a,problem b)
{
    long long resa,resb;
    resa = (long long)a.b*(long long)b.c;
    resb = (long long)b.b*(long long)a.c;
    return resa > resb;
}

long long dp[120000];

int TheProgrammingContestDivOne::find(int T, vector <int> maxPoints, vector <int> pointsPerMinute, vector <int> requiredTime) {
    int res = 0;
    int n = maxPoints.size();
    for (int i = 0;i < n;i++)
    {
        p[i].a = maxPoints[i];
        p[i].b = pointsPerMinute[i];
        p[i].c = requiredTime[i];
    }
    sort(p,p+n,cmp);
    memset(dp,0,sizeof(dp));
    for (int i = 0;i < n;i++)
    for (int j = T;j >= p[i].c;j--)
    if (p[i].a-p[i].b*j >= 0)
    if (dp[j-p[i].c]+p[i].a-p[i].b*j > dp[j])
    {
        dp[j] = dp[j-p[i].c]+p[i].a-p[i].b*j;
    }
    for (int i = 0;i <= T;i++)
    if (dp[i] > res)    res = dp[i];
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int p0 = 74;
	int t1[] = {502};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {47};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	TheProgrammingContestDivOne * obj = new TheProgrammingContestDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 408;
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
	int p0 = 40000;
	int t1[] = {100000, 100000};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1, 100000};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {50000, 30000};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	TheProgrammingContestDivOne * obj = new TheProgrammingContestDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 0;
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
	int p0 = 75;
	int t1[] = {250, 500, 1000};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2, 4, 8};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {25, 25, 25};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	TheProgrammingContestDivOne * obj = new TheProgrammingContestDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 1200;
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
	int p0 = 30;
	int t1[] = {100, 100, 100000};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1, 1, 100};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {15, 15, 30};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	TheProgrammingContestDivOne * obj = new TheProgrammingContestDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 97000;
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
