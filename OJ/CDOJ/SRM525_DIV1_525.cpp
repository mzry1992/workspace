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
#include <queue>
using namespace std;

class Rumor {
public:
	int getMinimum(string, vector <string>);
};

inline int getbit(int sta,int pos)
{
    return (sta>>(2*pos))&3;
}

inline int setbit(int sta,int pos,int val)
{
    return ((sta>>(2*pos+2))<<(2*pos+2))|(val<<(2*pos))|(sta&((1<<(pos*2))-1));
}

int n;
map<int,int> dp;
set<int> inq;
queue<int> Q;

void output(int sta)
{
    for (int i = 0;i < n;i++)
        printf("%3d",getbit(sta,i));
    printf("\n");
}

int Rumor::getMinimum(string knowledge, vector <string> graph) {
    n = knowledge.size();
    int inital = 0,final = 0;
    for (int i = 0;i < n;i++)
    {
        if (knowledge[i] == 'Y')
            inital = setbit(inital,i,3);
        final = setbit(final,i,3);
    }

    while (!Q.empty())  Q.pop();
    dp.clear();
    inq.clear();

    Q.push(inital);
    dp[inital] = 0;
    inq.insert(inital);

    int now,tupd,upd,know,a[16],tota;

    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();
        inq.erase(now);
        tupd = now;
        tota = 0;
        if (now == final)   return dp[now];
        /*output(now);
        cout << ' ' << dp[now] << endl;
        getchar();*/
        for (int i = 0;i < n;i++)
        {
            know = getbit(now,i);
            if (know < 3)
            {
                for (int j = 0;j < n;j++)
                    if (graph[i][j] == 'Y')
                        tupd = setbit(tupd,j,getbit(tupd,j)|know);
            }
            else    a[tota++] = i;
        }
        for (int i = 0;i < (1<<tota);i++)
        {
            upd = tupd;
            for (int j = 0;j < tota;j++)
                for (int k = 0;k < n;k++)
                    if (graph[a[j]][k] == 'Y')
                    {
                        if (((i>>j)&1) == 0)
                            upd = setbit(upd,k,getbit(upd,k)|1);
                        else
                            upd = setbit(upd,k,getbit(upd,k)|2);
                    }
            if (dp.find(upd) == dp.end() || dp[upd] > dp[now]+1)
            {
                dp[upd] = dp[now]+1;
                if (inq.find(upd) == inq.end())
                {
                    Q.push(upd);
                    inq.insert(upd);
                }
            }
        }
    }
    return -1;
    if (dp.find(final) == dp.end()) return -1;
    return dp[final];
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string p0 = "YNN";
	string t1[] = {"NYN"
,"NNY"
,"NNN"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	Rumor * obj = new Rumor();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
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
	string p0 = "YNNY";
	string t1[] = {"NYYN"
,"YNNY"
,"YNNY"
,"NYYN"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	Rumor * obj = new Rumor();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
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
double test2() {
	string p0 = "YYYY";
	string t1[] = {"NYNN"
,"YNYN"
,"NYNY"
,"NNYN"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	Rumor * obj = new Rumor();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
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
	string p0 = "YYYYYN";
	string t1[] = {"NYYYYN"
,"YNYYYN"
,"YYNYYN"
,"YYYNYN"
,"YYYYNN"
,"NNNNNN"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	Rumor * obj = new Rumor();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
	string p0 = "NNNY";
	string t1[] = {"NNNN"
,"YNNN"
,"YNNN"
,"NYYN"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	Rumor * obj = new Rumor();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
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
double test5() {
	string p0 =  "NNNNNNNYYY";
	string t1[] = {"NYNNYNNYNN"
,"NNYNYNNNNY"
,"YYNNNYNNNN"
,"YNNNYNYNNN"
,"NNYNNYNNYN"
,"NNNNYNNNYY"
,"NYNYNYNNNN"
,"NNNNNNYNYY"
,"NNNYNNNYNY"
,"NYYNNNNYNN"}
;
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	Rumor * obj = new Rumor();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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

	time = test5();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
