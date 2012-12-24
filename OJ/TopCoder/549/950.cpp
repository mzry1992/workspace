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

class CosmicBlocks {
public:
	int getNumOrders(vector <int>, int, int);
};

set<vector<vector<int> > > hash;
vector<int> a;
int n,res,op,ed;
bool use[6];
int dp[7][7];

void Gao(vector<vector<int> > now,int tot)
{
    if (tot == n)
    {
        if (hash.find(now) != hash.end())   return;
        hash.insert(now);
        int tt = 1,sum = 1;
        for (int i = 0;i < now.size();i++)
        {
            tt = tt*dp[sum][now[i].size()];
            sum += now[i].size();
        }
        if (tt >= op && tt <= ed)
        {
            res++;
        }
            if (n == 4)
            {
                for (int i = 0;i < now.size();i++)
                {
                    for (int j = 0;j < now[i].size();j++)
                        printf("%d ",a[now[i][j]]);
                    printf("\n");
                }
                printf("res = %d\n",tt);
            }
        return;
    }
    vector<vector<int> > nxt;
    vector<int> tmp;
    tmp.push_back(0);
    for (int i = 0;i < n;i++)
        if (use[i] == false)
        {
            use[i] = true;
            for (int j = 0;j < now.size();j++)
                if (a[i] >= a[now[j][now[j].size()-1]])
                {
                    nxt = now;
                    nxt[j].push_back(i);
                    Gao(nxt,tot+1);
                }
            bool flag = true;
            for (int j = 0;j < now.size() && flag;j++)
                if (now[j][0] > i)
                    flag = false;
            if (flag)
            {
                nxt = now;
                tmp[0] = i;
                nxt.push_back(tmp);
                Gao(nxt,tot+1);
            }
            use[i] = false;
        }
}

int CosmicBlocks::getNumOrders(vector <int> tb, int top, int ted) {
    a = tb;
    op = top;
    ed = ted;
    n = a.size();
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1;i <= 6;i++)
        for (int j = 0;j <= 6;j++)
            for (int k = 0;k <= j;k++)
                dp[i][j] = dp[i][j]+dp[i-1][k];
    vector<vector<int> > tmp;
    memset(use,false,sizeof(use));
    hash.clear();
    res = 0;
    Gao(tmp,0);
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int t0[] = {2,2,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1;
	int p2 = 1;
	CosmicBlocks * obj = new CosmicBlocks();
	clock_t start = clock();
	int my_answer = obj->getNumOrders(p0, p1, p2);
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
double test1() {
	int t0[] = {1,1,1,1,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 720;
	int p2 = 720;
	CosmicBlocks * obj = new CosmicBlocks();
	clock_t start = clock();
	int my_answer = obj->getNumOrders(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
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
	int t0[] = {2,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1;
	int p2 = 2;
	CosmicBlocks * obj = new CosmicBlocks();
	clock_t start = clock();
	int my_answer = obj->getNumOrders(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 3;
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
	int t0[] = {1,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1;
	int p2 = 2;
	CosmicBlocks * obj = new CosmicBlocks();
	clock_t start = clock();
	int my_answer = obj->getNumOrders(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
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
	int t0[] = {1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1;
	int p2 = 1;
	CosmicBlocks * obj = new CosmicBlocks();
	clock_t start = clock();
	int my_answer = obj->getNumOrders(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
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
	int t0[] = {1,2,4,8};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 5;
	int p2 = 30;
	CosmicBlocks * obj = new CosmicBlocks();
	clock_t start = clock();
	int my_answer = obj->getNumOrders(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 27;
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
double test6() {
	int t0[] = {1,2,3,4,5,6};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1;
	int p2 = 720;
	CosmicBlocks * obj = new CosmicBlocks();
	clock_t start = clock();
	int my_answer = obj->getNumOrders(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4445;
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
double test7() {
	int t0[] = {7500,1000,7500,1000,7500};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 8;
	int p2 = 88;
	CosmicBlocks * obj = new CosmicBlocks();
	clock_t start = clock();
	int my_answer = obj->getNumOrders(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 448;
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

	time = test6();
	if (time < 0)
		errors = true;

	time = test7();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
