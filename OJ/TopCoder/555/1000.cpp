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

class MapGuessing {
public:
	long long countPatterns(string, vector <string>);
};

long long MapGuessing::countPatterns(string goal, vector <string> code) {
    int len = goal.size();
    string lu;
    for (int i = 0;i < len;i++)
    {
        bool err = false;
        int curpos = i;
        for (int j = 0;j < code.size() && !err;j++)
            for (int k = 0;k < code[j].size() && !err;k++)
            {
                if (code[j][k] == '<')
                    curpos--;
                else if (code[j][k] == '>')
                    curpos++;
                if (curpos < 0 || curpos >= len)
                    err = true;
            }
        if (err)    continue;
    }
    return 0;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string p0 = "000";
	string t1[] = {"0"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	MapGuessing * obj = new MapGuessing();
	clock_t start = clock();
	long long my_answer = obj->countPatterns(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 4LL;
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
	string p0 = "001";
	string t1[] = {"0>1"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	MapGuessing * obj = new MapGuessing();
	clock_t start = clock();
	long long my_answer = obj->countPatterns(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 5LL;
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
	string p0 = "000";
	string t1[] = {"1>1>1"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	MapGuessing * obj = new MapGuessing();
	clock_t start = clock();
	long long my_answer = obj->countPatterns(p0, p1);
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
double test3() {
	string p0 = "11001";
	string t1[] = {">><<<<><<"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	MapGuessing * obj = new MapGuessing();
	clock_t start = clock();
	long long my_answer = obj->countPatterns(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 0LL;
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
	string p0 = "1000101011";
	string t1[] = {"1<<0>>0>1"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	MapGuessing * obj = new MapGuessing();
	clock_t start = clock();
	long long my_answer = obj->countPatterns(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 22LL;
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
	string p0 = "00000010000000000000000000000000";
	string t1[] = {"><>>0<0<>>1>0><>", "<<0>>0<>><0>0>>><><", ">>>0<>", ">0><>>>>0<<><>>0>>>0<0>>0>"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	MapGuessing * obj = new MapGuessing();
	clock_t start = clock();
	long long my_answer = obj->countPatterns(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 13601LL;
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
double test6() {
	string p0 = "11100011010111111010100100110001101";
	string t1[] = {"11111111111111111111"
,"1<><><><><><><><><>1"
,"1<>000>000><0<><0<>1"
,"1<0<><>0><0<00>00<>1"
,"1<>00<>000><0<0<0<>1"
,"1<><>0>0><0<0<><0<>1"
,"1<000<>0><0<0<><0<>1"
,"1<><><><><><><><><>1"
,"1<>000><000<>000><>1"
,"1<>0><><0<><>0><><>1"
,"1<>000><000<>000><>1"
,"1<><>0><><0<><>0><>1"
,"1<>000><000<>000><>1"
,"1<><><><><><><><><>1"
,"11111111111111111111"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	MapGuessing * obj = new MapGuessing();
	clock_t start = clock();
	long long my_answer = obj->countPatterns(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 90LL;
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

	time = test6();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

