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

class AlgridTwo {
public:
	int makeProgram(vector <string>);
};

const long long mod = 1000000007LL;
int AlgridTwo::makeProgram(vector <string> output) {
    int h = output.size();
    int w = output[0].size();
    for (int i = h-1;i >= 1;i--)
    for (int j = w-1;j >= 1;j--)
    {
        char A,B;
        A = output[i-1][j];
        B = output[i-1][j-1];
        if (A == 'W' && B == 'W')   continue;
        else if (A == 'W' && B == 'B')
        {
            if (output[i][j] == 'W' || output[i][j-1] == 'W')
                output[i][j] = output[i][j-1] = 'N';
            else
                output[i][j] = output[i][j-1] = 'U';
        }
        else if (A == 'B' && B == 'W')
        {
            if (output[i][j] == 'B' || output[i][j-1] == 'B')
                output[i][j] = output[i][j-1] = 'N';
            else
                output[i][j] = output[i][j-1] = 'U';
        }
        else
        {
            char temp = output[i][j];
            output[i][j] = output[i][j-1];
            output[i][j-1] = temp;
        }
    }
    long long res = 1;
    for (int i = 0;i < h;i++)
    for (int j = 0;j < w;j++)
    {
        if (output[i][j] == 'W' || output[i][j] == 'B') continue;
        if (output[i][j] == 'N')    res = 0;
        if (output[i][j] == 'U')
        {
            res = (res%mod*2)%mod;
        }
    }
    return (int)res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string t0[] = {"BB",
 "WB"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	AlgridTwo * obj = new AlgridTwo();
	clock_t start = clock();
	int my_answer = obj->makeProgram(p0);
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
double test1() {
	string t0[] = {"BBWBBB",
 "WBWBBW"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	AlgridTwo * obj = new AlgridTwo();
	clock_t start = clock();
	int my_answer = obj->makeProgram(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 8;
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
	string t0[] = {"BWBWBW",
 "WWWWWW",
 "WBBWBW"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	AlgridTwo * obj = new AlgridTwo();
	clock_t start = clock();
	int my_answer = obj->makeProgram(p0);
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
	string t0[] = {"WWBWBWBWBWBWBWBW",
 "BWBWBWBWBWBWBWBB",
 "BWBWBWBWBWBWBWBW"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	AlgridTwo * obj = new AlgridTwo();
	clock_t start = clock();
	int my_answer = obj->makeProgram(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 73741817;
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
