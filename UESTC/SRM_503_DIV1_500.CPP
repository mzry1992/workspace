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

class KingdomXCitiesandVillages {
public:
	double determineLength(vector <int>, vector <int>, vector <int>, vector <int>);
};

double Abs(int a)
{
    return (double)a*(double)a;
}

double mp[100][100];
double dp[100][100];

double KingdomXCitiesandVillages::determineLength(vector <int> cityX, vector <int> cityY, vector <int> villageX, vector <int> villageY) {
    double res = 0.0;
    int n,m;
    n = cityX.size();
    m = villageX.size();
    for (int i = 0;i < m;i++)
    {
        int x = villageX[i];
        int y = villageY[i];
        double mincity = 1e30;
        for (int j = 0;j <= m;j++)
            mp[i][j] = 0.0;
        for (int j = 0;j < n;j++)
        {
            int tx = cityX[j];
            int ty = cityY[j];
            if (sqrt(Abs(tx-x)+Abs(ty-y)) < mincity)
                mincity = sqrt(Abs(tx-x)+Abs(ty-y));
        }
        mp[i][m] = mincity;
        for (int j = 0;j < m;j++)
        if (i != j)
        {
            int tx = villageX[j];
            int ty = villageY[j];
            if (sqrt(Abs(tx-x)+Abs(ty-y)) <= mincity)
                mp[i][j] = sqrt(Abs(tx-x)+Abs(ty-y));
        }
    }
    memset(dp,0.0,sizeof(dp));
    for (int i = 0;i <= m;i++)
        dp[0][i] = mp[0][i];
    for (int i = 1;i < m;i++)
    {
        int ttot = 0;
        for (int j = 0;j <= m;j++)
        if (dp[i-1][j] > 0.0)    ttot++;
        double tres = 0.0;
        for (int j = 0;j <= m;j++)
            tres += dp[i-1][j];
        tres = tres/(double)ttot;
        for (int j = 0;j <= m;j++)
            dp[i][j] = mp[i][j]+tres;
    }
    res = 0.0;
    int ttot = 0;
    for (int j = 0;j <= m;j++)
    {
        res += dp[m-1][j];
        if (dp[m-1][j] > 0.0)   ttot++;
    }
    return res/(double)ttot;
}

//Powered by [KawigiEdit] 2.0!
double test0() {
	int t0[] = {3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {3,3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {2,1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	KingdomXCitiesandVillages * obj = new KingdomXCitiesandVillages();
	clock_t start = clock();
	double my_answer = obj->determineLength(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 2.5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {1,4,7,10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {5,5,5,5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1,4,7,10};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {4,4,4,4};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	KingdomXCitiesandVillages * obj = new KingdomXCitiesandVillages();
	clock_t start = clock();
	double my_answer = obj->determineLength(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 4.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {1,2,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {4,4,4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {4,5,6};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {4,4,4};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	KingdomXCitiesandVillages * obj = new KingdomXCitiesandVillages();
	clock_t start = clock();
	double my_answer = obj->determineLength(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 4.166666666666667;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
