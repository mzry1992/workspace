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

class EllysRivers {
public:
	double getMin(int, int, vector <int>, vector <int>);
};

double dp[51][100001];

double EllysRivers::getMin(int length, int walk, vector <int> width, vector <int> speed) {
    int n = width.size();

    for (int i = 0;i <= n;i++)
        for (int j = 0;j <= length;j++)
            dp[i][j] = 1e100;

    for (int i = 0;i < length;i++)
        dp[0][i] = (double)i/(double)walk;

    double totw = 0;
    double totlen = (double)length;
    for (int i = 0;i < n;i++)
        totw += (double)width[i];

    for (int i = 0;i < n;i++)
    {
        double tmp = totlen/totw*(double)width[i];
        int pl,pr;
        pl = floor(tmp);
        for (int j = 0;j <= length;j++)
            for (int k = -10;k <= 10;k++)
            {
                int dis = min(length-j,pl+k);
                dp[i+1][j+dis] = min(dp[i+1][j+dis],dp[i][j]+sqrt((double)dis*(double)dis+(double)width[i]*(double)width[i])/(double)speed[i]);
            }
    }
    double res = 1e100;
    for (int i = 0;i <= length;i++)
    {
        double tmp = dp[n][i]+(double)(length-i)/(double)walk;
        res = min(res,tmp);
    }
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int p0 = 10;
	int p1 = 3;
	int t2[] = {5, 2, 3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {5, 2, 7};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	EllysRivers * obj = new EllysRivers();
	clock_t start = clock();
	double my_answer = obj->getMin(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 3.231651964071508;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 10000;
	int p1 = 211;
	int t2[] = {911};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {207};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	EllysRivers * obj = new EllysRivers();
	clock_t start = clock();
	double my_answer = obj->getMin(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 48.24623664712219;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 1337;
	int p1 = 2;
	int t2[] = {100, 200, 300, 400};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {11, 12, 13, 14};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	EllysRivers * obj = new EllysRivers();
	clock_t start = clock();
	double my_answer = obj->getMin(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 128.57830549575695;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 77;
	int p1 = 119;
	int t2[] = {11, 12, 13, 14};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {100, 200, 300, 400};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	EllysRivers * obj = new EllysRivers();
	clock_t start = clock();
	double my_answer = obj->getMin(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 0.3842077071089629;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 7134;
	int p1 = 1525;
	int t2[] = {11567, 19763, 11026, 10444, 24588, 22263, 17709, 11181, 15292, 28895, 15039, 18744, 19985, 13795, 26697, 18812, 25655, 13620, 28926, 12393};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1620, 1477, 2837, 2590, 1692, 2270, 1655, 1078, 2683, 1475, 1383, 1153, 1862, 1770, 1671, 2318, 2197, 1768, 1979, 1057};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	EllysRivers * obj = new EllysRivers();
	clock_t start = clock();
	double my_answer = obj->getMin(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 214.6509731258811;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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
