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

class BlockEnemy {
public:
	int minEffort(int, vector <string>, vector <int>);
};

struct road
{
    int a,b,c;
}g[100];
int n,m,s;
int totl;
int f[100];

bool cmp(road a,road b)
{
    return a.c > b.c;
}

int findf(int x)
{
    if (f[x] != x) f[x] = findf(f[x]);
    return f[x];
}

int BlockEnemy::minEffort(int N, vector <string> roads, vector <int> occupiedTowns) {
    m = roads.size();
    s = occupiedTowns.size();
    n = N;
    totl = 0;
    for (int i = 0;i < m;i++)
    {
        sscanf(roads[i].c_str(),"%d%d%d",&g[i].a,&g[i].b,&g[i].c);
        totl += g[i].c;
    }
    int res = totl;
    sort(g,g+m,cmp);
    for (int i = 0;i < n;i++)
        f[i] = i;
    for (int i = 0;i < m;i++)
    {
        int fa,ta,fb,tb;
        fa = findf(g[i].a);
        fb = findf(g[i].b);
        bool canput = true;
        for (int j = 0;j < s;j++)
        for (int k = j+1;k < s;k++)
        {
            ta = findf(occupiedTowns[j]);
            tb = findf(occupiedTowns[k]);
            if (ta == fa && tb == fb)
                canput = false;
            if (ta == fb && tb == fa)
                canput = false;
        }
        if (canput == true)
        {
            res -= g[i].c;
            f[fa] = fb;
        }
    }
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int p0 = 5;
	string t1[] = {"1 0 1", "1 2 2", "0 3 3", "4 0 4"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int t2[] = {3, 2, 4};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	BlockEnemy * obj = new BlockEnemy();
	clock_t start = clock();
	int my_answer = obj->minEffort(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4;
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
	int p0 = 5;
	string t1[] = {"1 0 1", "1 2 2", "0 3 3", "4 0 4"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int t2[] = {3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	BlockEnemy * obj = new BlockEnemy();
	clock_t start = clock();
	int my_answer = obj->minEffort(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
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
	int p0 = 12;
	string t1[] = {"0 1 3", "2 0 5", "1 3 1", "1 4 8", "1 5 4", "2 6 2",
 "4 7 11", "4 8 10", "6 9 7", "6 10 9", "6 11 6"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int t2[] = {1, 2, 6, 8};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	BlockEnemy * obj = new BlockEnemy();
	clock_t start = clock();
	int my_answer = obj->minEffort(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 13;
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
	int p0 = 12;
	string t1[] = {"0 1 3", "2 0 5", "1 3 1", "1 4 8", "1 5 4", "2 6 2",
 "4 7 11", "4 8 10", "6 9 7", "6 10 9", "6 11 6"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int t2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	BlockEnemy * obj = new BlockEnemy();
	clock_t start = clock();
	int my_answer = obj->minEffort(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 66;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
