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

class Zoo {
public:
	long long theCount(vector <int>);
};

long long Zoo::theCount(vector <int> a) {
    sort(a.begin(),a.end());
    int n = a.size();
    for (int i = 0;i < n;i++)
        if (a[i] >= n)  return 0;
    int tz = 0;
    for (int i = 0;i < n;i++)
        if (a[i] == 0)  tz++;
    if (tz >= 3)    return 0;
    if (tz == 0)    return 0;
    if (tz == 1)
    {
        for (int i = 0;i < n;i++)
            if (a[i] != i)  return 0;
        return 2;
    }
    for (int i = 0;i < n;i++)
    {
        int tot = 0;
        for (int j = 0;j < n;j++)
            if (a[j] == i)  tot++;
        if (tot > 2)    return 0;
    }
    for (int i = 0;i < n;i++)
    {
        int tot = 0;
        for (int j = 0;j < n;j++)
            if (a[j] == i)  tot++;
        if (tot == 0)
        {
            for (int k = i+1;k < n;k++)
            {
                int ttot = 0;
                for (int j = 0;j < n;j++)
                    if (a[j] == k)  ttot++;
                if (ttot != 0)  return 0;
            }
            return (1LL<<(i));
        }
        if (tot == 1)
        {
            int premax = 1;
            for (int k = i+1;k < n;k++)
            {
                int ttot = 0;
                for (int j = 0;j < n;j++)
                    if (a[j] == k)  ttot++;
                if (ttot > premax)  return 0;
                premax = ttot;
            }
            return (1LL<<(i+1));
        }
    }
    return (1LL<<(n));
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int t0[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Zoo * obj = new Zoo();
	clock_t start = clock();
	long long my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 2LL;
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
	int t0[] = {0,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Zoo * obj = new Zoo();
	clock_t start = clock();
	long long my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 0LL;
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
	int t0[] = {0, 0, 0, 0, 0, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Zoo * obj = new Zoo();
	clock_t start = clock();
	long long my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 0LL;
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
	int t0[] = {1, 0, 2, 0, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Zoo * obj = new Zoo();
	clock_t start = clock();
	long long my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 8LL;
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
double test4() {
	int t0[] = {1, 0, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Zoo * obj = new Zoo();
	clock_t start = clock();
	long long my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 0LL;
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

	time = test4();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
