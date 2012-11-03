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

class MysteriousRestaurant {
public:
	int maxDays(vector <string>, int);
};

int pr[7][50];

int getval(char ch)
{
    if (ch >= '0' && ch <= '9') return ch-'0';
    if (ch >= 'A' && ch <= 'Z') return ch-'A'+10;
    return ch-'a'+36;
}

int MysteriousRestaurant::maxDays(vector <string> p, int b) {
    int n,m;
    n = p.size();
    m = p[0].size();
    int res = 0;
    for (int i = 0;i < n;i++)
    {
        int nowcost = 0;
        memset(pr,0,sizeof(pr));
        for (int j = 0;j <= i;j++)
            for (int k = 0;k < m;k++)
                pr[j%7][k] += getval(p[j][k]);
        for (int j = 0;j < 7;j++)
        {
            int tmin = pr[j][0];
            for (int k = 0;k < m;k++)
                tmin = min(tmin,pr[j][k]);
            nowcost += tmin;
        }
        if (nowcost <= b)   res = i+1;
    }
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string t0[] = {"26", "14", "72", "39", "32", "85", "06"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 13;
	MysteriousRestaurant * obj = new MysteriousRestaurant();
	clock_t start = clock();
	int my_answer = obj->maxDays(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 5;
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
	string t0[] = {"26", "14", "72", "39", "32", "85", "06", "91"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 20;
	MysteriousRestaurant * obj = new MysteriousRestaurant();
	clock_t start = clock();
	int my_answer = obj->maxDays(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 8;
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
	string t0[] = {"SRM", "512"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 4;
	MysteriousRestaurant * obj = new MysteriousRestaurant();
	clock_t start = clock();
	int my_answer = obj->maxDays(p0, p1);
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
	string t0[] = {"Dear", "Code", "rsHa", "veFu", "nInT", "heCh", "alle", "ngeP", "hase", "andb", "ecar", "eful"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 256;
	MysteriousRestaurant * obj = new MysteriousRestaurant();
	clock_t start = clock();
	int my_answer = obj->maxDays(p0, p1);
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
