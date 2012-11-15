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
#include <cstring>
using namespace std;

class FoxPlayingGame {
public:
	double theMax(int, int, int, int);
};

double dp[200][100][2];
bool visit[200][100][2];

double max(double a,double b)
{
    if (a > b)  return a;
    return b;
}

double min(double a,double b)
{
    if (a > b)  return b;
    return a;
}

double FoxPlayingGame::theMax(int nA, int nB, int paramA, int paramB) {
    int tot = nA+nB;
    dp[0][0][0] = dp[0][0][1] = 0;
    memset(visit,false,sizeof(visit));
    visit[0][0][0] = visit[0][0][1] = true;
    double sa,sb;
    sa = paramA/1000.0;
    sb = paramB/1000.0;
    for (int i = 1;i <= tot;i++)
    for (int j = 0;j <= nA;j++)
    {
        if (j > i)  break;
        double tmax,tmin;
        tmax = -1e30;
        tmin = 1e30;
        if (visit[i][j][0] == true) tmax = max(dp[i][j][0],tmax);
        if (visit[i][j][1] == true) tmax = max(dp[i][j][1],tmax);
        if (visit[i-1][j][0] == true) tmax = max(dp[i-1][j][0]*sb,tmax);
        if (visit[i-1][j][1] == true) tmax = max(dp[i-1][j][1]*sb,tmax);
        if (j > 0)
        {
            if (visit[i-1][j-1][0] == true) tmax = max(dp[i-1][j-1][0]+sa,tmax);
            if (visit[i-1][j-1][1] == true) tmax = max(dp[i-1][j-1][1]+sa,tmax);
        }
        if (tmax > -1e30)
        {
            if (visit[i][j][0] == false)
                dp[i][j][0] = tmax;
            if (visit[i][j][1] == false)
                dp[i][j][1] = tmax;
            visit[i][j][0] = true;
            visit[i][j][1] = true;
            dp[i][j][0] = max(tmax,dp[i][j][0]);
            dp[i][j][1] = min(tmax,dp[i][j][1]);
        }
        if (visit[i][j][0] == true) tmin = min(dp[i][j][0],tmin);
        if (visit[i][j][1] == true) tmin = min(dp[i][j][1],tmin);
        if (visit[i-1][j][0] == true) tmin = min(dp[i-1][j][0]*sb,tmin);
        if (visit[i-1][j][1] == true) tmin = min(dp[i-1][j][1]*sb,tmin);
        if (j > 0)
        {
            if (visit[i-1][j-1][0] == true) tmin = min(dp[i-1][j-1][0]+sa,tmin);
            if (visit[i-1][j-1][1] == true) tmin = min(dp[i-1][j-1][1]+sa,tmin);
        }
        if (tmin < 1e30)
        {
            if (visit[i][j][0] == false)
                dp[i][j][0] = tmin;
            if (visit[i][j][1] == false)
                dp[i][j][1] = tmin;
            visit[i][j][0] = true;
            visit[i][j][1] = true;
            dp[i][j][0] = max(tmin,dp[i][j][0]);
            dp[i][j][1] = min(tmin,dp[i][j][1]);
        }
    }
    dp[tot][nA][0] = max(dp[tot][nA][0],dp[tot][nA][1]);
    return dp[tot][nA][0];
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int p0 = 5;
	int p1 = 4;
	int p2 = 3000;
	int p3 = 2000;
	FoxPlayingGame * obj = new FoxPlayingGame();
	clock_t start = clock();
	double my_answer = obj->theMax(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 240.0;
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
	int p0 = 3;
	int p1 = 3;
	int p2 = 2000;
	int p3 = 100;
	FoxPlayingGame * obj = new FoxPlayingGame();
	clock_t start = clock();
	double my_answer = obj->theMax(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 6.0;
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
	int p0 = 4;
	int p1 = 3;
	int p2 = -2000;
	int p3 = 2000;
	FoxPlayingGame * obj = new FoxPlayingGame();
	clock_t start = clock();
	double my_answer = obj->theMax(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = -8.0;
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
	int p0 = 5;
	int p1 = 5;
	int p2 = 2000;
	int p3 = -2000;
	FoxPlayingGame * obj = new FoxPlayingGame();
	clock_t start = clock();
	double my_answer = obj->theMax(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 160.0;
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
	int p0 = 50;
	int p1 = 50;
	int p2 = 10000;
	int p3 = 2000;
	FoxPlayingGame * obj = new FoxPlayingGame();
	clock_t start = clock();
	double my_answer = obj->theMax(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 5.62949953421312E17;
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
double test5() {
	int p0 = 41;
	int p1 = 34;
	int p2 = 9876;
	int p3 = -1234;
	FoxPlayingGame * obj = new FoxPlayingGame();
	clock_t start = clock();
	double my_answer = obj->theMax(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 515323.9982341775;
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

	time = test5();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
