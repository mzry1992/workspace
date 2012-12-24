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

class SwitchesAndLamps {
public:
	int theMin(vector <string>, vector <string>);
};

int n,m,out[50],in[50];
vector<int> ck1,ck2;

int gao(int minval)
{
	ck2 = ck1;
	for (int i = 0;i < m;i++)
		if (i-ck2[i] < 0)
			return -1;
	int nowres = 0;
	for (int i = 0;i < m;i++)
	{
		int dif = i-ck2[i];
		nowres += dif;
		for (int j = i;j < m;j++)
		{
			int nowdif = j-ck2[j];
			if (nowdif > dif)
				nowdif = dif;
			ck2[j] += nowdif;
		}
	}
	return nowres;
}
int SwitchesAndLamps::theMin(vector <string> sw, vector <string> la) {
	n = sw.size();
	m = sw[0].size();
	for (int i = 0;i < m;i++)
		out[i] = in[i] = 0;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (sw[i][j] == 'Y')
				out[j]++;
			if (la[i][j] == 'Y')
				in[j]++;
		}
		ck1.clear();
		ck2.clear();
		for (int j = 0;j < m;j++)
		{
			ck1.push_back(out[j]);
			ck2.push_back(in[j]);
		}
		sort(ck1.begin(),ck1.end());
		sort(ck2.begin(),ck2.end());
		if (ck1 != ck2)	return -1;
	}
	int res = -1;
	for (int i = ck1[0];i <= ck1[m-1];i++)
	{
		int nowres = gao(i);
		if (nowres == -1)
			continue;
		if (res == -1 || res > nowres)
			res = nowres;
	}
	return res;
}


double test0() {
	string t0[] = {"NYNN", "NNYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"NNNY", "NNYN"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SwitchesAndLamps * obj = new SwitchesAndLamps();
	clock_t start = clock();
	int my_answer = obj->theMin(p0, p1);
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
double test1() {
	string t0[] = {"YYN", "YNY", "YYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"YNY", "NYY", "YNY"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SwitchesAndLamps * obj = new SwitchesAndLamps();
	clock_t start = clock();
	int my_answer = obj->theMin(p0, p1);
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
double test2() {
	string t0[] = {"NYYYNYNNYYYNYNNNNY", "NYYYNYNNYYYNYNNNNY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"YYYNNNYNNYNYNYNYNY", "YYYNNNYNNYNYYNNYNY"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SwitchesAndLamps * obj = new SwitchesAndLamps();
	clock_t start = clock();
	int my_answer = obj->theMin(p0, p1);
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
double test3() {
	string t0[] = {"YYNNN", "NNYYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"NYNNY", "NNNYY"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SwitchesAndLamps * obj = new SwitchesAndLamps();
	clock_t start = clock();
	int my_answer = obj->theMin(p0, p1);
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
	string t0[] = {"YNNYNNYNYY", "NYNNYNYNYN", "YNYNYYYYYN", "NNYYNYNYNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"NYYNYNNYNY", "NYYYNNYNNN", "YYYYNYNNYY", "YNNNNYNYYN"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SwitchesAndLamps * obj = new SwitchesAndLamps();
	clock_t start = clock();
	int my_answer = obj->theMin(p0, p1);
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
