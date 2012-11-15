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

class RoadsAndFools {
public:
	string determineOrientation(int, vector <int>);
};

int a[60][2];
int dp[60][2];

string ss(int a)
{
    string res;
    res = "";
    if (a == 0) return "0";
    while (a > 0)
    {
        res = (char)(a%10+'0')+res;
        a /= 10;
    }
    return res;
}

string RoadsAndFools::determineOrientation(int length, vector <int> frontSides) {
    for (int i = 0;i < frontSides.size();i++)
    {
        a[i+1][0] = frontSides[i];
        a[i+1][1] = length-a[i+1][0];
    }
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2;i <= frontSides.size();i++)
    {
        dp[i][0] = dp[i][1] = 0;
        for (int j = 0;j <= 1;j++)
        {
            for (int k = 0;k <= 1;k++)
            if (a[i][j] > a[i-1][k])
                dp[i][j] += dp[i-1][k];
        }
        if (a[i-1][0]*2 == length)
        {
            dp[i][0] /= 2;
            dp[i][1] /= 2;
        }
    }
    for (int i = 1;i <= frontSides.size();i++)
        cout << dp[i][0] << ' ' << dp[i][1] << ' ' << a[i][0] << ' ' << a[i][1] << endl;
    if (frontSides.size() == 1)
        if (frontSides[0]*2 == length)
        {
            return ss(frontSides[0]);
        }
    int temp = dp[frontSides.size()][0]+dp[frontSides.size()][1];
    if (a[frontSides.size()][0]*2 == length)    temp /= 2;
    if (temp == 0)
        return "NO SOLUTION";
    if (temp > 1)
        return "MULTIPLE SOLUTIONS";
    string res = "";
    int cur;
    if (dp[frontSides.size()][0] == 1)   cur = 0;
    else    cur = 1;
    for (int i = frontSides.size();i >= 1;i--)
    {
        res = ""+ss(a[i][cur])+res;
        if (i > 1)
            res = " "+res;
        if (dp[i-1][0] == 1 && dp[i-1][1] == 0)    cur = 0;
        else if (dp[i-1][0] == 0 && dp[i-1][1] == 1)   cur = 1;
        else
        {
            if (a[i-1][0] < a[i][cur])  cur = 0;
            else
                cur = 1;
        }
    }
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int p0 = 98;
	int t1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	RoadsAndFools * obj = new RoadsAndFools();
	clock_t start = clock();
	string my_answer = obj->determineOrientation(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "1 2 3";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 100;
	int t1[] = {50,51,52};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	RoadsAndFools * obj = new RoadsAndFools();
	clock_t start = clock();
	string my_answer = obj->determineOrientation(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "MULTIPLE SOLUTIONS";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 5;
	int t1[] = {4, 4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	RoadsAndFools * obj = new RoadsAndFools();
	clock_t start = clock();
	string my_answer = obj->determineOrientation(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "1 4";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 5;
	int t1[] = {4, 4, 4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	RoadsAndFools * obj = new RoadsAndFools();
	clock_t start = clock();
	string my_answer = obj->determineOrientation(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "NO SOLUTION";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 5;
	int t1[] = {3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	RoadsAndFools * obj = new RoadsAndFools();
	clock_t start = clock();
	string my_answer = obj->determineOrientation(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "MULTIPLE SOLUTIONS";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 10;
	int t1[] = {5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	RoadsAndFools * obj = new RoadsAndFools();
	clock_t start = clock();
	string my_answer = obj->determineOrientation(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "5";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
