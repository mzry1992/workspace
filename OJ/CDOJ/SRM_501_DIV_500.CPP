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

class FoxAverageSequence {
public:
	int theCount(vector <int>);
};

const long long MOD = 1000000007LL;

int top[100],bottom[100];
int res;

int FoxAverageSequence::theCount(vector <int> seq) {
    res = 1;
    int n = seq.size();
    for (int i = 0;i < n;i++)
    {
        int maxp,minp;
        maxp = minp = 0;
        for (int j = 0;j < i;j++)
        {
            maxp += top[j];
            minp += bottom[j];
        }
        if (seq[i] == -1)
        {
            if (i == 0)
            {
                top[i] = 40;
                bottom[i] = 0;
            }
            else
            {
                top[i] = (int)(maxp/i);
                bottom[i] = 0;
            }
        }
        else
        {
            top[i] = bottom[i] = seq[i];
            int ttot = seq[i]*i;
            if (ttot > minp)
            {
                ttot -= minp;
                for (int j = 0;j < i;j++)
                {
                    if (ttot == 0)  break;
                    if (top[j] > bottom[j])
                    {
                        if (top[j]-bottom[j] <= ttot)
                        {
                            ttot -= (top[j]-bottom[j]);
                            bottom[j] = top[j];
                        }
                        else
                        {
                            bottom[j] += ttot;
                            ttot = 0;
                        }
                    }
                }
                if (ttot > 0)   res = 0;
            }
        }
    }
    for (int i = 2;i < n;i++)
    if (bottom[i-2] > bottom[i-1] && bottom[i-1] > bottom[i])
    {
        bottom[i] = bottom[i-1];
        if (bottom[i] > top[i]) res = 0;
    }
    for (int i = 0;i < n;i++)
        res *= (top[i]-bottom[i]+1);
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int t0[] = {3, -1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxAverageSequence * obj = new FoxAverageSequence();
	clock_t start = clock();
	int my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 4;
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
	int t0[] = {5, 3, -1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxAverageSequence * obj = new FoxAverageSequence();
	clock_t start = clock();
	int my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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
	int t0[] = {-1, 0, 40};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxAverageSequence * obj = new FoxAverageSequence();
	clock_t start = clock();
	int my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
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
	int t0[] = {-1, 40, -1, -1, -1, 10, -1, -1, -1, 21, -1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxAverageSequence * obj = new FoxAverageSequence();
	clock_t start = clock();
	int my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 579347890;
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
	int t0[] = {-1, 12, 25, 0, 18, -1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxAverageSequence * obj = new FoxAverageSequence();
	clock_t start = clock();
	int my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 58;
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
