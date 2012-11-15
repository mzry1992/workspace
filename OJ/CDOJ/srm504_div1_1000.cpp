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

class Stackol {
public:
	int countPrograms(vector <string>, int);
};

const long long mod = 1000000007LL;

string output;
long long dp[3000][20];
int pre[3000];

int Stackol::countPrograms(vector <string> outputFragments, int k) {
    int n = outputFragments.size();
    output = "!";
    for (int i = 0;i < n;i++)
        output = output+outputFragments[i];
    int l = output.size();
    memset(dp,0,sizeof(dp));
    for (int i = 0;i < k;i++)
        dp[0][i] = 1;
    for (int i = l-1;i >= 1;i--)
    {
        int pos;
        bool flag = false;
        for (int j = i-1;j >= 1;j--)
        if (output[j] != output[i])
        {
            flag = true;
            pos = j;
            break;
        }
        if (flag == false)
            pre[i] = 0;
        else
            pre[i] = pos;
    }
    for (int i = 1;i < l;i++)
    for (int j = 0;j <= k;j++)
    {
        dp[i][j] = 0;
        if (j > 0)
        {
            for (int k = pre[i];k <= i;k++)
                dp[i][j] = (dp[i][j]+dp[k][j-1])%mod;
        }
        else
        {
            if (pre[i] == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }
    }
    for (int i = 0;i < l;i++)
    {
        for (int j = 0;j <= k;j++)
            cout << dp[i][j] << ' ';
        cout << endl;
    }
    return (int)dp[l-1][k];
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string t0[] = {"A"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	Stackol * obj = new Stackol();
	clock_t start = clock();
	int my_answer = obj->countPrograms(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	string t0[] = {"AAAA","BABA"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	Stackol * obj = new Stackol();
	clock_t start = clock();
	int my_answer = obj->countPrograms(p0, p1);
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
double test2() {
	string t0[] = {"AB"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	Stackol * obj = new Stackol();
	clock_t start = clock();
	int my_answer = obj->countPrograms(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1;
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
	string t0[] = {"AAABABABAABA", "AA", "BBAB"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 3;
	Stackol * obj = new Stackol();
	clock_t start = clock();
	int my_answer = obj->countPrograms(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 94;
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
double test4() {
	string t0[] = {"AAAAAAAAAAAA","B"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 4;
	Stackol * obj = new Stackol();
	clock_t start = clock();
	int my_answer = obj->countPrograms(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 120;
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

	time = test4();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
