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

class DivideAndShift {
public:
	int getLeast(int, int);
};

int prime[100000],tot;
bool isprime[1000000];

void getprime()
{
     tot = 0;
     memset(isprime,true,sizeof(isprime));
     for (int i = 2;i <= 1000000;i++)
     {
         if (isprime[i] == true)
         {
                        tot++;
                        prime[tot] = i;
         }
         for (int j = 1;j <= tot && i*prime[j] <= 1000000;j++)
         {
             isprime[i*prime[j]] = false;
             if (i%prime[j] == 0) break;
         }
     }
}

int fac[1000],tfac[1000],factot,res;

int calc(int m,int now)
{
    int tm = m%now;
    if (tm == 0) tm = now;
    return min(tm-1,now-tm+1);
}

void DFS(int m,int facnow,int now,int step)
{
    //cout << (m%now+step) << ' ' << m << ' ' << now << ' ' << step << endl;
    if (calc(m,now)+step < res)   res = calc(m,now)+step;
    if (facnow > factot)    return;
    int mypow = 1;
    for (int i = 1;i <= tfac[facnow];i++)
    {
        mypow *= fac[facnow];
        DFS(m,facnow+1,now/mypow,step+i);
    }
}

int DivideAndShift::getLeast(int n, int m) {
    getprime();
    factot = 0;
    int tn = n;
    for (int i = 1;prime[i] <= n;i++)
        if (n%prime[i] == 0)
        {
            factot++;
            tfac[factot] = 0;
            fac[factot] = prime[i];
            while (n%prime[i] == 0)
            {
                tfac[factot]++;
                n /= prime[i];
            }
        }
    n = tn;
    for (int i = 1;i <= factot;i++) cout << fac[i] << ' ' << tfac[i] << endl;
    res = 19921005;
    DFS(m,1,n,0);
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int p0 = 786432;
	int p1 = 24606;
	DivideAndShift * obj = new DivideAndShift();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	int p0 = 49;
	int p1 = 5;
	DivideAndShift * obj = new DivideAndShift();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	int p0 = 256;
	int p1 = 7;
	DivideAndShift * obj = new DivideAndShift();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
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
	int p0 = 6;
	int p1 = 1;
	DivideAndShift * obj = new DivideAndShift();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
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
	int p0 = 77777;
	int p1 = 11111;
	DivideAndShift * obj = new DivideAndShift();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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

