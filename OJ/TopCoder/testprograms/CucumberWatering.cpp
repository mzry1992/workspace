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

class CucumberWatering {
public:
	long long theMin(vector <int>, int);
};

long long pre[50][50];
vector<pair<long long,long long> > x;
vector<int> id;
vector<long long> pos;
int n;

long long Gao(int l,int r,int mid)
{
	long long res = 0;
	long long tel = x[mid].first;
	id.clear();
	for (int i = l;i <= r;i++)
		id.push_back(x[i].second);
	for (int i = 0;i < id.size();i++)
		cout << id[i] << ' ';
	cout << endl;
	for (int i = 0;i < id.size();i++)
	{
		if (id[i] != 0)
			res += abs(pos[id[i]]-tel);
		if (n == 4)
		cout << "star : " << i << " pos i : " << pos[i] << " tel : " << tel << ' ';
		while (i+1 < id.size() && id[i+1] == id[i]+1)
		{
			res += abs(pos[id[i+1]]-pos[id[i]]);
			i++;
		}
		if (id[i] != n-1)
			res += abs(pos[id[i]]-tel);
		if (n == 4)
		cout << "end : " << i << ' ' << "res : " << res << endl;
	}
	return res;
}

long long dp[50][50];

long long CucumberWatering::theMin(vector <int> X, int K) {
	n = X.size();
	x.clear();
	pos.clear();
	for (int i = 0;i < n;i++)
	{
		x.push_back(make_pair((long long)X[i],i));
		pos.push_back((long long)X[i]);
	}
	sort(x.begin(),x.end());
	for (int i = 0;i < n;i++)
		for (int j = i;j < n;j++)
		{
			pre[i][j] = -1;
			for (int k = i;k <= j;k++)
			{
				long long val = Gao(i,j,k);
				if (pre[i][j] == -1 || val < pre[i][j])
					pre[i][j] = val;
				if (n == 4)
					cout << i << ' ' << j << ' ' << k << ' ' << pre[i][j] << endl;
			}
		}
	for (int i = 0;i < n;i++)
		for (int j = 0;j < K;j++)
			dp[i][j] = -1;
	for (int i = 0;i < n;i++)
	{
		dp[i][0] = pre[0][i];
		for (int j = 1;j < K;j++)
			for (int k = 0;k < i;k++)
			{
				long long val = dp[k][j-1]+pre[k+1][i];
				if (dp[i][j] == -1 || dp[i][j] > val)
					dp[i][j] = val;
			}
	}
	long long res = -1;
	for (int j = 0;j < K;j++)
		if (dp[n-1][j] != -1)
			if (res == -1 || res > dp[n-1][j])
				res = dp[n-1][j];
	return res;
}


double test0() {
	int t0[] = {0, 6, 8, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 2;
	CucumberWatering * obj = new CucumberWatering();
	clock_t start = clock();
	long long my_answer = obj->theMin(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 6LL;
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
	int t0[] = {-1000000000, 1000000000, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1;
	CucumberWatering * obj = new CucumberWatering();
	clock_t start = clock();
	long long my_answer = obj->theMin(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 3000000000LL;
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
	int t0[] = {58, 2012};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 50;
	CucumberWatering * obj = new CucumberWatering();
	clock_t start = clock();
	long long my_answer = obj->theMin(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 0LL;
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
	int t0[] = {9, -3, 14, 6, 5, -9, 32, 7, -5, 26, 2, 11};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 3;
	CucumberWatering * obj = new CucumberWatering();
	clock_t start = clock();
	long long my_answer = obj->theMin(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 58LL;
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

//Powered by [KawigiEdit] 2.0!
