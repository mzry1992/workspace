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

class NetworkXOneTimePad {
public:
	int crack(vector <string>, vector <string>);
};

set<string> maybe;
set<string>::iterator it;
string now;

string XOR(string a,string b)
{
    string res = a;
    for (int i = 0;i < a.size();i++)
        if (a[i] == b[i])
            res[i] = '0';
        else
            res[i] = '1';
    return res;
}

int NetworkXOneTimePad::crack(vector <string> p, vector <string> c) {
    int n = p.size();
    int m = c.size();
    maybe.clear();
    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
            maybe.insert(XOR(p[i],c[j]));
    int res = 0;
    bool check,flag;
    for (it = maybe.begin();it != maybe.end();it++)
    {
        check = true;
        for (int i = 0;i < m;i++)
        {
            now = XOR(c[i],*it);
            flag = false;
            for (int j = 0;j < n;j++)
                if (p[j] == now)
                {
                    flag = true;
                    break;
                }
            if (flag == false)
            {
                check = false;
                break;
            }
        }
            //cout << (*it) << endl;
        if (check == true)
        {
            //cout << "OK" << endl;
            res++;
        }
    }
    cout << maybe.size() << endl;
    bool sumi[50];
    int res2 = 0;
    for (int i = 0;i < n;i++)
    {
        string key = XOR(p[i],c[0]);
        memset(sumi,false,sizeof(sumi));
        int f = 1;
        for (int j = 1;j < m;j++)
            for (int k = 0;k < n;k++)
                if (XOR(p[k],c[j]) == key)
                    sumi[j] = true;
        for (int j = 1;j < m;j++)
            if (!sumi[j])   f= 0;
        res2 += f;
    }
    cout << res2 << endl;
    return res;
}

//Powered by [KawigiEdit] 2.0!
double test0() {
	string t0[] = {"00","10","11","01"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] ={"00","10","11","01"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	NetworkXOneTimePad * obj = new NetworkXOneTimePad();
	clock_t start = clock();
	int my_answer = obj->crack(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	string t0[] = {"00", "01", "10", "11"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"00", "01"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	NetworkXOneTimePad * obj = new NetworkXOneTimePad();
	clock_t start = clock();
	int my_answer = obj->crack(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
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
	string t0[] = {"01", "10"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"00"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	NetworkXOneTimePad * obj = new NetworkXOneTimePad();
	clock_t start = clock();
	int my_answer = obj->crack(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	string t0[] = {"000", "111", "010", "101", "110", "001"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"011", "100"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	NetworkXOneTimePad * obj = new NetworkXOneTimePad();
	clock_t start = clock();
	int my_answer = obj->crack(p0, p1);
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

