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

class TwoRegisters {
public:
	string minProg(int);
};

int f[100];

string TwoRegisters::minProg(int r) {
    string res = "",tres;
    bool hasres,nowx;
    if (r == 1) return "";
    int x,y,nx,ny;
    for (int i = r/2;i >= 1;i--)
    {
        x = i;
        y = r-x;
        tres = "X";
        hasres = false;
        nowx = false;
        int step = 1;
        while (true)
        {
            if (x != 1 && y%x == 0) break;
            if (x == 1 && y == 1)
            {
                hasres = true;
                break;
            }
            if (x == 1)
            {
                if (y+step > res.size())    break;
            }
            if (nowx == true)  tres = "X"+tres;
            else tres = "Y"+tres;
            step++;
            if (step > res.size())  break;
            nx = x;
            ny = y-x;
            if (nx > ny)
            {
                swap(nx,ny);
                if (nowx == true)   nowx = false;
                else nowx = true;
            }
            x = nx;
            y = ny;
        }
        if (hasres == true)
        {
            if (tres[0] == 'Y')
                for (int i = 0;i < tres.size()-1;i++)
                    if (tres[i] == 'Y') tres[i] = 'X';
                    else tres[i] = 'Y';
            if (tres.size() < res.size()) res = tres;
            else if (tres.size() == res.size() && tres < res)   res = tres;
            cout << res << ' ' << tres << ' ' << i << endl;
        }
    }
    if (res.size() == r)    return "";
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int p0 = 10;
	TwoRegisters * obj = new TwoRegisters();
	clock_t start = clock();
	string my_answer = obj->minProg(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "XXYYX";
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
	int p0 = 3;
	TwoRegisters * obj = new TwoRegisters();
	clock_t start = clock();
	string my_answer = obj->minProg(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "XX";
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
	int p0 = 20;
	TwoRegisters * obj = new TwoRegisters();
	clock_t start = clock();
	string my_answer = obj->minProg(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "XYYYYXX";
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
	int p0 = 34;
	TwoRegisters * obj = new TwoRegisters();
	clock_t start = clock();
	string my_answer = obj->minProg(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "XYXYXYX";
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
