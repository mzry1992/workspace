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

class RectangleArea {
public:
	int minimumQueries(vector <string>);
};

bool g[60][60];
int mx,my,mval;

int RectangleArea::minimumQueries(vector <string> known) {
    int n,m;
    n = known.size();
    m = known[0].size();
    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
            if (known[i][j] == 'N')
                g[i][j] = false;
            else
                g[i][j] = true;
    int res = 0;
    while (true)
    {
        for (int i = 0;i < m;i++)
            for (int j = 0;j < n;j++)
                if (g[j][i] == true)
                    for (int k = 0;k < n;k++)
                        if (g[k][i] == true)
                            for (int q = 0;q < m;q++)
                                if (g[j][q] == true)
                                    g[k][q] = true;
        bool flag = false;
        mval = -1;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                if (g[i][j] == false)
                {
                    flag = true;
                    int val = 0;
                    for (int k = 0;k < n;k++)
                        for (int q = 0;q < m;q++)
                            if (g[k][q] == false)
                                if (g[k][j] == true && g[i][q] == true) val++;
                    if (val > mval)
                    {
                        mval = val;
                        mx = i;
                        my = j;
                    }
                }
        if (flag == false)  break;
        g[mx][my] = true;
        res++;
    }
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string t0[] = {"NN",
 "NN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RectangleArea * obj = new RectangleArea();
	clock_t start = clock();
	int my_answer = obj->minimumQueries(p0);
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
double test1() {
	string t0[] = {"YNY",
 "NYN",
 "YNY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RectangleArea * obj = new RectangleArea();
	clock_t start = clock();
	int my_answer = obj->minimumQueries(p0);
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
	string t0[] = {"YY",
 "YY",
 "YY",
 "YY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RectangleArea * obj = new RectangleArea();
	clock_t start = clock();
	int my_answer = obj->minimumQueries(p0);
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
double test3() {
	string t0[] = {"NNNNNNNNNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RectangleArea * obj = new RectangleArea();
	clock_t start = clock();
	int my_answer = obj->minimumQueries(p0);
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
double test4() {
	string t0[] = {"NNYYYNN",
 "NNNNNYN",
 "YYNNNNY",
 "NNNYNNN",
 "YYNNNNY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RectangleArea * obj = new RectangleArea();
	clock_t start = clock();
	int my_answer = obj->minimumQueries(p0);
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
