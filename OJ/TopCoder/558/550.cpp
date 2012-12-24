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

class Ear {
public:
	long long getCount(vector <string>, vector <string>, vector <string>);
};

struct Point
{
    int x,y;
    Point() {}
    Point(int _x,int _y)
    {
        x = _x;
        y = _y;
    }
    Point operator -(const Point& b)const
    {
        return Point(x-b.x,y-b.y);
    }
    int operator *(const Point& b)const
    {
        return x*b.y-y*b.x;
    }
};

struct Line
{
	Point s,e;
	Line(Point _s,Point _e)
	{
		s = _s;
		e = _e;
	}
};

bool inter(Line l1,Line l2)
{
	return (max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
			max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
			max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
			max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
			(long long)((l2.s-l1.s)*(l1.e-l1.s))*((l2.e-l1.s)*(l1.e-l1.s)) <= 0 &&
			(long long)((l1.s-l2.s)*(l2.e-l2.s))*((l1.e-l2.s)*(l2.e-l2.s)) <= 0);
}

char buf[3000];
vector<int> gao(vector<string> s)
{
	string tmp = "";
	for (int i = 0;i < s.size();i++)
		tmp = tmp+s[i];
	sprintf(buf,"%s",tmp.c_str());
	vector<int> res;
	int pos = 0,npos;
	int val;
	while (sscanf(buf+pos,"%d%n",&val,&npos) != EOF)
	{
		res.push_back(val);
		pos += npos;
	}
	return res;
}

int pl[400],pr[400];

long long Ear::getCount(vector <string> redX, vector <string> blueX, vector <string> blueY) {
	vector<int> rx = gao(redX);
	vector<int> bx = gao(blueX);
	vector<int> by = gao(blueY);

//	for (int i = 0;i < rx.size();i++)
//		printf("%d ",rx[i]);
//	printf("\n");
//
//	for (int i = 0;i < bx.size();i++)
//		printf("%d ",bx[i]);
//	printf("\n");
//
//	for (int i = 0;i < by.size();i++)
//		printf("%d ",by[i]);
//	printf("\n");

	int n = rx.size();
	int m = bx.size();

	sort(rx.begin(),rx.end());
	for (int i = 0;i < m;i++)
	{
		pl[i] = pr[i] = -1;
		for (int j = 0;j < n;j++)
			if (rx[j] < bx[i])
				pl[i] = j;
		for (int j = n-1;j >= 0;j--)
			if (rx[j] > bx[i])
				pr[i] = j;
	}

	long long res = 0;
	for (int i = 0;i < m;i++)
	{
		if (pl[i] == -1 || pr[i] == -1)	continue;
		for (int j = 0;j < m;j++)
		{
			if (pl[j] == -1 || pr[j] == -1)	continue;
			if (by[i] >= by[j])	continue;

			long long cntl,cntr;
			cntl = cntr = 0;

			int nowl = pl[i];
			int pa = min(pl[i],pl[j]);
			for (int k = nowl;k >= 0;k--)
			{
				while (pa >= 0 && inter(Line(Point(rx[pa],0),Point(bx[j],by[j])),Line(Point(rx[k],0),Point(bx[i],by[i]))))
					pa--;
				if (pa == -1)	break;
				cntl += pa+1;
			}

			int nowr = pr[i];
			int pb = max(pr[i],pr[j]);
			for (int k = nowr;k < n;k++)
			{
				while (pb < n && inter(Line(Point(rx[pb],0),Point(bx[j],by[j])),Line(Point(rx[k],0),Point(bx[i],by[i]))))
					pb++;
				if (pb == n)	break;
				cntr += n-pb;
			}

//			printf("j = %d, i = %d\n",j,i);
//			printf("pl[i] = %d, pr[i] = %d | pl[j] = %d, pr[j] = %d\n",pl[i],pr[i],pl[j],pr[j]);
//			printf("nowl = %d, nowr = %d\n",nowl,nowr);
//			printf("P = (%d, %d), Q = (%d, %d)\n",bx[j],by[j],bx[i],by[i]);
//			printf("cntl = %lld, cntr = %lld\n",cntl,cntr);
			res += cntl*cntr;
		}
	}
	return res;
}
//Powered by [KawigiEdit] 2.0!

double test0() {
	string t0[] = {"3 2 8 7"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"5 4"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"2 4"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	Ear * obj = new Ear();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 1LL;
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
	string t0[] = {"3 2 8 7"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"2 8"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"3 4"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	Ear * obj = new Ear();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 0LL;
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
	string t0[] = {"1 2 6 9"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"3 6 8 5"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"1 5 4 3"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	Ear * obj = new Ear();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 4LL;
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
	string t0[] = {"10000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"10000 9999"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"10000 9999"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	Ear * obj = new Ear();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 0LL;
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
	string t0[] = {"100 2", "00", " 39", "9", " 800 900 9", "99"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"15", "0 250 ", "349"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"2 3 1"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	Ear * obj = new Ear();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 12LL;
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
	string t0[] = {"1", " ", "2", " ", "3", " ", "4 5 6", " 7 8 9"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"4", " ", "5", " ", "6", " 7 ", "8"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"1", " 2 ", "3 4", " 5"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	Ear * obj = new Ear();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 204LL;
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
