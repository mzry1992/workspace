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

class YetAnotherIncredibleMachine {
public:
	int countWays(vector <int>, vector <int>, vector <int>);
};

const long long mod = 1000000009LL;

int YetAnotherIncredibleMachine::countWays(vector <int> platformMount, vector <int> platformLength, vector <int> balls) {
    int n = platformMount.size();
    int m = balls.size();
    sort(balls.begin(),balls.end());
    long long res = 1;
    int lm,rm;
    for (int i = 0;i < n;i++)
    {
        bool check = false;
        lm = platformMount[i]-platformLength[i];
        rm = min(platformMount[i]+platformLength[i],balls[0]-1);
        if (rm-lm+1 >= platformLength[i])
        {
            res = (res*(rm-lm+1-platformLength[i]))%mod;
            check = true;
        }
        for (int j = 0;j < m-1;j++)
        {
            lm = max(platformMount[i]-platformLength[i],balls[j]+1);
            rm = min(platformMount[i]+platformLength[i],balls[j+1]-1);
            if (rm-lm+1 >= platformLength[i])
            {
                res = (res*(rm-lm+1-platformLength[i]))%mod;
                check = true;
            }
        }
        lm = max(platformMount[i]-platformLength[i],balls[m-1]+1);
        rm = platformMount[i]+platformLength[i];
        if (rm-lm+1 >= platformLength[i])
        {
            res = (res*(rm-lm+1-platformLength[i]))%mod;
            check = true;
        }
        if (check == false) return 0;
    }
    return (int)res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int t0[] = {7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {3,4};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	YetAnotherIncredibleMachine * obj = new YetAnotherIncredibleMachine();
	clock_t start = clock();
	int my_answer = obj->countWays(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 3;
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
	int t0[] = {1,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {3,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,7};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	YetAnotherIncredibleMachine * obj = new YetAnotherIncredibleMachine();
	clock_t start = clock();
	int my_answer = obj->countWays(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
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
	int t0[] = {4,4,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10,9,8};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1,100};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	YetAnotherIncredibleMachine * obj = new YetAnotherIncredibleMachine();
	clock_t start = clock();
	int my_answer = obj->countWays(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 27;
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
	int t0[] = {0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {0};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	YetAnotherIncredibleMachine * obj = new YetAnotherIncredibleMachine();
	clock_t start = clock();
	int my_answer = obj->countWays(p0, p1, p2);
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
double test4() {
	int t0[] = {100, -4215, 251};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {400, 10000, 2121};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {5000, 2270, 8512, 6122};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	YetAnotherIncredibleMachine * obj = new YetAnotherIncredibleMachine();
	clock_t start = clock();
	int my_answer = obj->countWays(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 250379170;
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
