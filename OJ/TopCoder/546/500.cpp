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

class FavouriteDigits {
public:
	long long findNext(long long, int, int, int, int);
};

int d1,c1,d2,c2;
bool dp[20][2][2][16][16];
bool visit[20][2][2][16][16];
int next[20][2][2][16][16];
char a[20];

bool DP(int pos,int pre,int d,int now1,int now2)
{
    if (pos == 20)
        return (now1 >= c1) && (now2 >= c2);
    if (visit[pos][pre][d][now1][now2] == true)
        return dp[pos][pre][d][now1][now2];

    visit[pos][pre][d][now1][now2] = true;
    int op = 0;
    if (d == 1) op = a[pos]-'0';

    bool res = false;
    int nxt;
    for (int i = op;i < 10;i++)
    {
        int newpre = pre;
        if (pre == 0 && i > 0)  newpre = 1;
        int new1 = now1;
        if (i == d1)
            if (d1 != 0 || pre == 1)
                new1++;
        int new2 = now2;
        if (i == d2)
            if (d2 != 0 || pre == 1)
                new2++;
        if (DP(pos+1,newpre,(d == 1 && i == op),new1,new2) == true)
        {
            res = true;
            nxt = i;
            break;
        }
    }
    dp[pos][pre][d][now1][now2] = res;
    next[pos][pre][d][now1][now2] = nxt;
    return res;
}

long long FavouriteDigits::findNext(long long N, int digit1, int count1, int digit2, int count2) {
    sprintf(a,"%020lld",N);
    memset(visit,false,sizeof(visit));
    d1 = digit1;
    d2 = digit2;
    c1 = count1;
    c2 = count2;
    DP(0,0,1,0,0);
    long long res = 0;
    int nowd,nowc1,nowc2,nxt,pre;
    nowd = 1;
    nowc1 = nowc2 = pre = 0;
    for (int i = 0;i < 20;i++)
    {
        nxt = next[i][pre][nowd][nowc1][nowc2];
        if (pre == 0 && nxt > 0)  pre = 1;
        if (nowd == 1 && nxt != a[i]-'0')
            nowd = 0;
        if (nxt == d1)
            if (d1 != 0 || pre == 1)
                nowc1++;
        if (nxt == d2)
            if (d2 != 0 || pre == 1)
                nowc2++;
        res = res*10+nxt;
    }
    return res;
}

//Powered by [KawigiEdit] 2.0!
double test0() {
	long long p0 = 900000000099999LL;
	int p1 = 0;
	int p2 = 10;
	int p3 = 9;
	int p4 = 5;
	FavouriteDigits * obj = new FavouriteDigits();
	clock_t start = clock();
	long long my_answer = obj->findNext(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p5 = 47LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	long long p0 = 47LL;
	int p1 = 5;
	int p2 = 0;
	int p3 = 9;
	int p4 = 1;
	FavouriteDigits * obj = new FavouriteDigits();
	clock_t start = clock();
	long long my_answer = obj->findNext(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p5 = 49LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	long long p0 = 47LL;
	int p1 = 5;
	int p2 = 0;
	int p3 = 3;
	int p4 = 1;
	FavouriteDigits * obj = new FavouriteDigits();
	clock_t start = clock();
	long long my_answer = obj->findNext(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p5 = 53LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	long long p0 = 47LL;
	int p1 = 2;
	int p2 = 1;
	int p3 = 0;
	int p4 = 2;
	FavouriteDigits * obj = new FavouriteDigits();
	clock_t start = clock();
	long long my_answer = obj->findNext(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p5 = 200LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	long long p0 = 123456789012345LL;
	int p1 = 1;
	int p2 = 2;
	int p3 = 2;
	int p4 = 4;
	FavouriteDigits * obj = new FavouriteDigits();
	clock_t start = clock();
	long long my_answer = obj->findNext(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p5 = 123456789012422LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	long long p0 = 92LL;
	int p1 = 1;
	int p2 = 1;
	int p3 = 0;
	int p4 = 0;
	FavouriteDigits * obj = new FavouriteDigits();
	clock_t start = clock();
	long long my_answer = obj->findNext(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p5 = 100LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
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

