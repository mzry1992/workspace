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

class KingdomAndDice {
public:
	double newFairness(vector <int>, vector <int>, int);
};

int cnt[51];
bool can[51][2501];
vector<int> w;

double KingdomAndDice::newFairness(vector <int> a, vector <int> b, int x) {
    int n = a.size();
    sort(b.begin(),b.end());
    for (int i = 1;i < n;i++)
    {
        cnt[i] = b[i]-b[i-1]-1;
        for (int j = 0;j < n;j++)
            if (a[j] > b[i-1] && a[j] < b[i])
                cnt[i]--;
    }
    cnt[n] = x-b[n-1];
    w.clear();
    for (int i = 0;i < n;i++)
        w.push_back(0);
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n && j <= cnt[i];j++)
            w.push_back(i);
    memset(can,false,sizeof(can));
    can[0][0] = true;
    for (int i = 0;i < w.size();i++)
    {
        for (int j = n;j >= 1;j--)
            for (int k = n*n;k >= w[i];k--)
                can[j][k] |= can[j-1][k-w[i]];
    }
    int sumnow = 0;
    for (int i = 0;i < n;i++)
        if (a[i] > 0)
            for (int j = 0;j < n;j++)
                if (a[i] > b[j])
                    sumnow++;
    int tn = 0;
    for (int i = 0;i < n;i++)
        if (a[i] == 0)
            tn++;
    /*cout << sumnow << ' ' << tn << endl;
	for (int i = 0;i < w.size();i++)
		printf("%d ",w[i]);
	printf("\n");
	for (int i = 1;i <= n;i++)
		printf("%d ",cnt[i]);
	printf("\n");
	for (int i = 0;i <= n*n;i++)
		if (can[tn][i])
			printf("%d ",i);
	printf("\n");*/
    int res;
    bool hasres = false;
    for (int i = 0;i <= n*n;i++)
        if (can[tn][i] == true)
            if (i+sumnow <= n*n)
            {
                //cout << i+sumnow << ' ' << abs(2*res-n*n) << ' ' << abs(2*(i+sumnow)-n*n) << endl;
                if (hasres == false)
                {
                    res = i+sumnow;
                    hasres = true;
                }
                else
                {
                    int fa = abs(2*res-n*n);
                    int fb = abs(2*(i+sumnow)-n*n);
                    //cout << fa << ' ' << fb << endl;
                    if (fb < fa || (fa == fb && i+sumnow < res))
                        res = i+sumnow;
                }
            }
    //cout << res << endl;
    return (double)res/(double)(n*n);
}

//Powered by [KawigiEdit] 2.0!
double test0() {
	int t0[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 1000000000;
	KingdomAndDice * obj = new KingdomAndDice();
	clock_t start = clock();
	double my_answer = obj->newFairness(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.4375;
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
	int t0[] = {0,3, 6};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,4,7};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 7;
	KingdomAndDice * obj = new KingdomAndDice();
	clock_t start = clock();
	double my_answer = obj->newFairness(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.375;
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
	int t0[] = {0, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {5, 8};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 47;
	KingdomAndDice * obj = new KingdomAndDice();
	clock_t start = clock();
	double my_answer = obj->newFairness(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.5;
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
	int t0[] = {19, 50, 4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {26, 100, 37};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 1000;
	KingdomAndDice * obj = new KingdomAndDice();
	clock_t start = clock();
	double my_answer = obj->newFairness(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.2222222222222222;
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
	int t0[] = {6371, 0, 6256, 1852, 0, 0, 6317, 3004, 5218, 9012};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1557, 6318, 1560, 4519, 2012, 6316, 6315, 1559, 8215, 1561};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 10000;
	KingdomAndDice * obj = new KingdomAndDice();
	clock_t start = clock();
	double my_answer = obj->newFairness(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.49;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
