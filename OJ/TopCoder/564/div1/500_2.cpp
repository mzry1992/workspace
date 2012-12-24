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

class AlternateColors2 {
public:
	long long countWays(int, int);
};

//r > 0 && g > 0
long long count0(int n,int k) // r == g
{
    return n%2 == 0 && k%2 == 1;
}
long long count1(int n,int k) // r < g
{
    if (k%2 == 0 || k*2 >= n)
        return 0;
    return (n-1)/2-(k+1)/2+1;
}
long long count2(int n,int k) // r > g
{
    long long res = count1(n,k);
    res += (k+1)/2-1;
    return res;
}
long long count30(int n,int k)
{
    return n%3 == 0 && k%3 == 1;
}
long long count1(int a,int b,int c,int n,int k)
{
    if (a == 0)
    {
        long long res = 0;
        if (k%3 != 1 || k*3 >= n)
        {
        }
        else
            res += (n-1)/3-(k+2)/3+1;
        res += (k+2)/3-1;
    }
    else
    {
        long long res = 0;
        for (int tk = 1;3*tk < n;tk++)
            if ((n-3*tk)%2 == 0)
            {
                if (tk >= k)
                    res++;
                else
                    res += count0(n-3*tk,k-tk);
            }
        return res;
    }
}
long long count2(int a,int b,int c,int n,int k)
{
    if (a == 0)
    {
        if (k%3 != 1 || k*3 >= n)   return 0;
        return (n-1)/3-k+1;
    }
    else
    {
        long long res = 0;
        for (int tk = 1;3*tk < n;tk++)
        {
            // n-3*tk
            // k-tk

            if (tk >= k)
            {
                res += (n-3*tk-1)/2;
            }
            else
            {
                if (b == 0)
                    res += count2(n-3*tk,k-tk);
                else
                    res += count1(n-3*tk,k-tk);
            }
        }
        return res;
    }
}
int _a[3];
long long AlternateColors2::countWays(int n, int k) {
    int cnt = 0;
    for (int n3 = 0;n3*3  <= k;n3++)
        for (int n2 = 0;n3*3+n2*2 <= k;n2++)
            cnt++;
    return cnt;
    long long res = 1;
    res += 2*(count0(n,k)+count1(n,k)+count2(n,k));

    res += count30(n,k);
    res += count1(0,1,2,n,k);
    res += count1(1,0,2,n,k);
    res += count1(2,0,1,n,k);
    for (int i = 0;i < 3;i++)
        _a[i] = i;
    do
    {
        res += count2(_a[0],_a[1],_a[2],n,k);
    }while (next_permutation(_a,_a+3));
    return res;
}

//Powered by [KawigiEdit] 2.0!
double test0() {
	int p0 = 1;
	int p1 = 1;
	AlternateColors2 * obj = new AlternateColors2();
	clock_t start = clock();
	long long my_answer = obj->countWays(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 1LL;
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
	int p0 = 3;
	int p1 = 3;
	AlternateColors2 * obj = new AlternateColors2();
	clock_t start = clock();
	long long my_answer = obj->countWays(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 3LL;
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
	int p0 = 6;
	int p1 = 4;
	AlternateColors2 * obj = new AlternateColors2();
	clock_t start = clock();
	long long my_answer = obj->countWays(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 9LL;
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
	AlternateColors2 * obj = new AlternateColors2();
	clock_t start = clock();
	long long my_answer = obj->countWays(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 21LL;
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
	int p0 = 1000;
	int p1 = 2;
	AlternateColors2 * obj = new AlternateColors2();
	clock_t start = clock();
	long long my_answer = obj->countWays(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 1LL;
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
	int p0 = 100000;
	int p1 = 100000;
	AlternateColors2 * obj = new AlternateColors2();
	clock_t start = clock();
	long long my_answer = obj->countWays(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 1666700000LL;
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
