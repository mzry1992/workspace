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

class TheLotteryBothDivs {
public:
	double find(vector <string>);
};

bool use[100];

double TheLotteryBothDivs::find(vector <string> goodSuffixes) {
    double res = 0.0;
    int n = goodSuffixes.size();
    memset(use,false,sizeof(use));
    for (int i = 0;i < n;i++)
        if (use[i] == false)
            for (int j = 0;j < n;j++)
            if (i != j)
                if (use[j] == false)
                    if (goodSuffixes[i].size() <= goodSuffixes[j].size())
                        if (goodSuffixes[j].substr(goodSuffixes[j].size()-goodSuffixes[i].size(),goodSuffixes[i].size()) == goodSuffixes[i])
                            use[j] = true;
    for (int i = 0;i < n;i++)
    if (use[i] == false)
    {
        string now = goodSuffixes[i];
        double tres = 1.0;
        for (int j = 0;j < now.size();j++)
            tres = tres*0.1;
        res += tres;
    }
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string t0[] = {"4"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheLotteryBothDivs * obj = new TheLotteryBothDivs();
	clock_t start = clock();
	double my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 0.1;
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
	string t0[] = {"4", "7"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheLotteryBothDivs * obj = new TheLotteryBothDivs();
	clock_t start = clock();
	double my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 0.2;
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
	string t0[] = {"47", "47"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheLotteryBothDivs * obj = new TheLotteryBothDivs();
	clock_t start = clock();
	double my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 0.01;
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
	string t0[] = {"47", "58", "4747", "502"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheLotteryBothDivs * obj = new TheLotteryBothDivs();
	clock_t start = clock();
	double my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 0.021;
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
double test4() {
	string t0[] = {"8542861", "1954", "6", "523", "000000000", "5426", "8"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheLotteryBothDivs * obj = new TheLotteryBothDivs();
	clock_t start = clock();
	double my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 0.201100101;
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

	time = test4();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

