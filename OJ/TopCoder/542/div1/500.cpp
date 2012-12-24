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

class StrangeDictionary2 {
public:
	vector <double> getProbabilities(vector <string>);
};

int n,l;
long long ma[50],mb[50],mc[50];

vector <double> StrangeDictionary2::getProbabilities(vector <string> words) {
    n = words.size();
    l = words[0].size();
    vector <double> res(n);

    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            ma[j] = mb[j] = mc[j] = 0;
            for (int k = 0;k < l;k++)
            {
                if (words[i][k] < words[j][k])
                    ma[j] |= (1LL<<k);
                if (words[i][k] == words[j][k])
                    mb[j] |= (1LL<<k);
                if (words[i][k] > words[j][k])
                    mc[j] |= (1LL<<k);
            }
        }

    }

    return res;
}

//Powered by [KawigiEdit] 2.0!
double test0() {
	string t0[] = {"hardesttestever"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	StrangeDictionary2 * obj = new StrangeDictionary2();
	clock_t start = clock();
	vector <double> my_answer = obj->getProbabilities(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double t1[] = {1.0 };
	vector <double> p1(t1, t1+sizeof(t1)/sizeof(double));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"ab", "ba"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	StrangeDictionary2 * obj = new StrangeDictionary2();
	clock_t start = clock();
	vector <double> my_answer = obj->getProbabilities(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double t1[] = {0.5, 0.5 };
	vector <double> p1(t1, t1+sizeof(t1)/sizeof(double));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"aza", "aab", "bba"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	StrangeDictionary2 * obj = new StrangeDictionary2();
	clock_t start = clock();
	vector <double> my_answer = obj->getProbabilities(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double t1[] = {0.3333333333333333, 0.5, 0.16666666666666666 };
	vector <double> p1(t1, t1+sizeof(t1)/sizeof(double));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"abababab", "babababa", "acacacac", "cacacaca", "bcbcbcbc", "cbcbcbcb"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	StrangeDictionary2 * obj = new StrangeDictionary2();
	clock_t start = clock();
	vector <double> my_answer = obj->getProbabilities(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double t1[] = {0.5, 0.5, 0.0, 0.0, 0.0, 0.0 };
	vector <double> p1(t1, t1+sizeof(t1)/sizeof(double));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
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
