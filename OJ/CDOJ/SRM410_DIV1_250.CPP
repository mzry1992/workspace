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

class AddElectricalWires {
public:
	int maxNewWires(vector <string>, vector <int>);
};

int f[50],sc[50],tot[50],tmp[50];

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

int AddElectricalWires::maxNewWires(vector <string> wires, vector <int> gridConnections) {
    int n = wires.size();
    int has = 0;
    for (int i = 0;i < n;i++)   f[i] = i;
    for (int i = 0;i < n;i++)
        for (int j = i+1;j < n;j++)
            if (wires[i][j] == '1')
            {
                has++;
                int fa,fb;
                fa = findf(i);
                fb = findf(j);
                f[fa] = fb;
            }
    for (int i = 0;i < n;i++)   tot[i] = tmp[i] = 0;
    for (int i = 0;i < n;i++)
    {
        sc[i] = findf(i);
        tot[sc[i]]++;
    }
    for (int i = 0;i < gridConnections.size();i++)
        tmp[i] = tot[findf(gridConnections[i])];
    int left = n;
    for (int i = 0;i < gridConnections.size();i++)
        left -= tmp[i];
    int maxval,maxpos;
    maxval = -1;
    for (int i = 0;i < gridConnections.size();i++)
        if (tmp[i] > maxval)
        {
            maxval = tmp[i];
            maxpos = i;
        }
    tmp[maxpos] += left;
    int res = 0;
    for (int i = 0;i < gridConnections.size();i++)
        res += (tmp[i]*(tmp[i]-1))/2;
    /*for (int i = 0;i < gridConnections.size();i++)
        cout << tmp[i] << ' ';
    cout << endl;*/
    res -= has;
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string t0[] = {"000","000","000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	AddElectricalWires * obj = new AddElectricalWires();
	clock_t start = clock();
	int my_answer = obj->maxNewWires(p0, p1);
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
double test1() {
	string t0[] = {"000","000","000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {0,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	AddElectricalWires * obj = new AddElectricalWires();
	clock_t start = clock();
	int my_answer = obj->maxNewWires(p0, p1);
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
double test2() {
	string t0[] = {"01","10"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	AddElectricalWires * obj = new AddElectricalWires();
	clock_t start = clock();
	int my_answer = obj->maxNewWires(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
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
	string t0[] = {"00000","00000","00000","00000","00000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {0,1,2,3,4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	AddElectricalWires * obj = new AddElectricalWires();
	clock_t start = clock();
	int my_answer = obj->maxNewWires(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
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
	string t0[] = {"01000","10100","01010","00100","00000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = {2,4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	AddElectricalWires * obj = new AddElectricalWires();
	clock_t start = clock();
	int my_answer = obj->maxNewWires(p0, p1);
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
