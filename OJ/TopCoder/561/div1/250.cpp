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

class ICPCBalloons {
public:
	int minRepaintings(vector <int>, string, vector <int>);
};

const int inf = 0x3f3f3f3f;
int calc(vector<int> cnt,vector<int> acc)
{
    sort(cnt.begin(),cnt.end());
    sort(acc.begin(),acc.end());
    reverse(acc.begin(),acc.end());

    int sum = 0;
    for (int i = 0;i < cnt.size();i++)
        sum += cnt[i];
    int ans = 0;
    for (int i = 0;i < acc.size();i++)
    {
        if (acc[i] > sum)   return inf;
        if (cnt.empty())
        {
            ans += acc[i];
            sum -= acc[i];
        }
        else
        {
            if (cnt.back() < acc[i])
                ans += acc[i]-cnt.back();
            sum -= acc[i];
            cnt.pop_back();
        }
    }
    return ans;
}

int ICPCBalloons::minRepaintings(vector <int> cnt, string siz, vector <int> acc) {
    int n = cnt.size();
    int m = acc.size();
    vector<int> M,L;
    for (int i = 0;i < n;i++)
        if (siz[i] == 'M')
            M.push_back(cnt[i]);
        else
            L.push_back(cnt[i]);

    vector<int> cM,cL;
    int ans = inf;
    for (int sta = 0;sta < (1<<m);sta++)
    {
        cM.clear();
        cL.clear();
        for (int i = 0;i < m;i++)
            if (((sta>>i)&1) == 0)
                cM.push_back(acc[i]);
            else
                cL.push_back(acc[i]);

        ans = min(ans,calc(M,cM)+calc(L,cL));
    }
    if (ans == inf)
        ans = -1;
    return ans;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int t0[] = {100};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string p1 = "L";
	int t2[] = {1,2,3,4,5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ICPCBalloons * obj = new ICPCBalloons();
	clock_t start = clock();
	int my_answer = obj->minRepaintings(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 10;
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
	int t0[] = {100};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string p1 = "M";
	int t2[] = {10,20,30,40,50};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ICPCBalloons * obj = new ICPCBalloons();
	clock_t start = clock();
	int my_answer = obj->minRepaintings(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = -1;
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
	int t0[] = {5,6,1,5,6,1,5,6,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string p1 = "MLMMLMMLM";
	int t2[] = {7,7,4,4,7,7};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ICPCBalloons * obj = new ICPCBalloons();
	clock_t start = clock();
	int my_answer = obj->minRepaintings(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 6;
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
	int t0[] = {100,100};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string p1 = "ML";
	int t2[] = {50,51,51};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ICPCBalloons * obj = new ICPCBalloons();
	clock_t start = clock();
	int my_answer = obj->minRepaintings(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = -1;
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
	int t0[] = {8,5,1,4,1,1,3,1,3,3,5,4,5,6,9};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string p1 = "MMMLLLMMLLMLMLM";
	int t2[] = {3,5,3,3,5,6,4,6,4,2,3,7,1,5,2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ICPCBalloons * obj = new ICPCBalloons();
	clock_t start = clock();
	int my_answer = obj->minRepaintings(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 5;
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
double test5() {
	int t0[] = {1,18,4,7,19,7,7,1,4,8,10,5,14,13,8,22,6,3,13,5,3,4,2,1,3,15,19,4,5,9,4,11,2,7,12,20,11,26,22,7,2,10,9,20,13,20,2,9,11,9};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string p1 = "LLMLLLLMLLLLLLLLLLLLMLLLLLLLLLLMMLMLLLMLLLLLLLLMLL";
	int t2[] = {44,59,29,53,16,23,13,14,29,42,13,15,66,4,47};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ICPCBalloons * obj = new ICPCBalloons();
	clock_t start = clock();
	int my_answer = obj->minRepaintings(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 210;
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

	time = test5();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
