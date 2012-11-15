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

class QuickSort {
public:
	double getEval(vector <int>);
};

int Quicksort(vector <int> L)
{
    //cout << L.size() << endl;
    if (L.size() < 2)
        return L.size();
    vector <int> tL,L0,L1;
    tL.resize(L.size());
    for (int i = 0;i < tL.size();i++)
        tL[i] = L[i];
    sort(tL.begin(),tL.end());
    int res = 0;
    int pre = 0;
    for (int tp = 0;tp < tL.size();tp++)
    if (tL[tp] != L[tp])
    {
        int p = tL[tp];
        while (!L0.empty())
            L0.pop_back();
        while (!L1.empty())
            L1.pop_back();
        for (int i = 0;i < L.size();i++)
        if (L[i] != p)
        if (L[i] < p)
            L0.push_back(L[i]);
        else
            L1.push_back(L[i]);
        res += (Quicksort(L0)+p+Quicksort(L1))*(p-pre);
        pre = p;
    }
    return res;
}

double QuickSort::getEval(vector <int> L) {
    double res;
    res = Quicksort(L)*1.0;
    return res/50.0;
}

double test0() {
	int t0[] = {1,2,3,4,5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	QuickSort * obj = new QuickSort();
	clock_t start = clock();
	double my_answer = obj->getEval(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 0.0;
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
	int t0[] = {1,2,4,3,5,6};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	QuickSort * obj = new QuickSort();
	clock_t start = clock();
	double my_answer = obj->getEval(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 1.0;
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
	int t0[] = {3,2,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	QuickSort * obj = new QuickSort();
	clock_t start = clock();
	double my_answer = obj->getEval(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 2.6666666666666665;
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
	int t0[] = {50,40,30,20,10,15,25,35,45};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	QuickSort * obj = new QuickSort();
	clock_t start = clock();
	double my_answer = obj->getEval(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 11.07698412698413;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
