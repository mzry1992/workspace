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

class DesignCalendar {
public:
	int shortestPeriod(int, int);
};

bool isprime[100000];
int prime[100000],tot;

void getprime()
{
	memset(isprime,true,sizeof(isprime));
	tot = 0;
	for (int i = 2;i < 100000;i++)
	{
         if (isprime[i] == true)
         	prime[tot++] = i;
         for (int j = 0;j < tot && i*prime[j] < 100000;j++)
         {
             isprime[i*prime[j]] = false;
             if (i%prime[j] == 0) break;
         }
	}
}

int fac[100],ftot[100],totfac;
int year,day;
set<int> res;
set<int>::iterator it;

void Gao(int now,int val)
{
	if (now == totfac)
	{
	    res.insert(val);
		return;
	}
	Gao(now+1,val);
	int vnow = 1;
	for (int i = 0;i < ftot[now];i++)
	{
        vnow *= fac[now];
        Gao(now+1,val*vnow);
	}
}

int DesignCalendar::shortestPeriod(int dayLength, int yearLength) {
	day = dayLength;
	year = yearLength;
	getprime();
	totfac = 0;
	for (int i = 0;i < tot && prime[i]*prime[i] <= dayLength;i++)
		if (dayLength%prime[i] == 0)
		{
			fac[totfac] = prime[i];
			ftot[totfac] = 0;
			while (dayLength%prime[i] == 0)
			{
				dayLength /= prime[i];
				ftot[totfac]++;
			}
			totfac++;
		}
	if (dayLength > 1)
	{
		fac[totfac] = dayLength;
		ftot[totfac++] = 1;
	}
	res.clear();
	Gao(0,1);
	int ans = day,val,q;
    for (it = res.begin();it != res.end();it++)
    {
        val = *it;
        q = day/val;
    }
	return ans;
}

double test0() {
	int p0 = 1073741824;
	int p1 = 1073741824;
	DesignCalendar * obj = new DesignCalendar();
	clock_t start = clock();
	int my_answer = obj->shortestPeriod(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
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
	int p0 = 86400;
	int p1 = 31558150;
	DesignCalendar * obj = new DesignCalendar();
	clock_t start = clock();
	int my_answer = obj->shortestPeriod(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1728;
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
	int p0 = 98;
	int p1 = 100;
	DesignCalendar * obj = new DesignCalendar();
	clock_t start = clock();
	int my_answer = obj->shortestPeriod(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 49;
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
	int p0 = 1000;
	int p1 = 50000100;
	DesignCalendar * obj = new DesignCalendar();
	clock_t start = clock();
	int my_answer = obj->shortestPeriod(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 10;
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
	int p0 = 5673;
	int p1 = 28565335;
	DesignCalendar * obj = new DesignCalendar();
	clock_t start = clock();
	int my_answer = obj->shortestPeriod(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 5673;
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
double test5() {
	int p0 = 5555;
	int p1 = 846555;
	DesignCalendar * obj = new DesignCalendar();
	clock_t start = clock();
	int my_answer = obj->shortestPeriod(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1111;
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

	time = test5();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

