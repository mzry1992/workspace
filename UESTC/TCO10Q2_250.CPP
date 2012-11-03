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

class SnowPlow {
public:
	int solve(vector <string>);
};

int n;
bool visit[60][60],mp[60][60];

void DFS(int now)
{
    for (int i = 0;i < n;i++)
        if (mp[now][i] == true)
            if (visit[now][i] == false)
            {
                visit[now][i] = visit[i][now] = true;
                DFS(i);
            }
}

int SnowPlow::solve(vector <string> roads) {
    n = roads.size();
    int res = 0;
    memset(visit,false,sizeof(visit));
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            if (roads[i][j] == '0') mp[i][j] = false;
            else mp[i][j] = true;
    DFS(0);
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            if (mp[i][j] == true && visit[i][j] == false)   return -1;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            res += roads[i][j]-'0';
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string t0[] = {"010000",
 "101000",
 "010100",
 "001010",
 "000101",
 "000010"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SnowPlow * obj = new SnowPlow();
	clock_t start = clock();
	int my_answer = obj->solve(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 10;
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
	string t0[] = {"010000",
 "101000",
 "010100",
 "001020",
 "000201",
 "000010"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SnowPlow * obj = new SnowPlow();
	clock_t start = clock();
	int my_answer = obj->solve(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 12;
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
	string t0[] = {"031415",
 "300000",
 "100000",
 "400000",
 "100000",
 "500000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SnowPlow * obj = new SnowPlow();
	clock_t start = clock();
	int my_answer = obj->solve(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 28;
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
	string t0[] = {"0100",
 "1000",
 "0001",
 "0010"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SnowPlow * obj = new SnowPlow();
	clock_t start = clock();
	int my_answer = obj->solve(p0);
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
double test4() {
	string t0[] = {"0101",
 "1001",
 "0000",
 "1100"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SnowPlow * obj = new SnowPlow();
	clock_t start = clock();
	int my_answer = obj->solve(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 6;
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

