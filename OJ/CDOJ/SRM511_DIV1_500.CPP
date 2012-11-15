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

class FiveHundredEleven {
public:
	string theWinner(vector <int>);
};

string FiveHundredEleven::theWinner(vector <int> cards) {
    int n = cards.size();
    int res = 0,tmp = 0;
    for (int i = 0;i < n;i++)
        res = res | cards[i];
    tmp = cards[0];
    for (int i = 1;i < n;i++)
        tmp = tmp & cards[i];
    int tot = 0;
    for (int i = 0;i < n;i++)
        for (int j = i+1;j < n;j++)
            if (((cards[i] | cards[j]) == cards[i]) || ((cards[i] | cards[j]) == cards[j]))
                tot++;
    cout << n << ' ' << res << ' ' << tmp << ' ' << tot << endl;
    if (res != 511)
    {
        if (n%2 == 1)   return "Fox Ciel";
        else return "Toastman";
    }
    return "fuck";
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int t0[] = {1,2,510};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FiveHundredEleven * obj = new FiveHundredEleven();
	clock_t start = clock();
	string my_answer = obj->theWinner(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Fox Ciel";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {0, 0, 0, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FiveHundredEleven * obj = new FiveHundredEleven();
	clock_t start = clock();
	string my_answer = obj->theWinner(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Toastman";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {511};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FiveHundredEleven * obj = new FiveHundredEleven();
	clock_t start = clock();
	string my_answer = obj->theWinner(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Toastman";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {5, 58, 192, 256};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FiveHundredEleven * obj = new FiveHundredEleven();
	clock_t start = clock();
	string my_answer = obj->theWinner(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Fox Ciel";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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

