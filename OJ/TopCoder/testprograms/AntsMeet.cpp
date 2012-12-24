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

class AntsMeet {
public:
	int countAnts(vector <int>, vector <int>, string);
};

vector<int> x;
vector<int> y;
string d;
int dis[50][50];

int check(int a,int b)
{
	if (a == b)	return -1;
	if (d[a] == 'N' && d[b] == 'E')
	{
		if (x[b] < x[a] && y[b] > y[a])
		{
			if (y[b]-y[a] == x[b]-x[a])
				return (y[b]-y[a])*2;
		}
	}
	else if (d[a] == 'N' && d[b] == 'S')
	{
		if (x[b] == x[a] && y[b] > y[a])
			return (y[b]-y[a]);
	}
	else if (d[a] == 'N' && d[b] == 'W')
	{
		if (x[a] < x[b] && y[b] > y[a])
		{
			if (y[b]-y[a] == x[b]-x[a])
				return (y[b]-y[a])*2;
		}
	}
	else if (d[a] == 'E' && d[b] == 'N')
		return check(b,a);
	else if (d[a] == 'E' && d[b] == 'S')
	{
		if (x[a] < x[b] && y[a] < y[b])
		{
			if (x[b]-x[a] == y[b]-y[a])
				return (x[b]-x[a])*2;
		}
	}
	else if (d[a] == 'E' && d[b] == 'W')
	{
		if (x[a] < x[b] && y[a] == y[b])
			return (x[b]-x[a]);
	}
	else if (d[a] == 'S' && d[b] == 'N')
		return check(b,a);
	else if (d[a] == 'S' && d[b] == 'E')
		return check(b,a);
	else if (d[a] == 'S' && d[b] == 'W')
	{
		if (x[a] < x[b] && y[a] > y[b])
		{
			if (x[b]-x[a] == y[a]-y[b])
				return (x[b]-x[a])*2;
		}
	}
	else if (d[a] == 'W')
		return check(b,a);
	return -1;
}

int mindis[50];
bool del[50];

int AntsMeet::countAnts(vector <int> tx, vector <int> ty, string td) {
	x = tx;
	y = ty;
	d = td;
	int n = x.size();
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			dis[i][j] = check(i,j);
	for (int i = 0;i < n;i++)
	{
		mindis[i] = -1;
		del[i] = false;
		for (int j = 0;j < n;j++)
			if (dis[i][j] != -1)
			{
				if (mindis[i] == -1 || mindis[i] > dis[i][j])
					mindis[i] = dis[i][j];
			}
	}
	for (int i = 0;i < n;i++)
		if (mindis[i] != -1)
		for (int j = 0;j < n;j++)
			if (mindis[i] == mindis[j])
				del[i] = del[j] = true;
	int res = 0;
	for (int i = 0;i < n;i++)
		if (del[i] == true)
			res++;
	return res;
}


double test0() {
	int t0[] = {0,10,20,30};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,10,20,30};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string p2 = "NWNE";
	AntsMeet * obj = new AntsMeet();
	clock_t start = clock();
	int my_answer = obj->countAnts(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
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
	int t0[] = {-10,0,0,10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,-10,10,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string p2 = "NEWS";
	AntsMeet * obj = new AntsMeet();
	clock_t start = clock();
	int my_answer = obj->countAnts(p0, p1, p2);
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
	int t0[] = {-1,-1,-1,0,0,0,1,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-1,0,1,-1,0,1,-1,0,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string p2 = "ESEWNNEWW";
	AntsMeet * obj = new AntsMeet();
	clock_t start = clock();
	int my_answer = obj->countAnts(p0, p1, p2);
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
double test3() {
	int t0[] = {4,7,6,2,6,5,7,7,8,4,7,8,8,8,5,4,8,9,1,5,9,3,4,0,0,1,0,7,2,6,9,6,3,0,5,5,1,2,0,4,9,7,7,1,8,1,9,2,7,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,3,0,6,8,4,9,0,5,0,2,4,3,8,1,5,0,7,3,7,0,9,8,1,9,4,7,8,1,1,6,6,6,2,8,5,1,9,0,1,1,1,7,0,2,5,4,7,5,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string p2 = "SSNWSWSENSWSESWEWSWSENWNNNESWSWSWWSSWEEWWNWWWNWENN" ;
	AntsMeet * obj = new AntsMeet();
	clock_t start = clock();
	int my_answer = obj->countAnts(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 25;
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
	int t0[] = {478,-664,759,434,-405,513,565,-396,311,-174,56,993,251,-341,993,-112,242,129,383,513,-78,-341,-148,129,423
,493,434,-405,478,-148,929,251,56,242,929,-78,423,-664,802,251,759,383,-112,-591,-591,-248,660,660,735,493};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-186,98,948,795,289,-678,948,-170,-195,290,-354,-424,289,-157,-166,150,706,-678,684,-294,-234,36,36,-294,-216
,-234,427,945,265,-157,265,715,275,715,-186,337,798,-170,427,706,754,961,286,-216,798,286,961,684,-424,337};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string p2 = "WNSNNSSWWWEENWESNSWSWSEWWEWEWWWNWESNSSNNSNNWWWNESE";
	AntsMeet * obj = new AntsMeet();
	clock_t start = clock();
	int my_answer = obj->countAnts(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 44;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
