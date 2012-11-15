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

class TheAlmostLuckyNumbersDivOne {
public:
	long long find(long long, long long);
};

int a[30],b[30],len,la,lb,ca[30],cb[30];
long long dp[30][2][2][2][2];
bool use[30][2][2][2][2];

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

long long DP(int now,int u,int d,int f0,int tot)
{
    if (use[now][u][d][f0][tot] == true)    return dp[now][u][d][f0][tot];
    if (now == len)
    {
        return 1;
    }
    int op,ed;
    op = (d == 0)?0:a[now];
    ed = (u == 0)?9:b[now];
    use[now][u][d][f0][tot] = true;
    dp[now][u][d][f0][tot] = 0;
    for (int i = op;i <= ed;i++)
        if (i == 4 || i == 7)
            dp[now][u][d][f0][tot] += DP(now+1,checku(u,i,now),checkd(d,i,now),1,tot);
        else
        {
            if (i == 0)
            {
                if (f0 == 0)
                    dp[now][u][d][f0][tot] += DP(now+1,checku(u,i,now),checkd(d,i,now),0,tot);
                else if (tot == 0)
                    dp[now][u][d][f0][tot] += DP(now+1,checku(u,i,now),checkd(d,i,now),1,tot+1);
            }
            else if (tot == 0)
                dp[now][u][d][f0][tot] += DP(now+1,checku(u,i,now),checkd(d,i,now),1,tot+1);
        }
    return dp[now][u][d][f0][tot];
}

long long TheAlmostLuckyNumbersDivOne::find(long long ta, long long tb) {
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
    memset(use,false,sizeof(use));
    return DP(0,1,1,0,0);
}

//Powered by [KawigiEdit] 2.0!
double test0() {
	long long p0 = 4LL;
	long long p1 = 7LL;
	TheAlmostLuckyNumbersDivOne * obj = new TheAlmostLuckyNumbersDivOne();
	clock_t start = clock();
	long long my_answer = obj->find(p0, p1);
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
	long long p0 = 8LL;
	long long p1 = 19LL;
	TheAlmostLuckyNumbersDivOne * obj = new TheAlmostLuckyNumbersDivOne();
	clock_t start = clock();
	long long my_answer = obj->find(p0, p1);
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
double test2() {
	long long p0 = 28LL;
	long long p1 = 33LL;
	TheAlmostLuckyNumbersDivOne * obj = new TheAlmostLuckyNumbersDivOne();
	clock_t start = clock();
	long long my_answer = obj->find(p0, p1);
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
double test3() {
	long long p0 = 12345678900LL;
	long long p1 = 98765432100LL;
	TheAlmostLuckyNumbersDivOne * obj = new TheAlmostLuckyNumbersDivOne();
	clock_t start = clock();
	long long my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 91136LL;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

