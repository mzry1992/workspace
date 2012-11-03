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

class ColoredStrokes {
public:
	int getLeast(vector <string>);
};

int ColoredStrokes::getLeast(vector <string> picture) {
    int n,m;
    n = picture.size();
    m = picture[0].size();
    int res = 0;
    for (int i = 0;i < m;i++)
    {
        bool pre = false;
        for (int j = 0;j < n;j++)
        if (pre == true)
        {
            if (picture[j][i] == 'R' || picture[j][i] == '.')\
                pre = false;
        }
        else
        {
            if (picture[j][i] == 'B' || picture[j][i] == 'G')
            {
                pre = true;
                res++;
            }
        }
    }
    for (int i = 0;i < n;i++)
    {
        bool pre = false;
        for (int j = 0;j < m;j++)
        if (pre == true)
        {
            if (picture[i][j] == 'B' || picture[i][j] == '.')\
                pre = false;
        }
        else
        {
            if (picture[i][j] == 'R' || picture[i][j] == 'G')
            {
                pre = true;
                res++;
            }
        }
    }
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string t0[] = {"...",
 "..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ColoredStrokes * obj = new ColoredStrokes();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
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
	string t0[] = {"..B.",
 "..B."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ColoredStrokes * obj = new ColoredStrokes();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0);
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
double test2() {
	string t0[] = {".BB."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ColoredStrokes * obj = new ColoredStrokes();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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
	string t0[] = {"...B..",
 ".BRGRR",
 ".B.B.."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ColoredStrokes * obj = new ColoredStrokes();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0);
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
double test4() {
	string t0[] = {"...B..",
 ".BRBRR",
 ".B.B.."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ColoredStrokes * obj = new ColoredStrokes();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0);
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
double test5() {
	string t0[] = {"GR",
 "BG"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ColoredStrokes * obj = new ColoredStrokes();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0);
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
