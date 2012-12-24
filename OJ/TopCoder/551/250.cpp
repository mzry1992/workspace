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

class ColorfulChocolates {
public:
	int maximumSpread(string, int);
};

int ColorfulChocolates::maximumSpread(string c, int ms) {
    int n = c.size(),res = 1;
    vector<int> cnow,coth,pos;
    for (int i = 0;i < n;i++)
        for (int j = i+1;j < n;j++)
            if (c[i] == c[j])
            {
                cnow.clear(),coth.clear();
                for (int k = i;k <= j;k++)
                    if (c[k] == c[i])
                        cnow.push_back(k-i);
                    else
                        coth.push_back(k-i);
                for (int k = 0;k <= coth.size();k++)
                {
                    pos.clear();
                    for (int q = 0;q < k;q++)
                        pos.push_back(coth[q]);
                    for (int q = 0;q < cnow.size();q++)
                        pos.push_back(cnow[q]);
                    for (int q = k;q < coth.size();q++)
                        pos.push_back(coth[q]);
                    int cnt = 0;
                    for (int x = 0;x < pos.size();x++)
                        for (int y = x+1;y < pos.size();y++)
                            if (pos[x] > pos[y])
                                cnt++;
                    if (cnt <= ms)
                        res = max(res,(int)cnow.size());
                }
            }
    return res;
}

//Powered by [KawigiEdit] 2.0!
double test0() {
	string p0 = "ABCDCBC";
	int p1 = 1;
	ColorfulChocolates * obj = new ColorfulChocolates();
	clock_t start = clock();
	int my_answer = obj->maximumSpread(p0, p1);
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
	string p0 = "ABCDCBC";
	int p1 = 2;
	ColorfulChocolates * obj = new ColorfulChocolates();
	clock_t start = clock();
	int my_answer = obj->maximumSpread(p0, p1);
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
double test2() {
	string p0 = "ABBABABBA";
	int p1 = 3;
	ColorfulChocolates * obj = new ColorfulChocolates();
	clock_t start = clock();
	int my_answer = obj->maximumSpread(p0, p1);
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
double test3() {
	string p0 = "ABBABABBA";
	int p1 = 4;
	ColorfulChocolates * obj = new ColorfulChocolates();
	clock_t start = clock();
	int my_answer = obj->maximumSpread(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 5;
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
	string p0 = "QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO";
	int p1 = 77;
	ColorfulChocolates * obj = new ColorfulChocolates();
	clock_t start = clock();
	int my_answer = obj->maximumSpread(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 5;
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
