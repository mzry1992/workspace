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

class ToastXToast {
public:
	int bake(vector <int>, vector <int>);
};

int pos[100];

int ToastXToast::bake(vector <int> undertoasted, vector <int> overtoasted) {
    int n,m;
    n = undertoasted.size();
    m = overtoasted.size();
    sort(undertoasted.begin(),undertoasted.end());
    sort(overtoasted.begin(),overtoasted.end());
    if (overtoasted[0] <= undertoasted[0])  return -1;
    if (overtoasted[0] > undertoasted[n-1]) return 1;
    int res = 0;
    int cur = 0;
    for (int i = 0;i < m;i++)
    {
        pos[i] = n-1;
        for (int j = 0;j < n;j++)
        if (undertoasted[j] >= overtoasted[i])
        {
            pos[i] = j-1;
            break;
        }
    }
    if (pos[0] == -1)   return -1;
    if (pos[m-1] != n-1)    return -1;
    return 2;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int t0[] = {2,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {5,6,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ToastXToast * obj = new ToastXToast();
	clock_t start = clock();
	int my_answer = obj->bake(p0, p1);
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
double test1() {
	int t0[] = {5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ToastXToast * obj = new ToastXToast();
	clock_t start = clock();
	int my_answer = obj->bake(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
	int t0[] = {1,2,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {5,6,7};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ToastXToast * obj = new ToastXToast();
	clock_t start = clock();
	int my_answer = obj->bake(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1;
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
	int t0[] = {1,3,5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,4,6};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ToastXToast * obj = new ToastXToast();
	clock_t start = clock();
	int my_answer = obj->bake(p0, p1);
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
