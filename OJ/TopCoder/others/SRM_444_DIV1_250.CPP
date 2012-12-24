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

class UnfoldingTriangles {
public:
	int solve(vector <string>, int);
};

int UnfoldingTriangles::solve(vector <string> g, int lim) {
	int n,m;
	n = g.size();
	m = g[0].size();
	int res = -1,need;
	for (int k = 0;k < min(n,m);k++)
	{
		bool flag = false;
		for (int i = k;i < n && flag == false;i++)
			for (int j = k;j < m && flag == false;j++)
			{
				need = 0;
				if (j+1 < m)
					for (int x = i-k;x <= i;x++)
						if (g[x][j+1] == '#')
						{
							need = -1;
							break;
						}
				if (need == -1)	continue;
				if (i+1 < n)
					for (int y = j-k;y <= j;y++)
						if (g[i+1][y] == '#')
						{
							need = -1;
							break;
						}
				if (need == -1)	continue;
				for (int tk = 0;tk <= k;tk++)
				{
					int x = i-(k-tk);
                    if (g[x][j-tk] != '/')
                        need = -1;
					for (int y = j-tk+1;y <= j;y++)
						if (g[x][y] == '/')
							need++;
						else if (g[x][y] == '.')
							need = -1;
					if (need == -1)	break;
				}
				//cout << i << ' ' << j << ' ' << k << ' ' << need << endl;
				if (need == -1)	continue;
				if (need <= lim)
				{
					res = max((1+k+1)*(k+1)/2,res);
					flag = true;
				}
			}
	}
	return res;
}

//Powered by [KawigiEdit] 2.0!
double test0() {
	string t0[] = {".../",
 "../#",
 "./#/",
 "/#//"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 4;
	UnfoldingTriangles * obj = new UnfoldingTriangles();
	clock_t start = clock();
	int my_answer = obj->solve(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 10;
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
	string t0[] = {".../",
 "../#",
 "./#/",
 "/#//"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	UnfoldingTriangles * obj = new UnfoldingTriangles();
	clock_t start = clock();
	int my_answer = obj->solve(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	string t0[] = {"////",
 "////",
 "////",
 "////"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 5;
	UnfoldingTriangles * obj = new UnfoldingTriangles();
	clock_t start = clock();
	int my_answer = obj->solve(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
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
	string t0[] = {".....#...",
 "....###.."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 10;
	UnfoldingTriangles * obj = new UnfoldingTriangles();
	clock_t start = clock();
	int my_answer = obj->solve(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
double test4() {
	string t0[] = {"#//#",
 "#//#",
 "####",
 "///#"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 4;
	UnfoldingTriangles * obj = new UnfoldingTriangles();
	clock_t start = clock();
	int my_answer = obj->solve(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1;
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
double test5() {
	string t0[] = {".../.../",
 "../#..//",
 "./.#.///",
 "/###...."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 3;
	UnfoldingTriangles * obj = new UnfoldingTriangles();
	clock_t start = clock();
	int my_answer = obj->solve(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
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
