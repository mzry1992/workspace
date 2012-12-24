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

class ThreePoints {
public:
	long long countColoring(int, int, int, int, int, int, int, int, int);
};

int n;
pair<int,int> p[300000];
int lsx[300000],lsy[300000];
int tree1[300001],tree2[300001];
int cntu[300001];

int read1(int k)
{
    int sum = 0;
    for (;k;k ^= k&-k)
        sum += tree1[k];
    return sum;
}

void update1(int k)
{
    for (;k <= n;k += k&-k)
        tree1[k] ++;
}

int read2(int k)
{
    int sum = 0;
    for (;k <= n;k += k&-k)
        sum += tree2[k];
    return sum;
}

void update2(int k)
{
    for (;k;k ^= k&-k)
        tree2[k] ++;
}

long long ThreePoints::countColoring(int N, int xzero, int xmul, int xadd, int xmod, int yzero, int ymul, int yadd, int ymod) {
    p[0] = make_pair(xzero,yzero);
    for (int i = 1;i < N;i++)
        p[i] = make_pair(((long long)p[i-1].first*(long long)xmul+(long long)xadd)%xmod,
                        ((long long)p[i-1].second*(long long)ymul+(long long)yadd)%ymod);
    for (int i = 0;i < N;i++)
    {
        lsx[i] = p[i].first;
        lsy[i] = p[i].second;
    }
    sort(lsx,lsx+N);
    sort(lsy,lsy+N);
    for (int i = 0;i < N;i++)
    {
        p[i].first = (lower_bound(lsx,lsx+N,p[i].first)-lsx)+1;
        p[i].second = (lower_bound(lsy,lsy+N,p[i].second)-lsy)+1;
    }
    sort(p,p+N);
    n = N;
    for (int i = 0;i <= n;i++)
        tree1[i] = tree2[i] = 0;
    long long res = 0;
    for (int i = 0;i < N;i++)
    {
        cntu[i] = read2(p[i].second+1);
        res += (long long)read1(p[i].second-1)*(long long)cntu[i];
        update1(p[i].second);
        update2(p[i].second);
    }
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int p0 = 9;
	int p1 = 3;
	int p2 = 8;
	int p3 = 6;
	int p4 = 11;
	int p5 = 5;
	int p6 = 7;
	int p7 = 8;
	int p8 = 11;
	ThreePoints * obj = new ThreePoints();
	clock_t start = clock();
	long long my_answer = obj->countColoring(p0, p1, p2, p3, p4, p5, p6, p7, p8);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p9 = 8LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p9 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p9 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 4;
	int p1 = 9;
	int p2 = 6;
	int p3 = 8;
	int p4 = 10;
	int p5 = 4;
	int p6 = 8;
	int p7 = 5;
	int p8 = 10;
	ThreePoints * obj = new ThreePoints();
	clock_t start = clock();
	long long my_answer = obj->countColoring(p0, p1, p2, p3, p4, p5, p6, p7, p8);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p9 = 2LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p9 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p9 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 20;
	int p1 = 30;
	int p2 = 3;
	int p3 = 71;
	int p4 = 100;
	int p5 = 78;
	int p6 = 12;
	int p7 = 50;
	int p8 = 100;
	ThreePoints * obj = new ThreePoints();
	clock_t start = clock();
	long long my_answer = obj->countColoring(p0, p1, p2, p3, p4, p5, p6, p7, p8);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p9 = 263LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p9 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p9 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 300000;
	int p1 = 99097861;
	int p2 = 102766912;
	int p3 = 95284952;
	int p4 = 123456789;
	int p5 = 443104491;
	int p6 = 971853214;
	int p7 = 569775557;
	int p8 = 987654321;
	ThreePoints * obj = new ThreePoints();
	clock_t start = clock();
	long long my_answer = obj->countColoring(p0, p1, p2, p3, p4, p5, p6, p7, p8);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p9 = 749410681185726LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p9 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p9 != my_answer) {
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
