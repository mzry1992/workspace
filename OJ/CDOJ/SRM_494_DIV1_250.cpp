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

class Painting {
public:
	int largestBrush(vector <string>);
};

int Painting::largestBrush(vector <string> picture) {
    int n,m;
    n = picture.size();
    m = picture[0].size();
    int res = 19930703;
    bool flag = false;
    for (int i = 0;i < n;i++)
    for (int j = 0;j < m;j++)
    if (picture[i][j] == 'W')
    {
        flag = true;
        int tres = 19930703;
        bool tflag = false;
        if (i > 0)
        if (picture[i-1][j] != 'W')
        {
            tflag = true;
            int x = -1;
            for (int k = 0;k < i;k++)
            if (picture[k][j] == 'W')
                x = k;
            if (tres > i-x-1)
                tres = i-x-1;
        }
        if (j > 0)
        if (picture[i][j-1] != 'W')
        {
            tflag = true;
            int x = -1;
            for (int k = 0;k < j;k++)
            if (picture[i][k] == 'W')
                x = k;
            if (tres > j-x-1)
                tres = j-x-1;
        }
        if (i < n-1)
        if (picture[i+1][j] != 'W')
        {
            tflag = true;
            int x = n;
            for (int k = n-1;k > i;k--)
            if (picture[k][j] == 'W')
                x = k;
            if (tres > x-i-1)
                tres = x-i-1;
        }
        if (j < m-1)
        if (picture[i][j+1] != 'W')
        {
            tflag = true;
            int x = m;
            for (int k = m;k > j;k--)
            if (picture[i][k] == 'W')
                x = k;
            if (tres > x-j-1)
                tres = x-j-1;
        }
        if (tflag == true)
        if (res > tres) res = tres;
    }
    if (flag == true)
        return res;
    else
        return (n>m?m:n);
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string t0[] = {"BBBB",
 "BBBB",
 "BBBB",
 "BBBB"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Painting * obj = new Painting();
	clock_t start = clock();
	int my_answer = obj->largestBrush(p0);
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
	string t0[] = {"BBBB",
 "BWWB",
 "BWWB",
 "BBBB"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Painting * obj = new Painting();
	clock_t start = clock();
	int my_answer = obj->largestBrush(p0);
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
	string t0[] = {"WBBBBB",
 "BBBBBB",
 "BBBBBB",
 "BBBBBB"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Painting * obj = new Painting();
	clock_t start = clock();
	int my_answer = obj->largestBrush(p0);
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
double test3() {
	string t0[] = {"BBBB",
 "BBBB",
 "WBBB",
 "BBBB",
 "BBBB",
 "BBBB"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Painting * obj = new Painting();
	clock_t start = clock();
	int my_answer = obj->largestBrush(p0);
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
double test4() {
	string t0[] = {"WBBBBBWWWWWWWWW",
 "WBBBBBBWWWWWWWW",
 "WBBBBBBBBBBBWWW",
 "WBBBBBBBBBBBWWW",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBWWBBBBB",
 "BBBBBBBBWBBBBBB",
 "WBBBBBBBWBBBBBW",
 "BBBBBBBWWBBBBBW",
 "BBBBBBBWWBBBBBW",
 "BBBBBBWWWBBBBBW",
 "BBBBBWWWWWWWWWW",
 "BBBBBWWWWWWWWWW"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Painting * obj = new Painting();
	clock_t start = clock();
	int my_answer = obj->largestBrush(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 5;
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

