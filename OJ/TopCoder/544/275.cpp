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

class ElectionFraudDiv1 {
public:
	int MinimumVoters(vector <int>);
};

int lv[50],rv[50],pl,pr;

int ElectionFraudDiv1::MinimumVoters(vector <int> p) {
    int n = p.size();
    for (int res = 1;res <= 40000;res++)
    {
        bool check = true;
        //cout << l << ' ' << r << ' ' << mid << endl;
        int suml,sumr;
        suml = 0;
        sumr = 0;
        for (int i = 0;i < n;i++)
        {
            pl = max(0,2*p[i]-1);
            pr = min(200,2*p[i]+1);
            lv[i] = pl*res/200;
            rv[i] = pr*res/200;
            while (pl*res > 200*lv[i])    lv[i]++;
            while (pr*res <= 200*rv[i])   rv[i]--;
            if (lv[i] > rv[i])
                check = false;
            suml += lv[i];
            sumr += rv[i];
            //cout << pl << ' ' << pr << ' ' << pl*res << ' ' << pr*res << ' ' << lv[i]*200 << ' ' << rv[i]*200 << endl;
        }
        if (res < suml || res > sumr)
            check = false;
        //cout << check << endl;
        if (check == true)
            return res;
    }
    return -1;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int t0[] = {5,7,11,13,17,19,23,13};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ElectionFraudDiv1 * obj = new ElectionFraudDiv1();
	clock_t start = clock();
	int my_answer = obj->MinimumVoters(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
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
	int t0[] = {29, 29, 43};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ElectionFraudDiv1 * obj = new ElectionFraudDiv1();
	clock_t start = clock();
	int my_answer = obj->MinimumVoters(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 7;
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
	int t0[] = {12, 12, 12, 12, 12, 12, 12, 12};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ElectionFraudDiv1 * obj = new ElectionFraudDiv1();
	clock_t start = clock();
	int my_answer = obj->MinimumVoters(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
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
	int t0[] = {13, 13, 13, 13, 13, 13, 13, 13};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ElectionFraudDiv1 * obj = new ElectionFraudDiv1();
	clock_t start = clock();
	int my_answer = obj->MinimumVoters(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 8;
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
	int t0[] = {0, 1, 100};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ElectionFraudDiv1 * obj = new ElectionFraudDiv1();
	clock_t start = clock();
	int my_answer = obj->MinimumVoters(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 200;
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
double test5() {
	int t0[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	ElectionFraudDiv1 * obj = new ElectionFraudDiv1();
	clock_t start = clock();
	int my_answer = obj->MinimumVoters(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 97;
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

	time = test5();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

