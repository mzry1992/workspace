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
#define MAX(X,Y) (((X)>(Y))?(X):(Y))
#define ABS(X) (((X)>0)?(X):(-(X)))
using namespace std;

class FoxStones {
public:
	int getCount(int, int, vector <int>, vector <int>);
};

int tot;
long long jc[1000];
int s[100000][60];
int dis[60];
const int MOD = 1000000009;

int FoxStones::getCount(int N, int M, vector <int> sx, vector <int> sy) {
    int K = sx.size();
    tot = 0;
    jc[0] = 1;
    for (int i = 1;i <= 900;i++)
        jc[i] = (jc[i-1]*i)%MOD;
    int dist;
    for (int i = 1;i <= N;i++)
    for (int j = 1;j <= M;j++)
    {
        for (int k = 0;k < K;k++)
            dis[k+1] = MAX(ABS(sx[k]-i),ABS(sy[k]-j));
        int pos = 0;
        for (int x = 1;x <= tot;x++)
        {
            bool flag = true;
            for (int y = 1;y <= K;y++)
            if (dis[y] != s[x][y])
            {
                flag = false;
                break;
            }
            if (flag == true)
            {
                pos = x;
                break;
            }
        }
        if (pos == 0)
        {
            tot++;
            for (int x = 1;x <= K;x++)
                s[tot][x] = dis[x];
            s[tot][0] = 1;
        }
        else
        {
            s[pos][0]++;
        }
    }
    cout << tot << endl;
    for (int i = 1;i <= tot;i++)
        cout << s[i][0] << ' ';
    cout << endl;
    long long lres = 1;
    for (int i = 1;i <= tot;i++)
        lres = (lres*jc[s[i][0]])%MOD;
    return lres;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	int p0 = 200;
	int p1 = 200;
	int t2[] = {1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	FoxStones * obj = new FoxStones();
	clock_t start = clock();
	int my_answer = obj->getCount(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 4;
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
	int p0 = 2;
	int p1 = 2;
	int t2[] = {2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	FoxStones * obj = new FoxStones();
	clock_t start = clock();
	int my_answer = obj->getCount(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 6;
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
	int p0 = 3;
	int p1 = 3;
	int t2[] = {1,2,3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1,2,3};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	FoxStones * obj = new FoxStones();
	clock_t start = clock();
	int my_answer = obj->getCount(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 8;
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
double test3() {
	int p0 = 12;
	int p1 = 34;
	int t2[] = {5,6,7,8,9,10};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {11,12,13,14,15,16};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	FoxStones * obj = new FoxStones();
	clock_t start = clock();
	int my_answer = obj->getCount(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 410850247;
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

	time = test3();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
