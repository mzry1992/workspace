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

class Stamp {
public:
	int getMinimumCost(string, int, int);
};

int dp[60][3];

bool check(string a,int pos,int len,int col)
{
	if (pos+len > a.length())	return false;
	int r,g,b;
	r = g = b = 0;
	for (int i = 0;i < len;i++)
		if (a[pos+i] == 'R')
			r++;
		else if (a[pos+i] == 'G')
			g++;
		else if (a[pos+i] == 'B')
			b++;
	int cnt = 0;
	if (r > 0)	cnt++;
	if (g > 0)	cnt++;
	if (b > 0)	cnt++;
	if (cnt == 0)	return true;
	if (cnt > 1)	return false;
	if (col == 0)	return r > 0;
	if (col == 1)	return g > 0;
	if (col == 2)	return b > 0;
	return false;
}

int Stamp::getMinimumCost(string a, int b, int c) {
	int n = a.length();
	int res = b+n*c;
	for (int len = 2;len <= n;len++)
	{
		int tres = b*len;
		memset(dp,63,sizeof(dp));
		for (int i = 0;i < 3;i++)
			if (check(a,0,len,i))
				dp[0][i] = 1;
		for (int i = 0;i < n;i++)
			for (int j = 0;j < 3;j++)
				if (dp[i][j] != 0x3f3f3f3f)
				{
					for (int k = 0;k < 3;k++)
						if (check(a,i+len,len,k))
							dp[i+len][k] = min(dp[i+len][k],dp[i][j]+1);
					for (int k = 1;k < len;k++)
						if (check(a,i+k,len,j))
							dp[i+k][j] = min(dp[i+k][j],dp[i][j]+1);
				}
		int minv = 0x3f3f3f3f;
		for (int j = 0;j < 3;j++)
			minv = min(dp[n-len][j],minv);
		if (minv < 0x3f3f3f3f)
		{
			tres += minv*c;
			res = min(res,tres);
		}
	}
	return res;
}

//Powered by [KawigiEdit] 2.0!
double test0() {
	string p0 = "*********RR********G*************************RGB**";
	int p1 = 2;
	int p2 = 3;
	Stamp * obj = new Stamp();
	clock_t start = clock();
	int my_answer = obj->getMinimumCost(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string p0 = "R**GB*";
	int p1 = 1;
	int p2 = 1;
	Stamp * obj = new Stamp();
	clock_t start = clock();
	int my_answer = obj->getMinimumCost(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string p0 = "BRRB";
	int p1 = 2;
	int p2 = 7;
	Stamp * obj = new Stamp();
	clock_t start = clock();
	int my_answer = obj->getMinimumCost(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 30;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string p0 = "R*RR*GG";
	int p1 = 10;
	int p2 = 58;
	Stamp * obj = new Stamp();
	clock_t start = clock();
	int my_answer = obj->getMinimumCost(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 204;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string p0 = "*B**B**B*BB*G*BBB**B**B*";
	int p1 = 5;
	int p2 = 2;
	Stamp * obj = new Stamp();
	clock_t start = clock();
	int my_answer = obj->getMinimumCost(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 33;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	string p0 = "*R*RG*G*GR*RGG*G*GGR***RR*GG";
	int p1 = 7;
	int p2 = 1;
	Stamp * obj = new Stamp();
	clock_t start = clock();
	int my_answer = obj->getMinimumCost(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 30;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
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
