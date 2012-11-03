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

class OrderedSuperString {
public:
	int getLength(vector <string>);
};

int OrderedSuperString::getLength(vector <string> words) {
    int n = words.size();
    string res = words[0];
    int pre = 0;
    for (int i = 1;i < n;i++)
    {
        int pos = res.size();
        for (int j = pre;j < res.size();j++)
        if (res.size()-j <= words[i].size())
        {
            if (res.substr(j,res.size()-j) == words[i].substr(0,res.size()-j))
            {
                pos = j;
                break;
            }
        }
        else
        {
            if (res.substr(j,words[i].size()) == words[i])
            {
                pos = j;
                break;
            }
        }
        if (res.size()-pos <= words[i].size())
            res = res+words[i].substr(res.size()-pos,words[i].size()-(res.size()-pos));
        pre = pos;
    }
    return res.size();
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string t0[] = {"abc","ca"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	OrderedSuperString * obj = new OrderedSuperString();
	clock_t start = clock();
	int my_answer = obj->getLength(p0);
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
double test1() {
	string t0[] = {"a","a","b","a"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	OrderedSuperString * obj = new OrderedSuperString();
	clock_t start = clock();
	int my_answer = obj->getLength(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
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
	string t0[] = {"abcdef", "ab","bc", "de","ef"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	OrderedSuperString * obj = new OrderedSuperString();
	clock_t start = clock();
	int my_answer = obj->getLength(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 6;
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
	string t0[] = {"ab","bc", "de","ef","abcdef"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	OrderedSuperString * obj = new OrderedSuperString();
	clock_t start = clock();
	int my_answer = obj->getLength(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 12;
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
