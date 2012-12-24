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

class TheBrickTowerHardDivOne {
public:
	int find(int, int, long long);
};

const int mod = 1234567891;
const int MaxN = 113;
struct Matrix
{
    int a[MaxN][MaxN];
    Matrix(){}
    Matrix(int v)
    {
        memset(a,0,sizeof(a));
        for (int i = 0;i < MaxN;i++)
            a[i][i] = v;
    }
    Matrix operator *(const Matrix &b)const
    {
        Matrix res = Matrix(0);
        for (int i = 0;i < MaxN;i++)
            for (int j = 0;j < MaxN;j++)
                for (int k = 0;k < MaxN;k++)
                    res.a[i][j] = (res.a[i][j]+(long long)a[i][k]*b.a[k][j]%mod)%mod;
        return res;
    }
    Matrix operator ^(long long y)const
    {
        Matrix res = Matrix(1);
        Matrix a = *this;
        for (;y;y>>=1,a = a*a)
            if (y&1)
                res = res*a;
        return res;
    }
};

set<vector<int> > hash;
int diff[4],sta[14][4],tot;
int id[3];

void gendiff(int pos)
{
    if (pos == 4)
    {
        memset(id,-1,sizeof(id));
        int cntid = 0;
        for (int i = 0;i < 4;i++)
            if (id[diff[i]] == -1)
                id[diff[i]] = cntid++;
        vector<int> tmp(4);
        for (int i = 0;i < 4;i++)
            tmp[i] = id[diff[i]];
        if (hash.find(tmp) == hash.end())
        {
            hash.insert(tmp);
            for (int i = 0;i < 4;i++)
                sta[tot][i] = tmp[i];
            tot++;
        }
        return;
    }
    for (int i = 0;i < 3;i++)
    {
        diff[pos] = i;
        gendiff(pos+1);
    }
}

int calcxx(int a[4])
{
    return (a[0] == a[1]) + (a[1] == a[3]) + (a[0] == a[2]) + (a[2] == a[3]);
}

int TheBrickTowerHardDivOne::find(int C, int K, long long H) {
    hash.clear();
    tot = 0;
    gendiff(0);

    Matrix res = Matrix(0);
    for (int i = 0;i < MaxN;i++)
        res.a[0][i] = 1;

    for (int i = 0;i < tot;i++)
        for (int j = 0;j < tot;j++)
        {
            int baseK = calcxx(sta[j]);
        }

    res = res^H;
    return res.a[0][0];
}

//Powered by [KawigiEdit] 2.0!
double test0() {
	int p0 = 2;
	int p1 = 0;
	long long p2 = 2LL;
	TheBrickTowerHardDivOne * obj = new TheBrickTowerHardDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4;
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
	int p0 = 1;
	int p1 = 7;
	long long p2 = 19LL;
	TheBrickTowerHardDivOne * obj = new TheBrickTowerHardDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2);
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
	int p0 = 2;
	int p1 = 3;
	long long p2 = 1LL;
	TheBrickTowerHardDivOne * obj = new TheBrickTowerHardDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 14;
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
	int p0 = 4;
	int p1 = 7;
	long long p2 = 47LL;
	TheBrickTowerHardDivOne * obj = new TheBrickTowerHardDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1008981254;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
