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

class SubFibonacci {
public:
	int maxElements(vector <int>);
};

int f[50];
const int maxf = 45;

int calc(vector <int> s,int l,int r)
{
    if (l == r-1)   return 1;
    int res = 2;
    for (int i = l;i < r;i++)
        for (int j = i+1;j < r;j++)
            for (int k = 0;k < 44;k++)
                if ((long long)f[k]*(long long)s[i]+(long long)f[k+1] <= (long long)s[j])
                    if ((s[j]-f[k]*s[i])%f[k+1] == 0)
                    {
                        int a = s[i];
                        int b = (s[j]-f[k]*s[i])/f[k+1];
                        int c;
                        int tres = 1;
                        if (b > a)
                            for (int q = l;q < r;q++)
                                if (s[q] == b)
                                    tres++;
                        while (true)
                        {
                            c = a+b;
                            a = b;
                            b = c;
                            if (b > s[r-1]) break;
                            for (int q = l;q < r;q++)
                                if (s[q] == b)
                                    tres++;
                        }
                        res = max(res,tres);
                    }
    return res;
}

int SubFibonacci::maxElements(vector <int> s) {
    int n = s.size();
    if (n == 1) return 1;
    f[0] = 0;
    f[1] = 1;
    for (int i = 2;i < 50;i++)
        f[i] = f[i-1]+f[i-2];
    sort(s.begin(),s.end());
    int res = 0;
    for (int mid = 0;mid < n-1;mid++)
        res = max(res,calc(s,0,mid+1)+calc(s,mid+1,n));
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int t0[] = {250000001,
250000000,
500000001,
499999999,
500000000,
750000002,
750000001,
999999999,
1000000000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SubFibonacci * obj = new SubFibonacci();
	clock_t start = clock();
	int my_answer = obj->maxElements(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 7;
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
	int t0[] = {19, 47, 50, 58, 77, 99};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SubFibonacci * obj = new SubFibonacci();
	clock_t start = clock();
	int my_answer = obj->maxElements(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 4;
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
	int t0[] = {512};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SubFibonacci * obj = new SubFibonacci();
	clock_t start = clock();
	int my_answer = obj->maxElements(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
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
	int t0[] = {3, 5, 7, 10, 13, 15, 20, 90};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SubFibonacci * obj = new SubFibonacci();
	clock_t start = clock();
	int my_answer = obj->maxElements(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 7;
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
	int t0[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SubFibonacci * obj = new SubFibonacci();
	clock_t start = clock();
	int my_answer = obj->maxElements(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 10;
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

