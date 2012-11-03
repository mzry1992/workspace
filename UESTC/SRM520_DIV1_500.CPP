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

class SRMIntermissionPhase {
public:
	int countWays(vector <int>, vector <string>);
};

const long long mod = 1000000007LL;
long long dif[1<<3][200001],dp[20][200001],presum[200002];

int SRMIntermissionPhase::countWays(vector <int> poi, vector <string> des) {
    int n = des.size();
    memset(dif,0,sizeof(dif));
    dif[0][0] = 1;
    for (int i = 1;i <= poi[0];i++)
        dif[1][i] = 1;
    for (int i = 1;i <= poi[1];i++)
        dif[2][i] = 1;
    for (int i = 1;i <= poi[2];i++)
        dif[4][i] = 1;
    for (int i = 1;i <= poi[0]+poi[1];i++)
        if (min(poi[1],i-1) >= max(1,i-poi[0]))
            dif[3][i] = (min(poi[1],i-1)-max(1,i-poi[0])+1)%mod;
    for (int i = 1;i <= poi[0]+poi[2];i++)
        if (min(poi[2],i-1) >= max(1,i-poi[0]))
            dif[5][i] = (min(poi[2],i-1)-max(1,i-poi[0])+1)%mod;
    for (int i = 1;i <= poi[1]+poi[2];i++)
        if (min(poi[2],i-1) >= max(1,i-poi[1]))
            dif[6][i] = (min(poi[2],i-1)-max(1,i-poi[1])+1)%mod;
    memset(dp,0,sizeof(dp));
    for (int i = 0;i < 3;i++)
    {
        if (i == 0)
        {
            for (int j = 1;j <= poi[0];j++)
                dp[i][j] = 1;
        }
        else if (i == 1)
        {
            for (int j = 2;j <= poi[0]+poi[1];j++)
            {
                int l,r;
                l = j-1;
                r = j-poi[1]-1;
                if (r < 0)  r = 0;
                dp[i][j] = (presum[l]-presum[r]+mod)%mod;
            }
        }
        else
        {
            for (int j = 2;j <= poi[0]+poi[1]+poi[2];j++)
            {
                int l,r;
                l = j-1;
                r = j-poi[2]-1;
                if (r < 0)  r = 0;
                dp[i][j] = (presum[l]-presum[r]+mod)%mod;
            }
        }
        presum[0] = 0;
        for (int j = 1;j <= poi[0]+poi[1]+poi[2];j++)
            presum[j] = (presum[j-1]+dp[i][j])%mod;
    }
    for (int i = 0;i <= poi[0]+poi[1]+poi[2];i++)
        dif[7][i] = dp[2][i];
    memset(dp,0,sizeof(dp));
    for (int i = 0;i < n;i++)
    {
        int wdo = 0;
        for (int j = 0;j < 3;j++)
            if (des[i][j] == 'Y')
                wdo |= (1<<j);
        if (i == 0)
        {
            for (int j = 0;j <= poi[0]+poi[1]+poi[2];j++)
                dp[i][j] = dif[wdo][j];
        }
        else
        {
            for (int j = 0;j <= poi[0]+poi[1]+poi[2];j++)
                dp[i][j] = (dp[i][j]+presum[j+1]*dif[wdo][j])%mod;
        }
        presum[poi[0]+poi[1]+poi[2]+1] = 0;
        for (int j = poi[0]+poi[1]+poi[2];j >= 0;j--)
            presum[j] = (presum[j+1]+dp[i][j])%mod;
    }
    long long res = 0;
    for (int i = 0;i <= poi[0]+poi[1]+poi[2];i++)
        res = (res+dp[n-1][i])%mod;
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int t0[] = {25000, 50000, 100000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string t1[] = {"YYY"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SRMIntermissionPhase * obj = new SRMIntermissionPhase();
	clock_t start = clock();
	int my_answer = obj->countWays(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 25000;
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
	int t0[] = {30000, 60000, 90000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string t1[] = {"NYN",
 "NYN","NNN"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SRMIntermissionPhase * obj = new SRMIntermissionPhase();
	clock_t start = clock();
	int my_answer = obj->countWays(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 799969993;
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
	int t0[] = {25000, 45000, 110000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string t1[] = {"NNN",
 "YYY"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SRMIntermissionPhase * obj = new SRMIntermissionPhase();
	clock_t start = clock();
	int my_answer = obj->countWays(p0, p1);
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
	int t0[] = {25600, 51200, 102400};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string t1[] = {"NYY",
 "YNY",
 "YYY",
 "YNN",
 "YYN",
 "NNY",
 "NYN",
 "NNN"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SRMIntermissionPhase * obj = new SRMIntermissionPhase();
	clock_t start = clock();
	int my_answer = obj->countWays(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 867560805;
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
