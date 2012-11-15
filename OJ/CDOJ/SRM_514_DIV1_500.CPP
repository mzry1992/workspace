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

class MagicalGirlLevelTwoDivOne {
public:
	int theCount(vector <string>, int, int);
};

int totl,totr,id[50][50],rid[50*50][2],a[50*50][50*50],b[50*50];
const long long mod = 1000000007LL;

int MagicalGirlLevelTwoDivOne::theCount(vector <string> pa, int n, int m) {
    totr = 0;
    for (int i = 0;i < pa.size();i++)
        for (int j = 0;j < pa[0].size();j++)
            if (pa[i][j] == '.')
            {
                id[i][j] = totr;
                rid[totr][0] = i;
                rid[totr++][1] = j;
            }
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    totl = 0;
    for (int i = 0;i < pa.size()-n+1;i++)
        for (int j = 0;j < pa[0].size();j++)
        {
            int countnum = 0;
            bool nodot = false;
            for (int k = 0;k < n;k++)
                if (pa[i+k][j] == '.')
                {
                    a[totl][id[i+k][j]] = 1;
                    nodot = true;
                }
                else
                    countnum = (countnum+pa[i+k][j]-'0')%2;
            b[totl++] = (1+countnum)%2;
            if (nodot == false && countnum == 0)    return 0;
        }
    for (int i = 0;i < pa.size();i++)
        for (int j = 0;j < pa[0].size()-m+1;j++)
        {
            int countnum = 0;
            bool nodot = false;
            for (int k = 0;k < m;k++)
                if (pa[i][j+k] == '.')
                {
                    a[totl][id[i][j+k]] = 1;
                    nodot = true;
                }
                else
                    countnum = (countnum+pa[i][j+k]-'0')%2;
            b[totl++] = (1+countnum)%2;
            if (nodot == false && countnum == 0)    return 0;
        }
    for (int i = 0;i < totl;i++)
    {
        if (a[i][i] == 0)
            for (int j = i;j < totl;j++)
                if (a[j][i] != 0)
                {
                    for (int k = i;k < totr;k++)
                        swap(a[j][k],a[i][k]);
                    swap(b[j],b[i]);
                    break;
                }
        if (a[i][i] == 0)
            continue;
        for (int j = 0;j < totl;j++)
            if (i != j && a[j][i] != 0)
            {
                for (int k = i;k < totr;k++)
                    a[j][k] = (a[j][k]+a[i][k])%2;
                b[j] = (b[j]+b[i])%2;
            }
    }
    long long res = 1;
    for (int i = 0;i < totl;i++)
        if (a[i][i] == 1)
        {
            bool flag = true;
            for (int j = i+1;j < totr;j++)
                if (a[i][j] != 0)
                {
                    flag = false;
                    break;
                }
            if (flag == true)
            {
                if (b[i] == 0)  res = (res*4)%mod;
                else
                    res = (res*5)%mod;
            }
        }
    for (int i = 0;i < totr;i++)
    {
        bool check = false;
        for (int j = 0;j < totl;j++)
        {
            bool flag = true;
            for (int k = 0;k < i;k++)
                if (a[j][k] == 0)
                {
                    flag = false;
                    break;
                }
            if (flag == false)  break;
            for (int k = )
        }
    }
    return res;
}

//Powered by [KawigiEdit] 2.0!

double test0() {
	string t0[] = {"12",
 "2."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	int p2 = 2;
	MagicalGirlLevelTwoDivOne * obj = new MagicalGirlLevelTwoDivOne();
	clock_t start = clock();
	int my_answer = obj->theCount(p0, p1, p2);
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
double test1() {
	string t0[] = {"21",
 "1."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	int p2 = 2;
	MagicalGirlLevelTwoDivOne * obj = new MagicalGirlLevelTwoDivOne();
	clock_t start = clock();
	int my_answer = obj->theCount(p0, p1, p2);
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
double test2() {
	string t0[] = {"...",
 "...",
 "..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	int p2 = 1;
	MagicalGirlLevelTwoDivOne * obj = new MagicalGirlLevelTwoDivOne();
	clock_t start = clock();
	int my_answer = obj->theCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1953125;
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
	string t0[] = {"..58..",
 "..47.."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	int p2 = 3;
	MagicalGirlLevelTwoDivOne * obj = new MagicalGirlLevelTwoDivOne();
	clock_t start = clock();
	int my_answer = obj->theCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
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
	string t0[] = {"...1.2.3",
 "4.5.6...",
 "...7.8.9",
 "1.2.3..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 4;
	int p2 = 4;
	MagicalGirlLevelTwoDivOne * obj = new MagicalGirlLevelTwoDivOne();
	clock_t start = clock();
	int my_answer = obj->theCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 886073030;
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
	string t0[] = {"....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "...................."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 10;
	int p2 = 10;
	MagicalGirlLevelTwoDivOne * obj = new MagicalGirlLevelTwoDivOne();
	clock_t start = clock();
	int my_answer = obj->theCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 240076532;
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
