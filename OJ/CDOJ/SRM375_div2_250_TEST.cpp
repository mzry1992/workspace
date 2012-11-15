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

class MixtureDensity {
public:
	double getDensity(vector <string>);
};

double MixtureDensity::getDensity(vector <string> ingredients) {
	int i,j,v,m,k,tv,tm;
	double res;
	res = 0;
	v = m = 0;
	for (i = 0;i < ingredients.size();i++)
	{
        tv = tm = 0;
        j = 0;
        while ((ingredients[i][j] >= '0') && (ingredients[i][j] <= '9'))
        {
              tv = tv*10+ingredients[i][j]-'0';
              j++;
        }
        j = ingredients[i].size()-3;
        k = 1;
        while ((ingredients[i][j] >= '0') && (ingredients[i][j] <= '9'))
        {
              tm = tm+(ingredients[i][j]-'0')*k;
              k *= 10;
              j--;
        }
        v += tv;
        m += tm;
    }
    res = (double)m/(double)v;
    return res;
}

//Powered by [KawigiEdit] 2.0!


double test0() {
	string t0[] = {"200 ml of oil, weighing 180 g"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MixtureDensity * obj = new MixtureDensity();
	clock_t start = clock();
	double my_answer = obj->getDensity(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 0.9;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"100 ml of dichloromethane, weighing 130 g", "100 ml of sea water, weighing 103 g"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MixtureDensity * obj = new MixtureDensity();
	clock_t start = clock();
	double my_answer = obj->getDensity(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 1.165;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"1000 ml of water, weighing 1000 g", "500 ml of orange juice concentrate, weighing 566 g"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MixtureDensity * obj = new MixtureDensity();
	clock_t start = clock();
	double my_answer = obj->getDensity(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 1.044;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"1000 ml of something   l i g h t, weighing 1 g"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MixtureDensity * obj = new MixtureDensity();
	clock_t start = clock();
	double my_answer = obj->getDensity(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 0.0010;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
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
	system("pause");
}
