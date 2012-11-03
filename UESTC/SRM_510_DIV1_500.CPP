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

class TheLuckyGameDivOne {
public:
	int find(long long, long long, long long, long long);
};

int a[30],b[30],len,la,lb,ca[30],cb[30],tot;
long long lucknum[2050];

int checku(int preu,int now,int pos)
{
    if (preu == 0)  return 0;
    if (now < b[pos])   return 0;
    return 1;
}

int checkd(int pred,int now,int pos)
{
    if (pred == 0)  return 0;
    if (now > a[pos])   return 0;
    return 1;
}

void DP(int num,int now,int u,int d,int f0)
{
    if (now == len)
    {
        for (int i = 0;i < tot;i++)
            if (lucknum[i] == num)  return;
        tot++;
        lucknum[tot] = num;
        return;
    }
    int op,ed;
    op = (d == 0)?0:a[now];
    ed = (u == 0)?9:b[now];
    for (int i = op;i <= ed;i++)
        if (i == 4 || i == 7)
            DP(num*10+i,now+1,checku(u,i,now),checkd(d,i,now),1);
        else if (i == 0 && f0 == 0)
            DP(num*10+i,now+1,checku(u,i,now),checkd(d,i,now),0);
}

long long dis[2050];

int TheLuckyGameDivOne::find(long long ta, long long tb, long long jLen, long long bLen) {
    long long tmpa,tmpb;
    tmpa = ta;
    tmpb = tb;
    la = lb = 0;
    while (ta > 0)
    {
        ca[la] = ta%10;
        ta /= 10;
        la++;
    }
    while (tb > 0)
    {
        cb[lb] = tb%10;
        tb /= 10;
        lb++;
    }
    len = max(la,lb);
    for (int i = 0;i < len-la;i++)  a[i] = 0;
    for (int i = len-la;i < len;i++)    a[i] = ca[la-(i-(len-la))-1];
    for (int i = 0;i < len-lb;i++)  b[i] = 0;
    for (int i = len-lb;i < len;i++)    b[i] = cb[lb-(i-(len-lb))-1];
    DP(0,0,1,1,0);
    sort(lucknum+1,lucknum+tot+1);
    lucknum[0] = tmpa-1;
    lucknum[tot+1] = tmpb;
    int l = 0,r = tot,mid;
    while (l < r)
    {
        mid = (l+r+1)/2;
    }
    return 0;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	long long p0 = 1LL;
	long long p1 = 10LL;
	long long p2 = 2LL;
	long long p3 = 1LL;
	TheLuckyGameDivOne * obj = new TheLuckyGameDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 0;
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
	long long p0 = 1LL;
	long long p1 = 100LL;
	long long p2 = 100LL;
	long long p3 = 100LL;
	TheLuckyGameDivOne * obj = new TheLuckyGameDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 6;
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
	long long p0 = 4LL;
	long long p1 = 8LL;
	long long p2 = 3LL;
	long long p3 = 2LL;
	TheLuckyGameDivOne * obj = new TheLuckyGameDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 1;
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
	long long p0 = 1LL;
	long long p1 = 100LL;
	long long p2 = 75LL;
	long long p3 = 50LL;
	TheLuckyGameDivOne * obj = new TheLuckyGameDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 2;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
